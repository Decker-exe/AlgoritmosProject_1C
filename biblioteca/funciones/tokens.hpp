#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"

using namespace std;

// --[Funciones Token]--

// s = "John|Paul|George|Ringo"

int tokenCount(string s, char sep) {

    return charCount(s, sep) + 1;
}

// pablo|juan|pedro|carlos

string getTokenAt(string s, char sep, int p) {
    //igual en addToken ,no uso esta funcion

    return p == 0 ? substring(s, 0, indexOf(s, sep)) : p == tokenCount(s, sep) - 1 ? substring(s,
                                                                                               lastIndexOf(s, sep) + 1)
                                                                                   : substring(s,
                                                                                               indexOfN(s, sep, p) + 1,
                                                                                               indexOfN(s, sep, p + 1));


    /*
        if (p == 0) {
            return substring(s, 0, indexOf(s, sep));
        } else {
            if (p == tokenCount(s, sep)-1) {
                return substring(s, lastIndexOf(s, sep) + 1);
            }
            return substring(s, indexOfN(s, sep, p) + 1, indexOfN(s, sep, p + 1));
        }
     */

}

void addToken(string &s, char sep, string t) {
    if (isEmpty(s)) {
        s = t;
    } else {
        s = s + sep + t;
    }
}

void removeTokenAt(string &s, char sep, int p) {
    //a que hora volvemos?

    if (p == 0) {//inicio
        s = substring(s, indexOf(s, sep) + 1);
    } else {
        if (p == tokenCount(s, sep) - 1) {//final
            s = substring(s, 0, lastIndexOf(s, sep));
        } else {//medio
            //donde?
            s = substring(s, 0, indexOfN(s, sep, p)) + substring(s, indexOfN(s, sep, p + 1));
            //s = substring(s, indexOfN(s, sep, p) + 1, indexOfN(s, sep, p + 1));
        }


    }


}

void setTokenAt(string &s, char sep, string t, int p) {
    //

    if (p == 0) {//inicio

        removeTokenAt(s, sep, p);
        s = t + sep + s;

    } else {
        if (p == tokenCount(s, sep) - 1) {//final
            removeTokenAt(s, sep, p);
            addToken(s, sep, t);
        } else {

            s = substring(s, 0, indexOfN(s, sep, p)) + sep + t + substring(s, indexOfN(s, sep, p + 1));
        }

    }


}

int findToken(string s, char sep, string t) {
    //
    int token = -1;
    for (int i = 0; i < tokenCount(s, sep); i++) {
        if(getTokenAt(s,sep,i)==t){
            token=i;
        }
    }
    return token;
}

// --[/Funciones Token]--



#endif
