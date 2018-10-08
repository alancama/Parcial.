#include "juego.h"
#include <stdio.h>
#include "validacion.h"
#include <stdlib.h>
#include <string.h>
#include <conio.h>



int initJuegos( eJuego juegos [],int tam)
{
    int i;
    for( i=0; i < tam; i++)
    {
        juegos[i].isEmpty = 0;
        juegos[i].id=0;
    }
    return 0;
}



int buscarLibre( eJuego juegos [], int tam)
{
    int indice = -1,i;

    for( i=0; i< tam; i++)
    {

        if( juegos[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaJuegos(eJuego juegos [], int tam)
{
    eJuego auxJuego;
    int indice;
    char validaImporte[12];

    indice = buscarLibre(juegos, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {

         auxJuego.id=siguienteIDJuego(juegos,tam);
        do
            {
            printf("\nIngrese juego: ");
            fflush(stdin);
            gets(auxJuego.descripcion);
            }while(validarNombre(juegos[indice].descripcion)==0);
            do
            {
            printf("\nIngrese el importe del juego: ");
            scanf("%f",&auxJuego.importe);
            }while(validarNumero(validaImporte)==0);

            //nuevoEmpleado.idSector=elegirSector(sectores,5);

            auxJuego.isEmpty = 1;

            juegos[indice] = auxJuego;
    }
}

int siguienteIDJuego(eJuego juegos [],int tam)
{
    int retorno = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(juegos[i].isEmpty == 1)
        {
            if(juegos[i].id>retorno)
            {
                retorno=juegos[i].id;
            }

        }
    }

    return retorno+1;
}


