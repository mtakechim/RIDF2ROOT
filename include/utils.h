#ifndef utils_h
#define utils_h

// return tracked position based on middle point x, angle a and distance from middle point
class Track{
    public:
    double val=0;
    Track(){};
    double operator ()(double &x, double &a, double &distance){val = x + (a*distance/1000.);return val;}
    private:
    double *_x;
    double *_a;
};

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

#endif
