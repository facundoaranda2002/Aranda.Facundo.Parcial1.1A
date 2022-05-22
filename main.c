#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "fecha.h"
#include "validaciones.h"
#include "tipo.h"
#include "mascota.h"
#include "servicio.h"
#include "trabajo.h"
#include "color.h"


#define TAM 5
#define TAM_COLOR 5
#define TAM_TIPO 5
#define TAM_SERVICIO 3
#define TAM_TRABAJO 5

int main()
{
    eMascota listaMascotas[TAM];
    eTrabajo trabajos[TAM_TRABAJO];
    char salir='n';
    int contadorMascotas=0;
    int contadorTrabajos=0;
    int proximoIdMascota=1;
    int proximoIdTrabajo=1;


    eColor colores[TAM_COLOR]=
    {
       {5000, "Negro"},
       {5001, "Blanco"},
       {5002, "Rojo"},
       {5003, "Gris"},
       {5004, "Azul"}
    };

    eTipo tipos[TAM_TIPO]=
    {
       {1000, "Ave"},
       {1001, "Perro"},
       {1002, "Roedor"},
       {1003, "Gato"},
       {1004, "Pez"}
    };

    eServicio servicios[TAM_SERVICIO]=
    {
       {20000, "Corte", 450},
       {20001, "Desparasitado", 800},
       {20002, "Castrado", 600}
    };

    inicializarMascotas(listaMascotas, TAM);
    inicializarTrabajos(trabajos, TAM_TRABAJO);

    do
    {
        switch(menu())
        {
            case 'a':
                system("cls");
                if(altaMascota(listaMascotas, TAM, &proximoIdMascota, colores, TAM_COLOR, tipos, TAM_TIPO))
                {
                    printf("Mascota agregada con exito!!!\n");
                    contadorMascotas++;
                }
                else
                {
                    printf("Problema al hacer el alta de la mascota\n");
                }
                break;
            case 'b':
                system("cls");
                if(contadorMascotas==0)
                {
                    printf("No hay mascotas en el sistema\n");
                }
                else
                {
                    if(!modificarMascota(listaMascotas, TAM, colores, TAM_COLOR, tipos, TAM_TIPO))
                    {
                        printf("Problema al hacer la modificacion de la mascota\n");
                    }
                }
                break;
            case 'c':
                system("cls");
                if(contadorMascotas==0)
                {
                    printf("No hay mascotas en el sistema\n");
                }
                else
                {
                    if(!bajaMascota(listaMascotas, TAM, colores, TAM_COLOR, tipos, TAM_TIPO))
                    {
                        printf("Problema al hacer la baja de la mascota\n");
                    }
                    else
                    {
                        contadorMascotas--;
                    }
                }
                break;
            case 'd':
                system("cls");
                if(contadorMascotas==0)
                {
                    printf("No hay mascotas en el sistema\n");
                }
                else
                {
                    if(!listarMascotas(listaMascotas, TAM, colores, TAM_COLOR, tipos, TAM_TIPO))
                    {
                        printf("Problema al hacer el listado de mascotas\n");
                    }
                }
                break;
            case 'e':
                system("cls");
                if(!listarTipos(tipos, TAM_TIPO))
                {
                    printf("Problema al hacer el listado de los tipos\n");
                }
                break;
            case 'f':
                system("cls");
                if(!listarColores(colores, TAM_COLOR))
                {
                    printf("Problema al hacer el listado de los colores\n");
                }
                break;
            case 'g':
                system("cls");
                if(!listarServicios(servicios, TAM_SERVICIO))
                {
                    printf("Problema al hacer el listado de los servicios\n");
                }
                break;
            case 'h':
                system("cls");
                if(contadorMascotas!=0)
                {
                    if(altaTrabajo(listaMascotas, TAM, &proximoIdTrabajo, servicios, TAM_SERVICIO, trabajos, TAM_TRABAJO, colores, TAM_COLOR, tipos, TAM_TIPO))
                    {
                        printf("Trabajo agregado con exito!!!\n");
                        contadorTrabajos++;
                    }
                    else
                    {
                        printf("Problema al hacer el alta del trabajo\n");
                    }
                }
                else
                {
                    printf("No hay mascotas en el sistema\n");
                }
                break;
            case 'i':
                system("cls");
                if(contadorTrabajos==0)
                {
                    printf("No hay trabajos en el sistema\n");
                }
                else
                {
                    if(listarTrabajos(trabajos, TAM_TRABAJO, listaMascotas, TAM, servicios, TAM_SERVICIO)==0)
                    {
                        printf("Problema al hacer el listado de trabajos\n");
                    }
                }
                break;
            case 'z':
                system("cls");
                salir='s';
                break;
            default:
                system("cls");
                printf("Opcion invalida\n");
                break;
        }
        system("pause");
    }
    while(salir!='s');

    return 0;
}
