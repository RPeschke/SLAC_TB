#define abc_class_cxx
#include "abc_class.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


#include <iostream>

using namespace std;



abc_class::abc_class(const char* name)
{
    TTree *tree = NULL;
    TFile *f = (TFile*) gROOT->GetListOfFiles()->FindObject(name);
    if (!f || !f->IsOpen()) {
      f = new TFile(name);
    }
    f->GetObject("abc", tree);
    Init(tree);
  
}

abc_class::~abc_class()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t abc_class::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
  
}


void abc_class::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set object pointer
  hit = 0;
  cl_address = 0;
  cl_size = 0;
  cl_iso2 = 0;
  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("Run", &Run, &b_Run);
  fChain->SetBranchAddress("TLU", &TLU, &b_TLU);
  fChain->SetBranchAddress("TDC", &TDC, &b_TDC);
  fChain->SetBranchAddress("L0ID", &L0ID, &b_L0ID);
  fChain->SetBranchAddress("Tstamp", &Tstamp, &b_Tstamp);
  fChain->SetBranchAddress("nhit", &nhit, &b_nhit);
  fChain->SetBranchAddress("n1hit", &n1hit, &b_n1hit);
  fChain->SetBranchAddress("hit", &hit, &b_hit);
  fChain->SetBranchAddress("cl_address", &cl_address, &b_cl_address);
  fChain->SetBranchAddress("cl_size", &cl_size, &b_cl_size);
  fChain->SetBranchAddress("cl_iso2", &cl_iso2, &b_cl_iso2);
  fChain->SetBranchAddress("threshold", &threshold, &b_threshold);
 
}





Long64_t abc_class::GetEntries() const
{
  return fChain->GetEntries();
}

