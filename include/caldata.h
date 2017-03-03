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
    
    Double_t MUSIC1_pos;
    Double_t MUSIC2_pos;
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
    Double_t TOF37;
    Double_t TOF711;
    Double_t TOF711m;
    Double_t TOF711a;
    Double_t TOF711b;
    
    Double_t F3PLQ_X;
    Double_t F5PLQ_X;
    Double_t F7PLQ_X;
    Double_t F11PLQ_X;
    Double_t F11BPLQ_X;
    Double_t F11longPLQ_X;
    
    Double_t F11_reftime;
    
    ////////////////////
    Double_t X3;
    Double_t A3;
    
    Double_t X5;
    Double_t A5;
    
    Double_t X7;
    Double_t A7;
    
    Double_t X11;
    Double_t A11;
    //////////////////////////
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
    
    //F7-F9
    Double_t Delta79;
    //F9-F11
    Double_t Delta911;
    
    //F7-F11
    Double_t AoQ711;
    Double_t Delta711;
    Double_t Beta711;
    Double_t Beta711m;
    Double_t Brho711;
    
    //F3-F7
    Double_t Beta37;
    Double_t AoQ37;
    
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
    
    tree->Branch("MUSIC1_pos",&MUSIC1_pos,"MUSIC1_pos/D");
    tree->Branch("MUSIC2_pos",&MUSIC2_pos,"MUSIC2_pos/D");
    
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
    tree->Branch("TOF37",&TOF37,"TOF37/D");
    tree->Branch("TOF57",&TOF57,"TOF57/D");
    tree->Branch("TOF711",&TOF711,"TOF711/D");
    tree->Branch("TOF711m",&TOF711m,"TOF711m/D");
    tree->Branch("TOF711a",&TOF711a,"TOF711a/D");
    tree->Branch("TOF711b",&TOF711b,"TOF711b/D");
    
    tree->Branch("F3PLQ_X",&F3PLQ_X,"F3PLQ_X/D");
    tree->Branch("F5PLQ_X",&F5PLQ_X,"F5PLQ_X/D");
    tree->Branch("F7PLQ_X",&F7PLQ_X,"F7PLQ_X/D");
    tree->Branch("F11PLQ_X",&F11PLQ_X,"F11PLQ_X/D");
    tree->Branch("F11BPLQ_X",&F11BPLQ_X,"F11BPLQ_X/D");
    tree->Branch("F11longPLQ_X",&F11longPLQ_X,"F11longPLQ_X/D");
    
    tree->Branch("F11_reftime",&F11_reftime,"F11_reftime/D");

    tree->Branch("X3",&X3,"X3/D");
    tree->Branch("A3",&A3,"A3/D");
    tree->Branch("X5",&X5,"X5/D");
    tree->Branch("A5",&A5,"A5/D");
    tree->Branch("X7",&X7,"X7/D");
    tree->Branch("A7",&A7,"A7/D");
    tree->Branch("X11",&X11,"X11/D");
    tree->Branch("A11",&A11,"A11/D");

    tree->Branch("AoQ35",&AoQ35,"AoQ35/D");
    tree->Branch("Delta35",&Delta35,"Delta35/D");
    tree->Branch("Beta35",&Beta35,"Beta35/D");
    tree->Branch("Brho35",&Brho35,"Brho35/D");
    
    tree->Branch("AoQ57",&AoQ57,"AoQ57/D");
    tree->Branch("Delta57",&Delta57,"Delta57/D");
    tree->Branch("Beta57",&Beta57,"Beta57/D");
    tree->Branch("Brho57",&Brho57,"Brho57/D");
    
    tree->Branch("AoQ37",&AoQ37,"AoQ37/D");
    tree->Branch("Beta37",&Beta37,"Beta37/D");
    
    tree->Branch("Delta79",&Delta79,"Delta79/D");
    tree->Branch("Delta911",&Delta911,"Delta911/D");
    
    tree->Branch("AoQ711",&AoQ711,"AoQ711/D");
    tree->Branch("Delta711",&Delta711,"Delta711/D");
    tree->Branch("Beta711",&Beta711,"Beta711/D");
    tree->Branch("Beta711m",&Beta711m,"Beta711m/D");
    tree->Branch("Brho711",&Brho711,"Brho711/D");

    tree->Branch("Z3",&Z3,"Z3/D");
    tree->Branch("Z5",&Z5,"Z5/D");
    tree->Branch("Z7",&Z7,"Z7/D");
    tree->Branch("Z11",&Z11,"Z11/D");
    tree->Branch("Z11at",&Z11at,"Z11at/D");
}

void caldata::set_branch_addresses(TTree *tree){
    tree->SetBranchAddress("Nevent",&Nevent);

    tree->SetBranchAddress("F3X",&F3X);
    tree->SetBranchAddress("F5X",&F5X);
    tree->SetBranchAddress("F7X",&F7X);
    tree->SetBranchAddress("F9X",&F9X);
    tree->SetBranchAddress("F11X",&F11X);
  
    tree->SetBranchAddress("F3Y",&F3Y);
    tree->SetBranchAddress("F5Y",&F5Y);
    tree->SetBranchAddress("F7Y",&F7Y);
    tree->SetBranchAddress("F9Y",&F9Y);
    tree->SetBranchAddress("F11Y",&F11Y);
  
    tree->SetBranchAddress("F3A",&F3A);
    tree->SetBranchAddress("F5A",&F5A);
    tree->SetBranchAddress("F7A",&F7A);
    tree->SetBranchAddress("F9A",&F9A);
    tree->SetBranchAddress("F11A",&F11A);
  
    tree->SetBranchAddress("F3B",&F3B);
    tree->SetBranchAddress("F5B",&F5B);
    tree->SetBranchAddress("F7B",&F7B);
    tree->SetBranchAddress("F9B",&F9B);
    tree->SetBranchAddress("F11B",&F11B);
  
    tree->SetBranchAddress("F3ICGas",&F3ICGas);
    tree->SetBranchAddress("F3ICSum",&F3ICSum);
    tree->SetBranchAddress("F5ICSum",&F5ICSum);    
    tree->SetBranchAddress("F7ICSum",&F7ICSum);
    tree->SetBranchAddress("MUSIC1Sum",&MUSIC1Sum);
    tree->SetBranchAddress("MUSIC2Sum",&MUSIC2Sum);
    
    tree->SetBranchAddress("F3ICMean",&F3ICMean);
    tree->SetBranchAddress("F5ICMean",&F5ICMean);    
    tree->SetBranchAddress("F7ICMean",&F7ICMean);
    tree->SetBranchAddress("MUSIC1Mean",&MUSIC1Mean);
    tree->SetBranchAddress("MUSIC2Mean",&MUSIC2Mean);
    
    tree->SetBranchAddress("F3ICGMean",&F3ICGMean);
    tree->SetBranchAddress("F5ICGMean",&F5ICGMean);    
    tree->SetBranchAddress("F7ICGMean",&F7ICGMean);
    tree->SetBranchAddress("MUSIC1GMean",&MUSIC1GMean);
    tree->SetBranchAddress("MUSIC2GMean",&MUSIC2GMean);
    
    tree->SetBranchAddress("MUSIC1_pos",&MUSIC1_pos);
    tree->SetBranchAddress("MUSIC2_pos",&MUSIC2_pos);
    
    tree->SetBranchAddress("F3ICde",&F3ICde);
    tree->SetBranchAddress("F5ICde",&F5ICde);    
    tree->SetBranchAddress("F7ICde",&F7ICde);
    tree->SetBranchAddress("MUSIC1de",&MUSIC1de);
    tree->SetBranchAddress("MUSIC2de",&MUSIC2de);


    tree->SetBranchAddress("TOF35",&TOF35);
    tree->SetBranchAddress("TOF37",&TOF37);
    tree->SetBranchAddress("TOF57",&TOF57);
    tree->SetBranchAddress("TOF711",&TOF711);
    tree->SetBranchAddress("TOF711m",&TOF711m);
    tree->SetBranchAddress("TOF711a",&TOF711a);
    tree->SetBranchAddress("TOF711b",&TOF711b);
    tree->SetBranchAddress("F11_reftime",&F11_reftime);
    
    tree->SetBranchAddress("F3PLQ_X",&F3PLQ_X);
    tree->SetBranchAddress("F5PLQ_X",&F5PLQ_X);
    tree->SetBranchAddress("F7PLQ_X",&F7PLQ_X);
    tree->SetBranchAddress("F11PLQ_X",&F11PLQ_X);
    tree->SetBranchAddress("F11BPLQ_X",&F11BPLQ_X);
    tree->SetBranchAddress("F11longPLQ_X",&F11longPLQ_X);

    tree->SetBranchAddress("AoQ35",&AoQ35);
    tree->SetBranchAddress("Delta35",&Delta35);
    tree->SetBranchAddress("Beta35",&Beta35);
    tree->SetBranchAddress("Brho35",&Brho35);
    
    tree->SetBranchAddress("AoQ57",&AoQ57);
    tree->SetBranchAddress("Delta57",&Delta57);
    tree->SetBranchAddress("Beta57",&Beta57);
    tree->SetBranchAddress("Brho57",&Brho57);
    
    tree->SetBranchAddress("AoQ711",&AoQ711);
    tree->SetBranchAddress("Delta711",&Delta711);
    tree->SetBranchAddress("Beta711",&Beta711);
    tree->SetBranchAddress("Beta711m",&Beta711m);
    tree->SetBranchAddress("Brho711",&Brho711);

    tree->SetBranchAddress("X3",&X3);
    tree->SetBranchAddress("A3",&A3);
    tree->SetBranchAddress("X5",&X5);
    tree->SetBranchAddress("A5",&A5);
    tree->SetBranchAddress("X7",&X7);
    tree->SetBranchAddress("A7",&A7);
    tree->SetBranchAddress("X11",&X11);
    tree->SetBranchAddress("A11",&A11);

    tree->SetBranchAddress("Z3",&Z3);
    tree->SetBranchAddress("Z5",&Z5);
    tree->SetBranchAddress("Z7",&Z7);
    tree->SetBranchAddress("Z11",&Z11);
    tree->SetBranchAddress("Z11at",&Z11at);
}
 
#endif
