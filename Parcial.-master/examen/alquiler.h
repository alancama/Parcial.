#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

typedef struct
{
    int dia, mes , anio;

}eFecha;

typedef struct
{
    int id;
    int idJuego;
    int idCliente;
    eFecha feNac;

}eAlquiler;


#endif // ALQUILER_H_INCLUDED
