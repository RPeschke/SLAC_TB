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

private:
  abc* m_abc= nullptr;
  tel* m_tel =nullptr;
  TTree* m_tree = nullptr;
  Int_t m_cl_address;
  Double_t m_x;
  Double_t m_y;
  Double_t chi2;
  Double_t ntracks;
  Int_t eventNR;
};

#endif // correlation_h__
