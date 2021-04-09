#include <iostream>

using namespace std;

class Rail_fance {
private:
    int clave = 6;
    int patron[2]; //patron de 2 variables que se repite en cada fila de la matriz
    int suma, cont = 0; //suma es la variable que se suma los saltos del patron para ir añadiendo a la variable palabra
                        //contador verificara si la vuelta en el bucle es par o impar
    string palabra; //almacen del mensaje cifrado o decifrado
public:
    string Chiper(string mensaje) {
        patron[0] = (clave - 1) * 2; //primera variable del patron
        patron[1] = 0; //segunda variable del patron
        for (int i = 0; i < clave; ++i) {
            suma = i; //donde empieza cada secuencia del patron
            palabra.push_back(mensaje[i]); //añade la primera letra
            while (true) {
                if (cont % 2 == 0 or patron[1] == 0) { //si cont es par y la segunda variable del patron es igual a 0
                    suma = suma + patron[0];
                }
                if (cont % 2 != 0 or patron[0] == 0) { //si cont es impar y la primera variable del patron es igual a 0
                    suma = suma + patron[1];
                }
                if (suma > mensaje.size() - 1) { //si la variable suma es mayor que el tamaño del mensaje menos 1, entonces el bucle while se rompe
                    break;
                }
                cont++;
                palabra.push_back(mensaje[suma]); //se añade a la palabra la letra del mensaje que se encuentra en la posicion suma

            }
            patron[0] = patron[0] - 2; //primera variable del patron se reduce de 2 en 2 hasta llegar a 0
            patron[1] = patron[1] + 2; //segunda variable del patron se incrementa de 2 en 2 hasta llegar a "(clave-1)*2"
            cont = 0;
        }
        return palabra;
    }

    string Deschiper(string mensaje) {
        char despalabra[mensaje.size()]; //array de chars donde se iran añadiendo los caracteres cifrados en sus posiciones originales
        int iter = 0; // variable que recorrera cada letra del mensaje cifrado en orden
        patron[0] = (clave - 1) * 2; //primera variable del patron
        patron[1] = 0; //segunda variable del patron
        for (int i = 0; i < clave; ++i) {
            suma = i;
            while (true) {
                despalabra[suma] = mensaje[iter]; //va acomodando cada letra del mensaje cifrado en sus posiciones originales en despalabra
                if (cont % 2 == 0 or patron[1] == 0) {
                    suma = suma + patron[0];
                }
                if (cont % 2 != 0 or patron[0] == 0) {
                    suma = suma + patron[1];
                }
                if (suma > mensaje.size() - 1) {
                    break;
                }
                cont++;
                iter++;
            }
            patron[0] = patron[0] - 2;
            patron[1] = patron[1] + 2;
            cont = 0;
            iter++;
        }
        for (int i = 0; i < mensaje.size(); ++i) {
            palabra.push_back(despalabra[i]); //añade el mensaje descifrado en palabra para que el array de chars sea un string
        }
        return palabra;
    }
};

int main() {
    string mensaje = "Heo slotama osc";
    /*mensaje = Rail_fance().Chiper(mensaje);
    cout << "Mensaje Cifrado: " << mensaje << endl;*/
    mensaje = Rail_fance().Deschiper(mensaje);
    cout << "Mensaje Decifrado: " << mensaje;
}
