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
    char validaImporte[10];

    indice = buscarLibre(juegos, tam);

    if(indice != -1)
    {

         auxJuego.id=siguienteIDJuego(juegos,tam);
        do
            {
            printf("\nIngrese juego: ");
            fflush(stdin);
            gets(auxJuego.descripcion);
            }while(validarNombre(auxJuego.descripcion)==0);

            do
            {
            printf("\nIngrese el importe del juego: ");
            scanf("%s",&validaImporte);
            }while(validarNumero(validaImporte)==0);

            auxJuego.importe=atoi(validaImporte);

            //nuevoEmpleado.idSector=elegirSector(sectores,5);

            auxJuego.isEmpty = 1;

            juegos[indice] = auxJuego;
    }else
    {
        printf("NO HAY LUGAR");
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

void modificarJuego(eJuego juegos[],int tam)
{
    int id;
    int indice;
    int opcion;
    char seguir='s';

    mostrarJuegos(juegos,tam);

    printf("Ingrese id del juego a modificar:");
    scanf("%d",&id);

    indice=buscarJuego(juegos,tam,id);
    if( indice == -1)
    {
        printf("No hay ningun juego con el id %d\n",id);
    }
    else
    {

        mostrarJuego(juegos[indice]);

        do
        {
            printf("***Que Desea Modificar?***");

            printf("\n 1.Nombre del juego");
            printf("\n 2.Importe");
            printf("\n 3.salir\n ");

            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:

                printf("\nIngrese nuevo Nombre:");
                fflush(stdin);
                gets(juegos[indice].descripcion);
                system("pause");

                break;

            case 2:
                printf("\nIngrese Nuevo importe:");
                scanf("%f",&juegos[indice].importe);
                system("pause");
                break;

            case 3:
                seguir='n';
                break;

            }
        }
        while(seguir=='s');
        system("cls");
        mostrarJuegos(juegos,tam);
    }
}
void mostrarJuego(eJuego juegos/*eJuego sectores[],int tamSector*/)
{
    //char descripcion[30];
    //cargarDescripcion(sectores,tamSector,clientes.idSector,descripcion);
    printf("%d %s %.2f \n\n", juegos.id, juegos.descripcion, juegos.importe);
}

void mostrarJuegos(eJuego juegos[], int tam)
{
    for(int i=0; i< tam; i++)
    {
        if( juegos[i].isEmpty == 1)
        {
            mostrarJuego(juegos[i]);
        }
    }
}

int buscarJuego(eJuego juegos [], int tam, int id )
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {

        if( juegos[i].id == id && juegos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void bajaJuego(eJuego juegos[],int tam)
{
    int indice;
    int id;

    mostrarJuegos(juegos,tam);
    printf("Ingrese id del cliente a Dar de baja:");
    scanf("%d",&id);

    indice=buscarJuego(juegos,tam,id);

    if(indice==-1)
    {
        printf("Error id no Encontrado\n");
    }
    else
    {
        juegos[indice].isEmpty=0;
        printf("\n Juego Borrado\n");
    }
}
