#define RIBF123ReadAndCalcRAW_cxx

#include "RIBF123ReadAndCalcRAW.h"
//#include "ribf123_para.h"
//#include "ribf123_para2.h"

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <TTreeReader.h>
#include <TMath.h>


using namespace std;

void RIBF123ReadAndCalcRAW::SetTree(TTree *tree)
{ fReader.SetTree(tree);
    }

void RIBF123ReadAndCalcRAW::SetEntry(Long64_t entry)
{ fReader.SetEntry(entry);
  //  cout<<IC7Raw[1]<<endl;
    }

  

Double_t RIBF123ReadAndCalcRAW::GetICESum(int focalplane)
{
  SumIC = -100;
  
  if(focalplane==3){
    for (int i = 0, maxi=IC3Raw.GetSize(); i < maxi; ++i) {
      SumIC += IC3Raw[i];
      }
    return SumIC;
  }
  else if(focalplane==5){
    for (int i = 0, maxi=IC5Raw.GetSize(); i < maxi; ++i) {
      SumIC += IC5Raw[i];
      }
    return SumIC;
  }
  else if(focalplane==7){
    for (int i = 0, maxi=IC7Raw.GetSize(); i < maxi; ++i) {
      SumIC += IC7Raw[i];
      }
    return SumIC;
  }
  else if(focalplane==11){
    for (int i = 0, maxi=GSIICERaw.GetSize(); i < maxi; ++i) {
      if(i/8==0){
	SumIC+=GSIICERaw[i];
      }
      else{
	SumIC=SumIC;
      }
    }
    return SumIC;
  }
  else{
    cout<<"No IC in F"<<focalplane<<" !"<<endl;
  }
}



Double_t RIBF123ReadAndCalcRAW::GetIC2ESum(int focalplane)
{
  SumIC = -100;
  
  if(focalplane==11){
    for (int i = 0, maxi=GSIICERaw.GetSize(); i < maxi; ++i) {
      if(i/8==1){
	SumIC+=GSIICERaw[i-8];
      }
      else{
	SumIC=SumIC;
      }
    }
    return SumIC;
  }
  else{
    cout<<"No 2nd IC in F"<<focalplane<<" !"<<endl;
  }
}


Double_t RIBF123ReadAndCalcRAW::GetIC_GasRaw(FP focalplane){
  Double_t gas;
  gas = IC_GasRaw[int(focalplane)];
  return gas;
}

void RIBF123ReadAndCalcRAW::SetPPACTrack(int focalplane){

  //Zpos[2][12][4] [X/Y][focalplane][1A 1B 2A 2B]
  
  double tcal[4][4]; //[1A 1B 2A 2B][X1 Y1 X2 Y2]                                  
  double tdiffx[4];
  //  double posx[4];
  double tdiffy[4];
  //double posy[4];
  int overflowcheck = 1;
  
  double sumx=0.;
  double sumy=0.;
  double sumz_X=0.;
  double sumz_Y=0.;
  double sumzz_X=0.;
  double sumzz_Y=0.;
  double sumxz=0.;
  double sumyz=0.;

  if(focalplane==3){
    for (int i = 0, maxi=PPAC3_TRaw.GetSize(); i < maxi; ++i) {
      tcal[i/4][i%4]=ch2ns_PPAC[focalplane][i/4][i%4]*PPAC3_TRaw[i];
      //      cout<<i/4<<", "<<i%4<<", "<<tcal[i/4][i%4]<<endl;                    
    }
  }
  else if(focalplane==5){
    for (int i = 0, maxi=PPAC5_TRaw.GetSize(); i < maxi; ++i) {
      tcal[i/4][i%4]=ch2ns_PPAC[focalplane][i/4][i%4]*PPAC5_TRaw[i];
      //      cout<<i/4<<", "<<i%4<<", "<<tcal[i/4][i%4]<<endl;                    
    }
  }
  else if(focalplane==7){
    for (int i = 0, maxi=PPAC7_TRaw.GetSize(); i < maxi; ++i) {
      tcal[i/4][i%4]=ch2ns_PPAC[focalplane][i/4][i%4]*PPAC7_TRaw[i];
      //      cout<<i/4<<", "<<i%4<<", "<<tcal[i/4][i%4]<<endl;                    
    }
  }
  else if(focalplane==9){
    for (int i = 0, maxi=PPAC9_TRaw.GetSize(); i < maxi; ++i) {
      tcal[i/4][i%4]=ch2ns_PPAC[focalplane][i/4][i%4]*PPAC9_TRaw[i];
      //      cout<<i/4<<", "<<i%4<<", "<<tcal[i/4][i%4]<<endl;                    
    }
  }
  else if(focalplane==11){
    for (int i = 0, maxi=PPAC11_TRaw.GetSize(); i < maxi; ++i) {
      tcal[i/4][i%4]=ch2ns_PPAC[focalplane][i/4][i%4]*PPAC11_TRaw[i];
      //      cout<<i/4<<", "<<i%4<<", "<<tcal[i/4][i%4]<<endl;                    
    }
  }
  else{
    cout<<"No PPAC is available at F"<<focalplane<<"."<<endl;
  }

  for (int jj = 0; jj<4; ++jj){
    for(int kk = 0; kk<4; ++kk){
      if((tcal[jj][kk]-570)>0){
	
	overflowcheck = 0;
      }
    }
  }
  
  if(overflowcheck>0){
    for (int ii = 0; ii<4; ++ii){
      
      
      tdiffx[ii]=tcal[ii][2]-tcal[ii][0]-Outoffset[focalplane][ii][0];
      tdiffy[ii]=tcal[ii][1]-tcal[ii][3]-Outoffset[focalplane][ii][1];
      
      tsumx[focalplane]=tcal[0][2]+tcal[0][0];
      tsumy[focalplane]=tcal[0][1]+tcal[0][3];

      posx[ii]= ns2mm[focalplane][ii][0]*tdiffx[ii]-Inoffset[focalplane][ii][0]
	-Geomoffset[focalplane][ii][0];
      posy[ii]= ns2mm[focalplane][ii][1]*tdiffy[ii]-Inoffset[focalplane][ii][1]
	-Geomoffset[focalplane][ii][1];
      
      
      
      
    }
    
    /*    sumy += posy[ii];
	  sumz_Y += Zpos[1][focalplane][ii];
	  sumzz_Y += Zpos[1][focalplane][ii]*Zpos[1][focalplane][ii];
	  sumyz += posy[ii]*Zpos[1][focalplane][ii];*/
    
    if(posx[0]>-120.&&posx[0]<120.&&posx[2]>-120.&&posx[2]<120.){
      for (int ii = 0; ii<3; ii=ii+2){
	sumx += posx[ii];
	sumz_X += Zpos[0][focalplane][ii];
	sumzz_X += Zpos[0][focalplane][ii]*Zpos[0][focalplane][ii];
	sumxz += posx[ii]*Zpos[0][focalplane][ii];
      }
    }
    else if(posx[0]>-120.&&posx[0]<120.&&posx[3]>-120.&&posx[3]<120.){
      for (int ii = 0; ii<4; ii=ii+3){
	sumx += posx[ii];
	sumz_X += Zpos[0][focalplane][ii];
	sumzz_X += Zpos[0][focalplane][ii]*Zpos[0][focalplane][ii];
	sumxz += posx[ii]*Zpos[0][focalplane][ii];
	
      }
    }
    else if(posx[1]>-120.&&posx[1]<120.&&posx[2]>-120.&&posx[2]<120.){
      for (int ii = 1; ii<3; ii=ii+1){
	sumx += posx[ii];
	sumz_X += Zpos[0][focalplane][ii];
	sumzz_X += Zpos[0][focalplane][ii]*Zpos[0][focalplane][ii];
	sumxz += posx[ii]*Zpos[0][focalplane][ii];
	
      }
    }
    else if(posx[1]>-120.&&posx[1]<120.&&posx[3]>-120.&&posx[3]<120.){
      for (int ii = 1; ii<4; ii=ii+2){
	sumx += posx[ii];
	sumz_X += Zpos[0][focalplane][ii];
	sumzz_X += Zpos[0][focalplane][ii]*Zpos[0][focalplane][ii];
	sumxz += posx[ii]*Zpos[0][focalplane][ii];
	
      }
    }
    
    if(posy[0]>-120.&&posy[0]<120.&&posy[2]>-120.&&posy[2]<120.){
      for (int ii = 0; ii<3; ii=ii+2){
	sumy += posy[ii];
	sumz_Y += Zpos[1][focalplane][ii];
	sumzz_Y += Zpos[1][focalplane][ii]*Zpos[1][focalplane][ii];
	sumyz += posy[ii]*Zpos[1][focalplane][ii];
      }
    }
    else if(posy[0]>-120.&&posy[0]<120.&&posy[3]>-120.&&posy[3]<120.){
      for (int ii = 0; ii<4; ii=ii+3){
	sumy += posy[ii];
	sumz_Y += Zpos[1][focalplane][ii];
	sumzz_Y += Zpos[1][focalplane][ii]*Zpos[1][focalplane][ii];
	sumyz += posy[ii]*Zpos[1][focalplane][ii];
      }
    }
    else if(posy[1]>-120.&&posy[1]<120.&&posy[2]>-120.&&posy[2]<120.){
      for (int ii = 1; ii<3; ii=ii+1){
	sumy += posy[ii];
	sumz_Y += Zpos[1][focalplane][ii];
	sumzz_Y += Zpos[1][focalplane][ii]*Zpos[1][focalplane][ii];
	sumyz += posy[ii]*Zpos[1][focalplane][ii];
      }
    }
    else if(posy[1]>-120.&&posy[1]<120.&&posy[3]>-120.&&posy[3]<120.){
      for (int ii = 1; ii<4; ii=ii+2){
	sumy += posy[ii];
	sumz_Y += Zpos[1][focalplane][ii];
	sumzz_Y += Zpos[1][focalplane][ii]*Zpos[1][focalplane][ii];
	sumyz += posy[ii]*Zpos[1][focalplane][ii];
      }
    }
    
    aax[focalplane]=(sumz_X*sumx-2.*sumxz)/(sumz_X*sumz_X-2.*sumzz_X);
    bbx[focalplane]=(sumz_X*sumxz-sumx*sumzz_X)/(sumz_X*sumz_X-2.*sumzz_X);
    aay[focalplane]=(sumz_Y*sumy-2.*sumyz)/(sumz_Y*sumz_Y-2.*sumzz_Y);
    bby[focalplane]=(sumz_Y*sumyz-sumy*sumzz_Y)/(sumz_Y*sumz_Y-2.*sumzz_Y);
  }
  else{
    bbx[focalplane]=-200.;
    bby[focalplane]=-200.;
    aax[focalplane]=10000.;
    aay[focalplane]=10000.;
  }
}



Double_t RIBF123ReadAndCalcRAW::GetFocusPointX_mm(int focalplane){
  return bbx[focalplane];
}
Double_t RIBF123ReadAndCalcRAW::GetFocusPointY_mm(int focalplane){
  return bby[focalplane];
}
Double_t RIBF123ReadAndCalcRAW::GetFocusPointA_mrad(int focalplane){
  return TMath::ATan(aax[focalplane])*1000.;
}
Double_t RIBF123ReadAndCalcRAW::GetFocusPointB_mrad(int focalplane){
  return TMath::ATan(aay[focalplane])*1000.;
}

Double_t RIBF123ReadAndCalcRAW::GetTSumX(int focalplane){
  return tsumx[focalplane];
}
Double_t RIBF123ReadAndCalcRAW::GetTSumY(int focalplane){
  return tsumy[focalplane];
}


Double_t RIBF123ReadAndCalcRAW::GetLeadingEdgeTOF(int FPstart, int FPend){

  Double_t tdc[12];
  memset(tdc,-10000,sizeof(tdc));

  tdc[3]= ch2ns_PL[3][0]*PL3_TRaw[0]+ch2ns_PL[3][1]*PL3_TRaw[1];  
  tdc[5]= ch2ns_PL[5][0]*PL5_TRaw[0]+ch2ns_PL[5][1]*PL5_TRaw[1];  
  tdc[7]= ch2ns_PL[7][0]*PL7_TRaw[0]+ch2ns_PL[7][1]*PL7_TRaw[1];  
  //  tdc[11]= ch2ns_PL[11][0]*PL11_MTRaw[1]+ch2ns_PL[11][1]*PL11_MTRaw[11]
  //    +ch2ns_PL[0][0]*PL11_MTRaw[21]+ch2ns_PL[0][1]*PL11_MTRaw[31];  
  tdc[11]= (PL11_MTRaw[0]+PL11_MTRaw[10]+PL11_MTRaw[20]+PL11_MTRaw[30])/2.;  
  tdc[0]= PL7_MTRaw[0]+PL7_MTRaw[10];  

  //  cout<<PL11_MTRaw[0]<<endl;
  Double_t tof;
  Double_t tofoffset[12][12];
  memset(tofoffset,-100,sizeof(tofoffset));

  tofoffset[3][5]=TOFoffset[0][0];
  tofoffset[5][7]=TOFoffset[1][0];
  tofoffset[7][11]=TOFoffset[2][0];
  
  tof = tdc[FPend]-tdc[FPstart]+tofoffset[FPstart][FPend];

  return tof;
  
}

Double_t RIBF123ReadAndCalcRAW::GetPLQX(int focalplane){

  Double_t PLQ_X[12];
  memset(PLQ_X,-100,sizeof(PLQ_X));
  
  PLQ_X[focalplane]= PLQch2mm0[focalplane]+PLQch2mm1[focalplane]*(PL5_QRaw[0]-PL5_QRaw[1])
    +PLQch2mm2[focalplane]*(PL5_QRaw[0]-PL5_QRaw[1])*(PL5_QRaw[0]-PL5_QRaw[1])
    +PLQch2mm3[focalplane]*(PL5_QRaw[0]-PL5_QRaw[1])*(PL5_QRaw[0]-PL5_QRaw[1])*(PL5_QRaw[0]-PL5_QRaw[1]);

  return PLQ_X[focalplane];
}
  
