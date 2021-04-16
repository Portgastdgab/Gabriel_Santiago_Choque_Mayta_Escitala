#include <iostream>
#include <string>

using namespace std;

void dibujo(int vez){
    switch (vez) {
        case 0:{
            cout<<" "<<endl;
            break;
        }
        case 1:{
            cout<<" 0 "<<endl;
            break;
        }
        case 2:{
            cout<<" 0 "<<endl;
            cout<<" | "<<endl;
            break;
        }
        case 3:{
            cout<<" 0 "<<endl;
            cout<<"/| "<<endl;
            break;
        }
        case 4:{
            cout<<" 0 "<<endl;
            cout<<"/|\\"<<endl;
            break;
        }
        case 5:{
            cout<<" 0 "<<endl;
            cout<<"/|\\"<<endl;
            cout<<" |"<<endl;
            break;
        }
        case 6:{
            cout<<" 0 "<<endl;
            cout<<"/|\\"<<endl;
            cout<<" |"<<endl;
            cout<<"/"<<endl;
            break;
        }
        case 7:{
            cout<<" 0 "<<endl;
            cout<<"/|\\"<<endl;
            cout<<" |"<<endl;
            cout<<"/ \\"<<endl;
        }
    }
}

int main() {
    string palabras[] = {"gente", "humanidad", "humano", "persona", "hombre", "mujer", "bebe", "adolescente", "adulto",
                         "anciano", "pierna", "pie", "espinilla", "rodilla", "muslo", "cabeza", "cara", "parangaricutirimicuaro",
                         "abdomen", "cuello", "mente", "alma", "espalda"};

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
            if (iter == elegida.size()){
                cout<<"Felicidades!!! Adivino mi palabra. Desea jugar otra vez? si/no: ";
                cin>>jugar;
                break;
            }
            dibujo(intentos);
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