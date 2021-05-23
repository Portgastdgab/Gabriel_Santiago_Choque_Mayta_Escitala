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


int Euclid_extended(int a, int b) {
    int cont = 0;
    int temp1 = a;
    int temp2 = b;
    while (module(a, b) != 0) {
        int temp = b;
        b = module(a, b);
        a = temp;
        cont++;
    }
    cont = cont + 2;
    int g[cont];
    g[0] = temp1;
    g[1] = temp2;

    int y[cont], u[cont], v[cont];
    u[0] = 1, u[1] = 0, v[0] = 0, v[1] = 1;
    for (int i = 1;; ++i) {
        y[i + 1] = g[i - 1] / g[i];
        g[i + 1] = g[i - 1] - (y[i + 1] * g[i]);
        u[i + 1] = u[i - 1] - (y[i + 1] * u[i]);
        v[i + 1] = v[i - 1] - (y[i + 1] * v[i]);
        if (g[i + 1] == 0) {
            //cout<<"Valor de x: "<<u[i]<<endl;
            //cout<<"Valor de y: "<<v[i]<<endl;
            return module(u[i], g[1]);
        }
    }
}

int inverse(int a, int b){
    return Euclid_extended(a, b);
}

int modular_exponentiation(int base, int exponent, int mod){
    int reply = base;
    exponent/=2;
    while (exponent){
        base = module(base*base, mod);
        if (module(exponent, 2)){
            reply = module(reply*base, mod);
        }
        exponent/=2;
    }
    return reply;
}

int random(int begin, int end) {
    srand(time(NULL));
    return begin + rand() % (end - begin);
}