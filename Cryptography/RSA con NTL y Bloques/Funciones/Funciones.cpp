#include "Funciones.h"

ZZ module(ZZ a, ZZ n){
    ZZ r = a-n*(a/n);
    r = r+(r<0)*n;
    return r;
}

int module_int(int a, int n){
    int r = a-n*(a/n);
    r = r+(r<0)*n;
    return r;
}

ZZ empower(ZZ a, int x){
    ZZ b = ZZ(x);
    ZZ reply = a;
    for(ZZ i = ZZ(1); i < b; i++){
        reply = a*reply;
    }
    return reply;
}

ZZ Euclid(ZZ a, ZZ b){
    while (module(a, b) != ZZ(0)){
        ZZ temp = b;
        b = module(a, b);
        a = temp;
    }
    return b;
}

ZZ mcd(ZZ a, ZZ b){
    return Euclid(a, b);
}

ZZ Euclid_extended(ZZ a, ZZ b) {
    int cont = 0;
    ZZ temp1 = a;
    ZZ temp2 = b;
    while (module(a, b) != ZZ(0)) {
        ZZ temp = b;
        b = module(a, b);
        a = temp;
        cont++;
    }
    cont = cont + 2;
    ZZ g[cont];
    g[0] = temp1;
    g[1] = temp2;

    ZZ y[cont], u[cont], v[cont];
    u[0] = 1, u[1] = 0, v[0] = 0, v[1] = 1;
    for (int i = 1;; ++i) {
        y[i + 1] = g[i - 1] / g[i];
        g[i + 1] = g[i - 1] - (y[i + 1] * g[i]);
        u[i + 1] = u[i - 1] - (y[i + 1] * u[i]);
        v[i + 1] = v[i - 1] - (y[i + 1] * v[i]);
        if (g[i + 1] == 0) {
            //cout<<"Valor de x: "<<u[i]<<endl;
            //cout<<"Valor de y: "<<v[i]<<endl;
            return module(u[i], g[1]);
        }
    }
}

ZZ inverse(ZZ a, ZZ b){
    return Euclid_extended(a, b);
}

ZZ modular_exponentiation(ZZ base, ZZ exponent, ZZ mod){
    ZZ reply = base;
    exponent/=2;
    while (exponent != ZZ(0)){
        base = module(base*base, mod);
        if (module(exponent, ZZ(2)) != ZZ(0)){
            reply = module(reply*base, mod);
        }
        exponent/=2;
    }
    return reply;
}

int random(int begin, int end) {
    srand(time(NULL));
    return begin + rand() % (end - begin);
}

vector <ZZ> criba_eratostenes(ZZ limit)
{
    vector<ZZ> criba;
    ZZ prime_found;  // primos que se vayan encontrando

    // llenando el vector desde 2 hasta limit
    for (ZZ i = ZZ(2); i <= limit; i++)
        criba.push_back(i);

    if (limit == ZZ(2) || limit == ZZ(3))
        return criba;

    // iteradores para la seleccion
    vector<ZZ>::iterator it = criba.begin();
    vector<ZZ>::iterator it2;
    prime_found = *it;  // El primer primo es 2

    while (prime_found*prime_found < limit)
    {
        it2 = it + 1;

        for(; it2 <= criba.end(); it2++) //Borra multiplos de los primos hallados
            if(module(*it2, prime_found) == 0)
                criba.erase(it2);
        it++;
        prime_found = *it;
    }

    return criba;
}


vector <ZZ> prime_bits(int bit){ //devuelve los elementos primos segun el numero de bits que pide
    vector <ZZ> primos = criba_eratostenes(empower(ZZ(2), bit)-ZZ(1));
    vector<ZZ>::iterator it = primos.begin();
    while (*it < empower(ZZ(2), bit)/ZZ(2)){
        primos.erase(it);
    }
    return primos;
}

string add_zeros(string mssg, int tamano){ //añade ceros segun el tamaño del string q se desea
    for (int j = mssg.size(); j < tamano; ++j) {
        mssg.insert(0, "0");
    }
    return mssg;
}

void division_to_string(vector <string> &div, string mssg, int tamano){ //divide un string en bloques segun el tamaño
    string repos;
    for (int i = 0; i < mssg.size(); ) {
        repos = "";
        for (int j = 0; j < tamano; ++j) {
            repos.push_back(mssg[i]);
            i++;
        }
        div.push_back(repos);
    }
}

void division_to_int(vector <int> &div, vector <string> divided){
    for (int i = 0; i < divided.size(); ++i) {
        div.push_back(string_to_int(divided[i]));
    }
}

string int_to_string(int num){
    string cad(to_string(num));
    return cad;
}

int string_to_int(string cad){
    int num = atoi(cad.c_str());
    return num;
}
