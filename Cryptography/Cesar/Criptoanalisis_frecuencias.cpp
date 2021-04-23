#include "Criptoanalisis_frecuencias.h"
#include "Cifrado_Descifrado.h"

void swap(int arr[], int pos1, int pos2, string &fre_alf) {
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
    char temp2 = fre_alf[pos1];
    //cout<<fre_alf[pos1]<<" = "<< fre_alf[pos2]<<endl;
    //cout<<fre_alf[pos2]<<" = "<<temp2<<endl;
    fre_alf[pos1] = fre_alf[pos2];
    fre_alf[pos2] = temp2;
}

void bubbleSort(int arr[], int n, string &fre_alf) {
    bool vuelta;
    for (int i = 0; i < n - 1; i++) {
        vuelta = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr, j, j + 1, fre_alf);
                vuelta = true;
            }
        }
        if (vuelta == false)
            break;
    }
}

void frecuencias(string mensaje) {
    string alf_fre = Cesar().alfabeto;
    string espanol_rep = " eaolsndyq";
    int frecuencia[alf_fre.size()];
    int contador;
    for (int i = 0; i < alf_fre.size(); ++i) {
        contador = 0;
        for (int j = 0; j < mensaje.size(); ++j) {
            if (alf_fre[i] == mensaje[j]) {
                contador++;
            }
        }
        frecuencia[i] = contador;
    }
    bubbleSort(frecuencia, alf_fre.size(), alf_fre);
    cout << endl << endl << "Estas son las letras de mayor frecuencia y las veces que aparecen: " << endl;
    for (int i = 0; i < alf_fre.size(); ++i) {
        cout << frecuencia[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < alf_fre.size(); ++i) {
        cout << alf_fre[i] << " ";
    }
    int posible_clave;
    int iter = 0;
    for (int i = 0; i < alf_fre.size(); ++i) {
        posible_clave = (Cesar().alfabeto.find(alf_fre[iter]) + 1) - (Cesar().alfabeto.find(espanol_rep[iter]) + 1) % 27;

        if (posible_clave ==
            (Cesar().alfabeto.find(alf_fre[iter + 1]) + 1) - (Cesar().alfabeto.find(espanol_rep[iter + 1]) + 1) % 27) {
            break;
        } else {
            if (i % 2 == 0) {
                swap(frecuencia, iter, iter + 1, alf_fre);
            } else {
                swap(frecuencia, iter, iter + 1, alf_fre);
                iter++;
            }
        }
    }
    cout << endl << "posible clave: " << posible_clave;
}