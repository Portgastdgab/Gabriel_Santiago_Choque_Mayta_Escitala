#include <iostream>

using namespace std;

class Cesar {
private:

    string palabra;
    int clave = 157;

    int modulo(int a, int n);

public:
    string alfabeto = "abcdefghijklmnopqrstuvwxyz ";
    string Cifrado(string mensaje);

    string Descifrado(string mensaje);
};