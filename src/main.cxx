
#include <iostream>
#include "abc.hh"
#include "tel.hh"
#include "correlation.hh"
#include "TFile.h"



using namespace std;

int main(int argc, const char ** argv) {
 // gInterpreter->EnableAutoLoading();
//   auto a = loadFromFile("fdata_Run_349_start_10_last_10.root");
//   
//   for (int i = 0; i < a.size();++i)
//   {
//     a.getEntry(i);
//     a.printMemorylocation();
//     std::cout << (a.hit) << std::endl;
//   }
//   

  abc a("fdata_Run_349_start_10_last_10.root");
  tel t("C:/slac_data/TelescopeFiles1/Telescope001180_x.root");

  TFile *f = new TFile("test.root", "recreate");
  correlation c(a, t);
  c.run();
  f->Write();
  f->Close();
  delete f;
  return 0;
}