#include <iostream>
#include <string>
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


Coll<REquipo> subirEquipos()
{
    Coll<REquipo> x;
    return x;
}

REquipo buscarEquipo(Coll<REquipo> c,int id)
{
    REquipo x;
    return x;
}

REquipo requipoFromString(string s)
{
    REquipo x;
    return x;
}

int cmpREquipoId(REquipo e,int id)
{
    return 0;
}

string requipoToString(REquipo x)
{
    return "";
}

void actualizarPuntos(Coll<REquipo>& c,int id,int ptos)
{
    int pos = collFind<REquipo,int>(c,id,cmpREquipoId,requipoFromString);
    REquipo re = collGetAt<REquipo>(c,pos,requipoFromString);
    re.ptos+=ptos;
    collSetAt<REquipo>(c,re,pos,requipoToString);
}

REstadio restadioFromString(string s)
{
    REstadio x;
    return x;
}

int cmpREstadioEst(REstadio e,string est)
{
    return 0;
}

string restadioToString(REstadio e)
{
    return "";
}

void actualizarEstadio(Coll<REstadio>& c,string est,int empate)
{
    int pos = collFind<REstadio,string>(c,est,cmpREstadioEst,restadioFromString);

    if( pos<0 )
    {
        REstadio x = {est,0,0};
        pos = collAdd<REstadio>(c,x,restadioToString);
    }

    REstadio re = collGetAt<REstadio>(c,pos,restadioFromString);
    re.jug++;
    re.emp+=empate;
    collSetAt<REstadio>(c,re,pos,restadioToString);
}

int cmpREquipo(REquipo a,REquipo b)
{
    return b.ptos-a.ptos;
}

void punto1(Coll<REquipo> c)
{
    collSort<REquipo>(c,cmpREquipo,requipoFromString,requipoToString);
    collReset<REquipo>(c);
    while( collHasNext<REquipo>(c) )
    {
        REquipo x = collNext<REquipo>(c,requipoFromString);
        cout << requipoToString(x) << endl;
    }
}

void punto2(Coll<REstadio> c)
{
}

void punto3(Coll<REquipo> c)
{
    FILE* f = fopen("EQUIPOS.dat","r+b");

    collReset<REquipo>(c);
    while( collHasNext<REquipo>(c) )
    {
        REquipo x  = collNext(c,requipoFromString);
        x.eq.puntos+=x.ptos;
        write<Equipo>(f,x.eq);
    }

    fclose(f);
}

int main()
{
    // subo consultas a memoria
    Coll<REquipo> cEq = subirEquipos();

    // subo consultas a memoria
    Coll<REstadio> cEst = collCreate<REstadio>();

    // barro novedades
    FILE* f = fopen("RESULTADOS.dat","r+b");

    Resultado r = read<Resultado>(f);
    while( !feof(f) )
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