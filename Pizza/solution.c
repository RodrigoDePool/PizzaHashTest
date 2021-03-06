#include "solution.h"


int addSlice(Solution *s, Slice *sl){
    int i;
    if(s->nslices >= MAX_SLICES)
        return 0;
    for(i=0;i<4;i++){
        (s->slices[s->nslices]).sol[i]=sl->sol[i]; 
    }
    return 1;
}

int copySlice(Slice *sl1, Slice *sl2){
    int i;
    if(sl1==NULL || sl2==NULL)
        return 0;
    for(i=0;i<4;i++){
        sl2->sol[i]=sl1->sol[i];
    }
    return 1;
}

int printSolution(Solution s, char *path){
    FILE *f;
    int i;
    f=fopen(path, "w");
    if(f==NULL)
        return 0;
    fprintf(f,"%d\n", s.nslices);
    for(i=0;i<s.nslices;i++){
        fprintf(f,"%d %d %d %d\n",s.slices[i].sol[0],s.slices[i].sol[1],
                s.slices[i].sol[2],s.slices[i].sol[3]);
    }
   fclose(f);
   return 1;
}
