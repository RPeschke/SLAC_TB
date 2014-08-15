#ifndef tel_h__
#define tel_h__

#include <vector>
#include "Rtypes.h"

class tel{
public:


  // Declaration of leaf types
  Int_t                 ntracks;
  std::vector<double>  *chi2=nullptr;
  std::vector<double>  *DoF=nullptr;
  std::vector<double>  *x_ABC=nullptr;
  std::vector<double>  *y_ABC=nullptr;
  tel(const char* name);
  ~tel();

  Int_t    GetEntry(Long64_t entry);
  Int_t    GetEntries();
private:
  void* tel_pointer;



};

#endif // tel_h__
