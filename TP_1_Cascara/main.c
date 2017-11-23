#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float num1;
    float num2;
    while(seguir=='s')
    {
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1: num1 = pidoNumero();
                break;
            case 2: num2 = pidoNumero();
                break;
            case 3: printf("\n\nResultado suma: %f\n\n",suma(num1,num2));
                break;
            case 4: printf("\n\nResultado resta: %f\n\n",resta(num1,num2));
                break;
            case 5: printf("\n\nResultado divide: %f\n\n",divide(num1,num2));
                break;
            case 6: printf("\n\nResultado multiplica: %f\n\n",multiplica(num1,num2));
                break;
            case 7: printf("\n\nResultado fatoreo: %f\n\n",factorial(num1));
                break;
            case 8: printf("\n\nResultado suma: %f\n",suma(num1,num2));
                    printf("Resultado resta: %f\n",resta(num1,num2));
                    printf("Resultado divide: %\nf",multiplica(num1,num2));
                    printf("Resultado multiplica: %f\n",divide(num1,num2));
                    printf("Resultado fatoreo: %f\n\n",factorial(num1));
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
