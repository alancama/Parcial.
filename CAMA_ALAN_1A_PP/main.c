#include <stdio.h>
#include <stdlib.h>
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"
#include "utn.h"
#include "consultas.h"
#define TAMJUEGOS 4
#define TAMCLIENTES 6
#define TAMALQUILERES 5

int main()
{

    eJuego juegos[TAMJUEGOS];
    eCliente clientes[TAMCLIENTES];
    eAlquiler alquileres[TAMALQUILERES];
    char seguir = 's';

    iniciarEstadosJuegos(juegos, TAMJUEGOS);
    iniciarEstadosClientes(clientes, TAMCLIENTES);
    iniciarEstadosAlquileres(alquileres, TAMALQUILERES);

    hardcodeoJuegos(juegos);
    hardcodeoClientes(clientes);

    do
    {
        switch(menu())
        {
        case 1:
            abmJuegos(juegos, TAMJUEGOS);
            system("pause");
            break;
        case 2:
            abmClientes(clientes, TAMCLIENTES);
            system("pause");
            break;
        case 3:

            abmAlquiler(juegos, TAMJUEGOS, clientes, TAMCLIENTES, alquileres, TAMALQUILERES);
            system("pause");
            break;
        case 4:
            listarClientesXjuego(clientes,TAMCLIENTES,juegos,TAMJUEGOS);
            system("pause");
            break;

        case 5:
            abmConsultas(alquileres,TAMALQUILERES,juegos,TAMJUEGOS,clientes,TAMCLIENTES);
            system("pause");
            break;
        case 6:

            seguir = 'n';
            break;
        default:
            printf("Error, ingreso una opcion no valida. Reintente.\n\n");
            system("pause");
        }
    }
    while(seguir == 's');
    return 0;
}
