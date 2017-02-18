#include <methods.h>



Solution *methodA(Pizza *p){
    int n;
    Solution *sol;
    n=minSquare(p->L, p->H);
    if(n<0)
        return NULL;

    sol = newSol();
}


int minSquare(int L, int H){
    int n;
    int i;
    for(n=1;n*n<L;i++);
    if(n*n>H)
        return -1;
    return n;
}

Solution *newSol(){
    Solution *s;
    s= (Solution *) malloc(sizeof(Solution));
    
    return s;
}



/*
    0 if success
    1 if error
*/
int newSlice(Solutio *s){



}
