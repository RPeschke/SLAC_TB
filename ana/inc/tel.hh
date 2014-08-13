#ifndef tel_h__
#define tel_h__

#include <vector>
#include "Rtypes.h"

class tel{
public:


  // Declaration of leaf types
  Int_t                 ntracks;
  std::vector<double>  chi2;
  std::vector<double>  DoF;


  std::vector<double>  x_ABC;


  std::vector<double>  y_ABC;




  tel(const char* name);
  ~tel();

  Int_t    GetEntry(Long64_t entry);
  Int_t    GetEntries();
private:
  void* tel_pointer;



};

#endif // tel_h__
