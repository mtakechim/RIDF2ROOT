/* M. Takechi Dec. 2016
 * A. Prochazka feb 2017
 * 
 * last modification 13.2.2017
*/

// config
#define PPAC_DETAILS 1  // output ppac sums and partial positions
//#define IC_RAW 1  // output IC Raw data

#include "makecal.h"
#include "ribf123_rawvar.h"
#include "caldata.h"
#include "ic.h"
#include "plastics.h"
#include "ppac.h"
#include "pid.h"
using namespace std;

int main(int argc, char* argv[]){
  const char* outputdir = "./";
  const char* rawfileprefix = "raw_";
  const char* calfileprefix = "cal_";
  
  int run;
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
  
  RIBF123ReadAndCalcRAW rawdataold;
  //Define New Branches
  //DefineNewBranches(tree);
  //To Read Raw ROOT File
  rawdataold.SetTree(rawtree);
  
   

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
    
    
    cal.F3ICSum = f3ic.sum;
    cal.F3ICGas = raw.IC_GasRaw[3];
    cal.F5ICSum = f5ic.sum;
    cal.F7ICSum = f7ic.sum;
    cal.MUSIC1Sum = music1.sum;
    cal.MUSIC2Sum = music2.sum;
    
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
    
    cal.Z3 = cal.F3ICMean*cal.Beta35*cal.Beta35;
    cal.Z5 = cal.F5ICMean*cal.Beta57*cal.Beta57;
    cal.Z7 = cal.F7ICMean*cal.Beta57*cal.Beta57;
    cal.Z11 = cal.MUSIC1Mean*cal.Beta711*cal.Beta711;
    
    
    
    
    /// old part
    Entry = iEntry;
    rawdataold.SetEntry(iEntry);
    //F3 Data
    for (int i = 0, maxi=rawdataold.PL3_QRaw.GetSize(); i < maxi; ++i) {
      PL3_QRaw[i]=rawdataold.PL3_QRaw[i];
    }
    for (int i = 0, maxi=rawdataold.PL3_MHit.GetSize(); i < maxi; ++i) {
      PL3_MHit[i]=rawdataold.PL3_MHit[i];
    }

    for (int i = 0, maxi=rawdataold.IC3Raw.GetSize(); i < maxi; ++i) {
      F3IC[i]=rawdataold.IC3Raw[i];
    }
    F3ICSum=rawdataold.GetICESum(3);
    F3ICGas = rawdataold.GetIC_GasRaw(rawdataold.F3);

    rawdataold.SetPPACTrack(3);

    F3X=rawdataold.GetFocusPointX_mm(3);
    F3Y=rawdataold.GetFocusPointY_mm(3);
    F3A=rawdataold.GetFocusPointA_mrad(3);
    F3B=rawdataold.GetFocusPointB_mrad(3);
    F7TSumX=rawdataold.GetTSumX(3);

    /*	  F3TSumY=rawdataold.GetTSumY(3);*/


    //F5 Data

    for (int i = 0, maxi=rawdataold.PL5_QRaw.GetSize(); i < maxi; ++i) {
      PL5_QRaw[i]=rawdataold.PL5_QRaw[i];
    }
    for (int i = 0, maxi=rawdataold.PL5_MHit.GetSize(); i < maxi; ++i) {
      PL5_MHit[i]=rawdataold.PL5_MHit[i];
    }
    for (int i = 0, maxi=rawdataold.IC5Raw.GetSize(); i < maxi; ++i) {
      F5IC[i]=rawdataold.IC5Raw[i];
    }
    F5ICSum=rawdataold.GetICESum(5);

    rawdataold.SetPPACTrack(5);

    F5X=rawdataold.GetFocusPointX_mm(5);
    F5Y=rawdataold.GetFocusPointY_mm(5);
    F5A=rawdataold.GetFocusPointA_mrad(5);
    F5B=rawdataold.GetFocusPointB_mrad(5);

    F5PLQ_X = rawdataold.GetPLQX(5);






    
    //F7 Data
    for (int i = 0, maxi=rawdataold.PL7_QRaw.GetSize(); i < maxi; ++i) {
      PL7_QRaw[i]=rawdataold.PL7_QRaw[i];
    }
    for (int i = 0, maxi=rawdataold.PL7_MHit.GetSize(); i < maxi; ++i) {
      PL7_MHit[i]=rawdataold.PL7_MHit[i];
    }
    for (int i = 0, maxi=rawdataold.IC7Raw.GetSize(); i < maxi; ++i) {
      F7IC[i]=rawdataold.IC7Raw[i];
    }

    F7ICSum=rawdataold.GetICESum(7);
    rawdataold.SetPPACTrack(7);
    F7X=rawdataold.GetFocusPointX_mm(7);
    F7Y=rawdataold.GetFocusPointY_mm(7);
    F7A=rawdataold.GetFocusPointA_mrad(7);
    F7B=rawdataold.GetFocusPointB_mrad(7);



    



    //F9 Data

    rawdataold.SetPPACTrack(9);
    F9X=rawdataold.GetFocusPointX_mm(9);
    F9Y=rawdataold.GetFocusPointY_mm(9);
    F9A=rawdataold.GetFocusPointA_mrad(9);
    F9B=rawdataold.GetFocusPointB_mrad(9);






    //F11 Data
    for (int i = 0, maxi=rawdataold.PL11_QRaw.GetSize(); i < maxi; ++i) {
      PL11_QRaw[i]=rawdataold.PL11_TRaw[i];
    }
    for (int i = 0, maxi=rawdataold.PL11_MHit.GetSize(); i < maxi; ++i) {
      PL11_MHit[i]=rawdataold.PL11_MHit[i];
    }
    for (int i = 0, maxi=rawdataold.GSIICERaw.GetSize(); i < maxi; ++i) {
      if(i/8==0){
      MUSIC1[i]=rawdataold.GSIICERaw[i];
      }
      else if(i/8==1){
      MUSIC2[i-8]=rawdataold.GSIICERaw[i-8];
      }
    }
    
    MUSIC1Sum=rawdataold.GetICESum(11);
    MUSIC2Sum=rawdataold.GetIC2ESum(11);

    rawdataold.SetPPACTrack(11);
    F11X=rawdataold.GetFocusPointX_mm(11);
    F11Y=rawdataold.GetFocusPointY_mm(11);
    F11A=rawdataold.GetFocusPointA_mrad(11);
    F11B=rawdataold.GetFocusPointB_mrad(11);


    //TOF
    TOF35 = rawdataold.GetLeadingEdgeTOF(3,5);
    TOF57 = rawdataold.GetLeadingEdgeTOF(5,7);
    TOF711 = rawdataold.GetLeadingEdgeTOF(0,11);

    //    cout<<F3X<<endl;


    //PID
    RIBF123PID pid;
    pid.SetDataForAoQ(TOF35,rawdataold.Dipole[4],F3X,F5PLQ_X,F3A,3,5,3,5);
    AoQ35 = pid.GetAoQ(3,5);
    Delta35 = pid.GetDelta(3,5);

    pid.SetDataForZ(TOF35, 3, 5, 3, 5, F3X, F5PLQ_X, F3A, 3, F3ICSum, 1, F3B);
    Z3 = pid.GetZ(3);
    Beta35 = pid.GetBeta(3,5);
    

    
    /*
    if(AoQ35>1&&AoQ35<3){ // this is bad, it will not preserve correspondence to raw files
      tree->Fill();       // its better to preset variables with dummy values to know whent to draw or analyze 
    }
    */
    
    //    std::cout<<Posx[0]<<std::endl;
    tree->Fill();
     
  }

  file1->Write(); 
  file0->Close();
  file1->Close();
}

