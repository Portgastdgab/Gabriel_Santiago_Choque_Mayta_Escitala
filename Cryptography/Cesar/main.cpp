#include "Cifrado_Descifrado.h"



void swap(int &pos1, int &pos2)
{
    int temp = pos1;
    pos1 = pos2;
    pos2 = temp;

}

void bubbleSort(int arr[], int n)
{
    bool vuelta;
    for (int i = 0; i < n-1; i++)
    {
        vuelta = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] < arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                vuelta = true;
            }
        }
        if (vuelta == false)
            break;
    }
}

void frecuencias(string mensaje) {
    string alf_fre = "abcdefghijklmnopqrstuvwxyz ";
    for (int i = 0; i < Cesar().alfabeto.size(); ++i) {
        for (int j = 0; j < mensaje.size(); ++j) {
            if (Cesar().alfabeto[i] == mensaje[j]) {

            }
        }
    }
}

int main() {
    /*string mensaje = "deja ya de estar rezando y dandote golpes en el pecho lo que quiero que hagas es que salgas al mundo a disfrutar de tu vida quiero que goces que cantes que te diviertas y que disfrutes de todo";
    mensaje = Cesar().Cifrado(mensaje);
    cout << "Cifrado: " << mensaje << endl;
    //mensaje = Cesar().Descifrado(mensaje);
    //cout<<"Descifrado: "<<mensaje;*/
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    string alfabet= "abcdefg";
    bubbleSort(arr, n);
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }

}
