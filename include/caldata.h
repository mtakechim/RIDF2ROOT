#ifndef ribf123_calvar_h
#define ribf123_calvar_h

#include "TTree.h"

struct caldata{
    int Nevent;
    // ICs
    Double_t F3ICGas;
    Double_t F3ICSum;
    Double_t F5ICSum;
    Double_t F7ICSum;
    Double_t MUSIC1Sum;
    Double_t MUSIC2Sum;
    Double_t F3ICMean;
    Double_t F5ICMean;
    Double_t F7ICMean;
    Double_t MUSIC1Mean;
    Double_t MUSIC2Mean;
    Double_t F3ICGMean;
    Double_t F5ICGMean;
    Double_t F7ICGMean;
    Double_t MUSIC1GMean;
    Double_t MUSIC2GMean;
    Double_t F3ICde;
    Double_t F5ICde;
    Double_t F7ICde;
    Double_t MUSIC1de;
    Double_t MUSIC2de;
    
    //PPACs
    Double_t F3X;
    Double_t F5X;
    Double_t F7X;
    Double_t F9X;
    Double_t F11X;
    Double_t F3Y;
    Double_t F5Y;
    Double_t F7Y;
    Double_t F9Y;
    Double_t F11Y;
    Double_t F3A;
    Double_t F5A;
    Double_t F7A;
    Double_t F9A;
    Double_t F11A;
    Double_t F3B;
    Double_t F5B;
    Double_t F7B;
    Double_t F9B;
    Double_t F11B;
    
    //Plastic
    Double_t TOF35;
    Double_t TOF57;
    Double_t TOF711;
    Double_t F3PLQ_X;
    Double_t F5PLQ_X;
    Double_t F7PLQ_X;
    Double_t F11PLQ_X;
    Double_t F11longPLQ_X;
    
    //F3-F5
    Double_t AoQ35;
    Double_t Delta35;
    Double_t Beta35;
    Double_t Brho35;
    
    //F5-F7
    Double_t AoQ57;
    Double_t Delta57;
    Double_t Beta57;
    Double_t Brho57;
    
    //F7-F11
    Double_t AoQ711;
    Double_t Delta711;
    Double_t Beta711;
    Double_t Brho711;
    
    //Charges
    Double_t Z3;
    Double_t Z5;
    Double_t Z7;
    Double_t Z11;
    Double_t Z11at;
    
        
    void clear_variables();
    void set_branches(TTree *tree);
    void set_branch_addresses(TTree *tree);
};

void caldata::clear_variables(){
    
}

void caldata::set_branches(TTree *tree){
    tree->Branch("Nevent",&Nevent,"Nevent/I");

    tree->Branch("F3X",&F3X,"F3X/D");
    tree->Branch("F5X",&F5X,"F5X/D");
    tree->Branch("F7X",&F7X,"F7X/D");
    tree->Branch("F9X",&F9X,"F9X/D");
    tree->Branch("F11X",&F11X,"F11X/D");
  
    tree->Branch("F3Y",&F3Y,"F3Y/D");
    tree->Branch("F5Y",&F5Y,"F5Y/D");
    tree->Branch("F7Y",&F7Y,"F7Y/D");
    tree->Branch("F9Y",&F9Y,"F9Y/D");
    tree->Branch("F11Y",&F11Y,"F11Y/D");
  
    tree->Branch("F3A",&F3A,"F3A/D");
    tree->Branch("F5A",&F5A,"F5A/D");
    tree->Branch("F7A",&F7A,"F7A/D");
    tree->Branch("F9A",&F9A,"F9A/D");
    tree->Branch("F11A",&F11A,"F11A/D");
  
    tree->Branch("F3B",&F3B,"F3B/D");
    tree->Branch("F5B",&F5B,"F5B/D");
    tree->Branch("F7B",&F7B,"F7B/D");
    tree->Branch("F9B",&F9B,"F9B/D");
    tree->Branch("F11B",&F11B,"F11B/D");
  
    tree->Branch("F3ICGas",&F3ICGas,"F3ICGas/D");
    tree->Branch("F3ICSum",&F3ICSum,"F3ICSum/D");
    tree->Branch("F5ICSum",&F5ICSum,"F5ICSum/D");    
    tree->Branch("F7ICSum",&F7ICSum,"F7ICSum/D");
    tree->Branch("MUSIC1Sum",&MUSIC1Sum,"MUSIC1Sum/D");
    tree->Branch("MUSIC2Sum",&MUSIC2Sum,"MUSIC2Sum/D");
    
    tree->Branch("F3ICMean",&F3ICMean,"F3ICMean/D");
    tree->Branch("F5ICMean",&F5ICMean,"F5ICMean/D");    
    tree->Branch("F7ICMean",&F7ICMean,"F7ICMean/D");
    tree->Branch("MUSIC1Mean",&MUSIC1Mean,"MUSIC1Mean/D");
    tree->Branch("MUSIC2Mean",&MUSIC2Mean,"MUSIC2Mean/D");
    
    tree->Branch("F3ICGMean",&F3ICGMean,"F3ICGMean/D");
    tree->Branch("F5ICGMean",&F5ICGMean,"F5ICGMean/D");    
    tree->Branch("F7ICGMean",&F7ICGMean,"F7ICGMean/D");
    tree->Branch("MUSIC1GMean",&MUSIC1GMean,"MUSIC1GMean/D");
    tree->Branch("MUSIC2GMean",&MUSIC2GMean,"MUSIC2GMean/D");
    
    tree->Branch("F3ICde",&F3ICde,"F3ICde/D");
    tree->Branch("F5ICde",&F5ICde,"F5ICde/D");    
    tree->Branch("F7ICde",&F7ICde,"F7ICde/D");
    tree->Branch("MUSIC1de",&MUSIC1de,"MUSIC1de/D");
    tree->Branch("MUSIC2de",&MUSIC2de,"MUSIC2de/D");


    tree->Branch("TOF35",&TOF35,"TOF35/D");
    tree->Branch("TOF57",&TOF57,"TOF57/D");
    tree->Branch("TOF711",&TOF711,"TOF711/D");
    
    tree->Branch("F3PLQ_X",&F3PLQ_X,"F3PLQ_X/D");
    tree->Branch("F5PLQ_X",&F5PLQ_X,"F5PLQ_X/D");
    tree->Branch("F7PLQ_X",&F7PLQ_X,"F7PLQ_X/D");
    tree->Branch("F11PLQ_X",&F11PLQ_X,"F11PLQ_X/D");
    tree->Branch("F11longPLQ_X",&F11longPLQ_X,"F11longPLQ_X/D");

    tree->Branch("AoQ35",&AoQ35,"AoQ35/D");
    tree->Branch("Delta35",&Delta35,"Delta35/D");
    tree->Branch("Beta35",&Beta35,"Beta35/D");
    tree->Branch("Brho35",&Brho35,"Brho35/D");
    
    tree->Branch("AoQ57",&AoQ57,"AoQ57/D");
    tree->Branch("Delta57",&Delta57,"Delta57/D");
    tree->Branch("Beta57",&Beta57,"Beta57/D");
    tree->Branch("Brho57",&Brho57,"Brho57/D");
    
    tree->Branch("AoQ711",&AoQ711,"AoQ711/D");
    tree->Branch("Delta711",&Delta711,"Delta711/D");
    tree->Branch("Beta711",&Beta711,"Beta711/D");
    tree->Branch("Brho711",&Brho711,"Brho711/D");

    tree->Branch("Z3",&Z3,"Z3/D");
    tree->Branch("Z5",&Z5,"Z5/D");
    tree->Branch("Z7",&Z7,"Z7/D");
    tree->Branch("Z11",&Z11,"Z11/D");
    tree->Branch("Z11at",&Z11at,"Z11at/D");
}

void caldata::set_branch_addresses(TTree *tree){
    
}

#endif
