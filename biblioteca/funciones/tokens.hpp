#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

// --[Funciones Token]--

// s = "John|Paul|George|Ringo"
int tokenCount(string s,char sep) // ok
{
   return charCount(s,sep)+1;
}

// pablo|juan|pedro|carlos
string getTokenAt(string s,char sep, int p)  // ok
{
   return "";
}

void addToken(string& s,char sep,string t) // ok
{
}

void removeTokenAt(string& s,char sep, int p) //  ok
{
}

void setTokenAt(string& s,char sep, string t,int p) // ok
{
}

int findToken(string s,char sep, string t)
{
   return 0;
}

// --[/Funciones Token]--



#endif
