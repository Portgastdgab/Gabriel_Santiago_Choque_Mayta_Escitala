#include "Cifrado_Descifrado.h"

int Cesar::modulo(int a, int n) {
    int r = a - n * (a / n);
    r = r + (r < 0) * n;
    return r;
}

string Cesar::Emisor(string mensaje, int clave) {
    for (int i = 0; i < mensaje.size(); ++i) {
        palabra.push_back(alfabeto[modulo(((alfabeto.find(mensaje[i])) + clave), alfabeto.size())]);
    }
    return palabra;
}

string Cesar::Receptor(string mensaje, int clave) {
    for (int i = 0; i < mensaje.size(); ++i) {
        palabra.push_back(alfabeto[modulo(((alfabeto.find(mensaje[i])) - clave), alfabeto.size())]);
    }
    return palabra;
}