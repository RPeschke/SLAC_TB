#include "abc.hh"
#include "loadData.hh"

abc::abc(const char* name)
{
  abc_pointer = createABCObject(name);
  hit = new std::vector<int>();
  cl_address = new std::vector<int>();
  cl_size = new std::vector<int>();
  cl_iso2 = new std::vector<int>();
}

abc::~abc()
{
  delete hit;
  delete cl_address;
  delete cl_size;
  delete   cl_iso2;
  deleteABCObject(abc_pointer);
}

Int_t abc::GetEntry(Long64_t entry)
{
  int i = abc_getEntry(abc_pointer, entry);
  Run = abc_getRun(abc_pointer);
  TLU = abc_getTLU(abc_pointer);
  TDC = abc_getTDC(abc_pointer);

  Tstamp = abc_getTstamp(abc_pointer);
  nhit = abc_getnhit(abc_pointer);
  n1hit = abc_getn1hit(abc_pointer);
  threshold = abc_getThreshold(abc_pointer);
  hit->clear();

  for (int i = 0; i < abc_getHitSize(abc_pointer); ++i)
  {

    hit->push_back(abc_gethit(abc_pointer, i));
  }

  cl_address->clear();
  for (int i = 0; i < abc_get_cl_address_Size(abc_pointer); ++i)
  {

    cl_address->push_back(abc_get_cl_address(abc_pointer, i));
  }

  cl_size->clear();
  for (int i = 0; i < abc_get_cl_size_Size(abc_pointer); ++i)
  {

    cl_size->push_back(abc_get_cl_size(abc_pointer, i));
  }

  cl_iso2->clear();
  for (int i = 0; i < abc_get_cl_iso2_Size(abc_pointer); ++i)
  {

    cl_iso2->push_back(abc_get_cl_iso2(abc_pointer, i));
  }
  return i;
}

Int_t abc::GetEntries()
{
  return abc_getEntries(abc_pointer);
}
