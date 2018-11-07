#include "consultas.h"
#include <stdio.h>
#include <stdlib.h>
#include "juegos.h"
#include "clientes.h"
#include "alquileres.h"
#include "utn.h"
#define TAMJUEGOS 4
#define TAMCLIENTES 6
#define TAMALQUILERES 5
#include "string.h"


int consultas()
{
    int opcion;

    system("cls");
    printf("1-Promedio y total de los importes de juegos alquilados\n");
    printf("2-cantidad de juegos que no superan el promedio de juegos alquilados\n");
    //printf("3-listado de clientes que alquilaron un juego determinado\n");
    //printf("4-listado de juegos alquilados por un cliente determinado\n");
    //printf("5-listado de juegos menos alquilados\n");
    //printf("6-listado de juegos mas alquilados\n");
    //printf("7-listado de juegos alquilados en una fecha determinada\n");
    //printf("8-listado de clientes que realizaron al menos un alquiler en una fecha determinada\n");
    printf("9-listado de juegos ordenados por importe\n");
    printf("10-listado de clientes ordenados por apellido ascendente\n");
    printf("11-Salir\n");

    opcion=getInt("Ingrese opcion: ");


    return opcion;
}

void importesPromedio(eJuego juegos[],int tamJuego,eAlquiler alquileres[],int tamAlquiler)
{
    float promedio=0;
    float total=0;
    int contadorjuegos=0;



    for(int i=0; i<tamAlquiler; i++)
    {
        for(int j=0; j<tamJuego; j++)
        {
            if(juegos[j].idJuego==alquileres[i].idJuego && alquileres[i].isEmpty==0 && juegos[j].isEmpty==0)
            {
                contadorjuegos++;
                total=total+juegos[j].importe;
            }

        }
    }

    promedio=total/contadorjuegos;



    printf("Total importe: %.2f\n", total);
    printf("Promedio importe: %.2f\n", promedio);
}

void abmConsultas(eAlquiler alquiler[],int tamAlquiler,eJuego juegos[],int tamJuego,eCliente clientes[],int tamClientes)
{
    char seguir = 's';

    do
    {
        switch(consultas())
        {
        case 1:
            importesPromedio(juegos,tamJuego,alquiler,tamAlquiler);
            system("pause");
            break;
        case 2:
            PromedioQueNoSupera(juegos,tamJuego,alquiler,tamAlquiler);
            system("pause");
            break;

        case 3:
            listadoJuegosOrdenados(juegos,tamJuego);
            system("pause");
            break;

        case 4:
            listadoClientesOrdenados(clientes,tamClientes);
            system("pause");
            break;

        case 11:
            seguir = 'n';
            break;
        default:
            printf("Error, ingreso una opcion no valida. Reintente.\n\n");
            system("pause");


        }
    }
    while(seguir == 's');
}

void PromedioQueNoSupera(eJuego juegos[],int tamJuegos,eAlquiler alquileres[],int tamAlquiler)
{

    float promedio=0;
    float total=0;
    int contadorjuegos=0;
    int contadorImporte=0;



    for(int i=0; i<tamAlquiler; i++)
    {
        for(int j=0; j<tamJuegos; j++)
        {
            if(juegos[j].idJuego==alquileres[i].idJuego && alquileres[i].isEmpty==0 && juegos[j].isEmpty==0)
            {
                contadorjuegos++;
                total=total+juegos[j].importe;
            }

        }
    }

    promedio=total/contadorjuegos;

    for(int i=0; i<tamJuegos; i++)
    {
        if(juegos[i].isEmpty==0)
        {
            if(juegos[i].importe<promedio)
            {
                contadorImporte++;
            }
        }
    }

    printf("los juegos que no superan el promedio son: %d\n",contadorImporte);
}

void listadoDeclientesJuegoDeter(eCliente clientes[],int tamCliente,eJuego juegos[],int tamJuego)
{

}

void listadoJuegosMemosAlquilados(eAlquiler alquileres[],int tamAlquileres,eJuego juegos[],int tamJuegos)
{

}

void listadoJuegosOrdenados(eJuego juegos[],int tamJuegos)
{
    int j;
    eJuego aux;
    int flagNoEstaOrdenado = 1;
    while (flagNoEstaOrdenado==1)
    {
        flagNoEstaOrdenado = 0;
        for (j = 1; j < tamJuegos; j++)
        {
            if (juegos[j].importe < juegos[j - 1].importe)
            {
                aux = juegos[j];
                juegos[j] = juegos[j - 1];
                juegos[j - 1] = aux;
                flagNoEstaOrdenado = 1;
            }
        }
    }
    mostrarJuegos(juegos,tamJuegos);
}

void listadoClientesOrdenados(eCliente clientes [],int tamCliente)
{
    int i,j;
    eCliente temp;
    for(i=1; i<tamCliente; i++)
    {
        temp = clientes[i];
        j=i-1;
        while(j>=0 &&  strcmp(temp.apellido, clientes[j].apellido) < 0) // temp<clientes[j] o temp>clientes[j]
        {
            clientes[j+1] = clientes[j];
            j--;
        }
        clientes[j+1]=temp; // inserción
    }
    mostrarClientes(clientes,tamCliente);
}
