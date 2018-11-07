#ifndef CONSULTAS_H_INCLUDED
#define CONSULTAS_H_INCLUDED
#include "juegos.h"
#include "alquileres.h"

void importesPromedio(eJuego juegos[],int tamJuego,eAlquiler alquileres[],int tamAlquiler);
void abmConsultas(eAlquiler alquiler[],int tamAlquiler,eJuego juegos[],int tamJuego,eCliente clientes[],int tamClientes);
void PromedioQueNoSupera(eJuego juegos[],int tamJuegos,eAlquiler alquileres[],int tamAlquiler);
void listadoDeclientesJuegoDeter(eCliente clientes[],int tamCliente,eJuego juegos[],int tamJuego);
void listadoJuegosMemosAlquilados(eAlquiler alquileres[],int tamAlquileres,eJuego juegos[],int tamJuegos);
void listadoClientesOrdenados(eCliente clientes [],int tamCliente);
void listadoJuegosOrdenados(eJuego juegos[],int tamJuegos);
#endif // CONSULTAS_H_INCLUDED
