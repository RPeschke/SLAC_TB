
#include <iostream>
#include "abc.hh"
#include "tel.hh"
#include "correlation.hh"
#include "TFile.h"



using namespace std;

int main(int argc, const char ** argv) {


  abc a("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_100_last_100.root");
  tel t("C:/slac_data/TelescopeFiles1/Telescope001250_x.root");

  TFile *f = new TFile("test_1.root", "recreate");
  correlation c(a, t);
  c.run();
  f->Write();
  f->Close();
  delete f;
  return 0;
}