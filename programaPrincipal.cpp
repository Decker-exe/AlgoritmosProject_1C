
#include <iostream>
#include"biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/tads/Coll.hpp"

using namespace std;
struct BigInt {
    string s;
};
BigInt bigIntCreate(string n) {
    BigInt v = {n};
    //v.s = n;
    return v;
}
BigInt bigIntSumar(BigInt a,BigInt b){
    int r;
    BigInt valor;
    r=stringToInt(a.s)+stringToInt(b.s);
    valor.s=intToString(r);
    return valor;
}
BigInt bigIntRestar(BigInt a,BigInt b){
    int r;
    BigInt valor;
    r=stringToInt(a.s)-stringToInt(b.s);
    valor.s=intToString(r);
    return valor;
}

int main() {
    /*
     * --EJ1----
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
    /*
     --EJ2----
    string s = "Pedro,2-oct-1970,Argentino|Juan,9-dic-1985,Chileno|Pablo,14-ene-1992,Argentino";
    char sep = '|';
    char sep2 = ',';
    int j = 0;
    for (int i = 0; i < tokenCount(s, sep); i++) {
        cout << "nombre: " << getTokenAt(getTokenAt(s, sep, j), sep2, 0) << endl;
        cout << "Fecha de Nacimiento: " << getTokenAt(getTokenAt(s, sep, j), sep2, 1) << endl;
        cout << "Nacionalidad: " << getTokenAt(getTokenAt(s, sep, j), sep2, 2) << endl;
        cout << "-----------------------------------" << endl;
        j++;
    }

 */
    /*
     ---EJ3---
    string s = "15";
    BigInt a =bigIntCreate(s);
    BigInt b =bigIntCreate(s);
    BigInt r= bigIntRestar(a,b);
    BigInt z= bigIntSumar(a,b);
    cout << r.s << endl;
    cout << z.s << endl;
*/

}