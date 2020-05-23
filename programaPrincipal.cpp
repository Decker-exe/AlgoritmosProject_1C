
#include <iostream>
#include"biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

int main() {
    /* cout << "Ingresa un string" << endl;

     string s = "Z";
     cin >> s;
    
     int valor = 0;
     char c;
     string aux = "";
     int auxi = 0;

     for (int i = 0; s[i] != '\0'; i++) {
         aux = s[i];
         c = stringToChar(aux) - '@';
         valor = valor + c;
     }
     cout << valor << " valor " << endl;

     for (int i = digitCount(valor); i > 0; i--) {
         auxi = auxi + getDigit(valor, i);

     }
     cout << auxi << " auxi " << endl;
     */

    string s = "John|Paul|George|Ringo";
    char sep = '|';
    int pos = 0;
    string t = getTokenAt(s, sep, pos);
    cout << t << endl; // Salida: John
    pos = 1;
    t = getTokenAt(s, sep, pos);
    cout << t << endl; // Salida: Paul
    pos = 2;
    t = getTokenAt(s, sep, pos);
    cout << t << endl; // Salida: George
    pos = 3;
    t = getTokenAt(s, sep, pos);
    cout << t << endl; // Salida: Ringo
}