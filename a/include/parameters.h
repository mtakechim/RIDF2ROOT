#ifndef parameters_h
#define parameters_h

namespace parameters{
  
double PLQch2mm0[12]={0.,0.,0.,0.,0.,-61.72,    0.,0.,0.,0.,0.,0.};
double PLQch2mm1[12]={0.,0.,0.,0.,0.,0.1057,    0.,0.,0.,0.,0.,0.};
double PLQch2mm2[12]={0.,0.,0.,0.,0.,3.348E-05, 0.,0.,0.,0.,0.,0.};
double PLQch2mm3[12]={0.,0.,0.,0.,0.,-2.012E-08,0.,0.,0.,0.,0.,0.};


//===== Calibration ======================================
//===== PPAC ===========================
//===== TSum ============
double TSum_Min[12][4][2]={//[12]:Fpl, [4]:1A,1B,2A,2B, [2]:X,Y
  -750.,-750.,-750.,-750.,-750.,-750.,-750.,-750., /* F0 1A-X/Y, 1B-, 2A-, 2B- */
  -750.,-750.,-750.,-750.,-750.,-750.,-750.,-750., /* F1 1A-X/Y, 1B-, 2A-, 2B- */
  -750.,-750.,-750.,-750.,-750.,-750.,-750.,-750., /* F2 1A-X/Y, 1B-, 2A-, 2B- */
  624,642,644,650,722,660,722,660, /* F3 1A-X/Y, 1B-, 2A-, 2B- */
  -750.,-750.,-750.,-750.,-750.,-750.,-750.,-750., /* F4 1A-X/Y, 1B-, 2A-, 2B- */
  902,837,908,861,929,837,896,838, /* F5 1A-X/Y, 1B-, 2A-, 2B- */
  -750.,-750.,-750.,-750.,-750.,-750.,-750.,-750., /* F6 1A-X/Y, 1B-, 2A-, 2B- */
  840,767,861,768,846,782,861,803, /* F7 1A-X/Y, 1B-, 2A-, 2B- */
   260.,-750., 250.,-750.,-750.,-750., 203.,-750., /* F8 1A-X/Y, 1B-, 2A-, 2B- */
  389,329,355,287,380,357,384,328, /* F9 1A-X/Y, 1B-, 2A-, 2B- */
    83.,-750.,  54.,-750., 112.,-750., 100.,-750., /* F10 1A-X/Y, 1B-, 2A-, 2B- */
  954,879,930,847,957,876,947,864, /* F11 1A-X/Y, 1B-, 2A-, 2B- */
};

double TSum_Max[12][4][2]={//[12]:Fpl, [4]:1A,1B,2A,2B, [2]:X,Y
    750., 750., 750., 750., 750., 750., 750., 750., /* F0 1A-X/Y, 1B-, 2A-, 2B- */
    750., 750., 750., 750., 750., 750., 750., 750., /* F1 1A-X/Y, 1B-, 2A-, 2B- */
    750., 750., 750., 750., 750., 750., 750., 750., /* F2 1A-X/Y, 1B-, 2A-, 2B- */
    643.,661.,663.,670.,741.,680.,741.,680., /* F3 1A-X/Y, 1B-, 2A-, 2B- */
    750., 750., 750., 750., 750., 750., 750., 750., /* F4 1A-X/Y, 1B-, 2A-, 2B- */
    916.,851.,922.,875.,944.,851.,910.,852., /* F5 1A-X/Y, 1B-, 2A-, 2B- */
    750., 750., 750., 750., 750., 750., 750., 750., /* F6 1A-X/Y, 1B-, 2A-, 2B- */
    865.,792.,885.,793.,870.,806.,885.,827., /* F7 1A-X/Y, 1B-, 2A-, 2B- */
    270., 750., 260., 750., 750., 750., 213., 750., /* F8 1A-X/Y, 1B-, 2A-, 2B- */
    424.,364.,390.,322.,414.,392.,419.,362., /* F9 1A-X/Y, 1B-, 2A-, 2B- */
     95., 750.,  67., 750., 120., 750., 109., 750., /* F10 1A-X/Y, 1B-, 2A-, 2B- */
    1003.,927.,979.,895.,1006.,925.,995.,913., /* F11 1A-X/Y, 1B-, 2A-, 2B- */
};

//===== Cathodes ========
double  ch2ns_PPAC[12][4][4]={//[12]:Fpl, [4]:1A,1B,2A,2B, [4]:X1,Y1,X2,Y2
   0.09765, 0.09765, 0.09765, 0.09765, 0.09765, 0.09765, 0.09765, 0.09765, 0.09765, 0.09765, 0.09765, 0.09765, 0.09765, 0.09765, 0.09765, 0.09765, /* F0 1A-X1/Y1/X2/Y2, 1B-, 2A-, 2B- */
  0.141179,0.147747,0.144717, 0.14362,      0.,      0.,      0.,      0.,0.149795, 0.14605,0.146158,0.148486,      0.,      0.,      0.,      0., /* F1 1A-X1/Y1/X2/Y2, 1B-, 2A-, 2B- */
  0.150175, 0.15353,0.152608,0.149436,      0.,      0.,      0.,      0.,0.153498,0.142653,0.144948,0.147276,      0.,      0.,      0.,      0., /* F2 1A-X1/Y1/X2/Y2, 1B-, 2A-, 2B- */
  0.151096,0.148212,0.147478,0.150747,0.151345, 0.14818, 0.15148,0.146174,0.146298,0.148608,0.151626,0.150946,0.146958,0.144238,0.148189,0.146956, /* F3 1A-X1/Y1/X2/Y2, 1B-, 2A-, 2B- */
   0.14868,0.149443,0.147131,0.149318,      0.,      0.,      0.,      0.,      0.,      0.,      0.,      0.,      0.,      0.,      0.,      0., /* F4 1A-X1/Y1/X2/Y2, 1B-, 2A-, 2B- */
  0.151622,0.145979,0.147927,0.146828,0.151959,0.152978,0.144341,0.151408,0.146886,0.148598,0.147218,0.150814, 0.14824,0.151384,0.145607,0.148806, /* F5 1A-X1/Y1/X2/Y2, 1B-, 2A-, 2B- */
  0.150242,0.152564,0.146609,0.149084,      0.,      0.,      0.,      0.,      0.,      0.,      0.,      0.,      0.,      0.,      0.,      0., /* F6 1A-X1/Y1/X2/Y2, 1B-, 2A-, 2B- */
  0.141496,0.149205,0.142964,0.144151,0.145397,0.147769,0.149053,0.148728, 0.14645,0.147926,0.149802,0.151382, 0.14805,0.147009,0.147318,0.143919, /* F7 1A-X1/Y1/X2/Y2, 1B-, 2A-, 2B- */
  0.143029,0.144447,0.146295,0.144236,0.149385,0.143185,0.148076,0.146068,0.144117,0.143094,0.145777,0.147426,0.144564,0.146335,0.145097,0.147534, /* F8 1A-X1/Y1/X2/Y2, 1B-, 2A-, 2B- */
  0.152054,0.144032,0.149193,0.145932,0.141752,0.149194,0.145475,0.141491,0.147303,0.147355, 0.14983, 0.14613,0.144018,0.147399, 0.15279,0.152808, /* F9 1A-X1/Y1/X2/Y2, 1B-, 2A-, 2B- */
  0.146293,0.145615,0.152921, 0.14881,0.153731,0.149329,0.150958,0.148988,0.147988,0.150685,0.150567,0.154362,0.148954,0.153196,0.151319,0.151899, /* F10 1A-X1/Y1/X2/Y2, 1B-, 2A-, 2B- */
  0.147666,0.146122,0.143161,0.144448,0.145359,0.141926,0.152705,0.150023,0.147053,0.152173,0.143568,0.145391,0.144219,0.140717,0.149207,0.147558, /* F11 1A-X1/Y1/X2/Y2, 1B-, 2A-, 2B- */    
};

double  Inoffset[12][4][2]={//[12]:Fpl, [4]:1A,1B,2A,2B, [2]:X,Y
  0.00, 0.00,0.00, 0.00,0.00, 0.00,0.00, 0.00, /* F0 1A-X/Y, 1B-, 2A-, 2B- */
  1.24, 0.28,0.00, 0.00,0.86, 0.77,0.00, 0.00, /* F1 1A-X/Y, 1B-, 2A-, 2B- */
  0.75, 0.63,0.00, 0.00,0.84, 0.46,0.00, 0.00, /* F2 1A-X/Y, 1B-, 2A-, 2B- */
  0.55, -0.94, 0.99, -0.69, 0.77, -0.45, 1.29, 0.22, /* F3 1A-X/Y, 1B-, 2A-, 2B- */
  0.86, 0.01,0.00, 0.00,0.00, 0.00,0.00, 0.00, /* F4 1A-X/Y, 1B-, 2A-, 2B- */
  0.91, -0.77, 1.62, -0.5, 1.59, -0.72, 1.06, -0.59, /* F5 1A-X/Y, 1B-, 2A-, 2B- */
  0.95, 0.17,0.00, 0.00,0.00, 0.00,0.00, 0.00, /* F6 1A-X/Y, 1B-, 2A-, 2B- */
  0.56, -0.89, 1.25, -0.89, 1.18, -0.86, 1.25, -1.16, /* F7 1A-X/Y, 1B-, 2A-, 2B- */
  1.37, 0.21, 1.34, -0.89,1.18,0.65,1.18,0.19, /* F8 1A-X/Y, 1B-, 2A-, 2B- */
  1.18, -0.25, 1.17, -0.39, 0.83, 0.05, 0.35, -0.62, /* F9 1A-X/Y, 1B-, 2A-, 2B- */
  1.02, 0.00,1.35, 0.28,1.18, 0.41,0.95, 0.35, /* F10 1A-X/Y, 1B-, 2A-, 2B- */
  1.12, -0.56, 0.63, -0.12, 0.88, -0.53, 1.13, -0.53, /* F11 1A-X/Y, 1B-, 2A-, 2B- */    
};

double  ns2mm[12][4][2]={//[12]:Fpl, [4]:1A,1B,2A,2B, [2]:X,Y
  1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, /* F0 1A-X/Y, 1B-, 2A-, 2B- */
  1.232, 1.233, 1.000, 1.000, 1.231, 1.238, 1.000, 1.000, /* F1 1A-X/Y, 1B-, 2A-, 2B- */
  1.229, 1.233, 1.000, 1.000, 1.225, 1.232, 1.000, 1.000, /* F2 1A-X/Y, 1B-, 2A-, 2B- */
  1.228, 1.232, 1.240, 1.231, 1.225, 1.236, 1.234, 1.236, /* F3 1A-X/Y, 1B-, 2A-, 2B- */
  1.231, 1.226, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, /* F4 1A-X/Y, 1B-, 2A-, 2B- */
  1.226, 1.231, 1.231, 1.230, 1.229, 1.235, 1.227, 1.229, /* F5 1A-X/Y, 1B-, 2A-, 2B- */
  1.242, 1.223, 1.000, 1.000, 1.000, 1.000, 1.000, 1.000, /* F6 1A-X/Y, 1B-, 2A-, 2B- */
  1.220, 1.239, 1.211, 1.228, 1.244, 1.221, 1.244, 1.235, /* F7 1A-X/Y, 1B-, 2A-, 2B- */
  1.241, 1.237, 1.231, 1.238, 1.243,-1.227, 1.225, 1.232, /* F8 1A-X/Y, 1B-, 2A-, 2B- */
  1.225, 1.224, 1.226, 1.234, 1.230,-1.231, 1.234, 1.230, /* F9 1A-X/Y, 1B-, 2A-, 2B- */
  1.227, 1.232, 1.223, 1.227, 1.231,-1.243, 1.228, 1.230, /* F10 1A-X/Y, 1B-, 2A-, 2B- */
  1.231, 1.233, 1.227, 1.229, 1.229,-1.231, 1.226, 1.228, /* F11 1A-X/Y, 1B-, 2A-, 2B- */    
};

double  Outoffset[12][4][2]={//[12]:Fpl, [4]:1A,1B,2A,2B, [2]:X,Y
   0.000,   0.000,   0.000,  0.000,  0.000,   0.000,  0.000,  0.000, /* F0 1A-X/Y, 1B-, 2A-, 2B- */
   2.347,  -1.300,   0.000,  0.000,  7.524, -0.5679,  0.000,  0.000, /* F1 1A-X/Y, 1B-, 2A-, 2B- */
  -17.59,   22.10,   0.000,  0.000, 16.419, -25.804,  0.000,  0.000, /* F2 1A-X/Y, 1B-, 2A-, 2B- */
  -4.72,  -3.54,  -11.4, 16.33, 9.79,  10.17,  6.96,  8.05, /* F3 1A-X/Y, 1B-, 2A-, 2B- */
  6.9217,   17.34,   0.000,  0.000,  0.000,   0.000,  0.000,  0.000, /* F4 1A-X/Y, 1B-, 2A-, 2B- */
  13.66,   22.86,  14.38, 0.79, -14.86,   13.09, 10.94,-15.63, /* F5 1A-X/Y, 1B-, 2A-, 2B- */
  1.1163,  8.6399,   0.000,  0.000,  0.000,   0.000,  0.000,  0.000, /* F6 1A-X/Y, 1B-, 2A-, 2B- */
 -1.92, -7,  14.42, 16.42,  8.01,  -8.46, 12.8,-7.73, /* F7 1A-X/Y, 1B-, 2A-, 2B- */
  -2.212,  -6.022, -1.8487,  10.31,  -8.94, -2.6328, -5.657, -11.55, /* F8 1A-X/Y, 1B-, 2A-, 2B- */
  13.57,  3.34,-0.49,11.42, -26.46, 1.01, -10.55, 15.41, /* F9 1A-X/Y, 1B-, 2A-, 2B- */
  -13.279, 14.413, -1.3921, 16.995, 7.2957,-0.29604, 2.7221,-10.169, /* F10 1A-X/Y, 1B-, 2A-, 2B- */
   -2.6985,-6.0641,  11.094,-8.6362,-5.6477, -1.2329, 3.5575,-8.708, /* F11 1A-X/Y, 1B-, 2A-, 2B- */    
};

double  Geomoffset[12][4][2]={//[12]:Fpl, [4]:1A,1B,2A,2B, [2]:X,Y
    0.00, 0.00,   0.00, 0.00,   0.00, 0.00,  0.00, 0.00, /* F0 1A-X/Y, 1B-, 2A-, 2B- */
  -2.00 , 0.00,  -1.50, 0.00,   0.00, 0.00,  0.00, 0.00, /* F1 1A-X/Y, 1B-, 2A-, 2B- */
   0.00 ,-1.80,   1.00,-2.00,   0.00, 0.00,  0.00, 0.00, /* F2 1A-X/Y, 1B-, 2A-, 2B- */
   8.504, 7.89, 24.635, 6.42, -25.48, 17.4,-17.39, 11.3, /* F3 1A-X/Y, 1B-, 2A-, 2B- */
    //   1.046, 0.00, 0.5747, 0.00, 1.9789, 0.00, 1.764, 0.00, /* F3 1A-X/Y, 1B-, 2A-, 2B- */
   0.00 , 0.00,   0.00, 0.00, 0.00, 0.00, 0.00, 0.00, /* F4 1A-X/Y, 1B-, 2A-, 2B- */
    -35.44 , 4.815, -35.39, 3.82,33.35, 4.50,-26.49, 4.89, /* F5 1A-X/Y, 1B-, 2A-, 2B- */
    //0.00 , 0.00,   0.00, 0.00,-0.15, 0.00,-0.15, 0.00, /* F5 1A-X/Y, 1B-, 2A-, 2B- */
    0.00 , 0.00,   0.00, 0.00, 0.00, 0.00, 0.00, 0.00, /* F6 1A-X/Y, 1B-, 2A-, 2B- */
    10.23 , 2.39, -30.06, 5.33,-20.86, 4.28,-32.67, 4.13, /* F7 1A-X/Y, 1B-, 2A-, 2B- */
    //  -0.30 , 0.00,  -0.30, 0.00,-0.43, 0.00,-0.43, 0.00, /* F7 1A-X/Y, 1B-, 2A-, 2B- */
   0.00 , 0.00,   0.00, 0.00,-0.35, 0.00,-0.60,-0.70, /* F8 1A-X/Y, 1B-, 2A-, 2B- */
  -0.30 , -11.00,  -0.30, 18.20, 73.30,-2.80, 64.47, -2.80, /* F9 1A-X/Y, 1B-, 2A-, 2B- */
    //  -0.30 , 0.00,  -0.30, 0.00, 0.0, 0.00, 0., 0.00, /* F9 1A-X/Y, 1B-, 2A-, 2B- */
   0.00 ,-0.10,   0.00,-0.10, 0.00,-0.90, 0.00,-0.90, /* F10 1A-X/Y, 1B-, 2A-, 2B- */
  -0.50 , 0.00,   11.89, 0.00, 2.60, 0.00, 16.17, 0.00, /* F11 1A-X/Y, 1B-, 2A-, 2B- */    
    //  -0.50 , 0.00,   -0.50, 0.00, -0.10, 0.00, -0.10, 0.00, /* F11 1A-X/Y, 1B-, 2A-, 2B- */    
};

//===== Anodes ==========
double  ch2ns_PPACA[12][4]={//[12]:Fpl, [4]:1A,1B,2A,2B
  0.9765,0.9765,0.9765,0.9765, /* F0 1A/1B/2A/2B */ 
  0.9765,0.9765,0.9765,0.9765, /* F1 1A/1B/2A/2B */ 
  0.9765,0.9765,0.9765,0.9765, /* F2 1A/1B/2A/2B */ 
  0.147696, 0.144662, 0.150818, 0.149367, /* F3 1A/1B/2A/2B */ 
  0.9765,0.9765,0.9765,0.9765, /* F4 1A/1B/2A/2B */ 
  0.140546, 0.141985, 0.144636, 0.149480, /* F5 1A/1B/2A/2B */ 
  0.9765,0.9765,0.9765,0.9765, /* F6 1A/1B/2A/2B */ 
  0.139108, 0.138979, 0.148906, 0.147447, /* F7 1A/1B/2A/2B */ 
  0.9765,0.9765,0.9765,0.9765, /* F8 1A/1B/2A/2B */ 
  0.144846, 0.140907, 0.152341, 0.150016, /* F9 1A/1B/2A/2B */ 
  0.9765,0.9765,0.9765,0.9765, /* F10 1A/1B/2A/2B */
  0.147478, 0.146447, 0.146203, 0.148432, /* F11 1A/1B/2A/2B */    
};
//======================================

//===== Plastics =======================
//===== T ==========
double  ch2ns_PL[12][2]={//[12]:Fpl, [2]:L,R
  0.0274976,0.0274527, /* VETO L,R */
         0.,       0., /* F1 L,R */
   0.026868,0.0271937, /* F2 L,R */
  0.0271382,0.0276006, /* F3 L,R */
         0.,       0., /* F4 L,R */
   0.02742 ,  0.02681, /* F5 L,R */
         0.,       0., /* F6 L,R */
  0.0270701,0.0277871, /* F7 L,R */
  0.0270701,0.0278229, /* F8 L,R */
  0.0262554,0.0268812, /* F9 L,R */
         0.,       0., /* F10 L,R */
  0.0270212,0.0266295, /* F11 L,R */
};

// Slew = TRaw + A/sqrt(QRaw) + B // In accordance with TArtCalibPlastic.cc(ANAROOT)
// Slew = T + A/sqrt(QRaw) + B // Use in RIBF123
double  Slew_PL[2][12][2]={//[2]:A,B [12]:Fpl, [2]:L,R
  /* A */
  0.,0., /* VETO L,R */
  0.,0., /* F1 L,R */
  0.,0., /* F2 L,R */
  0.,0., /* F3 L,R */
  0.,0., /* F4 L,R */
  -214.341,17.4422, /* F5 L,R */
  0.,0., /* F6 L,R */
  0.,0., /* F7 L,R */
  0.,0., /* F8 L,R */
  0.,0., /* F9 L,R */
  0.,0., /* F10 L,R */
  0.,0., /* F11 L,R */
  /* B */
  0.,0., /* VETO L,R */
  0.,0., /* F1 L,R */
  0.,0., /* F2 L,R */
  0.,0., /* F3 L,R */
  0.,0., /* F4 L,R */
  -44.9429,-55.469, /* F5 L,R */
  0.,0., /* F6 L,R */
  0.,0., /* F7 L,R */
  0.,0., /* F8 L,R */
  0.,0., /* F9 L,R */
  0.,0., /* F10 L,R */
  0.,0., /* F11 L,R */
};

//===== Q ==========
double  ch2MeV_PL[3][12][2]={//[3]:p0,p1,p2 [12]:Fpl, [2]:L,R
  /* p0 */
  0.,0., /* VETO L,R */
  0.,0., /* F1 L,R */
  0.,0., /* F2 L,R */
  0.,0., /* F3 L,R */
  0.,0., /* F4 L,R */
  0.,0., /* F5 L,R */
  0.,0., /* F6 L,R */
  0.,0., /* F7 L,R */
  0.,0., /* F8 L,R */
  0.,0., /* F9 L,R */
  0.,0., /* F10 L,R */
  0.,0., /* F11 L,R */
  /* p1 */
  1.,1., /* VETO L,R */
  1.,1., /* F1 L,R */
  1.,1., /* F2 L,R */
  1.,1., /* F3 L,R */
  1.,1., /* F4 L,R */
  1.,1., /* F5 L,R */
  1.,1., /* F6 L,R */
  1.,1., /* F7 L,R */
  1.,1., /* F8 L,R */
  1.,1., /* F9 L,R */
  1.,1., /* F10 L,R */
  1.,1., /* F11 L,R */
  /* p2 */
  0.,0., /* VETO L,R */
  0.,0., /* F1 L,R */
  0.,0., /* F2 L,R */
  0.,0., /* F3 L,R */
  0.,0., /* F4 L,R */
  0.,0., /* F5 L,R */
  0.,0., /* F6 L,R */
  0.,0., /* F7 L,R */
  0.,0., /* F8 L,R */
  0.,0., /* F9 L,R */
  0.,0., /* F10 L,R */
  0.,0., /* F11 L,R */
};

//===== CFD ========
double  ch2ns_PL_CFD[12][2]={//[12]:Fpl, [2]:L,R
  0.0244,0.0244, /* VETO L,R */
  0.0244,0.0244, /* F1 L,R */
  0.0244,0.0244, /* F2 L,R */
  0.0244,0.0244, /* F3 L,R */
  0.0244,0.0244, /* F4 L,R */
  0.0244,0.0244, /* F5 L,R */
  0.0244,0.0244, /* F6 L,R */
  0.0244,0.0244, /* F7 L,R */
  0.0244,0.0244, /* F8 L,R */
  0.0244,0.0244, /* F9 L,R */
  0.0244,0.0244, /* F10 L,R */
  0.0244,0.0244, /* F11 L,R */
};
//===== tracking using Plastic ========
double MeV2mm_PL[4][12]={
  // p0
  0.,0.,0., 2.47,0.,-28.2,0.,-2.62, 18.197,0.,0., 5.31,
  // p1
  1.,1.,1.,15.5,1.,37.6,1.,35.2,-16.508,1.,1.,60.5,
  // p2
  0.,0.,0.,-7.35,0.,0.945,0.,-2.88,0.,0.,0.,6.85,
  // p3
  0.,0.,0.,-10.4,0.,-1.05,0.,7.24,0.,0.,0.,245,
};
double ns2mm_PL[4][12]={
  // p0
  0.,0.,0.,-156,0.,-84.3,0.,-112, 18.197,0.,0., 13.5,
  // p1
  1.,1.,1.,200,1.,-27.62,1.,-124.8,-16.508,1.,1.,48.3,
  // p2
  0.,0.,0.,-77.8,0.,2.723,0.,-47.35,0.,0.,0.,7.35,
  // p3
  0.,0.,0.,9.27,0.,0.4441,0.,-7.607,0.,0.,0.,17.2,
};
//===== RF ========
//double ch2ns_RF = {1.}; 
double ch2ns_RF=1.; 
//===== VETO ==========================
double ch2MeV_VETO[2][2]={
  //slope
  1.,1.,
  //ped
  0.,0.,
};
double Slew_VETO[2][2]={
  //parameter A
  0.,0.,
  //parameter B
  0.,0.,  
};
//======================================

//===== IC =============================
double  ch2MeV_IC[2][12][8]={//[2]:Slope,Pedestal [12]Fpl, [8]:Anodes
  /* Slope */
  1.,1.,1.,1.,1.,1.,1.,1., /* F0 IC ch0,1,--,7 */
  1.,1.,1.,1.,1.,1.,1.,1., /* F1 IC ch0,1,--,7 */
  1.,1.,1.,1.,1.,1.,1.,1., /* F2 IC ch0,1,--,7 */
  0.06605,0.06605,0.06605,0.06605,0.06605,0.06605,0.06605,0.06605, /* F3 IC ch0,1,--,7 */
  1.,1.,1.,1.,1.,1.,1.,1., /* F4 IC ch0,1,--,7 */
  //  0.0221,0.0221,0.0221,0.0221,0.0221,0.0221,0.0221,0.0221, /* F5 IC ch0,1,--,7 */
  0.03137289,0.03137289,0.03137289,0.03137289,0.03137289,0.03137289,0.03137289,0.03137289, /* F5 IC ch0,1,--,7 */
  1.,1.,1.,1.,1.,1.,1.,1., /* F6 IC ch0,1,--,7 */
  0.034069408,0.034069408,0.034069408,0.034069408,0.034069408,0.034069408,0.034069408,0.034069408, /* F7 IC ch0,1,--,7 */
  1.,1.,1.,1.,1.,1.,1.,1., /* F8 IC ch0,1,--,7 */
  1.,1.,1.,1.,1.,1.,1.,1., /* F9 IC ch0,1,--,7 */
  1.,1.,1.,1.,1.,1.,1.,1., /* F10 IC ch0,1,--,7 */
  1.,1.,1.,1.,1.,1.,1.,1., /* F11 IC ch0,1,--,7 */
  /* Pedestal */
  0.,0.,0.,0.,0.,0.,0.,0., /* F0 IC ch0,1,--,7 */
  0.,0.,0.,0.,0.,0.,0.,0., /* F1 IC ch0,1,--,7 */
  0.,0.,0.,0.,0.,0.,0.,0., /* F2 IC ch0,1,--,7 */
  -19.1276,-19.1276,-19.1276,-19.1276,-19.1276,-19.1276,-19.1276,-19.1276, /* F3 IC ch0,1,--,7 */
  0.,0.,0.,0.,0.,0.,0.,0., /* F4 IC ch0,1,--,7 */
  -12.75,-12.75,-12.75,-12.75,-12.75,-12.75,-12.75,-12.75, /* F5 IC ch0,1,--,7 */
  0.,0.,0.,0.,0.,0.,0.,0., /* F6 IC ch0,1,--,7 */
  -116.4,-116.4,-116.4,-116.4,-116.4,-116.4,-116.4,-116.4, /* F7 IC ch0,1,--,7 */
  0.,0.,0.,0.,0.,0.,0.,0., /* F8 IC ch0,1,--,7 */
  0.,0.,0.,0.,0.,0.,0.,0., /* F9 IC ch0,1,--,7 */
  0.,0.,0.,0.,0.,0.,0.,0., /* F10 IC ch0,1,--,7 */
  0.,0.,0.,0.,0.,0.,0.,0., /* F11 IC ch0,1,--,7 */
};

double  ch2Pa_IC[12]={//[12]Fpl
  1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1., /* F0,1,--,11 */
};

double ch2MeV_GSIIC[2][2][8]={// GSI IC
  /* Slope */
  0.097986,0.097986,0.097986,0.097986,0.097986,0.097986,0.097986,0.097986,
  0.0600574,0.0600574,0.0600574,0.0600574,0.0600574,0.0600574,0.0600574,0.0600574,
  /* Pedestal */
  -12.77,-12.77,-12.77,-12.77,-12.77,-12.77,-12.77,-12.77,
  -97.600,-97.600,-97.600,-97.600,-97.600,-97.600,-97.600,-97.600,
};

double ch2ns_GSIIC[2][2][8]={// GSI IC
  /* Slope */
  1.,1.,1.,1.,1.,1.,1.,1.,
  1.,1.,1.,1.,1.,1.,1.,1.,
  /* Pedestal */
  0.,0.,0.,0.,0.,0.,0.,0.,
  0.,0.,0.,0.,0.,0.,0.,0.,
};
//======================================

//===== Ge =============================
//===== T ==========
double  ch2ns_Ge[2][2][4]={//[2]:Slope,Pedestal [2]:1,2 [4]:Crystal
  /* Slope */
  1.,1.,1.,1., /*1-1,2,3,4*/
  1.,1.,1.,1., /*2-1,2,3,4*/
  /* Pedestal */
  0.,0.,0.,0., /*1-1,2,3,4*/
  0.,0.,0.,0., /*2-1,2,3,4*/
};

//===== Q ==========
double  ch2MeV_Ge[2][2][4]={//[2]:Slope,Pedestal [2]:1,2 [4]:Crystal
  /* Slope */
  1.,1.,1.,1., /*1-1,2,3,4*/
  1.,1.,1.,1., /*2-1,2,3,4*/
  /* Pedestal */
  0.,0.,0.,0., /*1-1,2,3,4*/
  0.,0.,0.,0., /*2-1,2,3,4*/
};
//======================================
//========================================================

//===== Reconstruction ===================================
//===== Tracking ========================
// the distance of the focus position from the ideal focus point along the z-axis at each Fpl.
double Zoffset[12]={ 
  0.,0.,0.,0.,0.,0.,0.,0.,134.5,0.,0.,720.0,
};

// the distance of the PPAC position from the upstream along z-axis at each Fpl.
double Zpos[2][12][4]={//[2]:X/Y [12]:Fpl [4] 1A/1B/2A/2B 
  // X [A]:-18.7, [B]:+18.7
   0.0,   0.0,   0.0,   0.0, /* F0 1A/1B/2A/2B */ 
   0.0,   0.0,   0.0,   0.0, /* F1 1A/1B/2A/2B */ 
   0.0,   0.0,   0.0,   0.0, /* F2 1A/1B/2A/2B */ 
 -18.7,  18.7, 871.3, 908.7, /* F3 1A/1B/2A/2B */ 
   0.0,   0.0,   0.0,   0.0, /* F4 1A/1B/2A/2B */ 
-418.7,-381.3, 231.3, 268.7, /* F5 1A/1B/2A/2B */ 
   0.0,   0.0,   0.0,   0.0, /* F6 1A/1B/2A/2B */ 
-868.7,-831.3,  76.3, 113.7, /* F7 1A/1B/2A/2B */ 
   0.0,   0.0,   0.0,   0.0, /* F8 1A/1B/2A/2B */ 
 -18.7,  18.7, 681.3, 718.7, /* F9 1A/1B/2A/2B */ // change  
   0.0,   0.0,   0.0,   0.0, /* F10 1A/1B/2A/2B */
 -810.7,-773.3,-310.7,-273.3, /* F11 1A/1B/2A/2B */ //change
  // Y [A]:-10.1, [B]:+10.1
   0.0,   0.0,   0.0,   0.0, /* F0 1A/1B/2A/2B */ 
   0.0,   0.0,   0.0,   0.0, /* F1 1A/1B/2A/2B */ 
   0.0,   0.0,   0.0,   0.0, /* F2 1A/1B/2A/2B */ 
 -10.1,  10.1, 879.9, 900.1, /* F3 1A/1B/2A/2B */ 
   0.0,   0.0,   0.0,   0.0, /* F4 1A/1B/2A/2B */ 
-410.1,-389.9, 239.9, 260.1, /* F5 1A/1B/2A/2B */ 
   0.0,   0.0,   0.0,   0.0, /* F6 1A/1B/2A/2B */ 
-860.1,-839.9,  84.9, 105.1, /* F7 1A/1B/2A/2B */ 
   0.0,   0.0,   0.0,   0.0, /* F8 1A/1B/2A/2B */ 
   -10.1,  10.1, 689.9, 710.1, /* F9 1A/1B/2A/2B */ //change 
   0.0,   0.0,   0.0,   0.0, /* F10 1A/1B/2A/2B */
-802.1,-781.9,-302.1,-281.9, /* F11 1A/1B/2A/2B */
};
//===== PID ===============================================
//===== TOF / Beta / Gamma =======================
//[3]:TOF35,57,711
//[3]: LE w/o Slew, CFD, LE w/ Slew
double TOFoffset[3][3]={ 
  116.65,122.71,170.7723, /* TOF35 */
  127.84,129.98,74.8457, /* TOF57 */
  214.44,235.22,214.44, /* TOF711 */
};
//===== Length =======================
// refer from beamline.xlsx in http://www.ribf.riken.jp/BigRIPSInfo/
// Length F3-F5,F5-F7,F7-F11 [m]
double Length[3]={
  23.283,23.284,47.783,
};
// focus point is shited 720mm to downstream in F11.(day2)

// speed of light [m/ns]
double Clight = 2.99792458E-01;
// mass of nucleon [MeV]
//double Mnucleon = 931.49432;
double Mnucleon = 9.3149432E-01;
//===== Transfer Matrix =======================
// refer from each file in http://www/ribf.riken.jp/BigRIPSInfo/optics/optics.html 
// F3-F5 : matrix_1st_7Tm.txt
// F5-F7 : matrix_1st_7Tm.txt
// F9-F11 : matrixz_1st_LargeAccAchr_7Tm.txt
//
// Tmat[0][][] : F3-F5
// Tmat[1][][] : F5-F7
// Tmat[2][][] : F9-F11
double TMat[3][5][5]={
  // F3-F5
   0.917467E+00, -0.520039E-02,  0.,            0.,            0.316051E+02,
  -0.187210E-01,  0.109006E+01,  0.,            0.,           -0.129966E-01,
   0.,            0.,            0.107852E+01,  0.325887E-01,  0.,
   0.,            0.,            0.331125E+00,  0.937205E+00,  0.,
  -0.316630E-01,  0.188156E+01,  0.,            0.,            0.896693E+02,
   // F5-F7
   0.109101E+01,  0.204150E-01,  0.,            0.,           -0.344457E+02,
  -0.172247E-01,  0.916262E+00,  0.,            0.,            0.590371E+00,
   0.,            0.,            0.939059E+00,  0.255208E-01,  0.,
   0.,            0.,            0.336060E+00,  0.107403E+01,  0.,
  -0.277197E-02, -0.172349E+01,  0.,            0.,            0.898155E+02,
   // F9-F11
   0.492516E+00,  0.940953E-01,  0.,            0.,            0.122280E+02,
  -0.248973E+00,  0.198282E+01,  0.,            0.,           -0.592115E+00,
   0.,            0.,            0.525997E+00, -0.179933E-01,  0.,
   0.,            0.,            0.521447E-01,  0.188332E+01,  0.,
  -0.721884E-02,  0.139695E+01,  0.,            0.,            0.802942E+02,
   /*
  // F3-F5
   0.917467E+00, -0.187210E-01,  0.,            0.,           -0.316630E-01,
  -0.520039E-02,  0.109006E+01,  0.,            0.,            0.188156E+01,
   0.,            0.,            0.107852E+01,  0.331125E+00,  0.,
   0.,            0.,            0.325887E-01,  0.937205E+00,  0.,
   0.316051E+02, -0.129966E-01,  0.,            0.,            0.896693E+02,
   // F5-F7
   0.109101E+01, -0.172247E-01,  0.,            0.,           -0.277197E-02,
   0.204150E-01,  0.916262E+00,  0.,            0.,           -0.172349E+01,
   0.,            0.,            0.939059E+00,  0.336060E+00,  0.,
   0.,            0.,            0.255208E-01,  0.107403E+01,  0.,
  -0.344457E+02,  0.590371E+00,  0.,            0.,            0.898155E+02,
   // F9-F11
   0.492516E+00, -0.248973E+00,  0.,            0.,           -0.721884E-02,
   0.940953E-01,  0.198282E+01,  0.,            0.,            0.139695E+01,
   0.,            0.,            0.525997E+00,  0.521447E-01,  0.,
   0.,            0.,           -0.179933E-01,  0.188332E+01,  0.,
   0.122280E+02, -0.592115E+00,  0.,            0.,            0.802942E+02,
   */
};
//===== Z =====================================
//double ionpair[3]={4866.,4866.,4866.,};
double ionpair[3]={3586.,4866.,4866.,};
double Z_calib[2][3][3]={
  //slope
  3.4679,3.4679,3.4679, /* F3IC*/	  
  3.2973,3.2973,3.2973, /* F7IC*/ 
  4.649,4.649,4.649, /* F11IC*/
  //intercept
  -0.89445,-0.89445,-0.89445, /* F3IC */	  
  1.6940,1.6940,1.6940, /* F7IC */ 
  -3.2345,-3.2345,-3.2345, /* F11IC */
  //  //slope
  //  3.5502,3.5502,3.5502, /* Beta:T*/	  
  //  11.76,11.76,11.76, /* Beta:CFD*/ 
  //  10.482,10.482,10.482, /* Beta:Slew*/
  //  //intercept
  //  //  -0.137,-0.137,-0.137, /* Beta:T*/	  
  //  0.55668,0.55668,0.55668, /* Beta:T*/	  
  //  -0.137,-0.137,-0.137, /* Beta:CFD*/ 
  //  -0.569,-0.569,-0.569, /* Beta:Slew*/
};	    


} // end of parameter namespace
#endif
