#include <iostream>
#include <cstring>

using std::strtok;
using namespace std;

int modulo(int a, int n) {
    int r = a - n * (a / n);
    r = r + (r < 0) * n;
    return r;
}

int main() {
    string texto;
    float bloque;
    char* tokens;
    cout<<"Ingrese la cadena:";
    cin>>texto;
    cout<<"Ingrese el tamano del bloque:";
    cin>>bloque;

    for (int i = bloque; i < texto.size(); i+=(bloque+1)) {
        texto.insert(i, " ");
    }

    char conversion[texto.size()];
    for (int i = 0; i < texto.size(); ++i) {
        conversion[i] = texto[i];
    }

    cout<<endl<<"Division en tokens: "<<endl;
    tokens = strtok(conversion, " ");
    while (tokens != NULL) {
        cout << tokens <<endl;
        if (sizeof *tokens < bloque+1)
        {
            for (int i = sizeof *tokens; i < bloque+1; ++i) {
                tokens[i] = 'X';
            }
        }
        tokens = strtok(NULL, " ");
    }
}