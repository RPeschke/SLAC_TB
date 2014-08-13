#ifndef abc_container_h__
#define abc_container_h__
#include <vector>
#include "Rtypes.h"


class TTree;



class abc_container{
public:
  abc_container(TTree* abcTree);
  Int_t getEntry(Long64_t element);
  Int_t size();
  int m_runNumber;
  int TLU;
  int TDC;
  int L0ID;
  int Tstamp;
  int nhit;
  int n1hit;
  int Threshold;
  std::vector<int> *hit=NULL;
  std::vector<int> *cl_address=nullptr;
  std::vector<int> *cl_size=nullptr;
  std::vector<int>* cl_iso2=nullptr;
  TTree* m_tree=nullptr;
};


abc_container loadFromFile(const char* name);
#endif // abc_container_h__
