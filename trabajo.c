#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "trabajo.h"
#include "fecha.h"


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

int altaTrabajo(eMascota vec[], int tam, int* pId, eServicio servicios[], int tamServ, eTrabajo trabajos[], int tamTrab, eColor colores[], int tamColores, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes)
{
    int todoOk = 0;
    int indice;
    eTrabajo nuevoTrabajo;
    eFecha fecha;

    if(vec!=NULL && tam > 0 && servicios!=NULL && tamServ>0 && trabajos!=NULL && tamTrab>0 && pId!=NULL && colores!=NULL && tamColores>0 && tipos!=NULL && tamTipos>0 && clientes != NULL && tamClientes>0)
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

                utn_getMascotas(vec, tam, &nuevoTrabajo.idMascota, colores, tamColores, tipos, tamTipos, clientes, tamClientes);
                printf("\n\n");

                utn_getServicios(servicios, tamServ, &nuevoTrabajo.idServicio);
                printf("\n\n");

                utn_getFecha(&fecha, "Ingrese la fecha del trabajo: ", "Error. ", 2000, 2030);
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

    if(trabajos!=NULL && tam>0 && mascotas!=NULL && tamMasc>0 && servicios!=NULL && tamServ)
    {
        system("cls");
        printf("    *** Lista de trabajos ***\n\n");
        printf("     Id        Mascota         Servicio     Fecha\n");
        printf("--------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                cargarDescripcionMascota(mascotas, tamMasc, trabajos[i].idMascota, descripcionMasc);
                cargarDescripcionServicio(servicios, tamServ, trabajos[i].idServicio, descripcionServ);
                printf("   %4d    %10s    %15s    %02d/%02d/%d \n", trabajos[i].id, descripcionMasc, descripcionServ, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
            }
        }
        printf("\n\n");
        todoOk=1;
    }

    return todoOk;
}

int hardcodearTrabajos(eTrabajo vec[], int tam, int cant, int* pId)
{

    int todoOk = 0;
    eTrabajo impostores[] =
    {
        {0, 1, 20000, {2,5,2022}, 0},
        {0, 3, 20001, {3,5,2022}, 0},
        {0, 1, 20000, {4,5,2022}, 0},
        {0, 2, 20002, {2,5,2022}, 0},
        {0, 4, 20000, {3,5,2022}, 0},
    };

    if(vec != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = impostores[i];
            vec[i].id = *pId;
            *pId = *pId +1;

        }
        todoOk = 1;
    }
    return todoOk;
}

int informarServicio(eServicio servicios[], int tam, eMascota mascotas[], int tamMasc, eTrabajo trabajos[], int tamTrab)
{
    int todoOk =0;
    char descripcionMasc[20];
    char descripcionServ[20];
    int id;
    int flag=0;
    if(servicios!=NULL && tam > 0 && mascotas!=NULL && tamMasc>0 && trabajos!=NULL && tamTrab>0)
    {
        printf("    *** Informe de servicios ***\n\n");
        printf("--------------------------------------------------\n");
        if(utn_getServicios(servicios, tam, &id))
        {
            printf("\n\n");
            printf("          Servicio       Nombre       Fecha\n");
            printf("--------------------------------------------------\n");
            for(int i=0; i<tamTrab; i++)
            {
                if(!trabajos[i].isEmpty && trabajos[i].idServicio==id)
                {
                    cargarDescripcionMascota(mascotas, tamMasc, trabajos[i].idMascota, descripcionMasc);
                    cargarDescripcionServicio(servicios, tam, trabajos[i].idServicio, descripcionServ);
                    printf(" %15s    %10s    %02d/%02d/%d \n", descripcionServ, descripcionMasc, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
                    flag=1;
                }
            }
            if(!flag)
            {
                cargarDescripcionServicio(servicios, tam, id, descripcionServ);
                printf("No hay mascotas atendidas con el servicio de %s\n", descripcionServ);
            }
            printf("\n\n");
            todoOk=1;
        }
    }
    return todoOk;
}

int utn_getTrabajos(eMascota mascotas[], int tam, int* pId, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ)
{
    int todoOk=0;
    int x;
    if(mascotas!=NULL && tam>0 && pId!=NULL && trabajos!=NULL && tamTrab>0 && servicios!=NULL && tamServ>0)
    {
        listarTrabajos(trabajos, tamTrab, mascotas, tam, servicios, tamServ);
        printf("Ingrese el id del trabajo: ");
        fflush(stdin);
        while(scanf("%d", &x)==0 || !validarTrabajos(trabajos, tamTrab, x))
        {
            printf("Error. Id invalido. Reingrese el id del trabajo: ");
            fflush(stdin);
        }
        *pId=x;
        todoOk=1;
    }
    return todoOk;
}

int validarTrabajos(eTrabajo trabajos[], int tam, int id)
{
    int todoOk=0;

    if(trabajos!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
           if(trabajos[i].id==id)
           {
              todoOk=1;
              break;
           }
        }
    }
    return todoOk;
}

int informarMascotaColor(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes)
{
    int todoOk = 0;
    int idColor;
    int flag = 1;
    char descripcion[20];


    if(vec!=NULL && tam>0 && colores!=NULL && tamColores>0 && tipos!=NULL && tamTipos>0 && clientes!=NULL && tamClientes>0)
    {
        system("cls");
        printf("   *** Listado de mascotas de un color ***\n");
        printf("---------------------------------------------------\n");

        utn_getColores(colores, tamColores, &idColor);

        printf("      Id       Nombre       Tipo         Color     Edad Vacunado   Cliente\n");
        printf("------------------------------------------------------------------------------\n");

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && vec[i].idColor == idColor)
            {
                mostrarMascota(vec[i], colores, tamColores, tipos, tamTipos, clientes, tamClientes);
                flag = 0;
            }
        }
        if(flag)
        {
            cargarDescripcionColor(colores, tamColores, idColor, descripcion);
            printf("No hay mascotas registradas con el color %s\n", descripcion);
        }
        printf("\n");

        todoOk = 1;
    }
    return todoOk;
}

int informarPromedioMascotasVacunadas(eMascota vec[], int tam)
{

    int todoOk = 0;
    int acumMasc = 0;
    int contMasc = 0;
    float promedio = 0;

    if(vec != NULL && tam > 0 )
    {

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty)
            {
                contMasc++;
                if(vec[i].vacunado=='s')
                {
                  acumMasc++;
                }
            }

        }

        if(contMasc > 0)
        {
            promedio = (float)acumMasc / contMasc;
        }

        system("cls");
        printf("    *** Informe Promedio Vacunados   ***\n\n");
        printf("Promedio vacunados: %.2f porciento\n", promedio*100);

        todoOk = 1;
    }
    return todoOk;
}

int informarMascotasMenorEdad(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes)
{
    int todoOk = 0;
    int menorEdad;
    int flag = 0;

    if(vec!=NULL && tam>0 && colores!=NULL && tamColores>0 && tipos!=NULL && tamTipos>0 && clientes!=NULL && tamClientes>0)
    {

        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty && (vec[i].edad < menorEdad || !flag)  )
            {
                menorEdad = vec[i].edad;
                flag = 1;
            }
        }

        system("cls");
        printf("     *** Informe Mascota menor edad   ***\n");
        printf("------------------------------------------\n\n");

        if(flag == 0)
        {
            printf("No hay Mascotas en el sistema\n\n");
        }
        else
        {
            printf("      Id       Nombre       Tipo         Color     Edad Vacunado   Cliente\n");
            printf("------------------------------------------------------------------------------\n");

            for(int i=0; i < tam; i++)
            {
                if( !vec[i].isEmpty && vec[i].edad == menorEdad)
                {
                    mostrarMascota(vec[i], colores, tamColores, tipos, tamTipos, clientes, tamClientes);
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

int informarMascotasXTipo(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes)
{
    int todoOk = 0;
    int flag;

    if(vec!=NULL && tam>0 && colores!=NULL && tamColores>0 && tipos!=NULL && tamTipos>0 && clientes!=NULL && tamClientes>0)
    {
        system("cls");
        printf("    *** Listado de mascotas por tipo  ***\n");
        printf("-----------------------------------------------------\n");

        for(int s=0; s < tamTipos; s++)
        {
            printf("Tipo: %s\n\n", tipos[s].descripcion);
            printf("      Id       Nombre       Tipo         Color     Edad Vacunado   Cliente\n");
            printf("------------------------------------------------------------------------------\n");

            flag = 1;
            for(int e = 0; e < tam; e++)
            {
                if( !vec[e].isEmpty && vec[e].idTipo == tipos[s].id)
                {
                    mostrarMascota(vec[e], colores, tamColores, tipos, tamTipos, clientes, tamClientes);
                    flag = 0;
                }
            }
            if(flag)
            {
                printf("No hay mascotas\n");
            }
            printf("\n\n");

        }
        todoOk = 1;
    }
    return todoOk;
}

int informarMascotasColorYTipo(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes)
{

    int todoOk = 0;
    int contMasc = 0;
    int idTipo;
    int idColor;
    int flag=0;
    char auxTipos[20];
    char auxColor[20];

    if(vec!=NULL && tam>0 && colores!=NULL && tamColores>0 && tipos!=NULL && tamTipos>0 && clientes!=NULL && tamClientes>0)
    {
        system("cls");
        printf("    *** Informe de mascotas de un color y tipo  ***\n");
        printf("-----------------------------------------------------\n");

        utn_getColores(colores, tamColores, &idColor);
        utn_getTipos(tipos, tamTipos, &idTipo);
        cargarDescripcionColor(colores, tamColores, idColor, auxColor);
        cargarDescripcionTipo(tipos, tamTipos, idTipo, auxTipos);

        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty==0 && vec[i].idColor==idColor && vec[i].idTipo==idTipo)
            {
                contMasc=contMasc+1;
                flag=1;
            }
        }
        fflush(stdin);
        if(flag==0)
        {
            printf("No hay mascotas de color %s y de tipo %s en el sistema\n", auxColor, auxTipos);
        }
        else
        {
            printf("Hay %d mascotas de color %s y de tipo %s en el sistema\n", contMasc, auxColor, auxTipos);
        }

        todoOk = 1;
    }
    return todoOk;
}

int informColorMasMascotas(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes)
{
    int todoOk = 0;
    int totalesColor[tamColores];
    int mayor;
    int flag = 1;

       if(vec!=NULL && tam>0 && colores!=NULL && tamColores>0 && tipos!=NULL && tamTipos>0 && clientes!=NULL && tamClientes>0)
        {
            system("cls");
            printf("   ***  Color con mas mascotas ***\n");
            printf("---------------------------------------------------\n");


            for(int i=0; i < tamColores; i++){
                totalesColor[i] = 0;
            }

            for(int s = 0; s < tamColores; s++){
                for(int e = 0; e < tam; e++){
                    if(!vec[e].isEmpty && vec[e].idColor == colores[s].id){
                        totalesColor[s]++;
                    }
                }
            }
            // recorro totales sueldos para conocer el mayor
            for(int s = 0; s < tamColores; s++){
                if(flag || totalesColor[s] > mayor){
                    mayor = totalesColor[s];
                    flag = 0;
                }
            }
            // recorro totales sueldos buscando los lugares donde aparece mayor
            printf("Los colores mas predominantes tienen %d mascotas y son :\n", mayor);
              for(int s = 0; s < tamColores; s++){
                if(totalesColor[s] == mayor){
                    printf("%s\n", colores[s].nombreColor);
                }
            }
          todoOk = 1;
        }
    return todoOk;
}


