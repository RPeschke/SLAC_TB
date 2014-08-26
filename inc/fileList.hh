#ifndef fileList_h__
#define fileList_h__
#include <map>
#include <string>
#include <vector>
#include <utility>

class fileList{

public:
  fileList(){
    
  
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_10_last_10.root", "C:/slac_data/TelescopeFiles1/Telescope001232_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_15_last_15.root", "C:/slac_data/TelescopeFiles1/Telescope001233_x.root");
    //setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_20_last_20.root", "C:/slac_data/TelescopeFiles1/Telescope001234_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_25_last_25.root", "C:/slac_data/TelescopeFiles1/Telescope001235_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_30_last_30.root", "C:/slac_data/TelescopeFiles1/Telescope001236_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_35_last_35.root", "C:/slac_data/TelescopeFiles1/Telescope001237_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_40_last_40.root", "C:/slac_data/TelescopeFiles1/Telescope001238_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_45_last_45.root", "C:/slac_data/TelescopeFiles1/Telescope001239_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_50_last_50.root", "C:/slac_data/TelescopeFiles1/Telescope001240_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_55_last_55.root", "C:/slac_data/TelescopeFiles1/Telescope001241_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_60_last_60.root", "C:/slac_data/TelescopeFiles1/Telescope001242_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_65_last_65.root", "C:/slac_data/TelescopeFiles1/Telescope001243_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_70_last_70.root", "C:/slac_data/TelescopeFiles1/Telescope001244_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_75_last_75.root", "C:/slac_data/TelescopeFiles1/Telescope001245_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_80_last_80.root", "C:/slac_data/TelescopeFiles1/Telescope001246_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_85_last_85.root", "C:/slac_data/TelescopeFiles1/Telescope001247_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_90_last_90.root", "C:/slac_data/TelescopeFiles1/Telescope001248_x.root");
    //setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_95_last_95.root", "C:/slac_data/TelescopeFiles1/Telescope001249_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_100_last_100.root", "C:/slac_data/TelescopeFiles1/Telescope001250_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_105_last_105.root", "C:/slac_data/TelescopeFiles1/Telescope001251_x.root");

    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_110_last_110.root", "C:/slac_data/TelescopeFiles1/Telescope001252_x.root");
    //setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_115_last_115.root", "C:/slac_data/TelescopeFiles1/Telescope001253_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_120_last_120.root", "C:/slac_data/TelescopeFiles1/Telescope001254_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_125_last_125.root", "C:/slac_data/TelescopeFiles1/Telescope001255_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_130_last_130.root", "C:/slac_data/TelescopeFiles1/Telescope001256_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_135_last_135.root", "C:/slac_data/TelescopeFiles1/Telescope001257_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_140_last_140.root", "C:/slac_data/TelescopeFiles1/Telescope001258_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_145_last_145.root", "C:/slac_data/TelescopeFiles1/Telescope001259_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_150_last_150.root", "C:/slac_data/TelescopeFiles1/Telescope001260_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_155_last_155.root", "C:/slac_data/TelescopeFiles1/Telescope001261_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_352_start_160_last_160.root", "C:/slac_data/TelescopeFiles1/Telescope001262_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_165_last_165.root", "C:/slac_data/TelescopeFiles1/Telescope001263_x.root");
    //setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_170_last_170.root", "C:/slac_data/TelescopeFiles1/Telescope001264_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_175_last_175.root", "C:/slac_data/TelescopeFiles1/Telescope001265_x.root");
    //setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_180_last_180.root", "C:/slac_data/TelescopeFiles1/Telescope001266_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_185_last_185.root", "C:/slac_data/TelescopeFiles1/Telescope001267_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_190_last_190.root", "C:/slac_data/TelescopeFiles1/Telescope001268_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_195_last_195.root", "C:/slac_data/TelescopeFiles1/Telescope001269_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_200_last_200.root", "C:/slac_data/TelescopeFiles1/Telescope001270_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_205_last_205.root", "C:/slac_data/TelescopeFiles1/Telescope001271_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_210_last_210.root", "C:/slac_data/TelescopeFiles1/Telescope001272_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_215_last_215.root", "C:/slac_data/TelescopeFiles1/Telescope001273_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_220_last_220.root", "C:/slac_data/TelescopeFiles1/Telescope001274_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_225_last_225.root", "C:/slac_data/TelescopeFiles1/Telescope001275_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_230_last_230.root", "C:/slac_data/TelescopeFiles1/Telescope001276_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_235_last_235.root", "C:/slac_data/TelescopeFiles1/Telescope001277_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_240_last_240.root", "C:/slac_data/TelescopeFiles1/Telescope001278_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_245_last_245.root", "C:/slac_data/TelescopeFiles1/Telescope001279_x.root");
    setfiles("C:/slac_data/abc/run_0712_1243/fdata_Run_353_start_250_last_250.root", "C:/slac_data/TelescopeFiles1/Telescope001280_x.root");


  }
  const char* getTEL(size_t i){ return m_abc_tel_file.at(i).second.c_str(); }
  const char* getABC(size_t i){ return m_abc_tel_file.at(i).first.c_str(); }
  size_t size(){ return m_abc_tel_file.size(); }
private:
  void  setfiles(std::string abc, std::string tel){
    m_abc_tel_file.push_back(make_pair(abc, tel));
    
  }

    std::vector<std::pair<std::string, std::string>> m_abc_tel_file;
    


};


#endif // fileList_h__
