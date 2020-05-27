
#include <iostream>
#include"biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/tads/Coll.hpp"

using namespace std;

int main() {
    /*
     * --Falta validacion ----
    cout << "Ingresa un string" << endl;
    string s = "Z";
    cin >> s;
    int valor = 0;
    string aux = "";
    int auxi = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        aux = s[i];
        valor = valor + stringToChar(aux) - '@';
    }
    cout << valor << " valor " << endl;

    for (int i = digitCount(valor); i > 0; i--) {
        auxi = auxi + getDigit(valor, i);
    }
    cout << auxi << " auxi " << endl;
     */
//anda
    string s = "John|Paul|George|Ringo";
    char sep = '|';
    string t = "Paul";
    int p = findToken(s,sep,t);
    cout << p << endl; // Salida: 1
    t = "John";
    p = findToken(s,sep,t);
    cout << p << endl; // Salida: 0

}