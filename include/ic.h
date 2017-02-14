#ifndef ic_h
#define ic_h

class IC{
    public:
    double sum=-1;
    double av=-1;
    int fired = 0;
    void calculate();
    void clear();
    
    IC(int num, int* _data, int* _time_data=nullptr):nanodes(num),data(_data),time(_time_data){};
    double total(){return sum;};
    double average(){return av;};
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
    av = -1;
    fired = 0;
};

void IC::calculate(){
    clear();
    for(int i=0;i<nanodes;i++){
	if(data[i]<=th)continue;
	fired++;
	sum+=data[i];
    }
    if(fired>0){
	av = sum/fired;
	}
}

#endif
