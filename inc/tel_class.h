//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Aug 13 15:01:04 2014 by ROOT version 5.34/19
// from TTree Tracks/Tracks
// found on file: Telescope001180_x.root
//////////////////////////////////////////////////////////

#ifndef tel_class_h
#define tel_class_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class tel_class {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t                 ntracks;
   std::vector<double>  *chi2;
   std::vector<double>  *DoF;
   std::vector<double>  *x_0;
   std::vector<double>  *x_1;
   std::vector<double>  *x_2;
   std::vector<double>  *x_3;
   std::vector<double>  *x_4;
   std::vector<double>  *x_5;
   std::vector<double>  *x_FCF;
   std::vector<double>  *x_ABC;
   std::vector<double>  *y_0;
   std::vector<double>  *y_1;
   std::vector<double>  *y_2;
   std::vector<double>  *y_3;
   std::vector<double>  *y_4;
   std::vector<double>  *y_5;
   std::vector<double>  *y_FCF;
   std::vector<double>  *y_ABC;

   // List of branches
   TBranch        *b_ntracks;   //!
   TBranch        *b_chi2;   //!
   TBranch        *b_DoF;   //!
   TBranch        *b_x_0;   //!
   TBranch        *b_x_1;   //!
   TBranch        *b_x_2;   //!
   TBranch        *b_x_3;   //!
   TBranch        *b_x_4;   //!
   TBranch        *b_x_5;   //!
   TBranch        *b_x_FCF;   //!
   TBranch        *b_x_ABC;   //!
   TBranch        *b_y_0;   //!
   TBranch        *b_y_1;   //!
   TBranch        *b_y_2;   //!
   TBranch        *b_y_3;   //!
   TBranch        *b_y_4;   //!
   TBranch        *b_y_5;   //!
   TBranch        *b_y_FCF;   //!
   TBranch        *b_y_ABC;   //!


   tel_class(const char* name);
   ~tel_class();

   Int_t    GetEntry(Long64_t entry);
   Long64_t GetEntries() const;
   void     Init(TTree *tree);

};

#endif



