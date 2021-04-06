#include <iostream>

using namespace std;

class Cesar{
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    string palabra;
    int clave =3 ;
    int l_a_n(char letra){
        for (int i = 0; i < 26; ++i) {
            if (letra == alfabeto[i]){
                return i;
            }
        }
    }

    char n_a_l(int pos){
        if (pos > 25){
            return alfabeto[pos-26];
        }else if (pos < 0){
            return alfabeto[pos+26];
        }
        else{
            return alfabeto[pos];
        }


    }

public:
    int Cifrado(string mensaje){
        for (int i = 0; i < mensaje.size(); ++i) {
            palabra.push_back(n_a_l(l_a_n(mensaje[i])+clave));
        }
        cout<<palabra;
    }
};

int main() {
    string mensaje = "hola";
    Cesar().Cifrado(mensaje);
}
