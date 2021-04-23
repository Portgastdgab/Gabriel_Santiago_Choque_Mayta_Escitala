#include "Cifrado_Descifrado.h"
#include "Criptoanalisis_frecuencias.h"

int main() {
    string mensaje = "deja ya de estar rezando y dandote golpes en el pecho lo que quiero\n"
                     "que hagas es que salgas al mundo a disfrutar de tu vida\n"
                     "\n"
                     "quiero que goces que cantes que te diviertas y que disfrutes de todo lo\n"
                     "que he hecho para ti\n"
                     "deja ya de ir a esos templos lugubres, obscuros y frios que tu mismo\n"
                     "construiste y que dices que son mi casa.\n"
                     "mi casa esta en las montanas en los bosques los ríos los lagos las\n"
                     "playas ahi es en donde vivo y ahi expreso mi amor por ti\n"
                     "deja ya de culparme de tu vida miserable yo nunca te dije que habia\n"
                     "nada mal en ti o que eras un pecador o que tu sexualidad fuera algo\n"
                     "malo";
    mensaje = Cesar().Cifrado(mensaje);
    cout << "Cifrado: " << mensaje << endl;
    frecuencias(mensaje);
    mensaje = Cesar().Descifrado(mensaje);
    cout<<"\n\n\nDescifrado: "<<mensaje;


}
