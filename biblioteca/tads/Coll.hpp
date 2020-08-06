#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;
//====|TAD Coll|======

// TAD Coll= struct Coll + funciones collXxx.

//2.1) Estructura Coll
template<typename T>
struct Coll{

    string s;

    char sep;

    int pos;
};
//Funciones collXxx

//2.2) Crea una coleccion vacia,preparada para contener elementos de tipo T; utilizando el caracter c como separador de la cadena tokenizada sobre la que se implementa la coleccion.
template<typename T>
Coll<T> collCreate(char c){

    Coll<T> x;

    x.sep=c;

    x.pos=0;

    return x;
}
//2.3) Func collCreate(sobrecarg.) . Crea una coleccion vacia,preparada para contener elementos de tipo T;definiendo un separador por defecto para usar en la cadena tokenizada sobre la cual se implementa la coleccion.
template<typename T>
Coll<T> collCreate(){

    Coll<T> x;

    x.sep='|';

    x.pos=0;

    return x;
}

//2.4) Retorna la cantidad de elementos que contiene la coleccion c.
template<typename T>
int collSize(Coll<T> c){

    return tokenCount(c.s,c.sep);
}

//2.5) Remueve de la coleccion c todos sus elementos, dejándola vacía.
template<typename T>
void collRemoveAll(Coll<T>& c){

    c.s="";

    c.pos=0;
}

//2.6) Remueve de la coleccion c el elemento ubicado en la posición p.
template<typename T>
void collRemoveAt(Coll<T>& c,int p){
    removeTokenAt(c.s,c.sep,p);
}

//2.7) Retorna true o false segun queden, en la coleccion c, mas elementos para continuar iterando.
template<typename T>
bool collHasNext(Coll<T> c){

    int l=collSize(c);

    return c.pos<l? true: false;
}


//2.8) Retorna el proximo elemento de la coleccion c.

template<typename T>
string collNextString (Coll<T>& c){

    string x;

    x= getTokenAt(c.s, c.sep, c.pos++);

    return x;
}
//
template<typename T>
T collNext (Coll<T>& c,T tFromString(string)){

    string g=collNextString<T>(c);

    T x= tFromString(g);

    return x;
}
//

//2.9) Reinicia la coleccion c para que la podamos volver a iterar.
template<typename T>
void collReset(Coll<T>& c){

    c.pos=0;
}


//2.10) Agrega el elemento t al final de la coleccion c. Retorna la posición que ocupa el elemento recientemente agregado.
template<typename T>
int collAdd(Coll<T>& c,T t, string tToString(T)){

    addToken(c.s,c.sep,tToString(t));

    return collSize(c)-1;
}

template<typename T,typename K>
Coll<T> collAddColl(Coll<K>& c1,string s,char sep1){

    Coll<T> c2=collCreate<T>();

    int i,l=collSize<K>(c1);
    string reg;

    collReset<K>(c1);
    cout<<"--------"<<endl;
    cout<< "c1 long: "<<l<<endl;
    for(i=0;i<l;i++){

        reg=collNextString<K>(c1);

        reg=reg+sep1+getTokenAt(s,'|',i);

        cout<<reg<<endl;

        addToken(c2.s,c2.sep,reg);
    }

    return c2;
}

template<typename T>
string collAddRepetir(Coll<T> c,string rep){

    string s="";
    int l=collSize<T>(c);
    cout<< "RepetirSize: "<<l<<endl;

    for(int i=0; i<l; i++){

        addToken(s,c.sep,rep);
    }

    return s;
}


//2.11) Reemplaza por t al elemento que se ubica en la posicion p.
template<typename T>
void collSetAt( Coll<T>& c, T t, int p, string tToString(T)){

    setTokenAt(c.s,c.sep,tToString(t),p);
}

//2.12) Retorna el elemento que se ubica en la posicion p de la coleccion c.
template<typename T>
T collGetAt( Coll<T> c,int p,
             T tFromString(string) ){

    string elem;
    elem=getTokenAt(c.s, c.sep, p);

    T x= tFromString( elem );

    return x;
}

//2.13) Determina si la coleccion c contiene al elemento k. Retorna la posicion que ocupa la primera ocurrencia de k dentro de c o un valor negativo si c no contiene a k.
template<typename T,typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string)){
    int i;

    for( i=0; i<collSize(c);i++){

        T t=collGetAt<T>(c,i,tFromString);

        if( cmpTK(t,k)==0 ){

            return i;
        }
    }

    return -1;
}

//2.14) Ordena los elementos de la coleccion c segun el criterio de la precedencia que establece cmpTT.
template<typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string), string tToString(T)){

    int ordenar=1,l=collSize(c);
    string sig,ant;

    while( ordenar>0 ){

        ordenar=0;

        for(int i=0;i+1<l;i++){

            T a=collGetAt(c,i+1,tFromString);

            T b=collGetAt(c,i,tFromString);

            if( cmpTT(a,b)< 0 ){

                ordenar++;

                sig= getTokenAt(c.s,c.sep,i+1);

                ant=getTokenAt(c.s,c.sep,i);

                setTokenAt(c.s,c.sep,ant,i+1);

                setTokenAt(c.s,c.sep,sig,i);
            }
        }
    }
}
//
template<typename T>
void collMostrar(Coll<T> c){

    int i=0;
    string reg;

    cout<<"--------"<<endl;
    cout<<" tokens:"<<endl<<endl;

    collReset<T>(c);

    while(collHasNext<T>(c)){

        reg=collNextString<T>(c);

        cout<<i<<"> "<<reg<<endl;

        i++;
    }

    cout<<endl<<"Elementos Colección: "<<collSize<T>(c)<<endl;

    cout<<"-------------------------"<<endl;
}




//------Fin TAD Coll----
#endif
