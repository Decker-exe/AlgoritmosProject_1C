#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;

template<typename T>
struct Coll {
    string s;
    char sep;
    T elem;
    int pos;
};

// collCreate

template<typename T>
Coll<T> collCreate(char c) {
    Coll<T> x;
    x.sep = c;
    x.pos - 1;
    return x;
}

template<typename T>
Coll<T> collCreate() {
    Coll<T> x;
    x.sep = '|';
    return x;
}


template<typename T>
int collSize(Coll<T> c) {
    return tokenCount(c.s, c.sep);
}

template<typename T>
void collRemoveAll(Coll<T> &c) {
    c.s = "";
    c.pos - 1;
}

template<typename T>
void collRemoveAt(Coll<T> &c, int p) {
    removeTokenAt(c.s, c.sep, p);
}


// -- [GENERICAS] --
template<typename T>
bool collHasNext(Coll<T> c) {
    bool v = true;
    if (c.pos + 1 < collSize(c)) {
        v = false;
    }
    return v;
}

template<typename T>
T collNext(Coll<T> &c, T tFromString(string)) {
    cout << c.pos << endl;
    T t = tFromString(getTokenAt(c.s, c.sep, c.pos + 1));
    c.pos = c.pos + 1;
    cout << c.pos << endl;
    return t;
}

template<typename T>
void collReset(Coll<T> &c) {
    c.pos = -1;
}

template<typename T>
int collAdd(Coll<T> &c, T t, string tToString(T)) {
    addToken(c.s, c.sep, tToString(t));
    return collSize(c) - 1;
}

template<typename T>
void collSetAt(Coll<T> &c, T t, int p, string tToString(T)) {
    setTokenAt(c.s, c.sep, tToString(t), p);
}

template<typename T>
T collGetAt(Coll<T> c, int p, T tFromString(string)) {
    T x = tFromString(getTokenAt(c.s, c.sep, p));

    return x;
}

template<typename T, typename K>
int collFind(Coll<T> c, K k, int cmpTK(T, K), T tFromString(string)) {
    for (int i = 0; i < collSize(c); i++) {
        if (cmpTK(tFromString(getTokenAt(c.s, c.sep, i)), k) == 0) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void collSort(Coll<T> &c, int cmpTT(T, T), T tFromString(string), string tToString(T)) {

    int ordenar = 1, i;
    string aux;
    while (ordenar > 0) {
        ordenar = 0;
        for (i = 0; i + 1 < collSize(c); i++) {
            T a = collGetAt(c, i + 1, tFromString);
            T b = collGetAt(c, i, tFromString);

            if (cmpTT(a, b) < 0) {
                ordenar++;
                aux = getTokenAt(c.s, c.sep, i + 1);
                setTokenAt(c.s, c.sep, getTokenAt(c.s, c.sep, i), i + 1);

                setTokenAt(c.s, c.sep, aux, i);
            }
        }
    }
}

#endif
