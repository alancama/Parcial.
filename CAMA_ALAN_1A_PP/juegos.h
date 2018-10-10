#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct
{
    int idJuego;
    char descripcion[51];
    float importe;
    int isEmpty;

} eJuego;

int menu();
int menuABM();
void hardcodeoJuegos(eJuego juegos[]);
int getNextId(eJuego juegos[],int tamanioJuegos);
int iniciarEstadosJuegos(eJuego juegos [], int tamanioJuegos);
void mostrarJuego(eJuego juegos);
void mostrarJuegos(eJuego juegos[], int tamanioJuegos);
int buscarJuegoLibre(eJuego juegos[], int tamanioJuegos);
int buscarJuego(eJuego juegos[], int tamanioJuegos, int idJuego);
void altaJuego(eJuego juegos[], int tamaniojuegos);
void modificarJuego(eJuego juegos[], int tamanioJuegos);
void bajaJuego(eJuego juegos[], int tamaniojuegos);
void listarJuegos(eJuego juegos[], int tamanioJuegos);
void abmJuegos(eJuego juegos[], int tamanioJuegos);
void ordenamiento (eJuego juegos[],int tam);

#endif // JUEGOS_H_INCLUDED
