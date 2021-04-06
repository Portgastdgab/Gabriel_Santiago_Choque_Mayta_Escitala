#include <iostream>

using namespace std;

class AlgoritmoX{
private:
    int clave[2] = {11,7};
    string palabra;
public:
    string Cifrado(string& mensaje){
        for (int i = 0; i <= clave[0]*clave[1]-mensaje.size()+1; ++i) {
            mensaje = mensaje + " ";
        }
        for (int i = 0; i < clave[1]; ++i) {
            for (int j = 0; j < clave[0]; ++j) {
                palabra.push_back(mensaje[i+(j*clave[1])]);
            }

        }
        return palabra;
    }
    string Decifrado(string mensaje){

        for (int i = 0; i < clave[0]; ++i) {
            for (int j = 0; j < clave[1]; ++j) {
                palabra.push_back(mensaje[i+(j*clave[0])]);
            }
        }
        return palabra;
    }

};

int main(){
    string mensaje = "and so discovers the continuity of the message. And the parchment";
    mensaje = AlgoritmoX().Cifrado(mensaje);
    cout<<"Mensaje cifrado: "<<mensaje<<endl;
    mensaje = AlgoritmoX().Decifrado(mensaje);
    cout<<"Mensaje decifrado: "<<mensaje;


}