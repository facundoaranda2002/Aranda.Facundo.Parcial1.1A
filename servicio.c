#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "servicio.h"

int listarServicios(eServicio servicios[], int tam)
{
    int todoOk=0;

    if(servicios!=NULL && tam>0)
    {
        //system("cls");
        printf("    *** Lista de Servicios ***\n\n");
        printf("    Id          Servicio    Precio\n");
        printf("-------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
           printf("   %4d    %15s   %4.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
        }
        printf("\n\n");
        todoOk=1;
    }

    return todoOk;
}

int cargarDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion[])
{
    int todoOk=0;

    if(servicios!=NULL && tam>0 && validarServicios(servicios, tam, id) && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
           if(servicios[i].id==id)
           {
               strcpy(descripcion, servicios[i].descripcion);
               break;
           }
        }

        todoOk=1;
    }

    return todoOk;
}

int validarServicios(eServicio servicios[], int tam, int id)
{
    int todoOk=0;

    if(servicios!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
           if(servicios[i].id==id)
           {
              todoOk=1;
              break;
           }
        }
    }

    return todoOk;
}

int utn_getServicios(eServicio servicios[], int tam, int* pId)
{
    int todoOk=0;
    int x;
    if(servicios!=NULL && tam>0 && pId!=NULL)
    {
        listarServicios(servicios, tam);
        printf("Ingrese el id del servicio: ");
        fflush(stdin);
        while(scanf("%d", &x)==0 || !validarServicios(servicios, tam, x))
        {
            printf("Error. Id invalido. Reingrese el id del servicio: ");
            fflush(stdin);
        }
        *pId=x;
        todoOk=1;
    }
    return todoOk;
}

