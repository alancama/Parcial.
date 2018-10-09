#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[51];
    float importe;
    int isEmpty;

} eJuego;

int buscarLibre(eJuego juegos [], int tam);
void altaJuegos(eJuego juegos [], int tam);
int siguienteIDJuego(eJuego juegos [],int tam);
int initJuegos(eJuego juegos [],int tam);
void mostrarJuego(eJuego juegos/*eJuego sectores[],int tamSector*/);
void modificarJuego(eJuego juegos[],int tam);
void mostrarJuegos(eJuego juegos[], int tam);
int buscarJuego(eJuego juegos [], int tam, int id );
void bajaJuego(eJuego juegos[],int tam);

#endif // JUEGO_H_INCLUDED
