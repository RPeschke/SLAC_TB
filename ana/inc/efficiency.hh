#ifndef efficiency_h__
#define efficiency_h__
#include "TTree.h"
#include "tel.hh"
#include "abc.hh"
#include "telAndABC.hh"

#define NUMBER_OF_CHANNEL 256

class efficiency
{
public:
  efficiency(telAndDUT& tABC);
  ~efficiency();
  void run();
  void finish();
  void createTree(const char* name);
  void reset();

private:
  telAndDUT* m_tABC=nullptr;
  TTree *m_tree=nullptr, *m_tmap=nullptr;
  Int_t Channel=0;
  Double_t effi_0[NUMBER_OF_CHANNEL],
    effi_1[NUMBER_OF_CHANNEL] ,
    effi_2[NUMBER_OF_CHANNEL] ,
    effi_3[NUMBER_OF_CHANNEL] ,
    effi_4[NUMBER_OF_CHANNEL];
  Int_t tracks[NUMBER_OF_CHANNEL];

  Double_t m_e0,m_e1, m_e2, m_e3, m_e4, m_t,m_thr,m_isolating;
  Double_t m_x, m_y, m_hit;
    
};
Double_t efficiency1(abc & a, tel& t);


Double_t Hit_x2chip_address(Double_t x);

Double_t chip_address2Hit_x(Double_t chip_address);
#endif // efficiency_h__
