#include <iostream>

using namespace std;

class Cesar{
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    string palabra;
    int clave = 157;

    int modulo(int a, int n){
        int r = a-n*(a/n);
        r = r+(r<0)*n;
        return r;
    }

public:
    string Cifrado(string mensaje){
        for (int i = 0; i < mensaje.size(); ++i) {
            palabra.push_back(alfabeto[modulo(((alfabeto.find(mensaje[i]))+clave),26)]);
        }
        return palabra;
    }
    string Descifrado(string mensaje){
        for (int i = 0; i < mensaje.size(); ++i) {
            palabra.push_back(alfabeto[modulo(((alfabeto.find(mensaje[i]))-clave),26)]);
        }
        return palabra;
    }
};

int main() {
    string mensaje = "hola";
    mensaje = Cesar().Cifrado(mensaje);
    cout<<"Cifrado: "<<mensaje<<endl;
    mensaje = Cesar().Descifrado(mensaje);
    cout<<"Descifrado: "<<mensaje;
}
