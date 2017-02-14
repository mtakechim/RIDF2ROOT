#ifndef plastics_h
#define plastics_h

#include "parameters.h"

class Plastics{
    public:
    double xq=999;
    int index=-1;
    int *qdata=nullptr; //pointer to int* for QDC
    int qth = 0;
    
    Plastics(int i,int* _qdata=nullptr):index(i),qdata(_qdata){};
    void clear();
    void calculate();
    void set_qdc_threshold(int _t){qth = _t;};
};

void Plastics::clear(){
    xq = -200;
}

void Plastics::calculate(){
    using namespace parameters;
    clear();
    
    // X position from QDC 
    if(qdata[0]>qth && qdata[1]>qth){ //check if both QDC are valid
	double dif=  qdata[0]-qdata[1];
	xq = PLQch2mm0[index]+PLQch2mm1[index]*(dif)
	    +PLQch2mm2[index]*(dif*dif)
	    +PLQch2mm3[index]*(dif*dif*dif);
	}
    }
#endif
