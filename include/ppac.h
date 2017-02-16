#ifndef ppac_h
#define ppac_h
class PPAC{
    public:
    int index=-1;
    double x;
    double y;
    double a;
    double b;
    int *q;
    int *t;
    int *aq;
    int *at;
    int overflow=570;
    
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
};


void PPAC::clear(){
    x=-200;
    y=-200;
    a = -200;
    b = -200;
    memset(posx,-200,sizeof(posx));
    memset(posy,-200,sizeof(posy));
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
	
        posx[i]= 0.5*parameters::ns2mm[index][i][0]*tdiffx[i]-parameters::Inoffset[index][i][0]-parameters::Geomoffset[index][i][0];
        posy[i]= 0.5*parameters::ns2mm[index][i][1]*tdiffy[i]-parameters::Inoffset[index][i][0]-parameters::Geomoffset[index][i][1];
    
        bx[i]=0;
        by[i]=0;
        if(posx[i]>-120.0 && posx[i]<120.0)bx[i]=1;
        if(posy[i]>-120.0 && posy[i]<120.0)by[i]=1;
    } //end of i loop i<4 
    
    
    double sum_x=0,sum_z=0, sum_zz=0, sum_xz=0;
    int nx=0;
    if( (bx[0] || bx[1]) && (bx[2] || bx[3])){
        for(int j=0;j<4;j++){
            if(bx[j]){
                sum_x += posx[j];
                sum_z += parameters::Zpos[0][index][j];
                sum_zz+= parameters::Zpos[0][index][j]*parameters::Zpos[0][index][j];
                sum_xz+= posx[j]*parameters::Zpos[0][index][j];
                nx++;
            }
        }
    }
    x = (sum_z*sum_xz-(sum_x*sum_zz))/(sum_z*sum_z- (nx*sum_zz));
    a = (sum_z*sum_x-(nx*sum_xz))/(sum_z*sum_z-(nx*sum_zz));
    a*= 1000.0; // to mrad
    
    double sum_y=0, sum_yz=0;
    int ny=0;
    sum_zz=0;
    sum_z=0;
    if( (by[0] || by[1]) && (by[2] || by[3])){
        for(int j=0;j<4;j++){
            if(by[j]){
                sum_y += posy[j];
                sum_z += parameters::Zpos[0][index][j];
                sum_zz+= parameters::Zpos[0][index][j]*parameters::Zpos[0][index][j];
                sum_yz+= posy[j]*parameters::Zpos[0][index][j];
                ny++;
            }
        }
    }
    y = (sum_z*sum_yz-(sum_y*sum_zz))/(sum_z*sum_z- (ny*sum_zz));
    b = (sum_z*sum_y-(ny*sum_yz))/(sum_z*sum_z-(ny*sum_zz));
    b*= 1000.0; // to mrad;
    
}

#endif
