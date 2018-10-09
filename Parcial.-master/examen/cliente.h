#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char apellido[51];
    char nombre[51];
    char sexo;
    char domicilio[51];
    int isEmpty;

}eCliente;

int initcliente(eCliente clientes[], int tam);
void altacliente(eCliente clientes[],int tam);
void mostrarCliente(eCliente clientes);
void mostrarClientes(eCliente clientes[], int tam);
void modificarCliente(eCliente clientes [],int tam);
int buscarcliente(eCliente clientes [], int tam, int id );
int obtenerEspacioLibre(eCliente clientes[], int tam);
void bajaCliente(eCliente clientes[],int tam);
int siguienteIDCliente(eCliente list[],int tam);




#endif // CLIENTE_H_INCLUDED
