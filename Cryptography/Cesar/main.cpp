#include "Cifrado_Descifrado.h"
#include "Criptoanalisis_frecuencias.h"

int main() {
    string mensaje = "deja ya de estar rezando y dandote golpes en el pecho lo que quiero que hagas es que salgas al mundo a disfrutar de tu vida quiero que goces que cantes que te diviertas y que disfrutes de todo";
    int clave = 16;
    mensaje = Cesar().Emisor(mensaje, clave);
    cout << "Cifrado: " << mensaje << endl;
    mensaje = frecuencias(mensaje);
    //mensaje = Cesar().Receptor(mensaje, clave);
    cout<<"\n\n\nDescifrado: "<<mensaje;
}
