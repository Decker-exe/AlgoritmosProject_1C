#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> T read(FILE* f)
{
   // PROGRAMAR AQUI...
   T x;
   return x;
}

template<typename T> void write(FILE* f, T v)
{
   // PROGRAMAR AQUI...
}

template<typename T> void seek(FILE* f, int n)
{
   // PROGRAMAR AQUI...
}

template<typename T> long fileSize(FILE* f)
{
   // PROGRAMAR AQUI...
   return 0;
}

template<typename T> long filePos(FILE* f)
{
   // PROGRAMAR AQUI...
   return 0;
}

#endif
