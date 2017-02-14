//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Dec  9 10:03:57 2016 by ROOT version 6.08/00
// from TTree tree/tree
// found on file: run0214.root
//////////////////////////////////////////////////////////

#ifndef RIBF123ReadAndCalcRAW_h
#define RIBF123ReadAndCalcRAW_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>


// Headers needed by this particular selector

class RIBF123ReadAndCalcRAW {
//:public TSelector {
#ifndef RIBF123ReadAndCalcRAWpara_h
#include "RIBF123ReadAndCalcRAWpara.h"                                                                                                  
#endif
  
  int SumIC;
  Double_t aax[12];
  Double_t bbx[12];
  Double_t aay[12];
  Double_t bby[12];

  Double_t tsumx[12];
  Double_t tsumy[12];

  
 public :

  TTreeReader     fReader;  //!the tree reader
  TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain
  Double_t posx[4];
  Double_t posy[4];
  enum FP {F1=1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11};  

  // Readers to access the data (delete the ones you do not need).
  TTreeReaderValue<Int_t> Nevent = {fReader, "Nevent"};
  TTreeReaderArray<Int_t> PPAC3_AQRaw = {fReader, "PPAC3_AQRaw"};
  TTreeReaderArray<Int_t> PPAC3_ATRaw = {fReader, "PPAC3_ATRaw"};
  TTreeReaderArray<Int_t> PPAC3_QRaw = {fReader, "PPAC3_QRaw"};
  TTreeReaderArray<Int_t> PPAC3_TRaw = {fReader, "PPAC3_TRaw"};
  TTreeReaderArray<Int_t> PPAC5_AQRaw = {fReader, "PPAC5_AQRaw"};
  TTreeReaderArray<Int_t> PPAC5_ATRaw = {fReader, "PPAC5_ATRaw"};
  TTreeReaderArray<Int_t> PPAC5_QRaw = {fReader, "PPAC5_QRaw"};
  TTreeReaderArray<Int_t> PPAC5_TRaw = {fReader, "PPAC5_TRaw"};
  TTreeReaderArray<Int_t> PPAC7_AQRaw = {fReader, "PPAC7_AQRaw"};
  TTreeReaderArray<Int_t> PPAC7_ATRaw = {fReader, "PPAC7_ATRaw"};
  TTreeReaderArray<Int_t> PPAC7_QRaw = {fReader, "PPAC7_QRaw"};
  TTreeReaderArray<Int_t> PPAC7_TRaw = {fReader, "PPAC7_TRaw"};
  TTreeReaderArray<Int_t> PPAC9_AQRaw = {fReader, "PPAC9_AQRaw"};
  TTreeReaderArray<Int_t> PPAC9_ATRaw = {fReader, "PPAC9_ATRaw"};
  TTreeReaderArray<Int_t> PPAC9_QRaw = {fReader, "PPAC9_QRaw"};
  TTreeReaderArray<Int_t> PPAC9_TRaw = {fReader, "PPAC9_TRaw"};
  TTreeReaderArray<Int_t> PPAC11_AQRaw = {fReader, "PPAC11_AQRaw"};
  TTreeReaderArray<Int_t> PPAC11_ATRaw = {fReader, "PPAC11_ATRaw"};
  TTreeReaderArray<Int_t> PPAC11_QRaw = {fReader, "PPAC11_QRaw"};
  TTreeReaderArray<Int_t> PPAC11_TRaw = {fReader, "PPAC11_TRaw"};
  TTreeReaderArray<Int_t> PL3_QRaw = {fReader, "PL3_QRaw"};
  TTreeReaderArray<Int_t> PL3_TRaw = {fReader, "PL3_TRaw"};
  TTreeReaderArray<Int_t> PL3_CFDRaw = {fReader, "PL3_CFDRaw"};
  TTreeReaderArray<Int_t> PL3_MHit = {fReader, "PL3_MHit"};
  TTreeReaderArray<Int_t> PL5_QRaw = {fReader, "PL5_QRaw"};
  TTreeReaderArray<Int_t> PL5_TRaw = {fReader, "PL5_TRaw"};
  TTreeReaderArray<Int_t> PL5_CFDRaw = {fReader, "PL5_CFDRaw"};
  TTreeReaderArray<Int_t> PL5_MHit = {fReader, "PL5_MHit"};
  TTreeReaderArray<Int_t> PL7_QRaw = {fReader, "PL7_QRaw"};
  TTreeReaderArray<Int_t> PL7_TRaw = {fReader, "PL7_TRaw"};
  TTreeReaderArray<Int_t> PL7_CFDRaw = {fReader, "PL7_CFDRaw"};
  TTreeReaderArray<Int_t>  PL7_MTRaw = {fReader, "PL7_MTRaw"};
  TTreeReaderArray<Int_t> PL7_MHit = {fReader, "PL7_MHit"};
  TTreeReaderArray<Int_t> PL11_QRaw = {fReader, "PL11_QRaw"};
  TTreeReaderArray<Int_t> PL11_TRaw = {fReader, "PL11_TRaw"};
  TTreeReaderArray<Int_t> PL11_CFDRaw = {fReader, "PL11_CFDRaw"};
  TTreeReaderArray<Int_t>  PL11_MTRaw = {fReader, "PL11_MTRaw"};
  TTreeReaderArray<Int_t> PL11_MHit = {fReader, "PL11_MHit"};
  TTreeReaderValue<Int_t> tV1290 = {fReader, "tV1290"};
  TTreeReaderValue<Int_t> tRFRaw = {fReader, "tRFRaw"};
  TTreeReaderArray<Int_t> PL11long_QRaw = {fReader, "PL11long_QRaw"};
  TTreeReaderArray<Int_t> IC3Raw = {fReader, "IC3Raw"};
  TTreeReaderArray<Int_t> IC5Raw = {fReader, "IC5Raw"};
  TTreeReaderArray<Int_t> IC7Raw = {fReader, "IC7Raw"};
  TTreeReaderArray<Int_t> IC_GasRaw = {fReader, "IC_GasRaw"};
  TTreeReaderValue<ULong64_t> TSRaw_C1 = {fReader, "TSRaw_C1"};
  TTreeReaderValue<ULong64_t> TSRaw_C8 = {fReader, "TSRaw_C8"};
  TTreeReaderValue<ULong64_t> TSRaw_F3 = {fReader, "TSRaw_F3"};
  TTreeReaderArray<Double_t> TS_C1 = {fReader, "TS_C1"};
  TTreeReaderArray<Double_t> TS_C8 = {fReader, "TS_C8"};
  TTreeReaderArray<Double_t> TS_F3 = {fReader, "TS_F3"};
  TTreeReaderArray<Double_t> Dipole = {fReader, "Dipole"};
  TTreeReaderArray<Int_t> GSIICERaw = {fReader, "GSIICERaw"};

  
  RIBF123ReadAndCalcRAW(){}

  void SetTree(TTree*tree);
  void SetEntry(Long64_t entry);


  Double_t GetICESum(int focalplane);
  Double_t GetIC2ESum(int focalplane);

  void SetPPACTrack(int focalplane);     

  Double_t GetFocusPointX_mm(int focalplane);
  Double_t GetFocusPointY_mm(int focalplane);
  Double_t GetFocusPointA_mrad(int focalplane);
  Double_t GetFocusPointB_mrad(int focalplane);
  Double_t GetTSumX(int focalplane);
  Double_t GetTSumY(int focalplane);

  Double_t GetLeadingEdgeTOF(int FPstart, int FPend);

  Double_t GetPLQX(int focalplane);
  Double_t GetIC_GasRaw(FP focalplane);

};

#endif


