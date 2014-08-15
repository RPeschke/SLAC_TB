#ifndef correlation_h__
#define correlation_h__
#include "Rtypes.h"

class abc;
class tel;
class TTree;


class correlation{
public:
  correlation(abc& a, tel& t);

  void run();
  void getTel(int i);
  void getABC(int i);
  bool nextEvent();
  Double_t calcDistance(Int_t element);
  Int_t calcStrip_pos(Double_t hit_x);
  TTree* m_tree = nullptr;
private:
  abc* m_abc= nullptr;
  tel* m_tel =nullptr;
  
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
};

#endif // correlation_h__
