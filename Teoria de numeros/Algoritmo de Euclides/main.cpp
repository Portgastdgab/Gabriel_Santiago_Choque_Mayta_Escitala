#include <iostream>

using namespace std;

int modulo(int a, int n){
    int r = a-n*(a/n);
    r = r+(r<0)*n;
    return r;
}

/*int Euclides(int a, int b){
    if (modulo(a, b) == 0){
        return b;
    }
    else   {
        int temp = b;
        b = modulo(a, b);
        a = temp;
        Euclides(a,b);
    }

}*/

int Euclides(int a, int b){
    while (modulo(a, b) != 0){
        int temp = b;
        b = modulo(a, b);
        a = temp;
    }
    return b;

}

int main() {
    int mcd = Euclides(12, 8);
    cout << mcd;
}