#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float pidoNumero()
{
    float retorno;
    printf("Ingrese un numero:");
    scanf("%f",&retorno);
    return retorno;
}
float suma(int num1,int num2)
{
    float retorno = num1 + num2;
    return retorno;
}
float resta(int num1,int num2)
{
    float retorno = num1 - num2;
    return retorno;
}
float divide(int num1,int num2)
{
    float retorno;

    while(num2 == 0)
    {
        printf("ERROR... no se puede divir por cero\n");
        num2 = pidoNumero();
    }
    retorno = (num1 / num2);
    return retorno;
}
float multiplica(int num1,int num2)
{
    float retorno = num1 * num2;
    return retorno;
}
float factorial(int num1)
{
    float retorno;
    for(int i = 1 ; i <= num1 ; i++)
    {
        retorno = multiplica(i,(i+1));
    }
    return retorno;
}
