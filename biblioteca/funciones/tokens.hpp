#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

// --[Funciones Token]--

// s = "John|Paul|George|Ringo"

int tokenCount(string s, char sep) // ok
{
    return charCount(s, sep) + 1;
}

// pablo|juan|pedro|carlos

string getTokenAt(string s, char sep, int p) // ok
{
    return p == 0 ? substring(s, 0, indexOf(s, sep)) : p == tokenCount(s, sep) - 1 ? substring(s, lastIndexOf(s, sep) + 1) : substring(s, indexOfN(s, sep, p) + 1, indexOfN(s, sep, p + 1));


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

void addToken(string& s, char sep, string t) // ok
{
}

void removeTokenAt(string& s, char sep, int p) //  ok
{
}

void setTokenAt(string& s, char sep, string t, int p) // ok
{
}

int findToken(string s, char sep, string t) {
    return 0;
}

// --[/Funciones Token]--



#endif
