#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "read_file.h"
#include "methods.h"


int rec(Pizza pizza, Slice* s, Solution* s){
    Slice x1, x2, y1, y2;
    int count;
    int new;
    int direction;

    new = cutHalf(*s, &direction);
    if(direccion == 0) {
        copy(&x1, s);
        x.sol[2] = newrow;
        copy(&y1, s);
        y.sol[0] = newrow+1;
    } else if (direccion == 1) {
        copy(&x1, s);
        x.sol[3] = newrow;
        copy(&y1, s);
        y.sol[1] = newrow+1;
    } else{
        return -1;
    }

etiq:
    if(satL(pizza, x1) == 1) {
        if(satL(pizza, y1) == 1) {
            if(satSize(pizza, x) == 1) {
                addSlice(s, &x1);
            } else{
                rec(pizza, &x1, s);
            }
            if(satSize(pizza, y1) == 1) {
                addSlice(s, &y1);
            } else{
                rec(pizza, &y1, s);
            }
        } else{
            if(direccion = 0) {
                copy(&x2, &x1);
                copy(&y2, &y1)
                x1.sol[2] = (x1.sol[0]+x1.sol[2])/2;
                y1.sol[0] = x1.sol[2]+1;
                goto etiq;
            } else{
                copy(&x2, &x1);
                copy(&y2, &y1)
                x1.sol[3] = (x1.sol[3]+x1.sol[1])/2;
                y1.sol[1] = x1.sol[3]+1;
                goto etiq;
            }
        }
    } else{
        if(satL(pizza, y1) == 1) {
            if(direccion = 0) {
                copy(&x2, &x1);
                copy(&y2, &y1)
                y1.sol[2] = (y1.sol[0]+y1.sol[2])/2;
                x1.sol[0] = y1.sol[2]+1;
                goto etiq;
            } else{
                copy(&x2, &x1);
                copy(&y2, &y1)
                y1.sol[3] = (y1.sol[3]+y1.sol[1])/2;
                x1.sol[1] = y1.sol[3]+1;
                goto etiq;
            }
        }else {
            return -1;
        }
    }

}

Solution* methodyujian(){
    Solution* solution;
    solution = (Solution*)malloc(sizeof(Solution));
    if(!solution) {
        return NULL;
    }



}
