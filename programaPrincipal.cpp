#include <iostream>
#include <string>
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "Futbol.hpp"
using namespace std;

Coll<REquipo> subirEquipos(){
    Coll<REquipo> x=collCreate<REquipo>();
    FILE* f = fopen("EQUIPOS.dat","r+b");
    REquipo re;
    re.ptos=0;
    Equipo e = read<Equipo>(f);
    while( !feof(f) ){
        re.eq = e;
        collAdd<REquipo>(x,re,requipoToString);
        e = read<Equipo>(f);
    }
    fclose(f);
    return x;
}

REquipo buscarEquipo(Coll<REquipo> c, int id,int& pos){
    pos = collFind<REquipo, int>(c,id,cmpREquipoId,requipoFromString);
    REquipo x = collGetAt<REquipo>(c,pos,requipoFromString);
    return x;
}

void actualizarPuntos(Coll<REquipo>& c, int id, int ptos){
    int pos = collFind<REquipo, int>(c,id,cmpREquipoId,requipoFromString);
    REquipo re = collGetAt<REquipo>(c,pos,requipoFromString);
    re.ptos += ptos;

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
/*
 *

        // resuelvo punto 1 y 3
        actualizarPuntos(cEq,r.idEq1,ptos1);
        actualizarPuntos(cEq,r.idEq2,ptos2);

        // resuelvo punto 2
        string est = r.estadio;
        int empate = r.codRes==0?1:0;
        actualizarEstadio(cEst,est,empate);
        */
void procesarEquipo(Resultado r,Coll<REquipo>& cEq){
    int pos,pos1;
    REquipo e1;
    REquipo e2;
    e1.ptos = r.codRes<0?3:r.codRes==0?1:0;
    e2.ptos = r.codRes>0?3:r.codRes==0?1:0;
    e1 = buscarEquipo(cEq,r.idEq1,pos);
    e2 = buscarEquipo(cEq,r.idEq2,pos1);
    e1.eq.puntos+=e1.ptos;
    e2.eq.puntos+=e2.ptos;
    collSetAt<REquipo>(cEq,e1,pos,requipoToString);
    collSetAt<REquipo>(cEq,e2,pos1,requipoToString);
}
void procesarEstadio(Resultado r,Coll<REstadio>& cEst){

}
void procesarResultado (Coll<REquipo>& cEq,Coll<REstadio>& cEst ){
    // barro novedades
    FILE* f = fopen("RESULTADOS.dat","r+b");
    Resultado r = read<Resultado>(f);
    while( !feof(f)){
        procesarEquipo(r,cEq);
        procesarEstadio(r,cEst);
        r = read<Resultado>(f);

    }
    fclose(f);
}
int main(){


    // subo consultas a memoria
    Coll<REquipo> cEq = subirEquipos();

    // subo consultas a memoria
    Coll<REstadio> cEst = collCreate<REstadio>();
    fileMostrar<Equipo>("EQUIPOS.dat",equipoToString);

    procesarResultado(cEq,cEst);

/*
    // tabla de posiciones
    punto1(cEq);

    // estadisticas x estadio
    punto2(cEst);

    // actualizar puntos
    punto3(cEq);
  */
    return 0;
}