#include <stdio.h>
#include <stdlib.h>
#include <readfile.h>
#include <solution.h>

int cuthalf(Slice sl, int c){
  int half;
  Slice x,y;

    if(c < 0 || c > 1)
      return NULL;
    if(c == 0){ //horizontal (return row)
      half = (sl[2]-sl[0])/2;
      return half;
    }
    if(c == 1){ //vertical (return col)
      half = (sl[3]-sl[1])/2;
      return half;
    }
    return half;
}
