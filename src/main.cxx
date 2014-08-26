
#include <iostream>
#include "abc.hh"
#include "tel.hh"
#include "correlation.hh"
#include "TFile.h"
#include "efficiency.hh"
#include "telAndABC.hh"
#include "fileList.hh"


using namespace std;

int main(int argc, const char ** argv) {

  fileList fl;
  abc a;
  tel t;
  telAndDUT c(&t, &a);
  c.setIsolationParameter(1);
  efficiency e(c);
  efficiency noise(c);
  correlation corr(&c);
  TFile *f = new TFile("test_10.root", "recreate");

  e.createTree("signal");
  noise.createTree("noise");
  corr.open("corr", f);
  //int i = 20;
  for (size_t i = 0; i < fl.size(); i++)
  {
    cout << "file " << i << " of " << fl.size() << " abc file " << fl.getABC(i) << "  tel file: " << fl.getTEL(i) << endl;
    a.openFile(fl.getABC(i));
    t.openFile(fl.getTEL(i));
    for (Int_t iso = 0; iso < 6; ++iso)
    {

      c.resetEvent();
      c.setIsolationParameter(iso);
      c.setOffset(1);
      e.reset();
      while (c.nextEvent())
      {
        corr.run();
        e.run();
      }
      e.finish();
    }
//       c.resetEvent();
//       c.setOffset(0);
//       noise.reset();
//       while (c.nextEvent())
//       {
// 
//         noise.run();
//       }
//       noise.finish();
 
  }
  

  
  

  
  
  

  f->Write();
  f->Close();
  delete f;
  return 0;
}