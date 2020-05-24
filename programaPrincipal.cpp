
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

    string s = "";
    char sep = '|';
    addToken(s, sep, "John");
    cout << s << endl; // Salida: John
    addToken(s, sep, "Paul");
    cout << s << endl; // Salida: John|Paul
    addToken(s, sep, "George");
    cout << s << endl; // Salida: John|Paul|George
    addToken(s, sep, "Ringo");
    cout << s << endl; // Salida: John|Paul|George|Ringo
}