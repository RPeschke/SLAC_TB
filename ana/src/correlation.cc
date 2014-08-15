#include "correlation.hh"
#include "TTree.h"
#include "abc.hh"
#include "tel.hh"
#include "efficiency.hh"


correlation::correlation(abc& a, tel& t) :m_abc(&a), m_tel(&t)
{
  m_tree = new TTree("corr", "correlation");
  m_tree->Branch("eventNr", &eventNR,"eventNr/I");
  m_tree->Branch("x", &m_x, "m_x/D");
  m_tree->Branch("y", &m_y, "m_x/D");
  m_tree->Branch("chi2", &chi2, "chi2/D");
  m_tree->Branch("ntracks", &ntracks, "ntracks/D");
  m_tree->Branch("cl_address", &m_cl_address, "m_cl_address/I");
  m_tree->Branch("threshold", &m_threshold, "m_threshold/I");
  m_tree->Branch("hits", &abc_hits, "abc_hits/I");
  m_tree->Branch("distance", &distance, "distance/D");
  m_tree->Branch("Cl_Size", &cl_size, "cl_size/I");
  m_tree->Branch("strip_pos", &m_strip_pos, "strip_pos/I");
  m_tree->Branch("xvsAddress", &m_chip2hit, "m_chip2hit/I");
  eventNR = 0;
}

void correlation::run()
{
  while (nextEvent())
  {
    for (int i = 0; i < m_tel->x_ABC->size();++i)
    {
      for (int j = 0; j < m_abc->cl_address->size();++j)
      {
        getTel(i);
        getABC(j);
        m_chip2hit = abs(m_strip_pos - m_cl_address);
        m_tree->Fill();
      }

    }
  }
}

void correlation::getTel(int i)
{
  chi2 = m_tel->chi2->at(i);
  m_x = m_tel->x_ABC->at(i);
  m_y = m_tel->y_ABC->at(i);
  ntracks = m_tel->ntracks;
  distance = calcDistance(i);
  m_strip_pos = calcStrip_pos(m_x);
}

void correlation::getABC(int i)
{
  m_cl_address = m_abc->cl_address->at(i);
  if (m_cl_address>50)
  {
    m_cl_address -= 24;
  }
  m_threshold = m_abc->threshold;
  abc_hits = m_abc->cl_address->size();
  cl_size = m_abc->cl_size->at(i);
}

bool correlation::nextEvent()
{
  ++eventNR;
  int offset = 1;
  if (eventNR<m_tel->GetEntries()&&eventNR<m_abc->GetEntries())
  {
    m_tel->GetEntry(eventNR);
    m_abc->GetEntry(eventNR+offset);
    return true;
  }
  
  return false;
}

Double_t correlation::calcDistance(Int_t element)
{
  Double_t dummy_distance = 100000, x, y;
  x = m_tel->x_ABC->at(element);
  y = m_tel->y_ABC->at(element);

  for (int i = 0; i < m_tel->x_ABC->size();++i)
  {
    if (i!=element)
    {
      double d = (x - m_tel->x_ABC->at(i))*(x - m_tel->x_ABC->at(i)) + (y - m_tel->y_ABC->at(i))*(y - m_tel->y_ABC->at(i));
      dummy_distance = __min(dummy_distance, d);
    }

  }
  dummy_distance = sqrt(dummy_distance);
  return dummy_distance;
}

Int_t correlation::calcStrip_pos(Double_t hit_x)
{
  Double_t dummy = Hit_x2chip_address(hit_x) ;
  if (dummy<0)
  {
    return -1;
  }
  else if (dummy>100)
  {
    return 101;
  }

  return static_cast<Int_t>(dummy + 0.5);
}
