#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

//  API para el tratamiento de Archivos de registros.


// (1)Lee del archivo f (en la posicion en la que esta el contador de lugar) un valor de tipo T ( dado que usamos la funcion fread, tener en cuenta, que una vez leido el archivo, esta funcion incrementa el contador de posicion en un registro( pos=pos+1) ).
template<typename T>
T read(FILE *f) {
    T t;
    fread(&t, sizeof(T), 1, f);
    return t;
}


// (2) Graba en el archivo f el valor contenido en v ( dado que usamos la funcion fwrite, tener en cuenta, que una vez grabado el archivo, esta funcion incrementa el contador de posicion en un registro( pos=pos+1).
template<typename T>
void write(FILE *f, T v) {
    fwrite(&v, sizeof(T), 1, f);
}


// (3) Mueve el indicador de posicion hacia el registro n; considerando que el archivo tiene valores(o registros) de longitud sizeof(T).
template<typename T>
void seek(FILE *f, int n) {
    fseek(f, n * sizeof(T), SEEK_SET);
}

// (4) Retorna el numero de registro que esta siendo apuntado por el indicador de Posicion del archivo.
template<typename T>
long filePos(FILE *f) {
    return ftell(f) / sizeof(T);
}

// (5) Retorna la cantidad de registros que contiene archivo.
template<typename T>
long fileSize(FILE *f) {
    int n, aux = ftell(f);
    fseek(f, 0, SEEK_END);
    n = filePos<T>(f);
    seek<T>(f, aux);
    return n;
}

// (6) Busca un registro en el archivo cuyo valor clave coincida con k. El archivo debe estar ordenado por el campo clave.
template<typename T, typename K>
int fileBinarySearch(FILE *f, K k, int cmpTK(T, K)) {

    for (int i = 0; i < fileSize<T>(f); i++) {
        seek<T>(f, i);
        if (cmpTK(read<T>(f), k) == 0) { return i; }
    }
    return -1;
}

//(7)Muestra registros, uno a uno. Recibe el archivo abierto  y en modo de apertura: "r+b".
template<typename T>
void fileMostrar(FILE *f, void mostrarT(T)) {
    cout << endl << endl;
    cout << "B) Registros:" << endl;
    int aux = ftell(f);
    seek<T>(f, 0);

    T a = read<T>(f);

    while (!feof(f)) {
        mostrarT(a);
        a = read<T>(f);
    }
    seek<T>(f, aux);
    cout << "---------------" << endl;
    cout << "total registros: " << fileSize<T>(f) << endl;
}
//(8)Graba registros, uno a uno.El segundo argumento es un valor de registro para dejar de grabar. Recibe el archivo abierto y en modo de apertura: "w+b".
/*template<typename T>
void fileGrabarS(FILE* f,string& s,char sep)
{

   T reg;
for(int i=0;i<tokenCount(s,sep);i++)
    { write<T>(f,s[i]);}
} */
//
template<typename T>
void fileGrabarT(FILE *f, T fin, T introT(T), int cmpTT(T, T)) {
    T reg;

    cout << "A)Ingresar Registro/s: " << endl;

    reg = introT(reg);

    while (cmpTT(reg, fin) != 0) {
        write<T>(f, reg);
        reg = introT(reg);
    }
    cout << "total registros: " << fileSize<T>(f) << endl;
}

#endif
