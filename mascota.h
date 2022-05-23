#include "color.h"
#include "tipo.h"
#include "validaciones.h"
#include "servicio.h"

#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int idTipo;
    int idColor;
    int edad;
    char vacunado;
    int isEmpty;
}
eMascota;

#endif // MASCOTA_H_INCLUDED


/** \brief inicializa los valores isEmpty del vector de mascotas en 1
 *
 * \param vec[] eMascota array de mascotas
 * \param tam int tamanio del array de mascotas
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int inicializarMascotas(eMascota vec[], int tam);
/** \brief muestra el menu de opciones principal y devuelve la opcion elegida
 *
 * \return char devuelve la opcion elegida
 *
 */
char menu();
/** \brief busca una posicion libre en el vector de mascotas y la devuelve
 *
 * \param vec[] eMascota array de mascotas
 * \param tam int tamanio del array de mascotas
 * \param pIndex int* direccion de memoria donde se guarda la ubicacion del primer indice libre del array de mascotas
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int buscarMascotaLibre(eMascota vec[], int tam, int* pIndex);
/** \brief realiza el alta de una mascota
 *
 * \param vec[] eMascota array de mascotas
 * \param tam int tamanio del array de mascotas
 * \param pId int* direccion de memoria que guarda el id asignado automaticamente a la nueva mascota
 * \param colores[] eColor array de colores
 * \param tamColores int tamanio del array de colores
 * \param tipos[] eTipo array de tipos
 * \param tamTipos int tamanio del array de tipos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int altaMascota(eMascota vec[], int tam, int* pId, eColor colores[], int tamColores, eTipo tipos[], int tamTipos);
/** \brief busca una mascota por id y devuelve la posicion de esta en el array
 *
 * \param vec[] eMascota array de mascotas
 * \param tam int tamanio del array de mascotas
 * \param id int id de la mascota a buscar
 * \param pIndex int* direccion de memoria donde se guarda la posicion de la mascota encontrada o -1 si no se encontro
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int buscarMascota(eMascota vec[], int tam, int id, int* pIndex);
/** \brief muestra el menu de opciones para modificar la mascota y devuelve la opcion ingresada
 *
 * \return int devuelve la opcion elegida
 *
 */
int menuModificarMascota();
/** \brief modifica ciertos apartados de una mascota previamente ingresada
 *
 * \param vec[] eMascota array de mascotas
 * \param tam int tamanio del array de mascotas
 * \param colores[] eColor array de colores
 * \param tamColores int tamanio del array de colores
 * \param tipos[] eTipo array de tipos
 * \param tamTipos int tamanio del array de tipos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int modificarMascota(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos);
/** \brief muestra los datos de una mascota
 *
 * \param m eMascota variable con los datos de la mascota
 * \param colores[] eColor array de colores
 * \param tamColores int tamanio del array de colores
 * \param tipos[] eTipo array de tipos
 * \param tamTipos int tamanio del array de tipos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int mostrarMascota(eMascota m, eColor colores[], int tamColores, eTipo tipos[], int tamTipos);
/** \brief lista las mascotas que se encuentran en el array
 *
 * \param vec[] eMascota array de mascotas
 * \param tam int tamanio del array de mascotas
 * \param colores[] eColor array de colores
 * \param tamColores int tamanio del array de colores
 * \param tipos[] eTipo array de tipos
 * \param tamTipos int tamanio del array de tipos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int listarMascotas(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos);
/** \brief ordena el array de mascotas por tipo y nombre
 *
 * \param vec[] eMascota array de mascotas
 * \param tam int tamanio del array de mascotas
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int ordenarMascotasPorTipoYNombre(eMascota vec[], int tam);
/** \brief realiza la baja de una mascota del array
 *
 * \param vec[] eMascota array de mascotas
 * \param tam int tamanio del array de mascotas
 * \param colores[] eColor array de colores
 * \param tamColores int tamanio del array de colores
 * \param tipos[] eTipo array de tipos
 * \param tamTipos int tamanio del array de tipos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int bajaMascota(eMascota vec[], int tam, eColor colores[], int tamColores, eTipo tipos[], int tamTipos);
/** \brief carga el nombre de la mascota correspondiente a la id recibida
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tam int tamanio del array de mascotas
 * \param id int id de la mascota recibida
 * \param descripcion[] char direccion de memoria donde se guardara el nombre de la mascota
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int cargarDescripcionMascota(eMascota mascotas[], int tam, int id, char descripcion[]);
/** \brief valida que el id ingresado coincida con uno del array de mascotas
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tam int tamanio del array de mascotas
 * \param id int id de la mascota recibida
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int validarMascotas(eMascota mascotas[], int tam, int id);
/** \brief permite al usuario ingresar un id de mascota y lo valida
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tam int tamanio del array de mascotas
 * \param pId int* direccion de memoria donde se guardara el id
 * \param colores[] eColor array de colores
 * \param tamCol int tamanio del array de colores
 * \param tipos[] eTipo array de tipos
 * \param tamTipos int tamanio del array de tipos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int utn_getMascotas(eMascota mascotas[], int tam, int* pId, eColor colores[], int tamCol, eTipo tipos[], int tamTipos);

int hardcodearMascotas(eMascota vec[], int tam, int cant, int* pId);

