#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int obtenerEspacioLibre(ePersona personas[] , int largo)
{
    int retorno = -1;
    for (int i = 0 ; i < largo ; i++)
    {
        if (personas[i].estado == 0)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int buscarPorDni(int dni , ePersona personas[] , int largo)
{
    int retorno = -1;
    for(int i = 0 ; i < largo ; i++)
    {
        if(personas[i].dni == dni)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int get_int(char vec[])
{
     while(!valida_int(vec))
    {
        printf("\nERROR...debe ingresar un numero:");
        printf("\nREINGRESE\n");
        fflush(stdin);
        gets(vec);
        printf("\n");
    }
    return atoi(vec);
}
void get_string(char string[])
{
    while(!valida_string(string))
    {
        printf("\nERROR... no puede ingresar numeros en este campo");
        printf("\nREINGRESE\n");
        printf("\nNombre:\t");
        fflush(stdin);
        gets(string);
        printf("\n");
    }
}
int  valida_string(char string[])
{
    int largo   = strlen(string);
    int retorno = 1;

    for(int i = 0 ; i < largo ; i++)
    {
        if(string[i] < 97 || string[i] > 122)
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int valida_int(char vec[])
{
    int retorno = 1 , veczice = strlen(vec);
    for(int i = 0 ; i < veczice ; i++)
    {
        if (vec[i] < 48 || vec[i] > 57){
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int validaDniUnico(int dni, ePersona personas[], int largo)
{
    int i = buscarPorDni(dni, personas,largo);

    if( i >= 0)
    {
        printf("\nLa PERSONA ya existe\n");
        if(personas[i].estado==0)
        {
            char opcion = 'n';
            printf("\npero a sido dada de baja anteriormente\n");
            printf("\nquiere darle de alta nuevamente? N o S\n");
            fflush(stdin);
            scanf("%c",&opcion);
            if(opcion!='n')
            {
                personas[i].estado = 1;
                printf("\nla persona a sido dada de alta\n");
                printf("\npresione una tecla para volver al menu");
                getche();
                main();
            }
            else
            {
                printf("\npresione una tecla para volver al menu");
                getche();
                main();
            }
        }
    getche();
    altaPersona(personas,largo);
    }
    else
    {
        return dni;
    }

}
void mostrarPersonas(ePersona personas[],int largo)
{
    for (int i = 0 ; i < largo ; i++ )
    {
        if(personas[i].estado != 0)
        {
           mostrarPersona(personas[i]);
        }
    }
    printf("\n\noprima una tecla para volver al menu\n");
    getche();
}
void mostrarPersona  (ePersona personas)
{
    printf("\nDNI:      %d\n",  personas.dni);
    printf("NOMBRE:   %s\n",  personas.nombre);
    printf("EDAD:     %d\n",  personas.edad);
}
void altaPersona(ePersona personas[] , int largo)
{
    int i = obtenerEspacioLibre(personas,largo); char aux[30];
    system("cls");
    printf("---ALTAS---\n");
    if(i >= 0)
    {
        printf("\n");
        printf("INGRESE \n");
        printf("Nombre:\t");
        fflush(stdin);
        gets(aux);
        get_string(aux);
        strcpy(personas[i].nombre , aux);
        /////////////////////////////////
        printf("\nDNI:\t");
        fflush(stdin);
        scanf("%s",aux);
        personas[i].dni = validaDniUnico(get_int(aux),personas,largo);
        //////////////////////////////////////////////////////////////
        printf("\nEdad:\t");
        fflush(stdin);
        scanf("%s",aux);
        personas[i].edad = get_int(aux);
        ///////////////////////////////////////////////////////////////
        personas[i].estado = 1;
        printf("\nla PERSONA se cargo correctamente\n");
    }
    else
    {
        printf("\n");
        printf("CUIDADO!\n");
        printf("no se puede dar de alta personas \n");
        printf("el array esta completo \n");
    }
    printf("\n");
    printf("oprima cualquir tecla para volver al menu \n");
    getche();
}
void bajaPersona(ePersona personas[], int largo)
{
    char aux[30];
    system("cls");
    printf("---BAJAS---\n\n");
    printf("Ingrese el DNI:");
    fflush(stdin);
    gets(aux);
    int i = buscarPorDni(get_int(aux),personas,largo);
    char opcion;
    if(i < 0)
    {
        printf("\n\nNo se encontro a la PERSONA\n\n");
        printf("Quiere volver a buscar? S o N\n\n");
        scanf ("%c",&opcion);
        if(opcion != 'n'){bajaPersona(personas,largo);}
    }
    else
    {
        mostrarPersona(personas[i]);
        if(personas[i].estado == 0)
        {
            printf("Esta persona ya fue dada de baja\n\n");
            printf("Quiere darla de alta? N\S \n");
            scanf ("%c",&opcion);
            if(opcion != 'n')
            {
                personas[i].estado = 1;
                printf("\nse a dado de alta nuevamente \n\n");
                mostrarPersona(personas[i]);
            }
        }
        else
        {
            printf("\nQuiere borrarlo? N\S \n");
            scanf ("%c",&opcion);
            if(opcion == 's')
            {
                personas[i].estado = 0;
                printf("\nSe borro la persona correctamente\n");
            }
        }

    }
    printf("\noprima culquier tecla para volver al menu \n");
    getche();
}
void ordenarNombre(ePersona personas[] , int largo)
{
    ePersona aux;
    for(int i = 0 ; i < largo ; i++)
    {
        for(int j = i+1 ; j < largo ; j++)
        {
            if(strcmp(personas[i].nombre,personas[j].nombre) > 0)
            {
                        aux = personas[i];
                personas[i] = personas[j];
                personas[j] = aux;
            }
        }
    }
}
void inicializaEstadoPersonas(ePersona personas[],int largo)
{
    for(int i = 0 ; i < largo ; i++ )
    {
        personas[i].estado = 0;
    }

}
void graficoEdad(ePersona personas[], int largo)
{
    printf("\n\t--GRAFICO DE EDADES--");
    printf("\n");
    int max = 0 , flag = 0, contadores[3]={0,0,0};
    for(int i = 0 ; i < largo ; i++)
    {
        if(personas[i].estado>0)
        {
            if(personas[i].edad<18){contadores[0]++;}
            if(personas[i].edad > 18 && personas[i].edad < 36){contadores[1]++;}
            if(personas[i].edad > 35){contadores[2]++;}
        }
    }
    for(int i = 0 ; i < 4 ; i++)
    {
        if(flag == 0)
        {
            max  = contadores[i];
            flag = 1;
        }
        if(max < contadores[i])
        {
            max = contadores[i];
        }

    }
    graficoEdadMatriz(contadores,max);
}
void graficoEdadMatriz(int contadores[],int max)
{
    for(int i = max ; i >= 0 ; i--)
    {
        if ( i < contadores[0])
        {
            printf("\t*");
        }
        else{printf("\t");}
        if ( i < contadores[1])
        {
            printf("\t*");
        }
        else{printf("\t");}
        if ( i < contadores[2])
        {
            printf("\t*");
        }
        printf("\n");
    }
    printf("\t");
    printf("<18\t");
    printf("19-35\t");
    printf(">35\t");
    getche();
}
