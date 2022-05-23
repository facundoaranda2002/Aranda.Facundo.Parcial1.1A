#include "mascota.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}
eTrabajo;

#endif // TRABAJO_H_INCLUDED
/** \brief inicializa los valores isEmpty del vector de trabajos en 1
 *
 * \param vec[] eTrabajo array de trabajos
 * \param tam int tamanio del array de trabajos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int inicializarTrabajos(eTrabajo vec[], int tam);
/** \brief busca una posicion libre en el vector de trabajos y la devuelve
 *
 * \param vec[] eTrabajo array de trabajos
 * \param tam int tamanio del array de trabajos
 * \param pIndex int* direccion de memoria donde se guarda la ubicacion del primer indice libre del array de trabajos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex);
/** \brief realiza el alta de un trabajo
 *
 * \param vec[] eMascota array de mascotas
 * \param tam int tamanio del array de mascotas
 * \param pId int* direccion de memoria que guarda el id asignado automaticamente al nuevo trabajo
 * \param servicios[] eServicio array de servicios
 * \param tamServ int tamanio del array de servicios
 * \param trabajos[] eTrabajo array de trabajos
 * \param tamTrab int tamanio del array de trabajos
 * \param colores[] eColor array de colores
 * \param tamColores int tamanio del array de colores
 * \param tipos[] eTipo array de tipos
 * \param tamTipos int tamanio del array de tipos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int altaTrabajo(eMascota vec[], int tam, int* pId, eServicio servicios[], int tamServ, eTrabajo trabajos[], int tamTrab, eColor colores[], int tamColores, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes);
/** \brief lista los trabajos que se encuentran en el array
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam int tamanio del array de trabajos
 * \param mascotas[] eMascota array de mascotas
 * \param tamMasc int tamanio del array de mascotas
 * \param servicios[] eServicio array de servicios
 * \param tamServ int tamanio del array de servicios
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int listarTrabajos(eTrabajo trabajos[], int tam, eMascota mascotas[], int tamMasc, eServicio servicios[], int tamServ);

int hardcodearTrabajos(eTrabajo vec[], int tam, int cant, int* pId);

int utn_getTrabajos(eMascota mascotas[], int tam, int* pId, eTrabajo trabajos[], int tamTrab, eServicio servicios[], int tamServ);

int validarTrabajos(eTrabajo trabajos[], int tam, int id);

//informes

int informarMascotaColor(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes);

int informarPromedioMascotasVacunadas(eMascota vec[], int tam);

int informarMascotasMenorEdad(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes);

int informarMascotasXTipo(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes);

int informarMascotasColorYTipo(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes);

int informColorMasMascotas(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes);

int informarServicio(eServicio servicios[], int tam, eMascota mascotas[], int tamMasc, eTrabajo trabajos[], int tamTrab);
