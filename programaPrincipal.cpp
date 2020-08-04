#include <iostream>
#include <string>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "Aviacion.hpp"
using namespace std;

int main(){
    //subo vuelos a memoria
    Coll<RVuelo> cvue = subirVuelos();

    //subo las ciudades a memoria
    Coll<RCiudad> cciu = subirCiudades();

    //coleccion de clientes y millas
    Coll<RCliente> ccli = collCreate<RCliente>();

    //proceso las reservas
    FILE* f = fopen("RESERVAS.dat","r+b");

    Reserva r = read<Reserva>(f);

    while( !feof(f) )
    {
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
        if( r.cant<=capActual )
        {

            //actualizo plazas aceptadas
            v.cpa += r.cant;

            //dar millas al cliente
            int millas = abs(co.c.millas-cd.c.millas);

            actualizarMillasCliente(ccli,r.idCli,millas);

        }
        else
        {
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