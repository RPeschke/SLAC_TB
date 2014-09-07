#include "telAndABC.hh"
#include "abc.hh"
#include "tel.hh"
#include "TTree.h"
#include "efficiency.hh"


telAndDUT::telAndDUT(tel* t, abc *a) : m_tel(t), m_abc(a)
{
//  resetEvent();
  
}

bool telAndDUT::nextEvent()
{
  ++eventNR;
 
  if (eventNR < m_tel->GetEntries() && eventNR + m_offset < m_abc->GetEntries())
  {
    m_tel->GetEntry(eventNR);
    m_abc->GetEntry(eventNR + m_offset);
    if (getTEL_Size()==0)
    {
      return nextEvent();
    }
    resetABC();
    resetTel();
    return true;
  }

  return false;
}

void telAndDUT::setOffset(eventID offset)
{
  m_offset = offset;
}

void telAndDUT::getTel(elementID i)
{

  tel_chi2_track = m_tel->chi2->at(i);
  m_tel_x = m_tel->x_ABC->at(i);
  m_tel_y = m_tel->y_ABC->at(i);
  m_tel_number_of_tracks = m_tel->ntracks;
  m_telt_distance_to_next_track = calcDistance(i);
  m_tel_calc_strip_pos = calcStrip_pos(m_tel_x);
  m_x_pos_cathegory = calc_xhit_pos_cat(m_tel_x);
  m_y_pos_cathegory = calc_yhit_pos_cat(m_tel_y);
  calcCombination();
}

void telAndDUT::getABC(elementID i)
{
  TDC = m_abc->TDC;
  if (m_abc->cl_address->size() == 0)
  {
    m_abc_strip_pos = -50;
    m_abc_threshold = m_abc->threshold;
    abc_number_of_hits = 0;
    m_abc_cluster_size = 0;
    return;
  }
  m_abc_strip_pos = m_abc->cl_address->at(i);
  if (m_abc_strip_pos > 50)
  {
    m_abc_strip_pos -= 24;
  }
  m_abc_threshold = m_abc->threshold;
  abc_number_of_hits = m_abc->cl_address->size();
  m_abc_cluster_size = m_abc->cl_size->at(i);
  calcCombination();
}

bool telAndDUT::nextElement()
{
  if (getNextABCElement())
  {
    return true;
  }

  if (getNextTelElement())
  {
    resetABC();
    return true;
  }

  if (nextEvent())
  {
    resetABC();
    resetTel();
    return true;
  }

  return false;

}

telAndDUT::elementID telAndDUT::getABC_Size()
{
  return m_abc->cl_address->size();
}

telAndDUT::elementID telAndDUT::getTEL_Size()
{
  return m_tel->x_ABC->size();
}

bool telAndDUT::getNextTelElement()
{

  if (m_tel_pos < getTEL_Size())
  {

    getTel(m_tel_pos++);
    return true;
  }
  return false;
}

bool telAndDUT::getNextABCElement()
{
  auto dummy = getABC_Size();
  
  if (m_abc_pos < getABC_Size())
  {
    
    getABC(m_abc_pos++);
    return true;
  }
  return false;
}

bool telAndDUT::nextTelElementCutted()
{
  do
  {
    if (!getNextTelElement())
    {
      return false;
    }


  } while (!isGoodElement());

  return true;
}

bool telAndDUT::isGoodElement()
{
 if (m_x_pos_cathegory==hitpos::center&&m_y_pos_cathegory==hitpos::center)
 {
   return true;
 }

  return false;
}

void telAndDUT::resetABC()
{
  m_abc_pos = 0;

  getABC(m_abc_pos);
}

void telAndDUT::resetTel()
{
  m_tel_pos = 0;

  getTel(m_tel_pos);
}

Double_t telAndDUT::calcDistance(Int_t element)
{
  Double_t dummy_distance = 100000, x, y;
  x = m_tel->x_ABC->at(element);
  y = m_tel->y_ABC->at(element);

  for (int i = 0; i < m_tel->x_ABC->size(); ++i)
  {
    if (i != element)
    {
      double d = (x - m_tel->x_ABC->at(i))*(x - m_tel->x_ABC->at(i)) + (y - m_tel->y_ABC->at(i))*(y - m_tel->y_ABC->at(i));
      dummy_distance = __min(dummy_distance, d);
    }

  }
  dummy_distance = sqrt(dummy_distance);
  return dummy_distance;
}

Int_t telAndDUT::calcStrip_pos(Double_t hit_x)
{
  Double_t dummy = Hit_x2chip_address(hit_x);
  if (dummy < 0)
  {
    return -1;
  }
  else if (dummy > 100)
  {
    return 101;
  }

  return static_cast<Int_t>(dummy + 0.5);
}

bool telAndDUT::getNextIsolatedTelElement()
{
  bool isolated = true;
  while (nextTelElementCutted())
  {
    isolated = true;
    for (elementID i = 0; i < getTEL_Size(); ++i){
      Double_t ch = m_tel->x_ABC->at(i);
      Int_t cat = calc_yhit_pos_cat(m_tel->y_ABC->at(i));

      if ((i != getTel_Pos() && 
        abs(Hit_x2chip_address(ch) - Hit_x2chip_address(m_tel_x)) <m_isolation)
        && cat>hitpos::outside_low
        &&cat<hitpos::outside_high )
      {
        isolated = false;
        break;
      }
    }
  
    if (isolated)
    {
      calcCombination();
      return true;
    }
  }
  return false;
}

void telAndDUT::resetEvent()
{
  eventNR = -1;   
  nextEvent();      // the class should load the first element to initialize the parameter correct 
  eventNR = -1;
  
}

void telAndDUT::calcCombination()
{
  m_comb_distance_tel_abc_0 = m_tel_x - chip_address2Hit_x(m_abc_pos);
}

hitpos telAndDUT::calc_xhit_pos_cat(Double_t hit_x)
{
  if (hit_x < -1.5)
  {
    return hitpos::outside_low;
  }
  else if (hit_x < -1.4)
  {
    return hitpos::edge_low;
  }
  else if (hit_x < 6.1)
  {
    return hitpos::center;
  }
  else if (hit_x < 6.2)
  {
    return hitpos::edge_high;
  }
  else{
    return hitpos::outside_high;

  }

}

hitpos telAndDUT::calc_yhit_pos_cat(Double_t hit_y)
{
  if (hit_y<-4.4)
  {
    return hitpos::outside_low;
  }
  else if (hit_y<-3.9)
  {
    return hitpos::edge_low;
  }else if (hit_y<-1.6)
  {
    return hitpos::center;
  }
  else if (hit_y<-1.35)
  {
    return hitpos::edge_high;
  }
  else{
    return hitpos::outside_high;

  }

  
}
