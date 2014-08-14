#include "correlation.hh"
#include "TTree.h"
#include "abc.hh"
#include "tel.hh"

correlation::correlation(abc& a, tel& t) :m_abc(&a), m_tel(&t)
{
  m_tree = new TTree("corr", "correlation");
  m_tree->Branch("eventNr", &eventNR,"eventNr/I");
  m_tree->Branch("x", &m_x, "m_x/D");
  m_tree->Branch("y", &m_y, "m_x/D");
  m_tree->Branch("chi2", &chi2, "chi2/D");
  m_tree->Branch("ntracks", &ntracks, "ntracks/D");
  m_tree->Branch("cl_address", &m_cl_address, "m_cl_address/I");
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
}

void correlation::getABC(int i)
{
  m_cl_address = m_abc->cl_address->at(i);
}

bool correlation::nextEvent()
{
  ++eventNR;
  if (eventNR<m_tel->GetEntries()&&eventNR<m_abc->GetEntries())
  {
    m_tel->GetEntry(eventNR);
    m_abc->GetEntry(eventNR);
    return true;
  }
  
  return false;
}
