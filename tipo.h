#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}
eTipo;


#endif // TIPO_H_INCLUDED
/** \brief lista los tipos de animales que se encuentran en el array
 *
 * \param tipos[] eTipo array de tipos
 * \param tam int tamanio del array de tipos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int listarTipos(eTipo tipos[], int tam);
/** \brief valida que el id ingresado coincida con uno del array de tipos
 *
 * \param tipos[] eTipo array de tipos
 * \param tam int tamanio del array de tipos
 * \param id int id a validar
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int validarTipos(eTipo tipos[], int tam, int id);
/** \brief carga la descripcion del tipo correspondiente a la id recibida
 *
 * \param tipos[] eTipo array de tipos
 * \param tam int tamanio del array de tipos
 * \param id int id de tipo recibida
 * \param descripcion[] char direccion de memoria donde se guardara la descripcion del tipo
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);
/** \brief permite al usuario ingresar un id de tipo y la valida
 *
 * \param tipos[] eTipo array de tipos
 * \param tam int tamanio del array de tipos
 * \param pId int* direccion de memoria donde se guardara el id
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int utn_getTipos(eTipo tipos[], int tam, int* pId);
/** \brief permite al usuario ingresar un nuevo id de tipo y la valida
 *
 * \param tipos[] eTipo array de tipos
 * \param tam int tamanio del array de tipos
 * \param pId int* direccion de memoria donde se guardara el nuevo id
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int utn_getTiposMod(eTipo tipos[], int tam, int* pId);
