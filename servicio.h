#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}
eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief lista los servicios que se encuentran en el array
 *
 * \param servicios[] eServicio array de servicios
 * \param tam int tamanio del array de servicios
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int listarServicios(eServicio servicios[], int tam);
/** \brief carga la descripcion del servicio correspondiente a la id recibida
 *
 * \param servicios[] eServicio array de servicios
 * \param tam int tamanio del array de servicios
 * \param id int id de servicios recibida
 * \param descripcion[] char direccion de memoria donde se guardara la descripcion del servicio
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int cargarDescripcionServicio(eServicio servicios[], int tam, int id, char descripcion[]);
/** \brief valida que el id ingresado coincida con uno del array de servicios
 *
 * \param servicios[] eServicio array de servicios
 * \param tam int tamanio del array de servicios
 * \param id int id a validar
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int validarServicios(eServicio servicios[], int tam, int id);
/** \brief permite al usuario ingresar un id de servicios y la valida
 *
 * \param servicios[] eServicio array de servicios
 * \param tam int tamanio del array de servicios
 * \param pId int* direccion de memoria donde se guardara el id
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int utn_getServicios(eServicio servicios[], int tam, int* pId);

