#include "loadData.hh"
#include "abc_class.h"
#include <iostream>
#include "tel_class.h"
#define get_abc_class(a) reinterpret_cast<abc_class*>(a)
#define get_tel_class(t) reinterpret_cast<tel_class*>(t)
using namespace std;


HANDLE createABCObject(const char* name)
{
  return new abc_class(name);
}

int abc_getRun(HANDLE abc)
{
  return get_abc_class(abc)->Run;
  
}

int abc_getEntry(HANDLE abc, int i)
{

  return get_abc_class(abc)->GetEntry(i);
}

int abc_gethit(HANDLE abc,  size_t pos)
{
  
  return get_abc_class(abc)->hit->at(pos);
  


  
}

int abc_getHitSize(HANDLE abc)
{
  return get_abc_class(abc)->hit->size();
}

int abc_getTDC(HANDLE abc)
{
  return get_abc_class(abc)->TDC;
}

int abc_getTLU(HANDLE abc)
{
  return get_abc_class(abc)->TLU;
}

int abc_getTstamp(HANDLE abc)
{
  return get_abc_class(abc)->Tstamp;
}

int abc_getnhit(HANDLE abc)
{
  return get_abc_class(abc)->nhit;
}

int abc_getn1hit(HANDLE abc)
{
  return get_abc_class(abc)->n1hit;
}

int abc_get_cl_address(HANDLE abc, size_t pos)
{
  return get_abc_class(abc)->cl_address->at(pos);
}

int abc_get_cl_address_Size(HANDLE abc)
{
  return get_abc_class(abc)->cl_address->size();
}

int abc_get_cl_size(HANDLE abc, size_t pos)
{
  return get_abc_class(abc)->cl_size->at(pos);
}

int abc_get_cl_size_Size(HANDLE abc)
{
  return get_abc_class(abc)->cl_size->size();
}

int abc_get_cl_iso2(HANDLE abc, size_t pos)
{
  return get_abc_class(abc)->cl_iso2->at(pos);
}

int abc_get_cl_iso2_Size(HANDLE abc)
{
  return get_abc_class(abc)->cl_iso2->size();
}

int abc_getThreshold(HANDLE abc)
{
  return get_abc_class(abc)->threshold;
}

void deleteABCObject(HANDLE abc)
{
  delete get_abc_class(abc);
  abc = NULL;
}

int abc_getEntries(HANDLE abc)
{
  return get_abc_class(abc)->GetEntries();
}

HANDLE createTELObject(const char* name)
{
  return new tel_class(name);
}

void deleteTELObject(HANDLE tel)
{
  delete get_tel_class(tel);
}

int tel_get_ntracks(HANDLE tel)
{
  return get_tel_class(tel)->ntracks;
}

double tel_get_chi2(HANDLE tel,size_t pos)
{
  return get_tel_class(tel)->chi2->at(pos);
}

size_t tel_get_chi2_size(HANDLE tel)
{
  return get_tel_class(tel)->chi2->size();
}

double tel_get_DoF(HANDLE tel, size_t pos)
{
  return get_tel_class(tel)->DoF->at(pos);
}

size_t tel_get_DoF_size(HANDLE tel)
{
  return get_tel_class(tel)->DoF->size();
}

double tel_get_x_ABC(HANDLE tel, size_t pos)
{
  return get_tel_class(tel)->x_ABC->at(pos);
}

size_t tel_get_x_ABC_size(HANDLE tel)
{
  return get_tel_class(tel)->x_ABC->size();
}

double tel_get_y_ABC(HANDLE tel,size_t pos)
{
  return get_tel_class(tel)->y_ABC->at(pos);
}

size_t tel_get_y_ABC_size(HANDLE tel)
{
  return get_tel_class(tel)->y_ABC->size();
}

int tel_get_entries(HANDLE tel)
{
  return get_tel_class(tel)->GetEntries();

}

int tel_get_entry(HANDLE tel, long long element)
{
  return get_tel_class(tel)->GetEntry(element);
}
