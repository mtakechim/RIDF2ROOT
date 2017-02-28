#ifndef plastics_h
#define plastics_h

#include "parameters.h"
#include "ribf123_rawvar.h"

class Plastics{
    public:
    double xq=999;
    double x_tdif;
    double x_mtdif;
    double t;
    double t_dif;
    double t_cfd;
    double t_cfd_dif;
    double mt;
    double mt_dif;
    int index=-1;
    int *qdata=nullptr; //pointer to int* for QDC
    int *tdata=nullptr; //pointer to int* for TDC LE
    int *tcfddata=nullptr; //pointer to int* for TDC CFD
    int *mt_left=nullptr;
    int *mt_right=nullptr;
    int *mt_left_nhit = nullptr;
    int *mt_right_nhit = nullptr;
    int *mt_time_ref = nullptr;
    int qth = 0;
    int time_th=0;
    
    Plastics(int i,int* _qdata=nullptr, int* _tdata=nullptr):index(i),qdata(_qdata),tdata(_tdata){};
    Plastics(FP i, rawdata &raw); // constructor for some default plastics
    void clear();
    void calculate();
    void set_qdc_threshold(int _t){qth = _t;};
    void set_tdc_threshold(int _t){time_th = _t;};
    
    void set_qdc_data(int* p){qdata = p;}
    void set_tdc_data(int* p){tdata = p;}
    void set_mtdc_data(int* left, int* right, int *nleft, int *nright, int *tref){mt_left = left; mt_right=right;mt_left_nhit=nleft;mt_right_nhit=nright;mt_time_ref=tref;}
};

Plastics::Plastics(FP i, rawdata &raw):index(i){
    switch(i){
	case F3: {
	    qdata=raw.PL3_QRaw;
	    tdata=raw.PL3_TRaw;
	    tcfddata=raw.PL3_CFDRaw;
	    mt_left=raw.PL3_MTRaw[0];
	    mt_right=raw.PL3_MTRaw[1];
	    mt_left_nhit = &raw.PL3_MHit[0];
	    mt_right_nhit = &raw.PL3_MHit[1];
	    break;
	    }
	case F5: {
	    qdata=raw.PL5_QRaw;
	    tdata=raw.PL5_TRaw;
	    tcfddata=raw.PL5_CFDRaw;
	    mt_left=raw.PL5_MTRaw[0];
	    mt_right=raw.PL5_MTRaw[1];
	    mt_left_nhit = &raw.PL5_MHit[0];
	    mt_right_nhit = &raw.PL5_MHit[1];
	    break;
	    }
	    
	case F7: {
	    qdata=raw.PL7_QRaw;
	    tdata=raw.PL7_TRaw;
	    tcfddata=raw.PL7_CFDRaw;
	    mt_left=raw.PL7_MTRaw[0];
	    mt_right=raw.PL7_MTRaw[1];
	    mt_left_nhit = &raw.PL7_MHit[0];
	    mt_right_nhit = &raw.PL7_MHit[1];
	    break;
	    }
	
	case F11: {
	    qdata=raw.PL11_QRaw;
	    tdata=raw.PL11_TRaw;
	    tcfddata=raw.PL11_CFDRaw;
	    mt_left=raw.PL11_MTRaw[0];
	    mt_right=raw.PL11_MTRaw[1];
	    mt_left_nhit = &raw.PL11_MHit[0];
	    mt_right_nhit = &raw.PL11_MHit[1];
	    break;
	    }
	case F11B: {
	    qdata=&raw.PL11_QRaw[2];
	    tdata=&raw.PL11_TRaw[2];
	    tcfddata=&raw.PL11_CFDRaw[2];
	    mt_left=raw.PL11_MTRaw[2];
	    mt_right=raw.PL11_MTRaw[3];
	    mt_left_nhit = &raw.PL11_MHit[2];
	    mt_right_nhit = &raw.PL11_MHit[3];
	    break;
	    }
	default: {
	    std::cout<<"Error: Default plastics configuration not found "<<"\n";
	    break;
	    }
    }
    mt_time_ref = &raw.tV1290;
}

void Plastics::clear(){
    xq = -200;
    x_tdif = -200;
    x_mtdif = -200;
    t = -9999;
    t_dif = -9999;
    t_cfd = -9999;
    t_cfd_dif = -9999;
    mt = -9999;
    mt_dif=-9999;
    
}

void Plastics::calculate(){
    using namespace parameters;
    clear();
    
    // X position from QDC 
    if(qdata!=nullptr && qdata[0]>qth && qdata[1]>qth){ //check if both QDC are valid
      double dif=  double(qdata[0]-qdata[1])/double(qdata[0]+qdata[1]);
	xq = PLQch2mm0[index]+PLQch2mm1[index]*(dif)
	    +PLQch2mm2[index]*(dif*dif)
	    +PLQch2mm3[index]*(dif*dif*dif);
	}
    
    // mean time left + right / 2
    if(tdata!= nullptr && tdata[0]>time_th && tdata[1]>time_th){
	t = ch2ns_PL[index][0]*tdata[0]+ch2ns_PL[index][1]*tdata[1];
	t = t/2.0;
	t_dif = (ch2ns_PL[index][0]*tdata[0]) - (ch2ns_PL[index][1]*tdata[1]);
	x_tdif = PL_t_mm[index][0] + t_dif*PL_t_mm[index][1];
    }
    
    // mean time left + right / 2
    if(tcfddata!= nullptr && tcfddata[0]>time_th && tcfddata[1]>time_th){
	t_cfd = ch2ns_PL_CFD[index][0]*tcfddata[0]+ch2ns_PL_CFD[index][1]*tcfddata[1];
	t_cfd = t_cfd/2.0;
	t_cfd_dif = (ch2ns_PL_CFD[index][0]*tcfddata[0]) - (ch2ns_PL_CFD[index][1]*tcfddata[1]);
    }
    
    // mean time from V1290
    if(mt_left != nullptr && mt_right != nullptr && *mt_left_nhit>0 && *mt_right_nhit>0){
	mt = mt_left[0]+mt_right[0]- *mt_time_ref - *mt_time_ref;
	//mt = mt_left[0]+mt_right[0];
	mt = 0.025*mt/2.;
	mt_dif = 0.025*(mt_left[0]- mt_right[0]);
	x_mtdif = PL_mt_mm[index][0] + mt_dif*PL_mt_mm[index][1];
    }
}

double tof(Plastics &start, Plastics &stop, Timing_t mode){
    double offset = 0;
    int imode = 0;
    double tof = -9999;
    
    switch(mode){
	case LE:{ 
		imode = 0;
        if(stop.t>-999 && start.t>-999){
            tof = stop.t- start.t;
            }
		break;
		}
	case CFD:{ 
		imode = 1;
        if(stop.t_cfd>-999 && start.t_cfd>-999){
            tof = stop.t- start.t;
            }
		tof = stop.t_cfd - start.t_cfd;
		break;
		}
	case LE_SLEW:{ 
		imode = 2;
        if(stop.t>-999 && start.t>-999){
            tof = stop.t- start.t;
            }
		tof = stop.t - start.t;  // still no slew correction, this needs to be updated
		break;
		}
	case V1290:{
		imode = 3;
        if(stop.mt>-999 && start.mt>-999){
            tof = stop.mt- start.mt;
            }
		tof = stop.mt - start.mt;
		break;
	    }
	}
        
    if(imode >= 0 && start.index == 3 && stop.index==5){
	offset = parameters::TOFoffset[0][imode];
    }
    else if(imode >= 0 && start.index == 5 && stop.index==7){
	offset = parameters::TOFoffset[1][imode];
    }
    else if(imode >= 0 && start.index == 7 && (stop.index==11 || stop.index==0)){
	offset = parameters::TOFoffset[2][imode];
    }
    else{
	offset = 0;
    }
    return tof + offset;
}


#endif
