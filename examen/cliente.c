#include "cliente.h"
#include <stdio.h>
#include <string.h>
#include "validacion.h"
#include <conio.h>
#include <stdlib.h>

int initcliente(eCliente clientes[], int tam)
{

    for(int i=0; i<tam; i++)
    {
        clientes[i].isEmpty=0;
        clientes[i].id=0;
    }

    return  0;
}

void altacliente(eCliente clientes[],int tam)
{

    eCliente aux;

    int index=obtenerEspacioLibre(clientes,tam);

    if(index!=-1)
    {
        aux.id=siguienteIDCliente(clientes,tam);

        do
        {

            printf("\nIngrese nombre:");
            fflush(stdin);
            gets(aux.nombre);
        }
        while(validarNombre(aux.nombre)==0);

        do
        {

            printf("\nIngrese Apellido:");
            fflush(stdin);
            gets(aux.apellido);
        }
        while(validarNombre(aux.apellido)==0);

        do
        {
            printf("\nIngrese sexo:");
            fflush(stdin);
           scanf("%c",&aux.sexo);
        }
        while(validarNombre(&aux.sexo)==0);


        do
        {
            printf("\nIngrese domicilio:");
            fflush(stdin);
            gets(aux.domicilio);
        }
        while(validarNombre(aux.domicilio)==0);


        //aux.idSector=elegirSector(sectores,5);

        aux.isEmpty = 1;

        clientes[index] = aux;

    }
    else
    {
        printf("ERROR NO HAY LUGAR\n ");
    }
}


int obtenerEspacioLibre(eCliente clientes[], int tam)
{
    int i;
    int retorno = -1;

    for(i=0; i<tam; i++)
    {
        if(clientes[i].isEmpty == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int menu()

{
    int opcion;

    printf("\n1-ALTA\n");
    printf("2-MODIFICAR\n");
    printf("3-BAJA\n");
    printf("4-INFORMAR\n");
    printf("5-Salir\n");

    scanf("%d",&opcion);

    return opcion;
}

int buscarcliente(eCliente clientes [], int tam, int id )
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {

        if( clientes[i].id == id && clientes[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarCliente(eCliente clientes/*eJuego sectores[],int tamSector*/)
{
    //char descripcion[30];
    //cargarDescripcion(sectores,tamSector,clientes.idSector,descripcion);
    printf("%d %s %s %c %s \n\n", clientes.id, clientes.nombre, clientes.apellido,clientes.sexo,clientes.domicilio);
}


void mostrarClientes(eCliente clientes[], int tam)
{
    for(int i=0; i< tam; i++)
    {
        if( clientes[i].isEmpty == 1)
        {
            mostrarCliente(clientes[i]);
        }
    }
}

int siguienteIDCliente(eCliente list[],int tam)
{
    int retorno = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty == 1)
        {
            if(list[i].id>retorno)
            {
                retorno=list[i].id;
            }

        }
    }

    return retorno+1;
}

void modificarCliente(eCliente clientes [],int tam)
{
    int id;
    int indice;
    int opcion;
    char seguir='s';

    mostrarClientes(clientes,tam);
    printf("Ingrese id del cliente a modificar:");
    scanf("%d",&id);

    indice=buscarcliente(clientes,tam,id);
    if( indice == -1)
    {
        printf("No hay ningun cliente con el id %d\n",id);
    }
    else
    {

        mostrarCliente(clientes[indice]);

        do
        {
            printf("***Que Desea Modificar?***");

            printf("\n 1.Nombre");
            printf("\n 2.Apellido");
            printf("\n 3.sexo");
            printf("\n 4.domicilio");
            printf("\n 5.salir\n ");

            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:

                printf("\nIngrese nuevo Nombre:");
                fflush(stdin);
                gets(clientes[indice].nombre);
                system("pause");

                break;

            case 2:
                printf("\nIngrese Nuevo Apellido:");
                fflush(stdin);
                gets(clientes[indice].apellido);
                system("pause");
                break;

            case 3:
                printf("\nIngrese Nuevo sexo:");
                fflush(stdin);
                scanf("%c",&clientes[indice].sexo);
                system("pause");
                break;

            case 4:
                printf("\ningrese nuevo domicilio:");
                fflush(stdin);
                gets(clientes[indice].domicilio);
                system("pause");
                break;

            case 5:
                seguir='n';
                break;

            }
        }
        while(seguir=='s');
        system("cls");
        mostrarClientes(clientes,tam);
    }
}

void bajaCliente(eCliente clientes[],int tam)
{
    int indice;
    int id;

    mostrarClientes(clientes,tam);
    printf("Ingrese id del cliente a Dar de baja:");
    scanf("%d",&id);

    indice=buscarcliente(clientes,tam,id);

    if(indice==-1)
    {
        printf("Error id no Encontrado\n");
    }
    else
    {
        clientes[indice].isEmpty=0;
        printf("\n cliente Borrado\n");
    }
}

/*void ordenarEmpleados(eCliente clientes[],int tam,eJuego sectores[],int tamSectores)
{
    eCliente aux;
    char descripcionI[20];
    char descripcionJ[20];

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam;j++)
        {
            cargarDescripcion(sectores,tamSectores,clientes[i].idSector,descripcionI);
            cargarDescripcion(sectores,tamSectores,clientes[j].idSector,descripcionJ);

            if(strcmp(descripcionI,descripcionJ)>0)
            {
                aux=clientes[i];
                clientes[i]=clientes[j];
                clientes[j]=aux;
            }
            else if(strcmp(descripcionI,descripcionJ)==0 && strcmp(clientes[i].apellido,clientes[j].apellido)>0)
            {
                aux=clientes[i];
                clientes[i]=clientes[j];
                clientes[j]=aux;
            }

        }
    }
}*/
