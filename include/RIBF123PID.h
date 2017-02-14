//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Dec  9 10:03:57 2016 by ROOT version 6.08/00
// from TTree tree/tree
// found on file: run0214.root
//////////////////////////////////////////////////////////

#ifndef RIBF123PID_h
#define RIBF123PID_h

#include <TROOT.h>

//#include "ribf123_para.h"                                                                                                              

// Headers needed by this particular selector

class RIBF123PID {
  

#ifndef RIBF123PIDpara_h
#include "RIBF123PIDpara.h"        
#endif
  
Double_t TOF[12][12];
  Double_t A_mrad[12];
  Double_t X_mm[12];
  Double_t Delta[12][12];
  Double_t Beta[12][12];
  Double_t Brho_T_mm;
  Double_t Brho_T_m[12][12];
  Double_t AoQ[12][12];
  Double_t Z[12];
  
 public :
  
  
  RIBF123PID(){}
  
  
  void SetDataForAoQ(Double_t tof, Double_t brho_at_dispFP, Double_t achrm_x_mm, Double_t disp_x_mm,Double_t achrm_a_mrad, int tofstartFP, int tofendFP, int achrmFP, int dispFP);
  
  void SetDataForZ(Double_t tof_for_beta, int tofstartFP, int tofendFP, int achrmFP_for_beta, int dispFP_for_beta, Double_t achrm_x_mm_for_beta, Double_t disp_x_mm_for_beta, Double_t achrm_a_mrad_for_beta, int ICFP, Double_t ICSum_ch, bool AngleCorrection,double  angle_for_cor);
 
 Double_t GetAoQ(int achrmFP, int dispFP);
 Double_t GetDelta(int achrmFP, int dispFP);
 Double_t GetBeta(int achrmFP, int dispFP);
 Double_t GetZ(int ICFP);
 
};

#endif


