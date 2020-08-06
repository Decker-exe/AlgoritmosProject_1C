#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
//stringxxx
using namespace std;

//0) funciones auxiliares
double potencia(int b,int  p)
{  double j=1;
    int aux;
    if(p<0)
    {aux=-p;}
    else
    {aux=p;}
    for(int i=1; i<=aux; i++)
    { j=j*b; }
    if(p<0)
    {j=1/j;}
    return j;
}

//1)Longitud cadena.
int length(string s){

    int i;

    for(i=0; s[i]!='\0';i++){
    }

    return i;
}
//2)Cant. repeticiones caracter.
int charCount(string s,char sep){

    int c=0;

    for(int i=0; i<length(s);i++){

        if( s[i]==sep){

            c++;
        }
    }

    return c;
}
//3) subcadena desde d (inclusive) hasta h (sin incluir).
string substring(string s,int d,int h){

    string p="";

    for(int i=0;i<length(s);i++){

        if(d<=i and i<h){

            p=p+s[i];
        }
    }

    return p;
}
// 4)Retorna la subcadena de s que va desde d (inclusive) hasta el final.
string substring(string s,int d){

    return substring(s,d,length(s));
}

// 5)Retorna la posicion de la primer ocurrencia de c dentro s,  o  -1 si s no contiene a c.
int indexOf(string s,char c){

    int i, l=length(s);

    for(i=0; s[i]!=c and i<l;i++){
    }

    return i==l? -1: i;
}

// 6)Retorna la posicion de la primer ocurrencia de c dentro de s considerando la subcadena de s que va desde  x  hasta el final.Ejemplo: indexOf("ALGORITMOS",'O',7) retorna: 1
int indexOf(string s,char c,int x){

    return indexOf(substring(s,x),c);
}

// 7)Retorna la posicion de la ultima ocurrencia de c dentro de s, o  -1 si s no contiene a c.
int lastIndexOf(string s,char c)
{
    int i, l=length(s);

    for(i=l; s[i]!=c and i>=0;i--){
    }

    return i;
}

// 8)Retorna la posicion de la n-esima ocurrencia de c dentro de s. Por ejemplo: indexOfN ("pedro|pablo|juan|rolo",'|',2) retorna 11.
int indexOfN(string s,char c,int n){

    int i, aux=0;

    for( i=0; aux<n; i++){

        if(s[i]==c){

            aux++;
        }
    }

    return i-1;
}

//9) Retorna el valor numerico de ch. Ejemplo: charToInt('4') retorna: 4.
int charToInt(char ch){

    int n;

    n=ch-48;//'0'=48,'1'=49 a '9'=57

    return n;// o (int)ch-48;
}

//10) Retorna el valor char de i. Ejemplo: intToChar(4) retorna: '4'.
char intToChar(int i){

    char c;

    c=48+i;

    return c;
}

//11) retorna el i-esimo digito de n contando desde la derecha
int getDigit(int n,int i){

    int m=1, rest;

    for(int j=0;j<i;j++){

        rest=n%(m*10);

        rest=rest/m;

        m=m*10;
    }

    return rest;
}
//12) Cantidad de digitos
int digitCount(int i){

    int m=1,j,rest=i-1;

    if(i<0){

        i=-i;
    }

    for(j=0;i!=rest;j++){

        rest=i%(m*10);

        m=m*10;
    }

    return j;
}

//13)
string intToString(int num){

    string s="";
    int d=digitCount(num);

    for( int i=0; i<d; i++){

        s=intToChar( getDigit(num,i+1))+ s; }

    return s;
}

//14)
int stringToInt(string s){

    int n=0, j=1;
    char c;

    for(int i=0; i<length(s); i++){

        c=s[length(s)-1-i];

        n=n+charToInt(c)*j;

        j=j*10;
    }

    return n;
}
//15)
int stringToInt(string s, int b)
{
    // PROGRAMAR AQUI...
    return 0;
}
//16)
string charToString(char c){

    string s;

    return s=c;
}
//17)
char stringToChar(string s){

    char c;

    return c=s[0];
}

//18)
void stringToCharArray(string s, char array[]){

    //pasaje de string (xej:con el nom del Archivo) a char array.

    strcpy( array,s.c_str());
}

//19)
string stringToString(string s){

    return s;
}
//20)
string doubleToString(double d){

    int a=d;
    string s;

    int b=(d-a+0.0000000001)*1000000000;
    for( int i=1; b%10==0;i++){

        b=b/10;
    }

    s=intToString(a)+"."+intToString(b);
    return s;
}
//21)
double stringToDouble(string s){

    string x,y;
    int a,b;
    double d;

    x=substring(s,0,indexOf(s,'.'));

    a=stringToInt(x);

    y=substring(s,indexOf(s,'.')+1);

    b=stringToInt(y);

    d=b;

    d=a+(d/potencia(10, length(y)));

    return d;
}
//22)Informa si la cadena s contiene o no a la cadena vacia.
bool isEmpty(string s){

    return length(s)==0? true: false;
}

//23)Determina si la cadena s contiene el caracter c.
bool contains(string s, char c){

    return charCount(s,c)>0?true:false;}

//24)Reemplaza en s todas las ocurrencias de oldChar por newChar
string replace(string s, char oldChar, char newChar){

    for(int i=0; i<length(s); i++){

        if(s[i]==oldChar){

            s[i]=newChar;
        }
    }

    return s;
}

//25)Inserta el caracter c en la posicion pos de la cadena s.
string insertAt( string s, int pos,  char c){

    string z="";
    int i, l=length(s);

    for( i=0; i<l+1; i++){

        if(i<pos){

            z+=s[i];
        }
        else{

            if(i==pos){

                z+=c;
            }
            else{

                z+=s[i-1];
            }
        }
    }

    return z;
}

//26)Remover de s el caracter ubicado en la posicion pos.
string removeAt(string s, int pos){

    for(int i=pos; s[i-1]!='\0';i++){

        s[i]=s[i+1];
    }

    return s;
}

//    string z="";
//    for( int i=0; i<length(s)-1; i++)
//   {   if(i<pos)
//       { z+=s[i]; }
//        else
//       {  z+=s[i+1]; }
//     }
// return z;


//27)Recorta los espacios en blanco a la izquierda de s.
string ltrim(string s){

    while( s[0]==' '){

        s=removeAt(s,0);
    }

    return s;
}

//28)Recorta los espacios en blanco a la derecha de s.
string rtrim(string s){

    while( s[ length(s)-1]==' '){

        s=removeAt(s, length(s)-1);
    }

    return s;
}

//29)Recorta los espacios en blanco a la izquierda y derecha de s.
string trim(string s){

    s=ltrim(s);

    return s=rtrim(s);
}

//30)Genera una cadena de caracteres compuesta por n caracteres c.
string replicate(int n, char c){

    string s="";

    for( int pos=0; pos<n; pos++){

        s=insertAt(s, pos, c);
    }

    return s;
}

//31)Genera una cadena de caracteres compuesta por n caracteres '  ' (caracter espacio)
string spaces(int n){

    string z=replicate( n, ' ');

    return z;
}

//32) Retorna una cadena identica a s, con longitud n completando, si fuese necesario, con caracteres c a la izquierda hasta llegar a la longitud requerida.
string lpad(string s,int n,char c){

    while( length(s)<n ){

        s=insertAt( s, 0, c);
    }

    return s;
}

//33) Idem a lpad pero, de ser necesario, agrega caracteres c a la derecha.
string rpad(string s,int n,char c){
    while(  length(s)<n ){

        s=insertAt( s, length(s), c);
    }

    return s;
}

//34) Idem a rpad pero distribuye los caracteres de c a izq. y derecha.
string cpad(string s, int n, char c)
{  for( int i=1; length(s)<n; i++)
    {   if(i%2==0)
        { s=rpad( s, length(s)+1, c);  }
        else
        { s=lpad( s, length(s)+1, c); }
    }
    return s;
}

//35) Determina si el valor de c corresponde o no a un digito numérico.
bool isDigit(char c)
{return c>=48 and c<=57?true:false;}

//36) Determina si el valor de c corresponde o no a una letra.
bool isLetter(char c)
{ return (c>=65 and c<=90) or (c>=97 and c<=122)?true:false;
}

//37) Determina si el valor de c corresponde a una letra mayúscula.
bool isUpperCase(char c)
{return c>=65 and c<=90?true:false;}

//38) Determina si el valor de c corresponde a una letra minuscula.
bool isLowerCase(char c)
{return c>=97 and c<=122?true:false;}

//39) Convertir el valor de c a mayuscula.
char toUpperCase(char c)
{return isLowerCase(c)?c=c-32:c;}

//40) Convertir el valor de c a minuscula.
char toLowerCase(char c)
{return isUpperCase(c)?c=c+32:c;}


#endif
