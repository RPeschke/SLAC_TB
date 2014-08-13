#include "abc_container.hh"
#include <TTree.h>
#include <TFile.h>

abc_container::abc_container(TTree* abcTree) :m_tree(abcTree)
{

  abcTree->SetBranchAddress("Run", &m_runNumber);
  abcTree->SetBranchAddress("TLU", &TLU);
  abcTree->SetBranchAddress("TDC", &TDC);
  abcTree->SetBranchAddress("L0ID", &L0ID);
  abcTree->SetBranchAddress("Tstamp", &Tstamp);
  abcTree->SetBranchAddress("nhit", &nhit);
  abcTree->SetBranchAddress("n1hit", &n1hit);
  abcTree->SetBranchAddress("hit", &hit);
  abcTree->SetBranchAddress("cl_address", &cl_address);
  abcTree->SetBranchAddress("cl_size", &cl_size);
  abcTree->SetBranchAddress("cl_iso2", &cl_iso2);
  abcTree->SetBranchAddress("threshold", &Threshold);
}

Int_t abc_container::getEntry(Long64_t element)
{
  return m_tree->GetEntry(element);
}

Int_t abc_container::size()
{
  return m_tree->GetEntries();
}


abc_container loadFromFile(const char* name)
{
  TFile* file = new TFile(name, "READ");
  TTree* tree;
  tree= dynamic_cast<TTree*>(file->Get("abc"));

  return abc_container(tree);
}
