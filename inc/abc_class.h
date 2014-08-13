//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Aug 13 10:31:32 2014 by ROOT version 5.34/19
// from TTree abc/abc
// found on file: fdata_Run_349_start_10_last_10.root
//////////////////////////////////////////////////////////

#ifndef abc_class_h
#define abc_class_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class abc_class {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
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

   // List of branches
   TBranch        *b_Run;   //!
   TBranch        *b_TLU;   //!
   TBranch        *b_TDC;   //!
   TBranch        *b_L0ID;   //!
   TBranch        *b_Tstamp;   //!
   TBranch        *b_nhit;   //!
   TBranch        *b_n1hit;   //!
   TBranch        *b_hit;   //!
   TBranch        *b_cl_address;   //!
   TBranch        *b_cl_size;   //!
   TBranch        *b_cl_iso2;   //!
   TBranch        *b_threshold;   //!


   abc_class(const char* name);
   ~abc_class();
   Int_t    GetEntry(Long64_t entry);
   Long64_t GetEntries() const;
   void Init(TTree *tree);
};

#endif


