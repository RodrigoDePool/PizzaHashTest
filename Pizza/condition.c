#include "condition.h"

int satL(Pizza p, Slice sl){
    int i,j, flagt, flagm;
    char c;
    flagt=0;
    flagm=0;
    for(i=sl.sol[0];i<=sl.sol[2];i++){
        for(j=sl.sol[1];j<=sl.sol[3];j++){
            c= p->cells[i][j];
            if(c=='T'){
                flagt++;
            }else if(c=='M'){
                flagm++;
            }
            if(flagt>=p.L && flagm>=p.L)
                return 1;
        }
    }
    return 0;
}


int satSize(Pizza p, Slice sl){
    int rows;
    int cols;

    rows=sl.sol[2]-sl.sol[0];
    cols=sl.sol[3]-sl.sol[1];
    if(rows*cols>p.H)
        return 0;
    return 1;

}
