#ifndef telAndABC_h__
#define telAndABC_h__


#include "Rtypes.h"
class abc;
class tel;
class TTree;


enum hitpos{
  outside_low,
  edge_low,
  center,
  edge_high,
  outside_high

};
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
  void calcCombination();
  elementID getABC_Size();
  elementID getABC_Pos(){ return m_tel_calc_strip_pos - 1; }
  elementID getTEL_Size();
  elementID getTel_Pos(){ return m_tel_pos - 1; }
  Double_t calcDistance(Int_t element);
  static Int_t calcStrip_pos(Double_t hit_x);
  static hitpos calc_xhit_pos_cat(Double_t hit_x);
  static hitpos calc_yhit_pos_cat(Double_t hit_y);
  bool isGoodElement();
  void resetEvent();
  bool nextEvent();
  bool nextElement();
  bool nextTelElementCutted();
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

  // abc Parameter
  Int_t m_abc_strip_pos; 
  Int_t m_abc_threshold;
  Int_t abc_number_of_hits;
  Int_t m_abc_cluster_size;

  // tel Parameter 
  Int_t m_tel_calc_strip_pos;
  Double_t m_tel_x;
  Double_t m_tel_y;
  Double_t tel_chi2_track;
  Double_t m_tel_number_of_tracks;
  Double_t m_telt_distance_to_next_track;
  Int_t m_x_pos_cathegory;
  Int_t m_y_pos_cathegory;
  // combined Parameter

  Double_t m_comb_distance_tel_abc_0;
  
};

#endif // telAndABC_h__
