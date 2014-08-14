#include "tel.hh"
#include "loadData.hh"
#define COPYDATAVECTOR(destination,size_function,element_function) destination->clear(); \
                                                                   for (int i=0; i< size_function(tel_pointer);++i)\
                                                                   {\
                                                                   destination->push_back(element_function(tel_pointer,i)); \
                                                                   }


// template <typename Container,typename size_fun,typename element_fun>
// void copyvector(Container& )


tel::tel(const char* name)
{
  
  tel_pointer = createTELObject(name);
  x_ABC = new std::vector<double>();
  y_ABC = new std::vector<double>();
  chi2 = new std::vector<double>();
  DoF = new std::vector<double>();

}

tel::~tel()
{
  delete y_ABC;
  delete x_ABC;
  delete chi2;
  delete DoF;
  deleteTELObject(tel_pointer);
}

Int_t tel::GetEntry(Long64_t entry)
{
   Int_t ret= tel_get_entry(tel_pointer,entry);
   COPYDATAVECTOR(x_ABC, tel_get_x_ABC_size, tel_get_x_ABC)
     COPYDATAVECTOR(y_ABC, tel_get_y_ABC_size, tel_get_y_ABC)


     COPYDATAVECTOR(chi2, tel_get_chi2_size, tel_get_chi2)
     COPYDATAVECTOR(DoF, tel_get_DoF_size, tel_get_DoF)
     ntracks = tel_get_ntracks(tel_pointer);
   return ret;
}

Int_t tel::GetEntries()
{
  return tel_get_entries(tel_pointer);
}
