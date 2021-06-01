#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <cmath>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ module(ZZ, ZZ);
int module_int(int, int);
ZZ empower(ZZ, int);
int recursive_Euclid(int, int );
int Euclid(int, int );
ZZ mcd(ZZ, ZZ);
ZZ Euclid_extended(ZZ, ZZ);
ZZ inverse(ZZ, ZZ);
ZZ modular_exponentiation(ZZ, ZZ, ZZ);
int random(int begin = 0, int end = 100);
vector<ZZ> criba_eratostenes(ZZ);
vector <ZZ> prime_bits(int);

//para RSA con bloques
string add_zeros(string, int);
void division_to_string(vector <string> &, string, int);
void division_to_int(vector <int> &, vector <string>);
string int_to_string(int);
int string_to_int(string);
