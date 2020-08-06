#include <iostream>
#include <sstream>
#include <string>
#include <string.h>

#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;
struct Resultado
{
    int idEq1;
    int idEq2;
    int codRes;
    char estadio[20];
};

struct Equipo
{
    int idEq;
    char nombre[20];
    int puntos;
};

struct REquipo
{
    Equipo eq;
    int ptos;
};

struct REstadio
{
    string est;
    int jug;
    int emp;
};

string equipoToString(Equipo x)
{
    char sep = ',';
    string sIdEq=to_string(x.idEq);
    string sNombre=x.nombre;
    string sPuntos=to_string(x.puntos);
    return  sIdEq+sep+sNombre+sep+sPuntos;
}
string resultadoToString(Resultado x)
{
    char sep = ',';
    string sIdEq1=to_string(x.idEq1);
    string sIdEq2=to_string(x.idEq2);
    string scodRes=to_string(x.codRes);
    string sNombre=x.estadio;
    return  sIdEq1+sep+sIdEq2+sep+scodRes+sep+sNombre;
}
string requipoToString(REquipo x)
{
    char sep = 3;
    string sEq=equipoToString(x.eq);
    string sPtos=to_string(x.ptos);
    return sEq+sep+sPtos;
}

Equipo equipoFromString(string s)
{
    char sep = 2;
    Equipo x;
    string t0 = getTokenAt(s,sep,0);
    x.idEq=stringToInt(t0);
    string t1 = getTokenAt(s,sep,1);
    strcpy(x.nombre,t1.c_str());
    string t2 = getTokenAt(s,sep,2);
    x.puntos=stringToInt(t2);
    return x;

}

REquipo requipoFromString(string s){

    char sep = 3;
    REquipo x;
    string t0 = getTokenAt(s,sep,0);
    x.eq=equipoFromString(t0);
    string t1 = getTokenAt(s,sep,1);
    x.ptos=stringToInt(t1);
    return x;
}
int cmpREquipoId(REquipo e, int id)
{
    return e.eq.idEq-id;
}
int cmpREstadioEst(REstadio e, string est)
{

    return e.est==est?0:-1;
}

string restadioToString(REstadio e)
{
    string jugados = intToString(e.jug);
    string empatados = intToString(e.emp);
    string estadio = e.est;

    return jugados+", "+estadio+", "+empatados;
}
string equipoToDebug(Equipo x)
{
    stringstream sout;
    sout<< "[";
    sout << x.idEq;
    sout << ",";
    sout << x.nombre;
    sout << ",";
    sout << x.puntos;
    sout<< "]";
    return sout.str();
}
string rEquipoToDebug(REquipo x)
{
    stringstream sout;
    sout<< "[";
    sout << equipoToDebug(x.eq);
    sout << ",";
    sout << x.ptos;
    sout<< "]";
    return sout.str();
}
int cmpREquipo(REquipo a, REquipo b)
{
    return (b.eq.puntos+b.ptos)-(a.eq.puntos+a.ptos);
}
string rEstadioToDebug(REstadio x)
{
    stringstream sout;
    sout<< "[";
    sout << x.est;
    sout << ",";
    sout << x.jug;
    sout << ",";
    sout << x.emp;
    sout<< "]";
    return sout.str();
}
REstadio restadioFromString(string s)
{
    REstadio x;
    x.emp = stringToInt(getTokenAt(s,',',0));
    x.est = getTokenAt(s,',',1);
    x.jug = stringToInt(getTokenAt(s,',',3));
    return x;
}
