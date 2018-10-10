#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

#include "juegos.h"
typedef struct
{
    int idCliente;
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[30];
    int isEmpty;
} eCliente;

int elejirJuego(eJuego juegos[],int tam);
void listarClientesXjuego(eCliente clientes [],int tam,eJuego juegos[] ,int tamJuegos);
void mostrarClienteConJuego(eCliente clientes,eJuego juegos[],int tam);
void cargarDescripcion(eJuego juegos [],int tam ,int id ,char cadena[]);

/** \brief Hardcodeo de clientes
 *
 * \param clientes[] eCliente Estructura de clientes
 * \return void
 *
 */
void hardcodeoClientes(eCliente clientes[]);


/** \brief Inicializa los estados en LIBRE
 *
 * \param [] eCliente clientes Estructura de clientes
 * \param tamanioClientes int Tamanio de la estructura
 * \return int
 *
 */
int iniciarEstadosClientes(eCliente clientes [], int tamanioClientes);


/** \brief Busca el siguinte id para cliente(autoincremental)
 *
 * \param [] eCliente clientes Estructura de clientes
 * \param tamanioClientes int Tamanio de la estructura
 * \return int
 *
 */
int getNextIdCliente(eCliente clientes[],int tamanioClientes);


/** \brief Busca el siguiente cliente libre
 *
 * \param [] eCliente clientes Estructura de clientes
 * \param tamanioClientes int Tamanio de la estructura
 * \return int
 *
 */
int buscarClienteLibre(eCliente clientes[], int tamanioClientes);


/** \brief Busca en el array el cliente con el id recibido por parametro
 *
 * \param [] eCliente clientes Estructura de clientes
 * \param tamanioClientes int Tamanio de la estructura
 * \param idCliente int ID INGRESADO POR USUARIO
 * \return int
 *
 */
int buscarCliente(eCliente clientes[], int tamanioClientes, int idCliente);

/** \brief Muestra un solo cliente
 *
 * \param clientes eCliente
 * \return void
 *
 */
void mostrarCliente(eCliente clientes);

/** \brief Muestra todos los clientes(llama a la función anterior)
 *
 * \param [] eCliente clientes Estructura de clientes
 * \param tamanioClientes int Tamanio de la estructura
 * \return void
 *
 */
void mostrarClientes(eCliente clientes[], int tamanioClientes);

/** \brief Ingresa un cliente
 *
 * \param [] eCliente clientes Estructura de clientes
 * \param tamanioClientes int Tamanio de la estructura
 * \return void
 *
 */
void altaClientes(eCliente clientes[], int tamanioClientes);

/** \brief Baja logica de cliente
 *
 * \param [] eCliente clientes Estructura de clientes
 * \param tamanioClientes int Tamanio de la estructura
 * \return void
 *
 */
void bajaCliente(eCliente clientes[], int tamanioClientes);


/** \brief Muetra un listado de clientes
 *
 * \param [] eCliente clientes Estructura de clientes
 * \param tamanioClientes int Tamanio de la estructura
 * \return void
 *
 */
void listarClientes(eCliente clientes[], int tamanioClientes);


/** \brief Menu para abm de clientes
 *
 * \param clientes[] eCliente
 * \param tamanioClientes int
 * \return void
 *
 */
void abmClientes(eCliente clientes[], int tamanioClientes);
#endif // CLIENTES_H_INCLUDED
