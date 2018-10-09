#include "validacion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int validarNombre(char nombre[])
{

    int retorno=1;
    int i;
    for(i=0 ; i<strlen(nombre); i++)
    {
        if(!(nombre[i]>=65 && nombre[i]<=90 || nombre[i]>=97 && nombre[i]<=122 || nombre[i]==32))
        {
            printf("Error, solo se pueden ingresar letras.");
            retorno=0;
        }
    }
    return retorno;
}

int validarNumero(char numero[])
{
    int retorno=1;

    int i;
    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            retorno=0;
            printf("Error, ingrese solo numeros. \n");
            break;
        }
    }

    return retorno;
}

