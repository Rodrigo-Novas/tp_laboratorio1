#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Herramientas.h"

static int getInt(int* pBuffer){
    return scanf("%d",pBuffer);
}

static int getFloat(float* pBuffer){
    return scanf("%f",pBuffer);
}


int utn_getEntero(  int* pEntero, char* msg,
                    char* msgErr,int min, int max,
                    int reintentos){
    int retorno=-1;
    int bufferInt;
    fflush(stdin);
    if(pEntero != NULL && msg != NULL && msgErr != NULL
        && min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( (getInt(&bufferInt) == 1) &&
                (bufferInt >= min && bufferInt <= max))
            {
                *pEntero = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
                printf("%s",msgErr);
            }
        }while(reintentos>=0);

    }
    return retorno;
}

int utn_getFlotante(  float* pFlotante, char* msg, char* msgErr,int min, int max,
                    int reintentos){
    int retorno=-1;
    float bufferFloat;
    if(pFlotante != NULL && msg != NULL && msgErr != NULL
        && min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( (getFloat(&bufferFloat) == 1) &&
                (bufferFloat >= min && bufferFloat <= max))
            {
                *pFlotante = bufferFloat;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
                printf("%s",msgErr);
            }
        }while(reintentos>=0);

    }
    return retorno;
}

int esLetra(char* input){
    int retorno=-1,i=0;
    while (input[i]!='\0'){
        if((input[i]!=' ')&&(input[i] < 'a' || input[i] > 'z') && (input[i] < 'A' || input[i] > 'Z')){
            retorno=-1;
            break;
        }
            i++;
    }
    if(input[i]=='\0'){
        retorno=1;
    }
    return retorno;
}

void utn_getString(char* input, char* msg) {
    fflush(stdin);
    printf("%s", msg);
    fgets(input,100,stdin);
    input[strcspn(input, "\n")] = 0;
}

int utn_getStringAvanzado(char* input,char* msg,char* msgErr,int MAXEMP, int reintentos){
    char aux[MAXEMP];
    int retorno = 0;
    do{
        utn_getString(aux,msg);
        if(esLetra(aux)!=-1){
            strcpy(input,aux);
            retorno = 1;
        }
        else{
            reintentos--;
            printf("%s",msgErr);
        }
    }while(reintentos>=0);
    return retorno;
}



int isValidMenu(int menu, int min, int max) {
    if (menu >= min && menu <= max) {
        return 1;
    } else
        return 0;
}
