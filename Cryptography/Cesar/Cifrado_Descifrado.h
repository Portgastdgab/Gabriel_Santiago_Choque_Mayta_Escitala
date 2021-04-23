#include <iostream>

using namespace std;

class Cesar {
private:

    string palabra;

    int modulo(int a, int n);

public:
    string alfabeto = "abcdefghijklmnopqrstuvwxyz ";
    string Emisor(string mensaje, int clave);
    string Receptor(string mensaje, int clave);
};