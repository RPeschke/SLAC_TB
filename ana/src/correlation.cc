#include "correlation.hh"
#include "TTree.h"
#include "abc.hh"
#include "tel.hh"
#include "efficiency.hh"
#include "TFile.h"




correlation::correlation(telAndDUT *tabc) : m_TAbc(tabc)
{

}

void correlation::run()
{

  while (m_TAbc->getNextIsolatedTelElement())
  {
       
    while (m_TAbc->getNextABCElement())
    {
        getTel();
        getABC();
        m_chip2hit = abs(m_strip_pos - m_cl_address);
        m_relCorrel = m_strip_pos - m_cl_address;
        eventNR = m_TAbc->eventNR;
        ++m_increment;
        m_tree->Fill();

      }

    }

}

void correlation::getTel()
{
  chi2 = m_TAbc->tel_chi2_track;
  m_x = m_TAbc->m_tel_x;
  m_y = m_TAbc->m_tel_y;
  ntracks = m_TAbc->m_tel_number_of_tracks;
  distance = m_TAbc->m_telt_distance_to_next_track;
  m_strip_pos = m_TAbc->m_tel_calc_strip_pos;
  m_isololation = m_TAbc->getIisolationParameter();
}

void correlation::getABC()
{
  m_cl_address = m_TAbc->m_abc_strip_pos;

  m_threshold = m_TAbc->m_abc_threshold;
  abc_hits = m_TAbc->abc_number_of_hits;
  cl_size = m_TAbc->m_abc_cluster_size;
}

void correlation::open(const char* name,TFile* f)
{
  m_tree = new TTree(name, name);

  m_tree->Branch("eventNr", &eventNR, "eventNr/I");
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
  m_tree->Branch("relcorr", &m_relCorrel, "m_relCorrel/D");
  m_tree->Branch("incr", &m_increment, "m_increment/I");
  eventNR = 0;
}






