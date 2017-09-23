#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define largo 20

int main()
{
    char seguir='s';
    int opcion=0;
    ePersona personas[largo]={"emiliano",31,1,32022,"juan",16,1,16875,"marcelo",25,1,36458,"carlos",68,1,265651,"maria",23,1,39456,"clarisa",12,1,7895, "clarisa",70,1,7895,"clarisa",70,1,7895,"clarisa",28,1,7895,"clarisa",21,1,7895,"clarisa",24,1,7895,"clarisa",10,1,7895,"clarisa",8,7895};


    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        printf("6- MUESTRO\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1: altaPersona(personas,largo);
                break;
            case 2: bajaPersona(personas,largo);
                break;
            case 3: ordenarNombre(personas,largo);
                    mostrarPersonas(personas,largo);
                break;
            case 4: graficoEdad(personas,largo);
                break;
            case 6: mostrarPersonas(personas,largo);
                break;
            case 7:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
