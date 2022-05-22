#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}
eFecha;

#endif // FECHA_H_INCLUDED

/** \brief permite al usuario ingresar una fecha y la valida
 *
 * \param pResultado eFecha* es donde se guarda la fecha ingresada
 * \param mensaje char* es el mensaje que pide el ingreso de la fecha
 * \param mensajeError char* es el mensaje que indica al usuario que hubo un error al ingresar la fecha
 * \param anioMinimo int anio maximo que se permite ingresar
 * \param anioMaximo int anio minimo que se permite ingresar
 * \return int devuelve 1 si no hubo problemas con los punteros y 0 si si los hubo
 *
 */
int utn_getFecha(eFecha* pResultado, char* mensaje, char* mensajeError, int anioMinimo, int anioMaximo);
