#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}
eColor;

#endif // COLOR_H_INCLUDED
/** \brief lista los colores de animales que se encuentran en el array
 *
 * \param colores[] eColor array de colores
 * \param tam int tamanio del array de colores
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int listarColores(eColor colores[], int tam);
/** \brief valida que el id ingresado coincida con uno del array de colores
 *
 * \param colores[] eColor array de colores
 * \param tam int tamanio del array de colores
 * \param id int id a validar
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int validarColores(eColor colores[], int tam, int id);
/** \brief carga la descripcion del color correspondiente a la id recibida
 *
 * \param colores[] eColor array de colores
 * \param tam int tamanio del array de colores
 * \param id int id de color recibida
 * \param descripcion[] char direccion de memoria donde se guardara la descripcion del color
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int cargarDescripcionColor(eColor colores[], int tam, int id, char descripcion[]);
/** \brief permite al usuario ingresar un id de color y la valida
 *
 * \param colores[] eColor array de colores
 * \param tam int tamanio del array de colores
 * \param pId int* direccion de memoria donde se guardara el id
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int utn_getColores(eColor colores[], int tam, int* pId);
