#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "validaciones.h"

int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
    int todoOk=0;
    int num;
    int resultadoScanF=0;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
        do
        {
            printf(mensaje);
            if(scanf("%d",&num)==1)
            {
                if(num<=maximo && num>=minimo)
                {
                    *pResultado = num;
                    resultadoScanF=1;
                }
                else
                {
                    printf(mensajeError);
                }
            }
            else
            {
                fflush(stdin);
                printf(mensajeError);
            }
        }
        while(resultadoScanF!=1);
        todoOk=1;
    }
    return todoOk;

}

int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
    int todoOk=0;
    float num;
    int resultadoScanF=0;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
       do
        {
            printf(mensaje);
            if(scanf("%f",&num)==1)
            {
                if(num<=maximo && num>=minimo)
                {
                    *pResultado = num;
                    resultadoScanF=1;
                }
                else
                {
                    printf(mensajeError);
                }
            }
            else
            {
                fflush(stdin);
                printf(mensajeError);
            }
        }
        while(resultadoScanF!=1);
        todoOk=1;
    }
    return todoOk;
}


int utn_getCadenaChar(char pResultado[], char* mensaje, char* mensajeError, int minimo, int maximo)
{
    int todoOk=0;
    char auxCad[100];
    int resultadoScanF=0;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
       do
        {
            printf(mensaje);
            fflush(stdin);
            gets(auxCad);

            if((strlen(auxCad) >= minimo) && (strlen(auxCad) < maximo))
            {
                strcpy(pResultado, auxCad);
                resultadoScanF=1;
            }
            else
            {
                fflush(stdin);
                printf(mensajeError);
            }

        }
        while(resultadoScanF!=1);
        todoOk=1;
    }
    return todoOk;
}
/*
int utn_getSexo(char* pResultado, char* mensaje, char* mensajeError)
{
    int todoOk=0;
    char sexo;
    int resultadoScanF=0;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
       do
        {
            printf(mensaje);
            fflush(stdin);
            if(scanf("%c",&sexo)==1)
            {
                sexo=tolower(sexo);
                if(sexo=='f' || sexo=='m')
                {
                    *pResultado = sexo;
                    resultadoScanF=1;
                }
                else
                {
                    printf(mensajeError);
                }
            }
            else
            {
                fflush(stdin);
                printf(mensajeError);
            }
        }
        while(resultadoScanF!=1);
        todoOk=1;
    }
    return todoOk;
}
*/
int utn_getRespuesta(char* pResultado, char* mensaje, char* mensajeError)
{
    int todoOk=0;
    char res;
    int resultadoScanF=0;
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
       do
        {
            printf(mensaje);
            fflush(stdin);
            if(scanf("%c",&res)==1)
            {
                res=tolower(res);
                if(res=='s' || res=='n')
                {
                    *pResultado = res;
                    resultadoScanF=1;
                }
                else
                {
                    printf(mensajeError);
                }
            }
            else
            {
                fflush(stdin);
                printf(mensajeError);
            }
        }
        while(resultadoScanF!=1);
        todoOk=1;
    }
    return todoOk;
}
