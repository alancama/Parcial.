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
int siguienteID(eJuego juegos [],int tam);
int initJuegos(eJuego juegos [],int tam);

#endif // JUEGO_H_INCLUDED
