#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> T read(FILE* f){
   T x;
   fread(&x,sizeof(T),1,f);
   return x;
}

template<typename T> void write(FILE* f, T v)
{
    fwrite(&v,sizeof(T),1,f);
}

template<typename T> void seek(FILE* f, int n){
   fseek(f,n*sizeof(T),SEEK_SET);
}

template<typename T> long fileSize(FILE* f){
    //seek<T>(f,SEEK_END);
    long aux =ftell(f);
    fseek(f,0,SEEK_END);
    long n=ftell(f)/sizeof(T);
    seek<T>(f,aux);
    return n;
}

template<typename T> long filePos(FILE* f){

    long n=ftell(f)/sizeof(T);
    return n;
}
#endif
