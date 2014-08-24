#include "tel.hh"

#ifdef _DEBUG
#include "loadData.hh"
#define COPYDATAVECTOR(destination,size_function,element_function) destination->clear(); \
                                                                   for (int i=0; i< size_function(tel_pointer);++i)\
                                                                   { destination->push_back(element_function(tel_pointer,i)); }

#else

#include "TFile.h"
#include "TTree.h"
#include "TROOT.h"

#endif // _DEBUG





tel::tel(const char* name)
{

  openFile(name);

}

tel::~tel()
{
  close();
}

Int_t tel::GetEntry(Long64_t entry)
{
#ifdef _DEBUG



  Int_t ret = tel_get_entry(tel_pointer, entry);
  COPYDATAVECTOR(x_ABC, tel_get_x_ABC_size, tel_get_x_ABC)
  COPYDATAVECTOR(y_ABC, tel_get_y_ABC_size, tel_get_y_ABC)


   COPYDATAVECTOR(chi2, tel_get_chi2_size, tel_get_chi2)
   COPYDATAVECTOR(DoF, tel_get_DoF_size, tel_get_DoF)
   ntracks = tel_get_ntracks(tel_pointer);
  return ret;


#else
  // Read contents of entry.
  if (!m_tree) return 0;
  return m_tree->GetEntry(entry);


#endif
}

Int_t tel::GetEntries()
{
#ifdef _DEBUG
  return tel_get_entries(tel_pointer);
#else
  if (!m_tree)
  {
    return -1;
  }
  return m_tree->GetEntries();
#endif // _DEBUGUG
}

void tel::openFile(const char* name)
{
  close();
#ifdef _DEBUG

  tel_pointer = createTELObject(name);
  x_ABC = new std::vector<double>();
  y_ABC = new std::vector<double>();
  chi2 = new std::vector<double>();
  DoF = new std::vector<double>();
#else
  m_tree=NULL;
  TFile *f = (TFile*) gROOT->GetListOfFiles()->FindObject(name);
  if (!f || !f->IsOpen()) {
    f = new TFile(name);
  }
  f->GetObject("Tracks", m_tree);

  // Set object pointer
  chi2 = 0;
  DoF = 0;

  x_ABC = 0;

  y_ABC = 0;
  // Set branch addresses and branch pointers

  m_tree->SetMakeClass(1);

  m_tree->SetBranchAddress("chi2", &chi2);
  m_tree->SetBranchAddress("DoF", &DoF);
  m_tree->SetBranchAddress("x_ABC", &x_ABC);
  m_tree->SetBranchAddress("y_ABC", &y_ABC);
#endif // DEBUG


}

void tel::close()
{
#ifdef _DEBUG

  if (x_ABC!=nullptr)
  {
    delete y_ABC;
    delete x_ABC;
    delete chi2;
    delete DoF;
    deleteTELObject(tel_pointer);
  }
  x_ABC = nullptr;
  y_ABC = nullptr;
  chi2 = nullptr;
  DoF = nullptr;
  tel_pointer = nullptr;
#else
  if (!m_tree) return;
  delete m_tree->GetCurrentFile();
  m_tree=nullptr;
  x_ABC = nullptr;
  y_ABC = nullptr;
  chi2 = nullptr;
  DoF = nullptr;
  tel_pointer = nullptr;
#endif // _DEBUG

}
