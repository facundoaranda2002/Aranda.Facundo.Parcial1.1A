#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"
#include "validaciones.h"

int listarColores(eColor colores[], int tam)
{
    int todoOk=0;

    if(colores!=NULL && tam>0)
    {
        //system("cls");
        printf("    *** Lista de Colores ***\n\n");
        printf("   Id           Color\n");
        printf("--------------------------\n");
        for(int i=0; i<tam; i++)
        {
           printf("   %4d    %10s\n", colores[i].id, colores[i].nombreColor);
        }
        printf("\n\n");
        todoOk=1;
    }

    return todoOk;
}


int validarColores(eColor colores[], int tam, int id)
{
    int todoOk=0;

    if(colores!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
           if(colores[i].id==id)
           {
              todoOk=1;
              break;
           }
        }
    }

    return todoOk;
}


int cargarDescripcionColor(eColor colores[], int tam, int id, char descripcion[])
{
    int todoOk=0;

    if(colores!=NULL && tam>0 && validarColores(colores, tam, id) && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
           if(colores[i].id==id)
           {
               strcpy(descripcion, colores[i].nombreColor);
               break;
           }
        }

        todoOk=1;
    }

    return todoOk;
}

int utn_getColores(eColor colores[], int tam, int* pId)
{
    int todoOk=0;
    int x;
    if(colores!=NULL && tam>0 && pId!=NULL)
    {
        listarColores(colores, tam);
        printf("Ingrese el id del color al que pertenece la mascota: ");
        fflush(stdin);
        while(scanf("%d", &x)==0 || !validarColores(colores, tam, x))
        {
            printf("Error. Id invalido. Reingrese el id del color al que pertenece la mascota: ");
            fflush(stdin);
        }
        *pId=x;
        todoOk=1;
    }
    return todoOk;
}

