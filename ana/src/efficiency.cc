#include "efficiency.hh"
#include <iostream>
#include <fstream>
#include "TTree.h"
using namespace std;

Double_t efficiency1(abc & a, tel& t)
{
  Int_t hits = 0;
  Int_t multi = 0;
  Int_t tracks = 0;
  Int_t entries = __min(a.GetEntries()- 1, t.GetEntries());
  for (Int_t i = 0; i < entries; ++i)
  {
    t.GetEntry(i);
    a.GetEntry(i + 1);
    if (a.cl_address->empty()||t.x_ABC->empty())
    {
      continue;
    }
    for (Int_t j = 0; j < t.x_ABC->size(); ++j)
    {
      Double_t x = t.x_ABC->at(j);
      Double_t tel_ch = Hit_x2chip_address(x);
      ++tracks;
      bool singlehit = true;
      bool first = true;
      for (Int_t k = 0; k < a.cl_address->size(); ++k)
      {
        Int_t ch = a.cl_address->at(k);
        if (ch > 50)
        {
          ch -= 24;
        }
        if (abs(tel_ch - ch) < 2)
        {
//           if (singlehit)
//           {
//            singlehit = false;
            ++hits;
//           }
//           else
//           {
//             if (first)
//             {
//               first = false;
//               --hits;
//               ++multi;
//             }
// 
//            
//           }

        }

      }

    }


  
    cout << "eventNR: " << i << "  hits: " << hits << endl;
  }

  cout << "hits " << hits << "   tracks " << tracks << "  multi  " << multi << " effi " << static_cast<Double_t>(hits) / static_cast<Double_t>(tracks) << endl;
  return static_cast<Double_t>(hits) / static_cast<Double_t>(tracks);
  
}

Double_t Hit_x2chip_address(Double_t x)
{
  return  -13.402*x + 81.967;
}

Double_t chip_address2Hit_x(Double_t chip_address)
{
  return  -0.0746*chip_address + 6.1158;
}



void efficiency::run()
{
  m_tABC->resetTel();
  
  while (m_tABC->getNextIsolatedTelElement())
  {
    bool hit0 = false, hit1 = false, hit2 = false, hit3 = false, hit4 = false;
    Double_t distance_ABC_channel_Tel_x_pos = 200;
    m_distance_ABC_channel_Tel_x_pos = 200;
    m_distance_ABC_channel_Tel_x_pos1 = 200;
    m_x = m_tABC->m_tel_x;
    m_y = m_tABC->m_tel_y;
    m_hit = 5;
    Double_t channelnr = Hit_x2chip_address(m_x);
    Int_t ch = telAndDUT::calcStrip_pos(m_x);
    if (ch==-1)
    {
      ch = 101;
    }
    ++tracks[ch];
    m_tABC->resetABC();
    while ((m_tABC->getNextABCElement()))
    {
      distance_ABC_channel_Tel_x_pos = abs(channelnr - m_tABC->m_abc_strip_pos);
      if (distance_ABC_channel_Tel_x_pos<1)
      {
        if (!hit0)
        {
          ++effi_0[ch];
          hit0 = true;
        }
        
        m_hit =__min(0,m_hit);
        if (m_distance_ABC_channel_Tel_x_pos>distance_ABC_channel_Tel_x_pos)
        {
          m_distance_ABC_channel_Tel_x_pos1 =  m_distance_ABC_channel_Tel_x_pos;
          m_distance_ABC_channel_Tel_x_pos =distance_ABC_channel_Tel_x_pos;
        }

      }
      if (distance_ABC_channel_Tel_x_pos<2)
      {
        if (!hit1)
        {
          ++effi_1[ch];
          hit1 = true;
        }
        
        m_hit = __min(1, m_hit);
        if (m_distance_ABC_channel_Tel_x_pos > distance_ABC_channel_Tel_x_pos)
        {
          m_distance_ABC_channel_Tel_x_pos1 = m_distance_ABC_channel_Tel_x_pos;
          m_distance_ABC_channel_Tel_x_pos = distance_ABC_channel_Tel_x_pos;
        }

      }
      if (distance_ABC_channel_Tel_x_pos< 3)
      {
        if (!hit2)
        {
          ++effi_2[ch];
          hit2 = true;
        }
        
        m_hit = __min(2, m_hit);
        if (m_distance_ABC_channel_Tel_x_pos>distance_ABC_channel_Tel_x_pos)
        {
          m_distance_ABC_channel_Tel_x_pos1 = m_distance_ABC_channel_Tel_x_pos;
          m_distance_ABC_channel_Tel_x_pos = distance_ABC_channel_Tel_x_pos;
        }

      }
      if (distance_ABC_channel_Tel_x_pos<4)
      {
        if (!hit3)
        {
          ++effi_3[ch];
          hit3 = true;
        }
        
        m_hit = __min(3, m_hit);
        if (m_distance_ABC_channel_Tel_x_pos > distance_ABC_channel_Tel_x_pos)
        {
          m_distance_ABC_channel_Tel_x_pos1 = m_distance_ABC_channel_Tel_x_pos;
          m_distance_ABC_channel_Tel_x_pos = distance_ABC_channel_Tel_x_pos;
        }

      }
      if (distance_ABC_channel_Tel_x_pos<5)
      {
        if (!hit4)
        {
          ++effi_4[ch];
          hit4 = true;
        }
        
        m_hit = __min(4, m_hit);
        if (m_distance_ABC_channel_Tel_x_pos > distance_ABC_channel_Tel_x_pos)
        {
          m_distance_ABC_channel_Tel_x_pos1 = m_distance_ABC_channel_Tel_x_pos;
          m_distance_ABC_channel_Tel_x_pos = distance_ABC_channel_Tel_x_pos;
        }

      }
    }

    m_tmap->Fill();
  }

 
}

efficiency::efficiency(telAndDUT &tABC)
{
  m_tABC = &tABC;

  reset();
  
}

efficiency::~efficiency()
{

}

void efficiency::finish()
{

  Double_t total_tracks = 0, total_effi0 = 0,total_effi1=0,total_effi2=0,total_effi3=0,total_effi4=0;

  m_isolating = m_tABC->getIisolationParameter();

  for (Channel = 0; Channel <101; ++Channel)
  {
    m_e0 = effi_0[Channel];
    total_effi0 += effi_0[Channel];
    m_e1 = effi_1[Channel];
    total_effi1 += effi_1[Channel];
    m_e2 = effi_2[Channel];
    total_effi2 += effi_2[Channel];
    m_e3 = effi_3[Channel];
    total_effi3 += effi_3[Channel];
    m_e4 = effi_4[Channel];
    total_effi4 += effi_4[Channel];
    m_t = tracks[Channel];
    total_tracks += m_t;
    m_e0 /= m_t/100;
    m_e1 /= m_t / 100;
    m_e2 /= m_t / 100;
    m_e3 /= m_t / 100;
    m_e4 /= m_t / 100;

   
   
    m_tree->Fill();
  }

  Channel = 101;
  m_e0 = total_effi0;
  m_e1 = total_effi1;
  m_e2 = total_effi2;
  m_e3 = total_effi3;
  m_e4 = total_effi4;
  m_t = total_tracks;
  m_e0 /= m_t / 100;
  m_e1 /= m_t / 100;
  m_e2 /= m_t / 100;
  m_e3 /= m_t / 100;
  m_e4 /= m_t / 100;

  m_tree->Fill();
}

void efficiency::reset()
{
  for (Int_t i = 0; i < NUMBER_OF_CHANNEL; ++i)
  {
    effi_0[i] = 0;
    effi_1[i] = 0;
    effi_2[i] = 0;
    effi_3[i] = 0;
    effi_4[i] = 0;
    tracks[i] = 0;
  }
  m_isolating = m_tABC->getIisolationParameter();
  m_thr = m_tABC->m_abc_threshold;
}

void efficiency::createTree(const char* name)
{

  m_tree = new TTree(name, name);
  m_tree->Branch("effi0", &m_e0, "m_e0/D");
  m_tree->Branch("effi1", &m_e1, "m_e1/D");
  m_tree->Branch("effi2", &m_e2, "m_e2/D");
  m_tree->Branch("effi3", &m_e3, "m_e3/D");
  m_tree->Branch("effi4", &m_e4, "m_e4/D");
  m_tree->Branch("tracks", &m_t, "m_t/D");
  m_tree->Branch("threshold", &m_thr, "m_thr/D");
  m_tree->Branch("channel", &Channel, "Channel/I");
  m_tree->Branch("isolating", &m_isolating, "m_isolating/D");


  m_tmap = new TTree("map", "map");
  m_tmap->Branch("x", &m_x, "m_x/D");
  m_tmap->Branch("y", &m_y, "m_y/D");
  m_tmap->Branch("hit", &m_hit, "m_hit/D");
  m_tmap->Branch("dist", &m_tABC->m_comb_distance_tel_abc_0, "m_dist/D");
  m_tmap->Branch("dist2", & m_distance_ABC_channel_Tel_x_pos, "m_dist2/D");
  m_tmap->Branch("dist3", &m_distance_ABC_channel_Tel_x_pos1, "m_dist3/D");
  m_tmap->Branch("isolating", &m_isolating, "m_isolating/D");
  m_tmap->Branch("threshold", &m_thr, "m_thr/D");
}

