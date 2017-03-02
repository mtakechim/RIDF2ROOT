#ifndef ppac_h
#define ppac_h
class PPAC{
    public:
    int index=-1;
    double x;
    double y;
    double a;
    double b;
    double x1;
    double x2;
    int *q;
    int *t;
    int *aq;
    int *at;
    int overflow=600;
    
    bool bx[4];
    bool by[4];
    double tcal[4][4];
    double tdiffx[4];
    double tdiffy[4];
    double tsumx[4];
    double tsumy[4];
    double posx[4];
    double posy[4];
    
    PPAC(int i,int _q[4][4], int _t[4][4]=nullptr, int* _aq=nullptr, int* _at=nullptr):index(i){
	q=&_q[0][0];
	t=&_t[0][0];
	aq = _aq;
	at = _at;
    };
    
    void clear();
    void calculate();
    void set_branches(TTree *tree, const char* name, int v=0);
};


void PPAC::clear(){
    x=-200;
    x1 = -200;
    x2 = -200;
    y=-200;
    a = -200;
    b = -200;
    for(int i=0;i<4;i++){
        posx[i]=-200.;
        posy[i]=-200.;
        bx[i]=0;
        by[i]=0;
        tsumx[i]=0;
        tsumy[i]=0;
        tdiffx[i]=0;
        tdiffy[i]=0;
    }
}

void PPAC::calculate(){
    clear();
    int overflowcheck=0;
    for(int j=0;j<4;j++)
    for(int i=0;i<4;i++){
	tcal[j][i]=parameters::ch2ns_PPAC[index][j][i]*t[(j*4)+i];
	if(tcal[j][i]>overflow){overflowcheck=1;}
    }
    
    if(overflowcheck)return;
    
    bool bx[4],by[4];
    for(int i=0;i<4;i++){ //loop over positions
        tdiffx[i]=tcal[i][2]-tcal[i][0]-parameters::Outoffset[index][i][0];
        tdiffy[i]=tcal[i][1]-tcal[i][3]-parameters::Outoffset[index][i][1];

        tsumx[i]=tcal[i][2]+tcal[i][0];
        tsumy[i]=tcal[i][1]+tcal[i][3];

        if(tsumx[i]>parameters::tsum_x[index][i][0] && tsumx[i]<parameters::tsum_x[index][i][1]){
            posx[i]= 0.5*parameters::ns2mm[index][i][0]*tdiffx[i]-parameters::Inoffset[index][i][0]-parameters::Geomoffset[index][i][0];
        }
        if(tsumy[i]>parameters::tsum_y[index][i][0] && tsumy[i]<parameters::tsum_y[index][i][1]){
            posy[i]= 0.5*parameters::ns2mm[index][i][1]*tdiffy[i]-parameters::Inoffset[index][i][1]-parameters::Geomoffset[index][i][1];
            }
        bx[i]=0;
        by[i]=0;
        if(posx[i]>-120.0 && posx[i]<120.0){
            bx[i]=1;
            }
        if(posy[i]>-120.0 && posy[i]<120.0){
            by[i]=1;
            }
    } //end of i loop i<4 
    
    if(bx[0] || bx[1])
        x1 = bx[0]*posx[0] + bx[1]*posx[1]/(bx[0]+bx[1]);
    if(bx[2] || bx[3])
        x2 = bx[2]*posx[2] + bx[3]*posx[3]/(bx[2]+bx[3]);
    
    double sum_x=0,sum_z=0, sum_zz=0, sum_xz=0;
    int nx=0;
    if( (bx[0] || bx[1]) && (bx[2] || bx[3])){
        for(int j=0;j<4;j++){
            if(bx[j]){
                double z = parameters::Zpos[0][index][j]-parameters::Zoffset[index];
                sum_x += posx[j];
                sum_z += z;
                sum_zz+= z*z;
                sum_xz+= posx[j]*z;
                nx++;
            }
            else{
                posx[j]=-200.0;
            }
        }
        
        x = (sum_z*sum_xz-(sum_x*sum_zz))/(sum_z*sum_z- (nx*sum_zz));
        a = (sum_z*sum_x-(nx*sum_xz))/(sum_z*sum_z-(nx*sum_zz));
        a*= 1000.0; // to mrad
    }
    
    
    double sum_y=0, sum_yz=0;
    int ny=0;
    sum_zz=0;
    sum_z=0;
    if( (by[0] || by[1]) && (by[2] || by[3])){
        for(int j=0;j<4;j++){
            if(by[j]){
                double z = parameters::Zpos[1][index][j]-parameters::Zoffset[index];
                sum_y += posy[j];
                sum_z += z;
                sum_zz+= z*z;
                sum_yz+= posy[j]*z;
                ny++;
            }
            else{
                posy[j]=-200.;
            }
        }
        
        y = (sum_z*sum_yz-(sum_y*sum_zz))/(sum_z*sum_z- (ny*sum_zz));
        b = (sum_z*sum_y-(ny*sum_yz))/(sum_z*sum_z-(ny*sum_zz));
        b*= 1000.0; // to mrad;
    }
    
    
}

void PPAC::set_branches(TTree *tree, const char* name, int var){
    
    tree->Branch(Form("%s_x1",name),&x1,Form("%s_x1/D",name));
    tree->Branch(Form("%s_x2",name),&x2,Form("%s_x2/D",name));
    tree->Branch(Form("%s_posx",name),posx,Form("%s_posx[4]/D",name));
    tree->Branch(Form("%s_tsumx",name),tsumx,Form("%s_tsumx[4]/D",name));
    tree->Branch(Form("%s_tsumy",name),tsumy,Form("%s_tsumy[4]/D",name));
}
#endif
