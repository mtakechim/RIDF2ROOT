#ifndef ic_h
#define ic_h
#include <string.h>

#define IC_V1290_MHITS 10

class IC{
    public:
    int index=-1;
    double sum=-1;
    double mean=-1;
    double gmean=-1;
    int fired = 0;
    int tfired = 0;
    double *pos;
    double meanpos;
    
    void calculate();
    void clear();
    
    IC(int num, int* _data, int* _time_data=nullptr, double* _rt=nullptr);
    ~IC();
    double get_total(){return sum;};
    double get_mean(){return mean;};
    void set_index(int i){index=i;};
    int fired_anodes(){return fired;};
    void threshold(int t){th=t;};
    void set_time_calibration(double _f, double _o=0.0){f=_f;off=_o;};
    void set_time_th(double min, double max){tmin = min;tmax = max;};
    void set_nhits(int *_n){nhits=_n;};
    
    private:
    double f = 1.0;
    double off = 0.0;
    int th=0;
    double tmin = 0.0;
    double tmax = 99999.9;
    int nanodes=0;
    int *data=nullptr;
    int *time=nullptr;
    int *nhits = nullptr;
    double *reftime=nullptr;
};

IC::IC(int num, int* _data, int* _time_data, double* _rt):nanodes(num),data(_data),reftime(_rt){
    pos = new double[num];
    time = _time_data;
};

IC::~IC(){
    delete[] pos;
}


void IC::clear(){
    sum = -1;
    mean = -1;
    gmean = -1;
    fired = 0;
    
    tfired = 0;
    meanpos = -999.9;
    for(int i = 0;i<nanodes;i++){
        pos[i]=-999.9;
    }
};

void IC::calculate(){
    clear();
    double gsum = 1;
    for(int i=0;i<nanodes;i++){
	if(data[i]<=th)continue;
        fired++;
        sum+=data[i];
        gsum*=data[i];
    }
    if(fired>0){
        mean = sum/fired;
        gmean = TMath::Power(gsum,1.0/fired);
	}
    
    double t;
    if(time != nullptr && reftime!=nullptr){
        meanpos = 0;
        for(int i=0;i<nanodes;i++){
            if(nhits[i]>0 && (*reftime) > 0){
                t = 0.025*time[i*IC_V1290_MHITS];
                t -= (*reftime);
                //std::cout<<t<<" "<<*reftime<<"\n";
                if(t>tmin && t<tmax){
                    pos[i]=f*t + off;
                    meanpos +=pos[i];
                    tfired++;
                }
            }
        }
        
        if(tfired>1){
            meanpos = meanpos/tfired;
        }
        else{
            meanpos = -999.0;
        }
    
    }
}
#endif
