#include <stdio.h>
#include <stdlib.h>
#include "alquiler.h"
#include "cliente.h"
#include "conio.h"
#include "string.h"
#define TAM 1
#include "juego.h"



int main()
{
    eJuego juego[TAM];
    eCliente cliente[TAM];

    int opcion;
    char seguir='s';

    initJuegos(juego, TAM);
    initcliente(cliente, TAM);

    do
    {

        printf("***  menu  ****\n\n");
        printf("1-alta cliente\n");
        printf("2-modifica cliente\n");
        printf("3-baja cliente\n");
        printf("4-alta juego\n");
        printf("5-modifica juego\n");
        printf("6-baja juego\n");
        printf("7-salir\n\n");
        scanf("%d",&opcion);


        switch(opcion)
        {

        case 1:
            altacliente(cliente,TAM);
            system("pause");
            break;
        case 2:
            modificarCliente(cliente,TAM);
            system("pause");
            break;
        case 3:
            bajaCliente(cliente,TAM);
            system("pause");
            break;
        case 4:
            altaJuegos(juego,TAM);
            system("pause");
            break;
        case 5:
            modificarJuego(juego,TAM);
            system("pause");
            break;
        case 6:
            bajaJuego(juego,TAM);
            system("pause");
            break;
        /*case 7:
            break;
        case 8:
            mostrarAlmuerzosConEmpleados(lista,10,comidas,5,almuerzos,20);
            system("pause");
            break;*/
        case 7:
            seguir = 'n';
            break;

        }

    }
    while(seguir == 's');
    return 0;
}
