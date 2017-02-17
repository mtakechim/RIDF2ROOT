#ifndef ic_h
#define ic_h
#include <string.h>

class IC{
    public:
    double sum=-1;
    double mean=-1;
    double gmean=-1;
    int fired = 0;
    void calculate();
    void clear();
    
    IC(int num, int* _data, int* _time_data=nullptr):nanodes(num),data(_data),time(_time_data){};
    double get_total(){return sum;};
    double get_mean(){return mean;};
    int fired_anodes(){return fired;};
    void threshold(int t){th=t;};
    
    private:
    int th=0;
    int nanodes=0;
    int *data=nullptr;
    int *time=nullptr;    
};

void IC::clear(){
    sum = -1;
    mean = -1;
    gmean = -1;
    fired = 0;
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
}

#endif
