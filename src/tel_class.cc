#define tel_class_cxx
#include "tel_class.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
using namespace std;



tel_class::tel_class(const char* name)
{
  TTree *tree = NULL;
  TFile *f = (TFile*) gROOT->GetListOfFiles()->FindObject(name);
  if (!f || !f->IsOpen()) {
    f = new TFile(name);
  }
  f->GetObject("Tracks", tree);
  
  Init(tree);
}

tel_class::~tel_class()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t tel_class::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}


void tel_class::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set object pointer
  chi2 = 0;
  DoF = 0;
  x_0 = 0;
  x_1 = 0;
  x_2 = 0;
  x_3 = 0;
  x_4 = 0;
  x_5 = 0;
  x_FCF = 0;
  x_ABC = 0;
  y_0 = 0;
  y_1 = 0;
  y_2 = 0;
  y_3 = 0;
  y_4 = 0;
  y_5 = 0;
  y_FCF = 0;
  y_ABC = 0;
  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("ntracks", &ntracks, &b_ntracks);
  fChain->SetBranchAddress("chi2", &chi2, &b_chi2);
  fChain->SetBranchAddress("DoF", &DoF, &b_DoF);
  fChain->SetBranchAddress("x_0", &x_0, &b_x_0);
  fChain->SetBranchAddress("x_1", &x_1, &b_x_1);
  fChain->SetBranchAddress("x_2", &x_2, &b_x_2);
  fChain->SetBranchAddress("x_3", &x_3, &b_x_3);
  fChain->SetBranchAddress("x_4", &x_4, &b_x_4);
  fChain->SetBranchAddress("x_5", &x_5, &b_x_5);
  fChain->SetBranchAddress("x_FCF", &x_FCF, &b_x_FCF);
  fChain->SetBranchAddress("x_ABC", &x_ABC, &b_x_ABC);
  fChain->SetBranchAddress("y_0", &y_0, &b_y_0);
  fChain->SetBranchAddress("y_1", &y_1, &b_y_1);
  fChain->SetBranchAddress("y_2", &y_2, &b_y_2);
  fChain->SetBranchAddress("y_3", &y_3, &b_y_3);
  fChain->SetBranchAddress("y_4", &y_4, &b_y_4);
  fChain->SetBranchAddress("y_5", &y_5, &b_y_5);
  fChain->SetBranchAddress("y_FCF", &y_FCF, &b_y_FCF);
  fChain->SetBranchAddress("y_ABC", &y_ABC, &b_y_ABC);
  
}




Long64_t tel_class::GetEntries() const
{
  return fChain->GetEntries();
}
