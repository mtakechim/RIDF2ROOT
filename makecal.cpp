/* M. Takechi Dec. 2016
 * A. Prochazka feb 2017
 * 
*/

// config
#define PLASTICS_DETAILS 1
#define PPAC_DETAILS 1  // output ppac sums and partial positions
#define IC_RAW 1  // output IC Raw data
#define IC_ANODES_NORMALIZATION
#define PPAC_TRACKS 1
#define ID_DETAILS 1

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
  
  ///////////// detector setup
  
  // ICs
  IC f3ic(6,raw.IC3Raw); //6 anodes, pointer to the data array
  IC f5ic(5,raw.IC5Raw);
  IC f7ic(6,raw.IC7Raw);
  
  IC music1(8,raw.GSIICERaw[0],&(raw.GSI1290Raw[0][0]),&cal.F11_reftime);
  IC music2(8,raw.GSIICERaw[1],&(raw.GSI1290Raw[8][0]),&cal.F11_reftime);
  music1.set_nhits(&raw.GSIMHit[0]);
  music2.set_nhits(&raw.GSIMHit[8]);
  music1.set_time_calibration(-0.04,0);
  music2.set_time_calibration(-0.04,0);
  
  // set ADC thresholds
  f3ic.threshold(100);
  f5ic.threshold(100);
  f7ic.threshold(100);
  music1.threshold(100);
  music2.threshold(100);
  
  // Plastics
  Plastics pl11long(1,raw.PL11long_QRaw);
  pl11long.set_mtdc_data(raw.PL11long_MTRaw[0],raw.PL11long_MTRaw[1],&raw.PL11_MHit[0],&raw.PL11_MHit[1],&raw.tV1290);
  Plastics pl3(F3,raw);
  Plastics pl5(F5,raw);
  Plastics pl7(F7,raw);
  Plastics pl11(F11,raw);
  Plastics pl11b(F11B,raw);
   
  pl3.set_qdc_threshold(50);
  pl5.set_qdc_threshold(50);
  pl7.set_qdc_threshold(50);
  pl11.set_qdc_threshold(50);
  pl11b.set_qdc_threshold(50);
  pl11long.set_qdc_threshold(50);
  
  pl3.set_tdc_threshold(1);
  pl5.set_tdc_threshold(1);
  pl7.set_tdc_threshold(1);
  pl11.set_tdc_threshold(1);
  pl11b.set_tdc_threshold(1);
  pl11long.set_tdc_threshold(1);
  
  // PPACs
  PPAC ppac3(3,raw.PPAC3_QRaw,raw.PPAC3_TRaw,raw.PPAC3_AQRaw,raw.PPAC3_ATRaw);
  PPAC ppac5(5,raw.PPAC5_QRaw,raw.PPAC5_TRaw,raw.PPAC5_AQRaw,raw.PPAC5_ATRaw);
  PPAC ppac7(7,raw.PPAC7_QRaw,raw.PPAC7_TRaw,raw.PPAC7_AQRaw,raw.PPAC7_ATRaw);
  PPAC ppac9(9,raw.PPAC9_QRaw,raw.PPAC9_TRaw,raw.PPAC9_AQRaw,raw.PPAC9_ATRaw);
  PPAC ppac11(11,raw.PPAC11_QRaw,raw.PPAC11_TRaw,raw.PPAC11_AQRaw,raw.PPAC11_ATRaw);
  
  // IDs
  PID id_35(F3,F5);
  id_35.set_matrix(parameters::Mat35);
  id_35.set_tof(&cal.TOF35);
  id_35.set_positions(&cal.X3,&cal.F3Y,&cal.X5,&cal.F5Y);
  id_35.set_angles(&cal.F3A,&cal.F3B,&cal.F5A,&cal.F5B);
  id_35.set_dipoles(raw.Dipole);
  
  PID id_57(F5,F7);
  id_57.set_matrix(parameters::Mat57);
  id_57.set_tof(&cal.TOF57);
  id_57.set_positions(&cal.F5X,&cal.F5Y,&cal.F7X,&cal.F7Y);
  id_57.set_angles(&cal.F5A,&cal.F5B,&cal.F7A,&cal.F7B);
  id_57.set_dipoles(raw.Dipole);
  
  PID id_37a(F3,F7);
  id_37a.set_pid_type(F35); // define from where to take reference Brho
  id_37a.set_focalplane_type(focal_planes_t::achromatic_dispersive);
  id_37a.set_matrix(parameters::Mat35);
  id_37a.set_tof(&cal.TOF37);
  id_37a.set_positions(&cal.F3X,&cal.F3Y,&cal.F5X,&cal.F5Y);
  id_37a.set_angles(&cal.F3A,&cal.F3B,&cal.F5A,&cal.F5B);
  id_37a.set_dipoles(raw.Dipole);
  PID id_37b(F3,F7);
  id_37b.set_pid_type(F57); // define from where to take reference Brho
  id_37b.set_focalplane_type(focal_planes_t::dispersive_achromatic);
  id_37b.set_matrix(parameters::Mat57);
  id_37b.set_tof(&cal.TOF37);
  id_37b.set_positions(&cal.F5X,&cal.F5Y,&cal.F7X,&cal.F7Y);
  id_37b.set_angles(&cal.F5A,&cal.F5B,&cal.F7A,&cal.F7B);
  id_37b.set_dipoles(raw.Dipole);
  
  
  PID id_79(F7,F9);
  id_79.set_matrix(parameters::Mat79);
  id_79.set_tof(&cal.TOF711m);
  id_79.set_tof_distance(parameters::TOFDistance[F11] - parameters::TOFDistance[F7]);
  id_79.set_positions(&cal.F7X,&cal.F7Y,&cal.F9X,&cal.F9Y);
  id_79.set_angles(&cal.F7A,&cal.F7B,&cal.F9A,&cal.F9B);
  id_79.set_dipoles(raw.Dipole);
  
  PID id_911(F9,F11);
  id_911.set_matrix(parameters::Mat911);
  id_911.set_tof(&cal.TOF711m);
  id_911.set_tof_distance(parameters::TOFDistance[F11] - parameters::TOFDistance[F7]);
  id_911.set_positions(&cal.F9X,&cal.F9Y,&cal.F11X,&cal.F11Y);
  id_911.set_angles(&cal.F9A,&cal.F9B,&cal.F11A,&cal.F11B);
  id_911.set_dipoles(raw.Dipole);
  
  PID id_711(F7,F11);
  id_711.set_matrix(parameters::Mat911);
  id_711.set_tof(&cal.TOF711m);
  id_711.set_positions(&cal.F9X,&cal.F9Y,&cal.F11X,&cal.F11Y);
  id_711.set_angles(&cal.F9A,&cal.F9B,&cal.F11A,&cal.F11B);
  id_711.set_dipoles(raw.Dipole);
  
  
  // here copy some variables from raw to cal 
  // this will points to raw variables data so the data does not neet to be copied
  tree->Branch("Nevent",&raw.Nevent,"Nevent/I");
  tree->Branch("Dipole",raw.Dipole,"Dipole[9]/D");
  tree->Branch("PL3_MHit",raw.PL3_MHit,"PL3_MHit[2]/I");
  tree->Branch("PL5_MHit",raw.PL5_MHit,"PL5_MHit[2]/I");
  tree->Branch("PL7_MHit",raw.PL7_MHit,"PL7_MHit[2]/I");
  tree->Branch("PL11_MHit",raw.PL11_MHit,"PL11_MHit[4]/I");
  tree->Branch("PL11long_MHit",raw.PL11long_MHit,"PL11long_MHit[2]/I");
  
  #ifdef IC_RAW
  tree->Branch("MUSIC1Raw",raw.GSIICERaw[0],"MUSIC1Raw[8]/I");
  tree->Branch("MUSIC2Raw",raw.GSIICERaw[1],"MUSIC2Raw[8]/I");
  tree->Branch("IC3Raw",raw.IC3Raw,"IC3Raw[6]/I");
  tree->Branch("IC5Raw",raw.IC5Raw,"IC5Raw[5]/I");
  tree->Branch("IC7Raw",raw.IC7Raw,"IC7Raw[6]/I");
  #endif
  tree->Branch("F3IC_nanodes",&f3ic.fired,"F3IC_nanodes/I");
  tree->Branch("F5IC_nanodes",&f5ic.fired,"F5IC_nanodes/I");
  tree->Branch("F7IC_nanodes",&f7ic.fired,"F7IC_nanodes/I");
  tree->Branch("MUSIC1_nanodes",&music1.fired,"MUSIC1_nanodes/I");
  tree->Branch("MUSIC2_nanodes",&music2.fired,"MUSIC2_nanodes/I");
  
  
  #ifdef PPAC_DETAILS
  ppac3.set_branches(tree,"PPAC3");
  ppac5.set_branches(tree,"PPAC5");
  ppac7.set_branches(tree,"PPAC7");
  ppac9.set_branches(tree,"PPAC9");
  ppac11.set_branches(tree,"PPAC11");
  
  #endif
  
  #ifdef PLASTICS_DETAILS  
  pl3.set_branches(tree,"PL3");
  pl5.set_branches(tree,"PL5");
  pl7.set_branches(tree,"PL7");
  pl11.set_branches(tree,"PL11");
  pl11b.set_branches(tree,"PL11B");
  #endif
  
  #ifdef ID_DETAILS
  tree->Branch("Beta37a",&id_37a.beta,"Beta37a/D");
  tree->Branch("Beta37b",&id_37b.beta,"Beta37b/D");
  
  tree->Branch("Delta37a",&id_37a.delta,"Delta37a/D");
  tree->Branch("Delta37b",&id_37b.delta,"Delta37b/D");
  
  tree->Branch("AoQ37a",&id_37a.aoq,"AoQ37a/D");
  tree->Branch("AoQ37b",&id_37b.aoq,"AoQ37b/D");
  
  
  tree->Branch("Brho79",&id_79.brho,"Brho79/D");
  tree->Branch("Brho911",&id_911.brho,"Brho911/D");
  
  tree->Branch("AoQ79",&id_79.aoq,"AoQ79/D");
  tree->Branch("AoQ911",&id_911.aoq,"AoQ911/D");
  
  tree->Branch("Beta79",&id_79.beta,"Beta79/D");
  tree->Branch("Beta911",&id_911.beta,"Beta911/D");
  
  tree->Branch("Gamma79",&id_79.gamma,"Gamma79/D");
  tree->Branch("Gamma911",&id_911.gamma,"Gamma911/D");
  
  #endif
  
  // Additional tracking
  #ifdef PPAC_TRACKS
  Track ppac_pl3x;
  tree->Branch("PPAC_PL3X",&ppac_pl3x.val,"PPAC_PL3X/D");
  Track ppac_pl5x;
  tree->Branch("PPAC_PL5X",&ppac_pl5x.val,"PPAC_PL5X/D");
  Track ppac_pl7x;
  tree->Branch("PPAC_PL7X",&ppac_pl7x.val,"PPAC_PL7X/D");
  Track ppac_pl11x;
  tree->Branch("PPAC_PL11X",&ppac_pl11x.val,"PPAC_PL11X/D");
  
  Track ppac_f11tx;
  Track ppac_f11ty;
  tree->Branch("PPAC_F11tx",&ppac_f11tx.val,"PPAC_F11tx/D");
  tree->Branch("PPAC_F11ty",&ppac_f11ty.val,"PPAC_F11ty/D");
  
  #endif
  

  //Event Loop
  Long64_t iEntry = 0;
  for(iEntry=0;iEntry<num;iEntry++){
    if(iEntry%1000==0)cout << 100*iEntry/num <<" % "<< flush << "\r";
    cal.clear_variables();
    rawtree->GetEntry(iEntry);
  
  // IC anodes normalization
  #ifdef IC_ANODES_NORMALIZATION
    for(int i=0;i<6;i++){
        raw.IC3Raw[i] *=parameters::F3IC_anodes_norms[i];
    }
    
    for(int i=0;i<5;i++){
        raw.IC5Raw[i] *=parameters::F5IC_anodes_norms[i];
    }
    /*
    for(int i=0;i<6;i++){
        raw.IC7Raw[i] *=parameters::F7IC_anodes_norms[i];
    }
    */ 
    
    for(int i=0;i<8;i++){
        raw.GSIICERaw[0][i] *=parameters::MUSIC1_anodes_norms[i];
    }
  #endif

    
    pl3.calculate();
    pl5.calculate();
    pl7.calculate();
    pl11.calculate();
    pl11b.calculate();
    pl11long.calculate();
    
    f3ic.calculate();    
    f5ic.calculate();
    f7ic.calculate();
    music1.calculate();
    music2.calculate();
    
    ppac3.calculate();
    ppac5.calculate();
    ppac7.calculate();
    ppac9.calculate();
    ppac11.calculate();
    
    cal.F3PLQ_X = pl3.xq;
    cal.F5PLQ_X = pl5.xq;
    cal.F7PLQ_X = pl7.xq;
    cal.F11PLQ_X = pl11.xq;
    cal.F11BPLQ_X = pl11b.xq;
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
    
    cal.F9X = ppac9.x;
    cal.F9Y = ppac9.y;
    cal.F9A = ppac9.a;
    cal.F9B = ppac9.b;
    
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
    ppac_f11tx(ppac11.x,ppac11.a,parameters::distance_F11target_focus);
    ppac_f11ty(ppac11.y,ppac11.b,parameters::distance_F11target_focus);
    
    cal.MUSIC1_pos = music1.meanpos;
    cal.MUSIC2_pos = music2.meanpos;
    
    cal.TOF35 = tof(pl3,pl5,LE);
    cal.TOF57 = tof(pl5,pl7,LE);
    cal.TOF37 = cal.TOF35 + cal.TOF57;
    cal.TOF711 = tof(pl7,pl11,LE);
    
    cal.TOF711a = tof(pl7,pl11,V1290);
    cal.TOF711b = tof(pl7,pl11b,V1290);
    cal.TOF711m = average(cal.TOF711a,cal.TOF711b,100,1000);
    
    cal.F11_reftime = 0.025*average(average(raw.GSI1290Raw[16][0],raw.GSI1290Raw[17][0],1400000,9999000),average(raw.GSI1290Raw[18][0],raw.GSI1290Raw[19][0],1400000,9999000),1400000,9999000);
    
    
    //cal.X3 = average(ppac3.x1,pl3.xq,-100,100);
    cal.X3 = choose(-100,100,cal.F3X,pl3.xq);
    //cal.X3 = pl3.xq;
    //cal.X3 = cal.F3X;
        
    //cal.X5 = average(cal.F5X,pl5.xq,-100,100);
    cal.X5 = choose(-100,100,cal.F5X,pl5.xq);
    //cal.X5 = pl5.xq;
    //cal.X5 =cal. F5X;
    
    cal.X7 = choose(-100,100,cal.F7X,pl7.xq);
    cal.X11 = choose(-100,100,cal.F11X,pl11.x_mtdif);
    
    
    id_35.calculate();
    cal.Beta35 = id_35.beta;
    cal.AoQ35 = id_35.aoq+0.03;
    cal.Delta35 = id_35.delta;
    cal.Brho35 = id_35.brho;
    
    id_57.calculate();
    cal.Beta57 = id_57.beta;
    cal.AoQ57 = id_57.aoq+0.02;
    cal.Delta57 = id_57.delta;
    cal.Brho57 = id_57.brho;
    
    id_37a.calculate();
    id_37b.calculate();
    //cal.Beta37 = average(id_37a.beta,id_37b.beta,0.3,1);
    cal.Beta37 = average(id_35.beta,id_57.beta,0.3,1);
    //cal.AoQ37 = average(id_37a.aoq,id_37b.aoq,1.5,3);
    cal.AoQ37 = average(cal.AoQ35,cal.AoQ57,1.5,3);
    
    id_79.calculate();
    id_911.calculate();
    cal.Delta79 = id_79.delta;
    cal.Delta911 = id_911.delta;
    cal.Beta711 = average(id_79.beta,id_911.beta,0.3,1);
    //cal.AoQ711 = average(id_79.aoq,id_911.aoq,1.5,3);
    cal.AoQ711 = id_911.aoq+0.02;
    
    id_711.calculate();
    cal.Beta711 = id_711.beta;
    cal.Beta711m = id_711.beta;
    cal.AoQ711 = id_711.aoq;
    cal.Delta711 = id_711.delta;
    cal.Brho711 = id_711.brho;
    
    
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
    
    cal.F3ICde = f3ic.mean*cal.Beta35*cal.Beta35;
    cal.F5ICde = f5ic.mean*cal.Beta57*cal.Beta57;
    cal.F7ICde = f7ic.mean*cal.Beta57*cal.Beta57;
    cal.MUSIC1de = music1.mean*cal.Beta711*cal.Beta711;
    cal.MUSIC2de = music2.mean*cal.Beta711*cal.Beta711;
    
    // angular correction
    if(cal.F3B>-200){
      cal.F3ICde *=(1-0.0002*cal.F3B);
      }
    
    cal.Z3 = TMath::Sqrt(parameters::Z_de[0][1]*cal.F3ICde)+parameters::Z_de[0][0];
    cal.Z5 = TMath::Sqrt(parameters::Z_de[1][1]*cal.F5ICde)+parameters::Z_de[1][0];
    cal.Z7 = TMath::Sqrt(parameters::Z_de[2][1]*cal.F7ICde)+parameters::Z_de[2][0];
    cal.Z11 = TMath::Sqrt(parameters::Z_de[3][1]*cal.MUSIC1de)+parameters::Z_de[3][0];
    cal.Z11at = TMath::Sqrt(parameters::Z_de[4][1]*cal.MUSIC2de)+parameters::Z_de[4][0];
    
    tree->Fill();
     
  }

  file1->Write(); 
  file0->Close();
  file1->Close();
}

