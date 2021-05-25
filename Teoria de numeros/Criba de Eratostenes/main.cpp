#include <iostream>
#include <vector>

using namespace std;

vector<int> criba_eratostenes(int limit)
{
    vector<int> criba;
    int prime_found;  // primos que se vayan encontrando

    // llenando el vector desde 2 hasta limit
    for (int i = 2; i <= limit; i++)
        criba.push_back(i);

    if (limit == 2 || limit == 3)
        return criba;

    // iteradores para la seleccion
    vector<int>::iterator it = criba.begin();
    vector<int>::iterator it2;
    prime_found = *it;  // El primer primo es 2

    while (prime_found*prime_found < limit)
    {
        it2 = it + 1;

        for(; it2 <= criba.end(); it2++) //Borra multiplos de los primos hallados
            if(*it2 % prime_found == 0)
                criba.erase(it2);
        it++;
        prime_found = *it;
    }

    return criba;
}

int main()
{
    vector<int> num_primos;
    num_primos = criba_eratostenes(20);

    for (int i = 0; i < num_primos.size(); i++)
        cout << num_primos[i] << "\t";

}
