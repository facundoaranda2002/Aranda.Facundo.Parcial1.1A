#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
}
eCliente;

#endif // CLIENTE_H_INCLUDED

int cargarDescripcionCliente(eCliente clientes[], int tam, int id, char descripcion[]);
int validarClientes(eCliente clientes[], int tam, int id);
