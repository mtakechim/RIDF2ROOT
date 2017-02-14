#define RIBF123PID_cxx

#include "RIBF123PID.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <TTreeReader.h>
#include <TMath.h>


using namespace std;


void RIBF123PID::SetDataForAoQ(Double_t tof, Double_t brho_at_dispFP, Double_t achrm_x_mm, Double_t disp_x_mm,Double_t achrm_a_mrad, int tofstartFP, int tofendFP, int achrmFP, int dispFP){
  
  Double_t C_mm_ns=299.792488;
  Double_t AMU_mev=931.49432;

  TOF[tofstartFP][tofendFP] = tof;
  X_mm[achrmFP] = achrm_x_mm;
  X_mm[dispFP] = disp_x_mm;
  A_mrad[achrmFP] = achrm_a_mrad;
  Brho_T_mm = brho_at_dispFP*1000.;  

  Delta[achrmFP][dispFP]=(X_mm[dispFP]-X_mm[achrmFP]*Mat35[0][0]-A_mrad[achrmFP]*Mat35[0][1])/Mat35[0][5];
  //  cout<<Delta[achrmFP][dispFP]<<endl;

  Beta[achrmFP][dispFP]=((Mat35[4][0]*X_mm[achrmFP]+Mat35[4][1]*A_mrad[achrmFP]+Mat35[4][5]*Delta[achrmFP][dispFP])+1000.*(DistanceFromF3[tofendFP]-DistanceFromF3[tofstartFP]))/C_mm_ns/TOF[tofstartFP][tofendFP];

  Brho_T_m[achrmFP][dispFP] = Brho_T_mm/1000.*(1+Delta[achrmFP][dispFP]/100.);

  AoQ[achrmFP][dispFP] =  C_mm_ns*TMath::Sqrt(1-Beta[achrmFP][dispFP]*Beta[achrmFP][dispFP])/Beta[achrmFP][dispFP]*Brho_T_m[achrmFP][dispFP]/AMU_mev;

  AoQ[3][5]=0.50972* AoQ[3][5]+1.0145;
  //  cout<<Mat35[4][5]<<endl;

}

void RIBF123PID::SetDataForZ(Double_t tof_for_beta, int tofstartFP, int tofendFP, int achrmFP_for_beta, int dispFP_for_beta, Double_t achrm_x_mm_for_beta, Double_t disp_x_mm_for_beta, Double_t achrm_a_mrad_for_beta, int ICFP, Double_t ICSum_ch, bool AngleCorrection, double angle_for_cor){

    double PI = 3.141592;
    double BohrRadius = 28.17E-13; //mm
    double Avogadoro = 6.0221067E23; //mol-1
    double ElectronMass = 0.511; //MeV
    double C_mm_ns=299.792488;
    double AMU_mev=931.49432;
    double Ioni_Pot = 209.64E-06;//MeV

    Beta[achrmFP_for_beta][dispFP_for_beta]=(Mat35[4][0]*X_mm[achrmFP_for_beta]+Mat35[4][1]*A_mrad[achrmFP_for_beta]+Mat35[4][5]*Delta[achrmFP_for_beta][dispFP_for_beta]+1000.*(DistanceFromF3[tofendFP]-DistanceFromF3[tofstartFP]))/C_mm_ns/TOF[tofstartFP][tofendFP];

    if(ICFP==3){
    if(AngleCorrection){
      Z[ICFP]=TMath::Sqrt(ICSum_ch+Beta[achrmFP_for_beta][dispFP_for_beta]*15000-3.*angle_for_cor);
      //      Z[ICFP] =  ICSum_ch/Beta[achrmFP_for_beta][dispFP_for_beta]/Beta[achrmFP_for_beta][dispFP_for_beta]+15000* Beta[achrmFP_for_beta][dispFP_for_beta]* Beta[achrmFP_for_beta][dispFP_for_beta]-1.5* angle_for_cor;
    }
    else
      {
      Z[ICFP] =  ICSum_ch/Beta[achrmFP_for_beta][dispFP_for_beta]/Beta[achrmFP_for_beta][dispFP_for_beta]+15000* Beta[achrmFP_for_beta][dispFP_for_beta]* Beta[achrmFP_for_beta][dispFP_for_beta];
      }
    }
    //TMath::Sqrt(ICSum_ch/2./PI/Avogadoro/BohrRadius/BohrRadius/ElectronMass*Beta[achrmFP_for_beta][dispFP_for_beta]*Beta[achrmFP_for_beta][dispFP_for_beta]/(TMath::Log(2.*ElectronMass*C_mm_ns*C_mm_ns*Beta[achrmFP_for_beta][dispFP_for_beta]*Beta[achrmFP_for_beta][dispFP_for_beta]/Ioni_Pot)-TMath::Log(1-Beta[achrmFP_for_beta][dispFP_for_beta]*Beta[achrmFP_for_beta][dispFP_for_beta])-Beta[achrmFP_for_beta][dispFP_for_beta]*Beta[achrmFP_for_beta][dispFP_for_beta]));
			   
    }

Double_t RIBF123PID::GetAoQ(int achrmFP, int dispFP){
  return AoQ[achrmFP][dispFP]; 
}  

Double_t RIBF123PID::GetDelta(int achrmFP, int dispFP){
  return Delta[achrmFP][dispFP];
}

Double_t RIBF123PID::GetBeta(int achrmFP, int dispFP){
  return Beta[achrmFP][dispFP];
}

Double_t RIBF123PID::GetZ(int ICFP){
  return Z[ICFP];
}


