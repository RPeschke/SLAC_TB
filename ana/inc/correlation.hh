#ifndef correlation_h__
#define correlation_h__
#include "Rtypes.h"

class telAndDUT;
class TTree;
class TFile;
class correlation{
public:
  correlation(telAndDUT *tabc);
  void open(const char* name,TFile * f);
  void run();
  void getTel();
  void getABC();



  TTree* m_tree = nullptr;
private:
  
  telAndDUT* m_TAbc=nullptr;
  Int_t m_cl_address;
  Int_t m_threshold;
  Int_t m_strip_pos;
  Double_t m_x;
  Double_t m_y;
  Double_t chi2;
  Double_t ntracks;
  Int_t abc_hits;
  Int_t cl_size;
  Int_t eventNR;
  Double_t distance;
  Int_t m_chip2hit;
  Double_t m_isololation;
};

#endif // correlation_h__
