#ifndef loadData_h__
#define loadData_h__

#include <windows.h>

#ifdef DLL_EXPORTS
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif 

extern "C"{
  DLLEXPORT HANDLE createABCObject(const char*);
  DLLEXPORT void deleteABCObject(HANDLE);
  DLLEXPORT int abc_getEntries(HANDLE abc);
  DLLEXPORT int abc_getEntry(HANDLE abc,int i);
  DLLEXPORT int abc_getRun(HANDLE abc);
  DLLEXPORT int abc_gethit(HANDLE abc,size_t pos);
  DLLEXPORT int abc_getHitSize(HANDLE abc);


  DLLEXPORT int abc_getTDC(HANDLE abc);
  DLLEXPORT int abc_getTLU(HANDLE abc);
  DLLEXPORT int abc_getTstamp(HANDLE abc);
  DLLEXPORT int abc_getnhit(HANDLE abc);
  DLLEXPORT int abc_getn1hit(HANDLE abc);
  DLLEXPORT int abc_getThreshold(HANDLE abc);
  
  DLLEXPORT int abc_get_cl_address(HANDLE abc, size_t pos);
  DLLEXPORT int abc_get_cl_address_Size(HANDLE abc);

  DLLEXPORT int abc_get_cl_size(HANDLE abc, size_t pos);
  DLLEXPORT int abc_get_cl_size_Size(HANDLE abc);

  DLLEXPORT int abc_get_cl_iso2(HANDLE abc, size_t pos);
  DLLEXPORT int abc_get_cl_iso2_Size(HANDLE abc);








  //////////////////////////////////////////////////////////////////////////
  // Telescope                                                            //
  //////////////////////////////////////////////////////////////////////////

  DLLEXPORT HANDLE createTELObject(const char* name);
  DLLEXPORT void deleteTELObject(HANDLE);
  DLLEXPORT  int tel_get_entries(HANDLE tel);
  DLLEXPORT  int tel_get_entry(HANDLE tel, long long element);

  DLLEXPORT  int tel_get_ntracks(HANDLE tel);
  DLLEXPORT  double tel_get_chi2(HANDLE tel,size_t pos);
  DLLEXPORT  size_t tel_get_chi2_size(HANDLE tel);
  DLLEXPORT  double tel_get_DoF(HANDLE tel,size_t pos);
  DLLEXPORT  size_t tel_get_DoF_size(HANDLE tel);
  DLLEXPORT  double tel_get_x_ABC(HANDLE tel,size_t pos);
  DLLEXPORT  size_t tel_get_x_ABC_size(HANDLE tel);
  DLLEXPORT  double tel_get_y_ABC(HANDLE tel,size_t pos);
  DLLEXPORT  size_t tel_get_y_ABC_size(HANDLE tel);

}

#endif // loadData_h__
