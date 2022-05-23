
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"

int cargarDescripcionCliente(eCliente clientes[], int tam, int id, char descripcion[])
{
    int todoOk=0;

    if(clientes!=NULL && tam>0 && validarClientes(clientes, tam, id) && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
           if(clientes[i].id==id)
           {
               strcpy(descripcion, clientes[i].nombre);
               break;
           }
        }

        todoOk=1;
    }

    return todoOk;
}

int validarClientes(eCliente clientes[], int tam, int id)
{
    int todoOk=0;

    if(clientes!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
           if(clientes[i].id==id)
           {
              todoOk=1;
              break;
           }
        }
    }

    return todoOk;
}
