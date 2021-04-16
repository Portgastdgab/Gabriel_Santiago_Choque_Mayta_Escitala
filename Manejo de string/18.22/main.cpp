#include <iostream>

using namespace std;

#include <string>

using std::string;

int main() {
    string texto = "Gabriel Santiago Choque Mayta";
    string::const_iterator iterador1 = texto.end()-1;
    cout<<"Texto escrito al reves: ";
    while (iterador1 != texto.begin() - 1) {
        cout << *iterador1;
        iterador1--;
    }

    cout << endl;
    return 0;
}
