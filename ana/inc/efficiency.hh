#ifndef efficiency_h__
#define efficiency_h__
#include "TTree.h"


Double_t efficiency(TTree *tree, Int_t Channel){

  
  return 1;
}

Double_t Hit_x2chip_address(Double_t x){

 return  -13.402*x + 81.967;
}

Double_t chip_address2Hit_x(Double_t chip_address){

  return  -0.0746*chip_address + 6.1158;
}
#endif // efficiency_h__
