#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "trabajo.h"


int inicializarTrabajos(eTrabajo vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty=1;
        }
      todoOk = 1;
    }
    return todoOk;
}


int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex!=NULL)
    {
        *pIndex=-1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex=i;
                break;
            }
        }
      todoOk = 1;
    }
    return todoOk;
}

int altaTrabajo(eMascota vec[], int tam, int* pId, eServicio servicios[], int tamServ, eTrabajo trabajos[], int tamTrab, eColor colores[], int tamColores, eTipo tipos[], int tamTipos)
{
    int todoOk = 0;
    int indice;
    eTrabajo nuevoTrabajo;
    eFecha fecha;

    if(vec!=NULL && tam > 0 && servicios!=NULL && tamServ>0 && trabajos!=NULL && tamTrab>0 && pId!=NULL && colores!=NULL && tamColores>0 && tipos!=NULL && tamTipos>0)
    {
        system("cls");
        printf("   *** Alta Trabajo ***\n\n");
        printf("--------------------------------------\n");
        printf("\n\n");

        if(buscarTrabajoLibre(trabajos, tamTrab, &indice))
        {
            if(indice == -1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {

                utn_getMascotas(vec, tam, &nuevoTrabajo.idMascota, colores, tamColores, tipos, tamTipos);
                printf("\n\n");

                utn_getServicios(servicios, tamServ, &nuevoTrabajo.idServicio);
                printf("\n\n");

                utn_getFecha(&fecha, "Ingrese la fecha del trabajo: ", "Error. ", 1900, 2022);
                nuevoTrabajo.fecha=fecha;
                printf("\n\n");

                nuevoTrabajo.isEmpty=0;
                nuevoTrabajo.id=*pId;
                *pId=*pId+1;

                trabajos[indice]=nuevoTrabajo;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}

int listarTrabajos(eTrabajo trabajos[], int tam, eMascota mascotas[], int tamMasc, eServicio servicios[], int tamServ)
{
    int todoOk=0;
    char descripcionMasc[20];
    char descripcionServ[20];

    if(trabajos!=NULL && tam>0)
    {
        system("cls");
        printf("    *** Lista de trabajos ***\n\n");
        printf("     Id       Mascota       Servicio   Fecha\n");
        printf("-----------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                cargarDescripcionMascota(mascotas, tamMasc, trabajos[i].idMascota, descripcionMasc);
                cargarDescripcionServicio(servicios, tamServ, trabajos[i].idServicio, descripcionServ);
                printf("   %4d    %10s    %10s    %02d/%02d/%d \n", trabajos[i].id, descripcionMasc, descripcionServ, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
            }
        }
        printf("\n\n");
        todoOk=1;
    }

    return todoOk;
}
