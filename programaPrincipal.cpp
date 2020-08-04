#include <iostream>
#include <string>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "Aviacion.hpp"
using namespace std;

Coll<RVuelo> subirVuelos(){

    Coll<RVuelo> rvuelo=collCreate<RVuelo>();

    FILE* file =fopen("VUELOS.dat","r+b");
    Vuelo v =read<Vuelo>(file);

    while (!feof(file)){
        RVuelo rv={v,0,0};
        collAdd<RVuelo>(rvuelo,rv,rVueloToString);
        v=read<Vuelo>(file);//contador
    }

    fclose(file);
    return rvuelo;
}
Coll<RCiudad> subirCiudades(){

    Coll<RCiudad> rciudad=collCreate<RCiudad>();

    FILE* file =fopen("CIUDADES.dat","r+b");
    Ciudad c =read<Ciudad>(file);

    while (!feof(file)){
        RCiudad rc={c,0};
        //coleccion,Tipo de dato del archivo,Funcion para convertir string
        collAdd<RCiudad>(rciudad,rc,rCiudadToString);
        c=read<Ciudad>(file);//contador
    }

    fclose(file);
    return rciudad;
}


int cmpVueloId(RVuelo rV,int i){
    return rV.v.idVue-i;
}

int cmpCiudadId(RCiudad rC,int i){
    return rC.c.idCiu-i;
}

int cmpClienteId(RCliente rC,int i){
    return rC.idCli-i ;
}

RVuelo buscarVuelo(Coll<RVuelo> rV , int idV){
    int pos = collFind<RVuelo,int>(rV,idV,cmpVueloId,rVueloFromString);
    RVuelo rv =collGetAt<RVuelo>(rV,pos,rVueloFromString);
    return rv;
}

RCiudad buscarCiudad(Coll<RCiudad> rC , int idC){
    int pos = collFind<RCiudad,int>(rC,idC,cmpCiudadId,rCiudadFromString);
    RCiudad rc =collGetAt<RCiudad>(rC,pos,rCiudadFromString);
    return rc;
}

void actualizarMillasCliente(Coll<RCliente> rCl,int idC,int millas){
    int pos=collFind<RCliente,int>(rCl,idC,cmpClienteId,rClienteFromString);

    if(pos<0){
        RCliente rCliente ={idC,0};
        pos = collAdd<RCliente>(rCl,rCliente,rClienteToString);
    }
    RCliente x = collGetAt<RCliente>(rCl,pos,rClienteFromString);
    x.ac+= millas;
    collSetAt<RCliente>(rCl,x,pos,rClienteToString);

}
void mostrarPto1(Coll<RCliente> c)
{
    while( collHasNext<RCliente>(c) ){
        RCliente r = collNext<RCliente>(c,rClienteFromString);
        cout << rClienteToDebug(r) << endl;

    }
    cout<<"----------------"<<endl;
}
void mostrarPto2(Coll<RCiudad> c)
{
    while( collHasNext<RCiudad>(c) )
    {
        RCiudad r = collNext<RCiudad>(c,rCiudadFromString);
        cout << rCiudadToDebug(r)<< endl;
    }
    cout<<"----------------"<<endl;
}
void mostrarPto3(Coll<RVuelo> v)
{
    while( collHasNext<RVuelo>(v) )
    {
        RVuelo r = collNext<RVuelo>(v,rVueloFromString);
        string mssgCompleto = (r.v.cap==r.cpa)?"Completo":"Incompleto";
        cout<<r.v.idVue<<", "<<r.cpr<<mssgCompleto<<endl;
    }
    cout<<"----------------"<<endl;
}
int main(){
    Coll<RVuelo> cvue = subirVuelos();

    //subo las ciudades a memoria
    Coll<RCiudad> cciu = subirCiudades();

    //coleccion de clientes y millas
    Coll<RCliente> ccli = collCreate<RCliente>();

    //proceso las reservas
    FILE* f = fopen("RESERVAS.dat","r+b");

    Reserva r = read<Reserva>(f);

    while( !feof(f) ){
        //busco el vuelo de la reserva
        RVuelo v = buscarVuelo(cvue,r.idVue);
        //busco ciudad de la reserva
        RCiudad co = buscarCiudad(cciu,v.v.idOri);
        RCiudad cd = buscarCiudad(cciu,v.v.idDes);
        //actualizo cant de grupos que optaron por esta ciudad
        cd.cont++;
        //capacidad de plazas actual
        int capActual = v.v.cap-v.cpa;
        //verifico si acepto o rechazo
        if( r.cant<=capActual ){

            //actualizo plazas aceptadas
            v.cpa += r.cant;

            //dar millas al cliente
            int millas = abs(co.c.millas-cd.c.millas);

           actualizarMillasCliente(ccli,r.idCli,millas);

        }else{
            //actualizo plazas rechazadas
            v.cpr += r.cant;

        }

        r = read<Reserva>(f);
    }

    mostrarPto1(ccli);
    mostrarPto2(cciu);
    mostrarPto3(cvue);

    return 0;
}