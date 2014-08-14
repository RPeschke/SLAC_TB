#ifndef abc_h__
#define abc_h__

#include "Rtypes.h"
#include <vector>

class abc {
public:

  Int_t           Run;
  Int_t           TLU;
  Int_t           TDC;
  Int_t           L0ID;
  Int_t           Tstamp;
  Int_t           nhit;
  Int_t           n1hit;
  std::vector<int>     *hit;
  std::vector<int>     *cl_address;
  std::vector<int>     *cl_size;
  std::vector<int>     *cl_iso2;
  Int_t           threshold;



  abc(const char* name);
  ~abc();

  Int_t    GetEntry(Long64_t entry);
  Int_t    GetEntries();
private:
  void* abc_pointer;
};


#endif // abc_h__
