#include "abc.hh"
#ifdef _DEBUG

#include "loadData.hh"

#else


#include "TTree.h"
#include "TFile.h"
#include "TROOT.h"

#endif // _DEBUG



abc::abc(const char* name)
{
  openFile(name);
}

abc::~abc()
{
  close();
}

Int_t abc::GetEntry(Long64_t entry)
{
#ifdef _DEBUG
  int i = abc_getEntry(abc_pointer, entry);
  Run = abc_getRun(abc_pointer);
  TLU = abc_getTLU(abc_pointer);
  TDC = abc_getTDC(abc_pointer);

  Tstamp = abc_getTstamp(abc_pointer);
  nhit = abc_getnhit(abc_pointer);
  n1hit = abc_getn1hit(abc_pointer);
  threshold = abc_getThreshold(abc_pointer);
  hit->clear();

  for (int i = 0; i < abc_getHitSize(abc_pointer); ++i)
  {

    hit->push_back(abc_gethit(abc_pointer, i));
  }

  cl_address->clear();
  for (int i = 0; i < abc_get_cl_address_Size(abc_pointer); ++i)
  {

    cl_address->push_back(abc_get_cl_address(abc_pointer, i));
  }

  cl_size->clear();
  for (int i = 0; i < abc_get_cl_size_Size(abc_pointer); ++i)
  {

    cl_size->push_back(abc_get_cl_size(abc_pointer, i));
  }

  cl_iso2->clear();
  for (int i = 0; i < abc_get_cl_iso2_Size(abc_pointer); ++i)
  {

    cl_iso2->push_back(abc_get_cl_iso2(abc_pointer, i));
  }
  return i;
#else
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
#endif // _DEBUG
}

Int_t abc::GetEntries()
{
#ifdef _DEBUG
  return abc_getEntries(abc_pointer);
#else
  if (!fChain)
  {
    return -1;
  }
  return fChain->GetEntries();

#endif // _DEBUG

  
}

void abc::openFile(const char* name)
{
 // close();
#ifdef _DEBUG

  abc_pointer = createABCObject(name);
  hit = new std::vector<int>();
  cl_address = new std::vector<int>();
  cl_size = new std::vector<int>();
  cl_iso2 = new std::vector<int>();
#else
  fChain = NULL;
  TFile *f = (TFile*) gROOT->GetListOfFiles()->FindObject(name);
  if (!f || !f->IsOpen()) {
    f = new TFile(name);
  }
  f->GetObject("abc", fChain);

  // Set object pointer
  hit = 0;
  cl_address = 0;
  cl_size = 0;
  cl_iso2 = 0;
  // Set branch addresses and branch pointers
 
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("Run", &Run);
  fChain->SetBranchAddress("TLU", &TLU);
  fChain->SetBranchAddress("TDC", &TDC);
  fChain->SetBranchAddress("L0ID", &L0ID);
  fChain->SetBranchAddress("Tstamp", &Tstamp);
  fChain->SetBranchAddress("nhit", &nhit);
  fChain->SetBranchAddress("n1hit", &n1hit);
  fChain->SetBranchAddress("hit", &hit);
  fChain->SetBranchAddress("cl_address", &cl_address);
  fChain->SetBranchAddress("cl_size", &cl_size);
  fChain->SetBranchAddress("cl_iso2", &cl_iso2);
  fChain->SetBranchAddress("threshold", &threshold);


#endif // _DEBUG


}

void abc::close()
{
#ifdef _DEBUG




  if (hit!=nullptr)
  {
    delete hit;
    delete cl_address;
    delete cl_size;
    delete   cl_iso2;
    deleteABCObject(abc_pointer);
  }

  hit = nullptr;
  cl_address = nullptr;
  cl_size = nullptr;
  cl_iso2 = nullptr;
  abc_pointer = nullptr;

#else
  if (!fChain) return;
  delete fChain->GetCurrentFile();
  fChain = nullptr;

#endif // _DEBUG
}
