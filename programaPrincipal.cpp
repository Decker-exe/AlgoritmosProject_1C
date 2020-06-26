#include <iostream>
#include"biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "biblioteca/funciones/files.hpp"
#include <stdio.h>

using namespace std;

/*
 * template<typename T>
string tToString(T a) {
    return a;
}
struct BigInt {
    string s;
};

BigInt bigIntCreate(string n) {
    BigInt v = {n};
    //v.s = n;
    return v;
}

BigInt bigIntSumar(BigInt a, BigInt b) {
    int r;
    BigInt valor;
    r = stringToInt(a.s) + stringToInt(b.s);
    valor.s = intToString(r);
    return valor;
}

BigInt bigIntRestar(BigInt a, BigInt b) {
    int r;
    BigInt valor;
    r = stringToInt(a.s) - stringToInt(b.s);
    valor.s = intToString(r);
    return valor;
}

struct Matriz {
    string s;
    int filas;
    int columnas;
};

Matriz matrizCreate(int n, int m) {
    Matriz mat;
    mat.columnas = m;
    mat.filas = n;
    return mat;
}

Matriz matrizCreate(string x, int n, int m) {

    int mat[n][m];
    int aux = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int i = 0; x[i] != '\0'; i++) {
                aux = x[i];
                mat[i][j] = aux;
            }
        }
    }

}
*/
struct Elemento {
    string subR;
    string pos;
};

template<typename T>
void mostrarFile(FILE *arc) {
    T a = read<T>(arc);
    while (!feof(arc)) {
        cout << a << endl;
        a = read<T>(arc);

    }
}

template<typename T>
void grabarFile(FILE *arc, T sep) {
    T reg;
    cout << "Ingrese registro: " << endl;
    cin >> reg;
    while (reg != sep) {
        write<T>(arc, reg);
        cout << "Ingrese registro: " << endl;
        cin >> reg;
    }
}

int cmp1(string a,string b){
    return stringToInt(a)-stringToInt(b);
}
template<typename T>
void mayor(FILE *arc, Elemento mayor) {
    mayor.pos="";
    mayor.subR="";
    string aux = "";
    T reg;
    T sep=',';
    for (int i = 0; i < fileSize<T>(arc); i++) {
        seek<T>(arc, i);
        reg = read<T>(arc);
        if (i== fileSize<T>(arc)-1 ){
            aux=aux+reg;
        }
        if (reg!=sep && i!=fileSize<T>(arc)-1 ){
            aux=aux+reg;
        } else{
           if(i-length(aux)==0){
               mayor.subR=aux;
           }
           if (cmp1(aux,mayor.subR)>=0){
               if(mayor.subR!=aux){
                   mayor.pos="";
               }
               mayor.subR=aux;
               addToken(mayor.pos,sep,intToString(i-1));
           }
            aux="";
        }
    }
    cout<<"mayor :  "<< mayor.subR<<endl;
    cout<<"may pos  "<<mayor.pos<<endl;
}

int main() {

    FILE *arc = fopen("Ej2.xx", "r+b");
    mostrarFile<char>(arc);
    Elemento may;
    mayor<char>(arc, may);
    fclose(arc);


    /*
    //FILE *arc = fopen("archivo.xx", "w+b");
    //grabarFile<int>(arc,123);
    //fclose(arc);
    FILE *arc2 = fopen("archivo.xx", "r+b");
    mostrarFile<int>(arc2);
    cout<<read<int>(arc2)<<endl;
    cout<<"FilePos antes 0: "<<filePos<int>(arc2)<<endl;
    seek<int>(arc2,0);
    cout<<"FilePos despues 0 :"<<filePos<int>(arc2)<<endl;
    cout<<"nuevo : "<<read<int>(arc2)<<endl;
    cout<<"FilePos 2"<<filePos<int>(arc2)<<endl;
    seek<int>(arc2,2);
    cout<<"nuevo 2 : "<<read<int>(arc2)<<endl;
    cout<<fileSize<int>(arc2)<<endl;
    fclose(arc2);
*/
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
    /*
    Coll<int> x = collCreate<int>();
    collAdd<int>(x, 1, intToString);
    collAdd<int>(x, 2, intToString);
    collAdd<int>(x, 3, intToString);
    cout << getTokenAt(x.s, x.sep, 0) << endl;
    cout << getTokenAt(x.s, x.sep, 1) << endl;
    cout << getTokenAt(x.s, x.sep, 2) << endl;
    collSetAt<int>(x, 9, 1, intToString);
    cout << getTokenAt(x.s, x.sep, 0) << endl;
    cout << getTokenAt(x.s, x.sep, 1) << endl;
    cout << getTokenAt(x.s, x.sep, 2) << endl;
*/
}