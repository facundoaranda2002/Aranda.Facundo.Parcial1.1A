#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
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
#define MASC_HARD 5
#define TRAB_HARD 5

int main()
{
    eMascota listaMascotas[TAM];
    eTrabajo trabajos[TAM_TRABAJO];
    eCliente clientes[5]=
    {
       {1, "ala", 'f'},
       {2, "ola", 'm'},
       {3, "ila", 'f'},
       {4, "ela", 'm'},
       {5, "fala", 'f'}
    };

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
                    if(!modificarMascota(listaMascotas, TAM, colores, TAM_COLOR, tipos, TAM_TIPO, clientes, 5))
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
                    if(!bajaMascota(listaMascotas, TAM, colores, TAM_COLOR, tipos, TAM_TIPO, clientes, 5))
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
                    if(!listarMascotas(listaMascotas, TAM, colores, TAM_COLOR, tipos, TAM_TIPO, clientes, 5))
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
                    if(altaTrabajo(listaMascotas, TAM, &proximoIdTrabajo, servicios, TAM_SERVICIO, trabajos, TAM_TRABAJO, colores, TAM_COLOR, tipos, TAM_TIPO, clientes, 5))
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
            case 'j':
                system("cls");
                proximoIdMascota=1;
                if(hardcodearMascotas(listaMascotas, TAM, MASC_HARD, &proximoIdMascota))
                {
                    printf("Se han harcodeado %d mascotas\n", MASC_HARD);
                    contadorMascotas=contadorMascotas+MASC_HARD;
                }
                else
                {
                    printf("Problema al hardcodear mascotas\n");
                }
                break;
            case 'k':
                system("cls");
                if(contadorMascotas<MASC_HARD)
                {
                    printf("Faltan mascotas en el sistema\n");
                }
                else
                {
                    proximoIdTrabajo=1;
                    if(hardcodearTrabajos(trabajos, TAM_TRABAJO, TRAB_HARD, &proximoIdTrabajo))
                    {
                        printf("Se han harcodeado %d trabajos\n", TRAB_HARD);
                        contadorTrabajos=contadorTrabajos+TRAB_HARD;
                    }
                    else
                    {
                        printf("Problema al hardcodear trabajos\n");
                    }
                }
                break;
            case '1':
                system("cls");
                if(contadorMascotas==0)
                {
                    printf("No hay mascotas en el sistema\n");
                }
                else
                {
                    if(!informarMascotaColor(listaMascotas, TAM, colores, TAM_COLOR, tipos, TAM_TIPO, clientes, 5))
                    {
                        printf("Problema al informar mascotas por color\n");
                    }
                }
                break;
            case '2':
                system("cls");
                if(contadorMascotas==0)
                {
                    printf("No hay mascotas en el sistema\n");
                }
                else
                {
                    if(!informarPromedioMascotasVacunadas(listaMascotas, TAM))
                    {
                        printf("Problema al informar mascotas vacunadas\n");
                    }
                }
                break;
            case '3':
                system("cls");
                if(contadorMascotas==0)
                {
                    printf("No hay mascotas en el sistema\n");
                }
                else
                {
                    if(!informarMascotasMenorEdad(listaMascotas, TAM, colores, TAM_COLOR, tipos, TAM_TIPO, clientes, 5))
                    {
                        printf("Problema al informar mascotas menor edad\n");
                    }
                }
                break;
            case '4':
                system("cls");
                if(contadorMascotas==0)
                {
                    printf("No hay mascotas en el sistema\n");
                }
                else
                {
                    if(!informarMascotasXTipo(listaMascotas, TAM, colores, TAM_COLOR, tipos, TAM_TIPO, clientes, 5))
                    {
                        printf("Problema al informar mascotas por tipo\n");
                    }
                }
                break;
            case '5':
                system("cls");
                if(contadorMascotas==0)
                {
                    printf("No hay mascotas en el sistema\n");
                }
                else
                {
                    if(!informarMascotasColorYTipo(listaMascotas, TAM, colores, TAM_COLOR, tipos, TAM_TIPO, clientes, 5))
                    {
                        printf("Problema al informar mascotas de color y tipo\n");
                    }
                }
                break;
            case '6':
                system("cls");
                if(contadorMascotas==0)
                {
                    printf("No hay mascotas en el sistema\n");
                }
                else
                {
                    if(!informColorMasMascotas(listaMascotas, TAM, colores, TAM_COLOR, tipos, TAM_TIPO, clientes, 5))
                    {
                        printf("Problema al informar color con mas mascotas\n");
                    }
                }
                break;
            case '7':
                system("cls");
                if(contadorTrabajos==0)
                {
                    printf("No hay trabajos en el sistema\n");
                }
                else
                {
                    if(!informarServicioMascota(listaMascotas, TAM, servicios, TAM_SERVICIO, trabajos, TAM_TRABAJO, colores, TAM_COLOR, tipos, TAM_TIPO, clientes, 5))
                    {
                        printf("Problema al informar trabajos a una mascota\n");
                    }
                }
                break;
            case '8':
                system("cls");
                if(contadorTrabajos==0)
                {
                    printf("No hay trabajos en el sistema\n");
                }
                else
                {
                    if(!informarSumaImportesMasc(listaMascotas, TAM, servicios, TAM_SERVICIO, trabajos, TAM_TRABAJO, colores, TAM_COLOR, tipos, TAM_TIPO, clientes, 5))
                    {
                        printf("Problema al informar suma de importes de trabajos a una mascota\n");
                    }
                }
                break;
            case '9':
                system("cls");
                if(contadorTrabajos==0)
                {
                    printf("No hay trabajos en el sistema\n");
                }
                else
                {
                    if(!informarServicio(servicios, TAM_SERVICIO, listaMascotas, TAM, trabajos, TAM_TRABAJO))
                    {
                        printf("Problema al informar servicios\n");
                    }
                }
                break;
            case '0':
                system("cls");
                if(contadorTrabajos==0)
                {
                    printf("No hay trabajos en el sistema\n");
                }
                else
                {
                    if(!informarServicioFecha(listaMascotas, TAM, servicios, TAM_SERVICIO, trabajos, TAM_TRABAJO, colores, TAM_COLOR, tipos, TAM_TIPO, clientes, 5))
                    {
                        printf("Problema al informar servicios\n");
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
