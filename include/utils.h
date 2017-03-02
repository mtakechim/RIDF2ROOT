#ifndef utils_h
#define utils_h

// return tracked position based on middle point x, angle a and distance from middle point
class Track{
    public:
    double val=0;
    Track(){};
    double operator ()(double &x, double &a, double &distance);
    private:
    double *_x;
    double *_a;
};

double Track::operator ()(double &x, double &a, double &distance)
{
    if(x<-199 || a<-100){val = -999;}
    val = x + (a*distance/1000.);
    return val;
    }

double average(double x1, double x2, double min, double max){
    double r=0.0;
    
    int n=0;
    if(x1>min && x1<max){
        r=x1;
        n++;
        }
    if(x2>min && x2<max){
        r+=x2;
        n++;
        }
    if(n>0)
        r = r/n;
    else 
        r= 0.0;
    
    return r;
}

double choose(double min, double max,double v1, double v2=-9999999, double v3=-99999999,double v4=-99999999){
    double r=0;
    if(v1>min && v1<max){
        r = v1;
    }
    else if(v2>min && v2<max){
        r = v2;
    }
    else if(v3>min && v3<max){
        r = v3;
    }
    else if(v4>min && v4<max){
        r = v4;
    }
    else{
        r = -9999999;
    }
    
    return r;
}



#endif
