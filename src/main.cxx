
#include <iostream>
#include "abc_container.hh"
#include "TInterpreter.h"
#include <TSystem.h>
#include <TROOT.h>

using namespace std;

int main(int argc, const char ** argv) {
  gInterpreter->EnableAutoLoading();
  auto a = loadFromFile("fdata_Run_349_start_10_last_10.root");
  
  for (int i = 0; i < a.size();++i)
  {
    a.getEntry(i);

    std::cout << a.hit->size() << std::endl;
  }
  

  return 0;
}