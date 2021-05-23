#include <iostream>
#include "../../Funciones/Funciones.h"

using namespace std;

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

int main() {
    cout<<modular_exponentiation(549, 101, 731);
}
