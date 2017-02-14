#ifndef makecal_h
#define makecal_h

//Defining New Branches
#include "TTree.h"
#include "TFile.h"

#include <signal.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <TTreeReader.h>

#include "TSystem.h"
#include "TString.h"
#include "TMath.h"
#include "TMatrix.h"
#include "TRandom.h"

#include "./include/RIBF123ReadAndCalcRAW.h"
#include "./include/RIBF123PID.h"

Int_t Entry;


Double_t F3ICSum;
Int_t F3IC[6];
Double_t F3ICGas;
Double_t F5ICSum;
Int_t F5IC[5];
Double_t F7ICSum;
Int_t F7IC[6];
Double_t MUSIC1Sum;
Int_t MUSIC1[8];
Double_t MUSIC2Sum;
Int_t MUSIC2[8];

Double_t F7TSumX;
Double_t F7TSumY;
Double_t posx[4];
Double_t F3X;
Double_t F5X;
Double_t F7X;
Double_t F9X;
Double_t F11X;
Double_t F3Y;
Double_t F5Y;
Double_t F7Y;
Double_t F9Y;
Double_t F11Y;
Double_t F3A;
Double_t F5A;
Double_t F7A;
Double_t F9A;
Double_t F11A;
Double_t F3B;
Double_t F5B;
Double_t F7B;
Double_t F9B;
Double_t F11B;

Double_t TOF35;
Double_t TOF57;
Double_t TOF711;

Double_t F5PLQ_X;

Double_t PL3_QRaw[2];
Double_t PL3_MHit[2];
Double_t PL5_QRaw[2];
Double_t PL5_MHit[2];
Double_t PL7_QRaw[2];
Double_t PL7_MHit[2];
Double_t PL11_QRaw[4];
Double_t PL11_MHit[4];

Double_t AoQ35;
Double_t Delta35;
Double_t Beta35;

Double_t Z3;

void DefineNewBranches(TTree *tree){
  

  tree->Branch("Entry",&Entry,"Entry/I");

  tree->Branch("F7TSumX",&F7TSumX,"F7TSumX/D");
  tree->Branch("posx[4]",posx,"posx[4]/D");

  tree->Branch("F3X",&F3X,"F3X/D");
  tree->Branch("F5X",&F5X,"F5X/D");
  tree->Branch("F7X",&F7X,"F7X/D");
  tree->Branch("F9X",&F9X,"F9X/D");
  tree->Branch("F11X",&F11X,"F11X/D");
  
  tree->Branch("F3Y",&F3Y,"F3Y/D");
  tree->Branch("F5Y",&F5Y,"F5Y/D");
  tree->Branch("F7Y",&F7Y,"F7Y/D");
  tree->Branch("F9Y",&F9Y,"F9Y/D");
  tree->Branch("F11Y",&F11Y,"F11Y/D");
  
  tree->Branch("F3A",&F3A,"F3A/D");
  tree->Branch("F5A",&F5A,"F5A/D");
  tree->Branch("F7A",&F7A,"F7A/D");
  tree->Branch("F9A",&F9A,"F9A/D");
  tree->Branch("F11A",&F11A,"F11A/D");
  
  tree->Branch("F3B",&F3B,"F3B/D");
  tree->Branch("F5B",&F5B,"F5B/D");
  tree->Branch("F7B",&F7B,"F7B/D");
  tree->Branch("F9B",&F9B,"F9B/D");
  tree->Branch("F11B",&F11B,"F11B/D");
  
  tree->Branch("F3ICSum",&F3ICSum,"F3ICSum/D");
  tree->Branch("F3ICGas",&F3ICGas,"F3ICGas/D");
  tree->Branch("F3IC[6]",F3IC,"F3IC[6]/I");

  tree->Branch("F5ICSum",&F5ICSum,"F5ICSum/D");
  tree->Branch("F5IC[5]",F5IC,"F5IC[5]/I");

  tree->Branch("F7ICSum",&F7ICSum,"F7ICSum/D");
  tree->Branch("F7IC[6]",F7IC,"F7IC[6]/I");

  tree->Branch("MUSIC1Sum",&MUSIC1Sum,"MUSIC1Sum/D");
  tree->Branch("MUSIC1[8]",MUSIC1,"MUSIC1[8]/I");

  tree->Branch("MUSIC2Sum",&MUSIC2Sum,"MUSIC2Sum/D");
  tree->Branch("MUSIC2[8]",MUSIC2,"MUSIC2[8]/I");

  tree->Branch("TOF35",&TOF35,"TOF35/D");
  tree->Branch("TOF57",&TOF57,"TOF57/D");
  tree->Branch("TOF711",&TOF711,"TOF711/D");

  tree->Branch("F5PLQ_X",&F5PLQ_X,"F5PLQ_X/D");

  tree->Branch("PL3_QRaw[2]",PL3_QRaw,"PL3_QRaw[2]/D");
  tree->Branch("PL3_MHit[2]",PL3_MHit,"PL3_MHit[2]/D");
  tree->Branch("PL5_QRaw[2]",PL5_QRaw,"PL5_QRaw[2]/D");
  tree->Branch("PL5_MHit[2]",PL5_MHit,"PL5_MHit[2]/D");
  tree->Branch("PL7_QRaw[2]",PL7_QRaw,"PL7_QRaw[2]/D");
  tree->Branch("PL7_MHit[2]",PL7_MHit,"PL7_MHit[2]/D");
  tree->Branch("PL11_QRaw[4]",PL11_QRaw,"PL11_QRaw[4]/D");
  tree->Branch("PL11_MHit[4]",PL11_MHit,"PL11_MHit[4]/D");
    
  tree->Branch("AoQ35",&AoQ35,"AoQ35/D");
  tree->Branch("Delta35",&Delta35,"Delta35/D");
 tree->Branch("Beta35",&Beta35,"Beta35/D");

 tree->Branch("Z3",&Z3,"Z3/D");



}
#endif
