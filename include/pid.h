#ifndef pid_h
#define pid_h

#include "plastics.h"
#include "ppac.h"
#include "ic.h"
#include "parameters.h"
#include "ribf123_rawvar.h"

class PID{
    public:
    double beta;
    double aoq;
    double delta;
    double brho;
    double gamma;
    
    double distance;
    Plastics *pl_i=nullptr;
    Plastics *pl_f=nullptr;
    PPAC *ppac_i=nullptr;
    PPAC *ppac_f=nullptr;
    double *xi=nullptr;
    double *yi=nullptr;
    double *ai=nullptr;
    double *bi=nullptr;
    double *xf=nullptr;
    double *yf=nullptr;
    double *af=nullptr;
    double *bf=nullptr;
    double *tof=nullptr;
    double *dipole = nullptr;
    FP initial_fp;
    FP final_fp;
    PID_t idt;
    double *tmatrix=nullptr;
    
    PID(FP fp1, FP fp2):initial_fp(fp1),final_fp(fp2){};
    void set_plastics(Plastics *p1, Plastics *p2){pl_i = p1; pl_f = p2;};
    void set_ppacs(PPAC *p1, PPAC *p2){ppac_i = p1; ppac_f = p2;};
    void set_tof(double *t){tof = t;};
    void set_positions(double *_xi, double *_yi, double *_xf, double *_yf){xi=_xi;yi=_yi;xf=_xf;yf=_yf;};
    void set_angles(double *_ai, double *_bi, double *_af, double *_bf){ai=_ai;bi=_bi;af=_af;bf=_bf;};
    void set_matrix(double m[6][6]){tmatrix = &m[0][0];};
    void set_dipoles(double *d){dipole = d;};
    double matrix(int i, int j){return tmatrix[(6*i) + j];};
    
    void clear();
    void calculate();
    double dipole_brho();
};

void PID::clear(){
    aoq=-1;
    brho=-1;
    beta = -1;
    delta = -999;
    gamma = 0;
}


void PID::calculate(){
    using namespace parameters;
    clear();
    // check if properly initialized
    if(xi==nullptr || xf==nullptr || ai==nullptr || af==nullptr || yi==nullptr || yf==nullptr || bi==nullptr || bf==nullptr){
        std::cout<<"PID error: null pointers "<<"\n";
        return;
        }
    if(tmatrix==nullptr || tof==nullptr){
        std::cout<<"PID error: null pointers "<<"\n";
        return;
        }
        
    double dispersion = matrix(0,6);
    double distance = TOFDistance[final_fp] - TOFDistance[initial_fp];
    delta = ( (*xf)- (*xi)*matrix(0,0) - (*ai)*matrix(0,1))/dispersion;
    brho = (1+(delta/100.))*dipole_brho();
    beta = ((matrix(4,0)*(*xi) + matrix(4,1)*(*ai) + matrix(4,5)*delta)+1000.*distance)/c/(*tof);
    gamma = 1/TMath::Sqrt(1 - (beta*beta));
    aoq = brho/beta/gamma/c/mass_unit;
}


double PID::dipole_brho(){
    double res;
    switch(idt){
        case F35: {
            res = (dipole[3] + dipole[4])/2.0;
            break;
        }
        case F57: {
            res = (dipole[5] + dipole[6])/2.0;
            break;
        }
        
        case F711: {
            res = (dipole[7] + dipole[8])/2.0;
            break;
        }
        
        default: res=0;
    }
    
    return res;
}


#endif
