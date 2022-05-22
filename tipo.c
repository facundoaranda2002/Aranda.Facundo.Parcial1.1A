#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "validaciones.h"
#include "tipo.h"

int listarTipos(eTipo tipos[], int tam)
{
    int todoOk=0;

    if(tipos!=NULL && tam>0)
    {
        //system("cls");
        printf("    *** Lista de Tipos ***\n\n");
        printf("   Id      Descripcion\n");
        printf("--------------------------\n");
        for(int i=0; i<tam; i++)
        {
           printf("   %4d    %10s\n", tipos[i].id, tipos[i].descripcion);
        }
        printf("\n\n");
        todoOk=1;
    }

    return todoOk;
}

int validarTipos(eTipo tipos[], int tam, int id)
{
    int todoOk=0;

    if(tipos!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
           if(tipos[i].id==id)
           {
              todoOk=1;
              break;
           }
        }
    }

    return todoOk;
}

int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[])
{
    int todoOk=0;

    if(tipos!=NULL && tam>0 && validarTipos(tipos, tam, id) && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
           if(tipos[i].id==id)
           {
               strcpy(descripcion, tipos[i].descripcion);
               break;
           }
        }

        todoOk=1;
    }

    return todoOk;
}

int utn_getTipos(eTipo tipos[], int tam, int* pId)
{
    int todoOk=0;
    int x;
    if(tipos!=NULL && tam>0 && pId!=NULL)
    {
        listarTipos(tipos, tam);
        printf("Ingrese el id del tipo al que pertenece la mascota: ");
        fflush(stdin);
        while(scanf("%d", &x)==0 || !validarTipos(tipos, tam, x))
        {
            printf("Error. Id invalido. Reingrese el id del tipo al que pertenece la mascota: ");
            fflush(stdin);
        }
        *pId=x;
        todoOk=1;
    }
    return todoOk;
}

int utn_getTiposMod(eTipo tipos[], int tam, int* pId)
{
    int todoOk=0;
    int x;
    if(tipos!=NULL && tam>0 && pId!=NULL)
    {
        listarTipos(tipos, tam);
        printf("Ingrese el id del nuevo tipo al que pertenece la mascota: ");
        fflush(stdin);
        while(scanf("%d", &x)==0 || !validarTipos(tipos, tam, x))
        {
            printf("Error. Id invalido. Reingrese el id del nuevo tipo al que pertenece la mascota: ");
            fflush(stdin);
        }
        *pId=x;
        todoOk=1;
    }
    return todoOk;
}

