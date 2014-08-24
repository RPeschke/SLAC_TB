#ifndef abc_h__
#define abc_h__

#include "Rtypes.h"
#include <vector>

class TTree;

class abc {
public:

  Int_t           Run;
  Int_t           TLU;
  Int_t           TDC;
  Int_t           L0ID;
  Int_t           Tstamp;
  Int_t           nhit;
  Int_t           n1hit;
  std::vector<int>     *hit=nullptr;
  std::vector<int>     *cl_address=nullptr;
  std::vector<int>     *cl_size=nullptr;
  std::vector<int>     *cl_iso2=nullptr;
  Int_t           threshold;


  void openFile(const char* name);
  void close();
  abc(const char* name);
  abc() = default;
  ~abc();

  Int_t    GetEntry(Long64_t entry);
  Int_t    GetEntries();
private:
  
  void* abc_pointer=nullptr;
  TTree          *fChain;

};


#endif // abc_h__
