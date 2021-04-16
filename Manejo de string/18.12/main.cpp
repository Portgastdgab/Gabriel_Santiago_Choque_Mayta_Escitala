#include <iostream>
#include <string>

using namespace std;

int main() {
    string palabras[] = {"gente", "humanidad", "humano", "persona", "hombre", "mujer", "bebe", "adolescente", "adulto",
                         "anciano", "pierna", "pie", "espinilla", "rodilla", "muslo", "cabeza", "cara", "parangaricutirimicuaro",
                         "abdomen", "cuello", "mente", "alma", "espalda"};
    string dibujos[]={"\t      0","\n\t/","|","\\","\n\t |","\n\t/"," \\ \n\n"};
    char letra;
    int iter;
    string jugar;
    while (true){
        iter = 0;
        string elegida = palabras[rand()%24];
        string escondido = "";
        escondido.resize(elegida.size(), 'X');
        for (int intentos = 0; intentos < 7; ) {
            cout<<"Introduzca una letra:";
            cin >> letra;
            if (escondido == elegida){
                break;
            }
            if (elegida.find(letra)<elegida.size()){
                for (int i = 0; i < elegida.size(); ++i) {
                    if(elegida[elegida.find(letra)] == elegida[i]){
                        escondido[i] = letra;
                        iter++;
                    }
                }
                escondido[elegida.find(letra)] =letra;
            }
            else{
                intentos++;
            }

            for (int i = 0; i < intentos; ++i) {
                cout<<dibujos[i];
            }

            if (iter == elegida.size()){
                cout<<"Felicidades!!! Adivino mi palabra. Desea jugar otra vez? si/no: ";
                cin>>jugar;
                break;
            }
            if (intentos == 7){
                cout<<"MORISTE. Desea jugar otra vez? si/no: ";
                cin>>jugar;
                break;
            }
            cout<<endl<<"Adivina la palabra: "<<escondido<<endl;
        }
        if (jugar == "no"){
            break;
        }
    }
}