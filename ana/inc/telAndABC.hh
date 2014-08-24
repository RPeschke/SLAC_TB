#ifndef telAndABC_h__
#define telAndABC_h__


#include "Rtypes.h"
class abc;
class tel;
class TTree;

class telAndDUT
{
public:
  typedef int eventID;
  typedef size_t elementID;

  telAndDUT(tel* t, abc *a);
  void getTel(elementID i);
  bool getNextTelElement();
  bool getNextIsolatedTelElement();
  void getABC(elementID i);
  bool getNextABCElement();
  void resetABC();
  void resetTel();
  elementID getABC_Size();
  elementID getABC_Pos(){ return m_strip_pos - 1; }
  elementID getTEL_Size();
  elementID getTel_Pos(){ return m_tel_pos - 1; }
  Double_t calcDistance(Int_t element);
  static Int_t calcStrip_pos(Double_t hit_x);

  bool isGoodElement();
  void resetEvent();
  bool nextEvent();
  bool nextElement();
  bool nextElementCutted();
  void setOffset(eventID offset);
  void setIsolationParameter(Double_t isolation){ m_isolation = isolation; }
  Double_t getIisolationParameter(){ return m_isolation; }
  eventID eventNR = 0;
private:

  tel* m_tel=nullptr;
  abc* m_abc=nullptr;


  eventID m_offset = 1; // $$ #magic_number
  Double_t m_isolation = 2;
  elementID m_abc_pos = 0, m_tel_pos = 0;

public:
  //////////////////////////////////////////////////////////////////////////
  //  Tree Parameter                                                     //
  //////////////////////////////////////////////////////////////////////////

  Int_t m_cl_address;
  Int_t m_threshold;
  Int_t m_strip_pos;
  Double_t m_x;
  Double_t m_y;
  Double_t chi2;
  Double_t ntracks;
  Int_t abc_hits;
  Int_t cl_size;
  Double_t distance;
  Int_t m_chip2hit;

  
};

#endif // telAndABC_h__
