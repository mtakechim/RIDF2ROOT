/* M. Takechi Dec. 2016
 * A. Prochazka feb 2017
 * 
 * last modification 13.2.2017
*/

// config
#define PLASTICS_DETAILS 1
//#define PPAC_DETAILS 1  // output ppac sums and partial positions
//#define IC_RAW 1  // output IC Raw data
#define PPAC_TRACKS 1

#include "makecal.h"
#include "ribf123_rawvar.h"
#include "caldata.h"
#include "pid.h"
#include "utils.h"
using namespace std;

int main(int argc, char* argv[]){
  const char* outputdir = "./";
  const char* rawfileprefix = "raw_";
  const char* calfileprefix = "cal_";
  
  TString ifname, ofname, ofprefix;
  
  // Check Arguments
  if(argc<2){ // at least 2 arguments are expected
      printf("Wrong arguments %d\n",argc);
      printf("Arguments: ./makecal rawfile.root output.root\n");
      printf("output filename is optional\n");
      return 0;
  }
  
  if(argc>1){  // 1st argument is input file
    ifname = argv[1];
  }
  
  if(argc>2){ //output filename provided
    ofname = argv[2];
  }
  else{ // create some default name
    ofname = ifname; 
    ofprefix = outputdir; //set the output directory in front of output filename 
    ofname.ReplaceAll(rawfileprefix,calfileprefix); // change raw_ to cal_
    ofname.Replace(0,ofname.Last('/')+1,ofprefix.Data()); //strip of possible input file directory part
  }
  
  cout<<"input file = \033[1;32m"<<ifname<<"\033[0m"<<endl;
  cout<<"output file = \033[1;32m"<<ofname<<"\033[0m"<<endl;
  
  // load raw root tree
  TFile *file0 = TFile::Open(ifname);
  TTree *rawtree = (TTree*)file0->Get("tree");
  Int_t num;
  num = rawtree->GetEntries();  
  cout << "Total event = " << num << endl;
  rawdata raw; // structure to store raw event variables
  raw.set_branch_addresses(rawtree); // set addreses to point to rawdata structure variables
  
  TFile *file1 = new TFile(ofname,"RECREATE");
  TTree *tree = new TTree("tree","tree");
  caldata cal;
  cal.set_branches(tree);
  
  // detector setup
  IC f3ic(6,raw.IC3Raw); //6 anodes, pointer to the data array
  IC f5ic(5,raw.IC5Raw);
  IC f7ic(6,raw.IC7Raw);
  IC music1(8,raw.GSIICERaw[0],raw.GSI1290Raw[0]);
  IC music2(8,raw.GSIICERaw[1],raw.GSI1290Raw[8]);
  
  // set ADC thresholds
  f3ic.threshold(50);
  f5ic.threshold(50);
  f7ic.threshold(50);
  music1.threshold(50);
  music2.threshold(50);
  
  //Plastics pl3(3,raw.PL3_QRaw);
  //Plastics pl5(5,raw.PL5_QRaw);
  //Plastics pl7(7,raw.PL7_QRaw);
  //Plastics pl11(11,raw.PL11_QRaw);
  Plastics pl11long(0,raw.PL11long_QRaw);
  pl11long.set_mtdc_data(raw.PL11long_MTRaw[0],raw.PL11long_MTRaw[1],&raw.PL11_MHit[0],&raw.PL11_MHit[1],&raw.tV1290);
  
  Plastics pl3(F3,raw);
  Plastics pl5(F5,raw);
  Plastics pl7(F7,raw);
  Plastics pl11(F11,raw);
  
 
  pl3.set_qdc_threshold(50);
  pl5.set_qdc_threshold(50);
  pl7.set_qdc_threshold(50);
  pl11.set_qdc_threshold(50);
  pl11long.set_qdc_threshold(50);
  
  pl3.set_tdc_threshold(1);
  pl5.set_tdc_threshold(1);
  pl7.set_tdc_threshold(1);
  pl11.set_tdc_threshold(1);
  pl11long.set_tdc_threshold(1);
  
  PPAC ppac3(3,raw.PPAC3_QRaw,raw.PPAC3_TRaw,raw.PPAC3_AQRaw,raw.PPAC3_ATRaw);
  PPAC ppac5(5,raw.PPAC5_QRaw,raw.PPAC5_TRaw,raw.PPAC5_AQRaw,raw.PPAC5_ATRaw);
  PPAC ppac7(7,raw.PPAC7_QRaw,raw.PPAC7_TRaw,raw.PPAC7_AQRaw,raw.PPAC7_ATRaw);
  PPAC ppac11(11,raw.PPAC11_QRaw,raw.PPAC11_TRaw,raw.PPAC11_AQRaw,raw.PPAC11_ATRaw);
  
  ppac3.overflow = 570;
  ppac5.overflow = 570;
  ppac7.overflow = 570;
  ppac11.overflow = 570;
  
  PID id_35(F3,F5);
  id_35.set_matrix(parameters::Mat35);
  id_35.set_tof(&cal.TOF35);
  id_35.set_positions(&cal.F3X,&cal.F3Y,&cal.F5X,&cal.F5Y);
  id_35.set_angles(&cal.F3A,&cal.F3B,&cal.F5A,&cal.F5B);
  id_35.set_dipoles(raw.Dipole);
  
  PID id_57(F5,F7);
  id_57.set_matrix(parameters::Mat57);
  id_57.set_tof(&cal.TOF57);
  id_57.set_positions(&cal.F5X,&cal.F5Y,&cal.F7X,&cal.F7Y);
  id_57.set_angles(&cal.F5A,&cal.F5B,&cal.F7A,&cal.F7B);
  id_57.set_dipoles(raw.Dipole);
  
  
  
  // here copy some variables from raw to cal 
  // this will points to raw variables data so the data does not neet to be copied
  tree->Branch("Nevent",&raw.Nevent,"Nevent/I");
  tree->Branch("Dipole",raw.Dipole,"Dipole[9]/D");
  tree->Branch("PL3_MHit",raw.PL3_MHit,"PL3_MHit[2]/I");
  tree->Branch("PL5_MHit",raw.PL5_MHit,"PL5_MHit[2]/I");
  tree->Branch("PL7_MHit",raw.PL7_MHit,"PL7_MHit[2]/I");
  tree->Branch("PL11_MHit",raw.PL11_MHit,"PL11_MHit[2]/I");
  tree->Branch("PL11long_MHit",raw.PL11long_MHit,"PL11long_MHit[2]/I");
  
  #ifdef IC_RAW
  tree->Branch("GSIICERaw",raw.GSIICERaw,"GSIICERaw[2][8]/I");
  tree->Branch("IC3Raw",raw.IC3Raw,"IC3Raw[6]/I");
  tree->Branch("IC5Raw",raw.IC5Raw,"IC5Raw[5]/I");
  tree->Branch("IC7Raw",raw.IC7Raw,"IC7Raw[6]/I");
  #endif
  
  #ifdef PPAC_DETAILS
  tree->Branch("PPAC3_posx",ppac3.posx,"PPAC3_posx[4]/D");
  tree->Branch("PPAC5_posx",ppac5.posx,"PPAC5_posx[4]/D");
  tree->Branch("PPAC7_posx",ppac7.posx,"PPAC7_posx[4]/D");
  tree->Branch("PPAC11_posx",ppac11.posx,"PPAC11_posx[4]/D");
  tree->Branch("PPAC3_tsumx",ppac3.tsumx,"PPAC3_tsumx[4]/D");
  tree->Branch("PPAC3_tsumy",ppac3.tsumy,"PPAC3_tsumy[4]/D");  
  tree->Branch("PPAC5_tsumx",ppac5.tsumx,"PPAC5_tsumx[4]/D");
  tree->Branch("PPAC5_tsumy",ppac5.tsumy,"PPAC5_tsumy[4]/D");
  tree->Branch("PPAC7_tsumx",ppac7.tsumx,"PPAC7_tsumx[4]/D");
  tree->Branch("PPAC7_tsumy",ppac7.tsumy,"PPAC7_tsumy[4]/D");  
  tree->Branch("PPAC11_tsumx",ppac11.tsumx,"PPAC11_tsumx[4]/D");
  tree->Branch("PPAC11_tsumy",ppac11.tsumy,"PPAC11_tsumy[4]/D");
  #endif
  
  #ifdef PLASTICS_DETAILS
  tree->Branch("PL3_tdif",&pl3.t_dif,"PL3_tdif/D");
  tree->Branch("PL5_tdif",&pl5.t_dif,"PL5_tdif/D");
  tree->Branch("PL7_tdif",&pl7.t_dif,"PL7_tdif/D");
  tree->Branch("PL3_mtdif",&pl3.mt_dif,"PL3_mtdif/D");
  tree->Branch("PL5_mtdif",&pl5.mt_dif,"PL5_mtdif/D");
  tree->Branch("PL7_mtdif",&pl7.mt_dif,"PL7_mtdif/D");
  #endif
  
  #ifdef PPAC_TRACKS
  Track ppac_pl3x;
  tree->Branch("PPAC_PL3X",&ppac_pl3x.val,"PPAC_PL3X/D");
  Track ppac_pl5x;
  tree->Branch("PPAC_PL5X",&ppac_pl5x.val,"PPAC_PL5X/D");
  Track ppac_pl7x;
  tree->Branch("PPAC_PL7X",&ppac_pl7x.val,"PPAC_PL7X/D");
  Track ppac_pl11x;
  tree->Branch("PPAC_PL11X",&ppac_pl11x.val,"PPAC_PL11X/D");
  #endif

  //Event Loop
  Long64_t iEntry = 0;
  for(iEntry=0;iEntry<num;iEntry++){
    if(iEntry%1000==0)cout << 100*iEntry/num <<" % "<< flush << "\r";
    cal.clear_variables();
    rawtree->GetEntry(iEntry);

    f3ic.calculate();    
    f5ic.calculate();
    f7ic.calculate();
    music1.calculate();
    music2.calculate();
    pl3.calculate();
    pl5.calculate();
    pl7.calculate();
    pl11.calculate();
    pl11long.calculate();
    ppac3.calculate();
    ppac5.calculate();
    ppac7.calculate();
    ppac11.calculate();
    
    cal.F3PLQ_X = pl3.xq;
    cal.F5PLQ_X = pl5.xq;
    cal.F7PLQ_X = pl7.xq;
    cal.F11PLQ_X = pl11.xq;
    cal.F11longPLQ_X = pl11long.xq;
    
    cal.F3X = ppac3.x;
    cal.F3Y = ppac3.y;
    cal.F3A = ppac3.a;
    cal.F3B = ppac3.b;
    
    cal.F5X = ppac5.x;
    cal.F5Y = ppac5.y;
    cal.F5A = ppac5.a;
    cal.F5B = ppac5.b;
    
    cal.F7X = ppac7.x;
    cal.F7Y = ppac7.y;
    cal.F7A = ppac7.a;
    cal.F7B = ppac7.b;
    
    cal.F11X = ppac11.x;
    cal.F11Y = ppac11.y;
    cal.F11A = ppac11.a;
    cal.F11B = ppac11.b;
    
    #ifdef PPAC_TRACKS
    ppac_pl3x(ppac3.x,ppac3.a,parameters::distance_PL3_focus);
    ppac_pl5x(ppac5.x,ppac5.a,parameters::distance_PL5_focus);
    ppac_pl7x(ppac7.x,ppac7.a,parameters::distance_PL7_focus);
    ppac_pl11x(ppac11.x,ppac11.a,parameters::distance_PL11_focus);
    #endif
    
    cal.TOF35 = tof(pl3,pl5,LE);
    cal.TOF57 = tof(pl5,pl7,LE);
    cal.TOF711 = tof(pl7,pl11,LE);
    
    
    id_35.calculate();
    cal.Beta35 = id_35.beta;
    cal.AoQ35 = id_35.aoq+0.03;
    cal.Delta35 = id_35.delta;
    cal.Brho35 = id_35.brho;
    
    id_57.calculate();
    cal.Beta57 = id_57.beta;
    cal.AoQ57 = id_57.aoq;
    cal.Delta57 = id_57.delta;
    cal.Brho57 = id_57.delta;
    
    
    cal.F3ICGas = raw.IC_GasRaw[3];
    cal.F3ICSum = f3ic.sum;
    cal.F5ICSum = f5ic.sum;
    cal.F7ICSum = f7ic.sum;
    cal.MUSIC1Sum = music1.sum;
    cal.MUSIC2Sum = music2.sum;
    
    cal.F3ICMean = f3ic.mean;
    cal.F5ICMean = f5ic.mean;
    cal.F7ICMean = f7ic.mean;
    cal.MUSIC1Mean = music1.mean;
    cal.MUSIC2Mean = music2.mean;
    
    cal.F3ICGMean = f3ic.gmean;
    cal.F5ICGMean = f5ic.gmean;
    cal.F7ICGMean = f7ic.gmean;
    cal.MUSIC1GMean = music1.gmean;
    cal.MUSIC2GMean = music2.gmean;
    
    cal.Z3 = TMath::Sqrt(cal.F3ICMean*cal.Beta35*cal.Beta35);
    cal.Z5 = TMath::Sqrt(cal.F5ICMean*cal.Beta57*cal.Beta57);
    cal.Z7 = TMath::Sqrt(cal.F7ICMean*cal.Beta57*cal.Beta57);
    cal.Z11 = TMath::Sqrt(cal.MUSIC1Mean*cal.Beta711*cal.Beta711);
    
    tree->Fill();
     
  }

  file1->Write(); 
  file0->Close();
  file1->Close();
}

