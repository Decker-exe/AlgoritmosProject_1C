#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>

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
    char sep = 2;
    string sIdEq=to_string(x.idEq);
    string sNombre=x.nombre;
    string sPuntos=to_string(x.puntos);
    return  sIdEq+sep+sNombre+sep+sPuntos;
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
Coll<REquipo> subirEquipos()
{
    Coll<REquipo> x;
    FILE* f = fopen("EQUIPOS.dat","r+b");

    Equipo e = read<Equipo>(f);
    while( !feof(f) )
    {
        REquipo re = { e, 0 };
        collAdd<REquipo>(x,re,requipoToString);
        e = read<Equipo>(f);
    }
    return x;
}

int cmpREquipoId(REquipo e, int id)
{
    return e.eq.idEq-id;
}




REquipo buscarEquipo(Coll<REquipo> c, int id)
{
    int pos = collFind<REquipo, int>(c,id,cmpREquipoId,requipoFromString);
    REquipo x = collGetAt<REquipo>(c,pos,requipoFromString);

    return x;
}



void actualizarPuntos(Coll<REquipo>& c, int id, int ptos)
{
    int pos = collFind<REquipo, int>(c,id,cmpREquipoId,requipoFromString);
    REquipo re = collGetAt<REquipo>(c,pos,requipoFromString);
    re.ptos += ptos;
    collSetAt<REquipo>(c,re,pos,requipoToString);
}

REstadio restadioFromString(string s)
{
    REstadio x;
    x.emp = stringToInt(getTokenAt(s,',',0));
    x.est = getTokenAt(s,',',1);
    x.jug = stringToInt(getTokenAt(s,',',3));
    return x;
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

void actualizarEstadio(Coll<REstadio>& c, string est, int empate)
{
    int pos = collFind<REstadio, string>(c,est,cmpREstadioEst,
                                         restadioFromString);

    if( pos<0 )
    {
        REstadio x = { est, 0, 0 };
        pos = collAdd<REstadio>(c,x,restadioToString);
    }

    REstadio re = collGetAt<REstadio>(c,pos,restadioFromString);
    re.jug++;
    re.emp += empate;
    collSetAt<REstadio>(c,re,pos,restadioToString);
}

int cmpREquipo(REquipo a, REquipo b)
{
    return (b.eq.puntos+b.ptos)-(a.eq.puntos+a.ptos);
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
void punto1(Coll<REquipo> c)
{
    collSort<REquipo>(c,cmpREquipo,requipoFromString,requipoToString);
    collReset<REquipo>(c);
    while( collHasNext<REquipo>(c) )
    {
        REquipo x = collNext<REquipo>(c,requipoFromString);
        cout<<rEquipoToDebug(x)<<endl;
    }
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
void punto2(Coll<REstadio> c)
{
    while(collHasNext<REstadio>(c))
    {
        REstadio e = collNext<REstadio>(c,restadioFromString);
        cout << rEstadioToDebug(e)<< endl;
    }
}

void punto3(Coll<REquipo> c)
{
    FILE* f = fopen("EQUIPOS.dat","r+b");

    collReset<REquipo>(c);
    while( collHasNext<REquipo>(c) )
    {
        REquipo x = collNext(c,requipoFromString);
        x.eq.puntos += x.ptos;
        write<Equipo>(f,x.eq);
    }

    fclose(f);
}

int main()
{
    int i=0;
    // subo consultas a memoria
    Coll<REquipo> cEq = subirEquipos();

    // subo consultas a memoria
    Coll<REstadio> cEst = collCreate<REstadio>();

    // barro novedades
    FILE* f = fopen("RESULTADOS.dat","r+b");

    Resultado r = read<Resultado>(f);
    while( !feof(f) || i<5 )
    {
        // equipos que jugaron
        REquipo e1 = buscarEquipo(cEq,r.idEq1);
        REquipo e2 = buscarEquipo(cEq,r.idEq2);

        int ptos1 = r.codRes<0?3:r.codRes==0?1:0;
        int ptos2 = r.codRes>0?3:r.codRes==0?1:0;

        // resuelvo punto 1 y 3
        actualizarPuntos(cEq,r.idEq1,ptos1);
        actualizarPuntos(cEq,r.idEq2,ptos2);

        // resuelvo punto 2
        string est = r.estadio;
        int empate = r.codRes==0?1:0;
        actualizarEstadio(cEst,est,empate);

        r = read<Resultado>(f);
        i++;
    }

    // tabla de posiciones
    punto1(cEq);

    // estadisticas x estadio
    punto2(cEst);

    // actualizar puntos
    punto3(cEq);

    fclose(f);
    return 0;
}