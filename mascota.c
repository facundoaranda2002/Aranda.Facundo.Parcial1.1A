#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "mascota.h"


char menu()
{
    char opcion;
    system("cls");
    printf("MENU DE OPCIONES:\n");
    printf("A- Alta Mascota\n");
    printf("B- Modificar Mascota\n");
    printf("C- Baja Mascota\n");
    printf("D- Listar Mascotas\n");
    printf("E- Listar Tipos\n");
    printf("F- Listar Colores\n");
    printf("G- Listar Servicios\n");
    printf("H- Alta Trabajo\n");
    printf("I- Listar Trabajos\n");
    printf("Z- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    opcion=tolower(opcion);
    return opcion;
}

int inicializarMascotas(eMascota vec[], int tam)
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

int buscarMascotaLibre(eMascota vec[], int tam, int* pIndex)
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

int altaMascota(eMascota vec[], int tam, int* pId, eColor colores[], int tamColores, eTipo tipos[], int tamTipos)
{
    int todoOk = 0;
    int indice;
    eMascota nuevaMascota;

    if(vec!=NULL && tam > 0 && colores!=NULL && tamColores>0 && tipos!=NULL && tamTipos>0 && pId!=NULL)
    {
        if(buscarMascotaLibre(vec, tam, &indice))
        {
            if(indice == -1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                //aca caigo cuando haya lugar
                utn_getCadenaChar(nuevaMascota.nombre, "Ingrese el nombre de la mascota: ", "Nombre demasiado largo. ", 1, 20);

                utn_getNumeroInt(&nuevaMascota.edad, "Ingrese edad: ", "Error. ", 1, 40);

                utn_getRespuesta(&nuevaMascota.vacunado, "Ingrese estado de vacunacion del animal(s/n): ", "Error. ");

                printf("\n\n");
                utn_getTipos(tipos, tamTipos, &nuevaMascota.idTipo);

                printf("\n\n");
                utn_getColores(colores, tamColores, &nuevaMascota.idColor);

                nuevaMascota.isEmpty=0;
                nuevaMascota.id=*pId;
                *pId=*pId+1;

                vec[indice]=nuevaMascota;
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

int buscarMascota(eMascota vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex!=NULL && id>0)
    {
        *pIndex=-1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty==0 && vec[i].id==id)
            {
                *pIndex=i;
                break;
            }
        }
      todoOk = 1;
    }
    return todoOk;
}


int menuModificarMascota()
{
    int opcion;
    printf("Seleccione que apartado modificar:\n");
    printf("1- Tipo\n");
    printf("2- Vacunado\n");
    printf("3- Salir\n");
    utn_getNumeroInt(&opcion, "Ingrese opcion: ", "Error. ", 1, 3);
    return opcion;
}

int modificarMascota(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos)
{
    int todoOk = 0;
    int indice;
    int id;
    eMascota auxMascota;
    char salir='n';

    if(vec!=NULL && tam > 0 && colores!=NULL && tamColores>0 && tipos!=NULL && tamTipos>0)
    {
        listarMascotas(vec, tam, colores, tamColores, tipos, tamTipos);
        printf("Ingrese id: ");
        scanf("%d", &id);
        if(buscarMascota(vec, tam, id, &indice))
        {
            if(indice==-1)
            {
                printf("No hay una mascota con el id %d\n", id);
            }
            else
            {
                system("cls");
                printf("      Id       Nombre       Tipo         Color     Edad Vacunado\n");
                printf("-----------------------------------------------------------------------\n");
                mostrarMascota(vec[indice], colores, tamColores, tipos, tamTipos);

                do
                {
                    printf("\n\n");
                    switch(menuModificarMascota())
                    {
                    case 1:
                        utn_getTiposMod(tipos, tamTipos, &auxMascota.idTipo);
                        vec[indice].idTipo=auxMascota.idTipo;
                        printf("Se ha modificado el tipo\n");
                        break;
                    case 2:
                        utn_getRespuesta(&auxMascota.vacunado, "Ingrese nuevo estado de vacunacion del animal(s/n): ", "Error. ");
                        vec[indice].vacunado=auxMascota.vacunado;
                        printf("Se ha modificado el estado de vacunacion\n");
                        break;
                    case 3:
                        salir='s';
                        break;
                    }
                }
                while(salir!='s');
                todoOk=1;
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar mascota\n");
        }
    }
    return todoOk;
}

int mostrarMascota(eMascota m, eColor colores[], int tamColores, eTipo tipos[], int tamTipos)
{
    int todoOk=0;
    char descColor[20];
    char descTipo[20];

    if(colores!=NULL && tamColores>0 && tipos!=NULL && tamTipos>0)
    {
        cargarDescripcionColor(colores, tamColores, m.idColor, descColor);
        cargarDescripcionTipo(tipos, tamTipos, m.idTipo, descTipo);

        printf("  %5d   %10s   %10s   %10s   %5d   %2c\n", m.id, m.nombre, descTipo, descColor, m.edad, m.vacunado);
        todoOk=1;
    }

    return todoOk;
}

int listarMascotas(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos)
{
    int todoOK=0;
    int flag=0;
    if(vec!=NULL && tam>0)
    {
        ordenarMascotasPorTipoYNombre(vec, tam);
        //system("cls");
        printf("       *** Listado de mascotas ***\n\n");
        printf("      Id       Nombre       Tipo         Color     Edad Vacunado\n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                mostrarMascota(vec[i], colores, tamColores, tipos, tamTipos);
                flag++;
            }
        }
        if(flag==0)
        {
            printf("   No hay mascotas en el sistema");
        }
        printf("\n\n");
        todoOK=1;
    }
    return todoOK;
}

int ordenarMascotasPorTipoYNombre(eMascota vec[], int tam)
{
    int todoOk = 0;
    eMascota auxMascota;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {

                if( ( (vec[i].idTipo == vec[j].idTipo) && (stricmp(vec[i].nombre, vec[j].nombre) > 0) )
                   || (vec[i].idTipo > vec[j].idTipo)  )
                {
                    auxMascota = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxMascota;
                }

            }
        }
      todoOk = 1;
    }
    return todoOk;
}


int bajaMascota(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos)
{
    int todoOk =0;
    int indice;
    int id;
    char confirma;
    if(vec!=NULL && tam > 0 && colores!=NULL && tamColores>0 && tipos!=NULL && tamTipos>0)
    {
        listarMascotas(vec, tam, colores, tamColores, tipos, tamTipos);
        printf("\n\n");
        printf("Ingrese id: ");
        scanf("%d", &id);
        if(buscarMascota(vec, tam, id, &indice))
        {
            if(indice==-1)
            {
                printf("No hay una mascota con el id %d\n", id);
            }
            else
            {
                printf("\n\n");
                printf("      Id       Nombre       Tipo         Color     Edad Vacunado\n");
                printf("-----------------------------------------------------------------------\n");
                mostrarMascota(vec[indice], colores, tamColores, tipos, tamTipos);
                printf("\n\n");
                utn_getRespuesta(&confirma, "Confirma baja?(s/n): ", "Error. ");
                if(confirma=='n')
                {
                    printf("Baja cancelada por el usuario\n");
                }
                else
                {
                    vec[indice].isEmpty=1;
                    printf("Baja realizada con exito\n");
                    todoOk=1;
                }
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar mascota\n");
        }
    }
    return todoOk;
}

int cargarDescripcionMascota(eMascota mascotas[], int tam, int id, char descripcion[])
{
    int todoOk=0;

    if(mascotas!=NULL && tam>0 && validarMascotas(mascotas, tam, id) && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
           if(mascotas[i].id==id)
           {
               strcpy(descripcion, mascotas[i].nombre);
               break;
           }
        }

        todoOk=1;
    }

    return todoOk;
}

int validarMascotas(eMascota mascotas[], int tam, int id)
{
    int todoOk=0;

    if(mascotas!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
           if(mascotas[i].id==id)
           {
              todoOk=1;
              break;
           }
        }
    }

    return todoOk;
}

int utn_getMascotas(eMascota mascotas[], int tam, int* pId, eColor colores[], int tamCol, eTipo tipos[], int tamTipos)
{
    int todoOk=0;
    int x;
    if(mascotas!=NULL && tam>0 && pId!=NULL && colores!=NULL && tamCol>0 && tipos!=NULL && tamTipos>0)
    {
        listarMascotas(mascotas, tam, colores, tamCol, tipos, tamTipos);
        printf("Ingrese el id de la mascota: ");
        fflush(stdin);
        while(scanf("%d", &x)==0 || !validarMascotas(mascotas, tam, x))
        {
            printf("Error. Id invalido. Reingrese el id de la mascota: ");
            fflush(stdin);
        }
        *pId=x;
        todoOk=1;
    }
    return todoOk;
}
