#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int utn_getFecha(eFecha* pResultado, char* mensaje, char* mensajeError, int anioMinimo, int anioMaximo)
{
    int todoOk=0;
    eFecha fecha;
    int resultadoScanF=0;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
        do
        {
            printf(mensaje);
            fflush(stdin);
            if(scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio)==3)
            {
                if((fecha.dia>=1 && fecha.dia<=31) && (fecha.mes>=1 && fecha.mes<=12) && (fecha.anio>=anioMinimo && fecha.anio<=anioMaximo))
                {
                    *pResultado = fecha;
                    resultadoScanF=1;
                }
                else
                {
                    printf(mensajeError);
                }
            }
            else
            {
                printf(mensajeError);
            }
        }
        while(resultadoScanF!=1);
        todoOk=1;
    }
    return todoOk;
}
