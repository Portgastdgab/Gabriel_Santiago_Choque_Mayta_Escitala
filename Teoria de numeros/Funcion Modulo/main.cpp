#include <iostream>
using namespace std;

void division(int a, int n){
   int r = a-n*(a/n); //Halla el residuo sin necesidad de usar modulo "%"
   int q = a/n - (r<0); //Si r es un numero negativo, a q le resto 1
   r = a-q*n; //Vuelvo a hallar el residuo por si r antes era negativo
   cout<<"q: "<<q<<endl;
   cout<<"r: "<<r;
}

int main() {
   division(-299,11);
}

