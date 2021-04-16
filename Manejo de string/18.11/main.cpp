#include <iostream>

using namespace std;

int main() {
    string nombre, apellido;
    cout<<"Introduzca el Nombre:";
    cin>>nombre;
    cout<<"Introduzca el Apellido:";
    cin>>apellido;
    nombre.append(" "+apellido);
    cout<<nombre;
}
