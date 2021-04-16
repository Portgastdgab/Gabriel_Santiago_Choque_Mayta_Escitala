#include <iostream>

using namespace std;

char alfabeto(int letra){
    switch (letra) {
        case 0:
            return 0;
            break;
        case 1:
            return '1';
            break;
        case 2:
            return '2';
            break;
        case 3:
            return '3';
            break;
        case 4:
            return '4';
            break;
        case 5:
            return '5';
            break;
        case 6:
            return '6';
            break;
        case 7:
            return '7';
            break;
        case 8:
            return '8';
            break;
        case 9:
            return '9';
            break;

    }
}

string cambio(string texto) {
    string vuelta;
    string::const_iterator iterador1 = texto.end()-1;
    while (iterador1 != texto.begin() -1) {
        vuelta.push_back(*iterador1);
        iterador1--;
    }
    return vuelta;

}
int main(){
    int numero = 456384;
    string texto;
    int divisor = 10;
    while (divisor<numero){
        texto.push_back(alfabeto((numero%divisor)/(divisor/10)));
        numero=numero-numero%divisor;
        divisor=divisor*10;
    }
    string final = cambio(texto);
    cout<<final;
}