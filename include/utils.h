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

#endif
