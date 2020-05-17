
#include <iostream>

#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

int main() {
    string s = "Esto es una prueba";
    int p = lastIndexOf(s, 'E');
    cout << p << endl; // muestra: 5
}