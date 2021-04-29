#include "Funciones.h"

int module(int a, int n){
    int r = a-n*(a/n);
    r = r+(r<0)*n;
    return r;
}

int recursive_Euclid(int a, int b){
    if (module(a, b) == 0){
        return b;
    }
    else   {
        int temp = b;
        b = module(a, b);
        a = temp;
        recursive_Euclid(a,b);
    }

}

int Euclid(int a, int b){
    while (module(a, b) != 0){
        int temp = b;
        b = module(a, b);
        a = temp;
    }
    return b;

}