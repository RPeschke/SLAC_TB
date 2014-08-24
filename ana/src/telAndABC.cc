#include "telAndABC.hh"
#include "abc.hh"
#include "tel.hh"
#include "TTree.h"
#include "efficiency.hh"


telAndDUT::telAndDUT(tel* t, abc *a) : m_tel(t), m_abc(a)
{
  resetEvent();
  
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

  chi2 = m_tel->chi2->at(i);
  m_x = m_tel->x_ABC->at(i);
  m_y = m_tel->y_ABC->at(i);
  ntracks = m_tel->ntracks;
  distance = calcDistance(i);
  m_strip_pos = calcStrip_pos(m_x);

}

void telAndDUT::getABC(elementID i)
{
  if (m_abc->cl_address->size() == 0)
  {
    m_cl_address = -50;
    m_threshold = m_abc->threshold;
    abc_hits = 0;
    cl_size = 0;
    return;
  }
  m_cl_address = m_abc->cl_address->at(i);
  if (m_cl_address > 50)
  {
    m_cl_address -= 24;
  }
  m_threshold = m_abc->threshold;
  abc_hits = m_abc->cl_address->size();
  cl_size = m_abc->cl_size->at(i);
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

bool telAndDUT::nextElementCutted()
{
  do
  {
    if (!nextElement())
    {
      return false;
    }


  } while (!isGoodElement());

  return true;
}

bool telAndDUT::isGoodElement()
{
  // is hit

  return true;
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
  while (getNextTelElement())
  {
    isolated = true;
    for (elementID i = 0; i < getTEL_Size(); ++i){
      Double_t ch = m_tel->x_ABC->at(i);
      if (i != getTel_Pos() && abs(Hit_x2chip_address(ch) - Hit_x2chip_address(m_x)) <m_isolation)
      {
        isolated = false;
        break;
      }
    }
  
    if (isolated)
    {
      return true;
    }
  }
  return false;
}

void telAndDUT::resetEvent()
{
  eventNR = -1;

}
