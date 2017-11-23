/*#include <stdio.h>
#include <stdlib.h>
#include "milib.h"
int menu ()
{
    int opcion = 0;
    system("cls");
    printf("1-> ALTAS\n");
    printf("2-->BAJAS\n");
    printf("3-->MODIFICAR\n");
    printf("4-->LISTAR\n");
    printf("5-->LISTAR ORDENADAMENTE\n");
    printf("6-->BUSCAR PERSONA\n");
    printf("0-->SALIR\n");
    scanf("%d",&opcion);
    return opcion;
}
int opcion()
{
    int opcion = 0;
    system("cls");
    printf("ELIJA LA OPCION PARA ORDENAR\n");
    printf("1->NOMBRE\n");
    printf("2->APELLIDO\n");
    printf("3->dni\n");
    printf("0->CANCELAR Y SALIR\n");
    scanf ("%d",&opcion);
    return opcion;
}
void altaPersona(ePersona personas[] , int largo)
{
    int i = getEmpty(personas,largo); char aux[30];
    system("cls");
    printf("---ALTAS---\n");
    if(i > 0)
    {
        printf("\n");
        printf("INGRESE \n");
        printf("Nombre:\n");
        fflush(stdin);
        gets(aux);
        strcpy(personas[i].nombre , aux);
        printf("Apellido:\n");
        fflush(stdin);
        scanf("%s",aux);
        strcpy(personas[i].apellido , aux);
        printf("dni:\n");
        fflush(stdin);
        scanf("%s",aux);
        personas[i].dni = validaDniUnico(get_char_int(aux),personas,largo);

        personas[i].estado = 1;
        printf("se cargo correctamente a la persona \n");
    }
    else
    {
        printf("\n");
        printf("no se puede dar de alta personas \n");
        printf("el array esta completo \n");
    }
    printf("\n");
    printf("oprima cualquir tecla para volver al menu \n");
    getche();
}
int getEmpty(ePersona personas[] , int largo)
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
//MUESTRA LAS PERSONAS SIN ORDEN///////////////////////////////////////////////////////////////////////
void mostrarPersona  (ePersona personas)
{
    printf("nombre:   %s\n",  personas.nombre);
    printf("apellido: %s\n",  personas.apellido);
    printf("dni:   %d\n",  personas.dni);
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
}
//BORRA A LA PERSONA SELECIONADA////////////////////////////////////////////////////////////////////////////
void bajaPersona(ePersona personas[], int largo)
{
    int i = filtrar(personas,largo);
    char opcion;
    if(i <= 0)
    {
        printf("No se encontro a la persona\n");
        printf("Quiere volver a buscar? S o N\n");
        scanf ("%c",&opcion);
        if(opcion != 'n'){bajaPersona(personas,largo);}
    }
    else
    {
        mostrarPersona(personas[i]);
        if(personas[i].estado == 0)
        {
            printf("Esta persona ya fue dada de baja\n");
            printf("Quiere darla de alta? N\S \n");
            scanf ("%c",&opcion);
            if(opcion != 'n')
            {
                personas[i].estado = 1;
                printf("se a dado de alta nuevamente \n");
                mostrarPersona(personas[i]);
            }
        }
        else
        {
            printf("Quiere borrarlo? N\S \n");
            scanf ("%c",&opcion);
            if(opcion == 's')
            {
                personas[i].estado = 0;
                printf("Se borro la persona correctamente\n");
            }
        }

    }
    printf("oprima culquier tecla para volver al menu \n");
    getche();
}
void modificaPersona(ePersona personas[],int largo)
{
    int i = filtrar(personas,largo);
    char opcion , aux[30];
    if(i < 0)
    {
        printf("No se encontro a la persona\n");
        printf("Quiere volver a buscar? S o N\n");
        scanf ("%c",&opcion);
        if(opcion != 'n'){modificaPersona(personas,largo);}
    }
    else
    {
        mostrarPersona(personas[i]);
        printf("Quiere modificar? S o N \n");
        scanf("%c",&opcion);
        if((opcion!='n'))
        {
            printf("Nombre: \n");
            fflush(stdin);
            gets(aux);
            strcpy(personas[i].nombre,aux);
            printf("Apellido: \n");
            fflush(stdin);
            gets(aux);
            strcpy(personas[i].apellido,aux);
            printf("dni: \n");
            scanf("%d",&personas[i].dni);
        }
        printf("Se modifico la persona \n");
    }
    printf("oprima culquier tecla para volver al menu \n");
}
//FILTRA POR EL NOMBRE Y DEVUELVA LA POSICION/////////////////////////////////////////
int filtrarNombre(char nombre[] , ePersona personas[] , int largo)
{
    int retorno = -1;
    for(int i = 0 ; i < largo ; i++)
    {
        if(strcmp(personas[i].nombre,nombre) == 0 )
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
//FILTRA POR EL APELLIDO Y DEVUELVA LA POSICION/////////////////////////////////////////
int filtrarApellido(char apellido[] , ePersona personas[] , int largo)
{
    int retorno;
    for(int i = 0 ; i < largo ; i++){
        if(strcmp(personas[i].apellido,apellido) == 0 )
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
//FILTRA POR DNI Y DEVUELVA LA INDICE/////////////////////////////////////////
int filtrarDni(int dni , ePersona personas[] , int largo)
{
    int retorno = -1;
    for(int i = 0 ; i < largo ; i++)
    {
        if(personas[i].dni ==dni)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int validaDniUnico(int dni, ePersona personas[], int largo)
{
    int i = filtrarDni(dni,personas,largo);

    if( i >=0)
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
//ORDENA POR NOMBRE////////////////////////////////////////////////////////////////
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
//ORDENA POR APELLIDO//////////////////////////////////////////////////////////////////
void ordenarApellido(ePersona personas[] , int largo)
{
    ePersona aux;
    for(int i = 0 ; i < largo ; i++){
        for(int j = i+1 ; j < largo ; j++){
            if(strcmp(personas[i].apellido,personas[j].apellido) > 0){
                        aux = personas[i];
                personas[i] = personas[j];
                personas[j] = aux;
            }
        }
    }
}
//ORDENA POR dni//////////////////////////////////////////////////////////////////
void ordenardni(ePersona personas[] , int largo)
{
    ePersona aux;
    for(int i = 0 ; i < largo ; i++){
        for(int j = i+1 ; j < largo ; j++){
            if(strcmp(personas[i].dni,personas[j].dni) > 0){
                        aux = personas[i];
                personas[i] = personas[j];
                personas[j] = aux;
            }
        }
    }
}
//ORDENA SEGUN LA OPCION QUE SE PASA POR PARAMETRO//////////////////////////////////////////////////////////////////
void ordenar(int opcion, ePersona personas[],int largo)
{
    switch(opcion)
    {
        case 1: ordenarNombre(personas,largo);
                mostrarPersonas(personas,largo);
                getche();
            break;
        case 2: ordenarApellido(personas,largo);
                mostrarPersonas(personas,largo);
                getche();
            break;
        case 3: ordenardni(personas,largo);
                mostrarPersonas(personas,largo);
                getche();
            break;
        default:printf("no es una opcion correcta");
                getche();
            break;
    }
}
int filtrar(ePersona personas[],int largo)
{
    int retorno = -1;
    char aux[30];
    switch(opcion())
    {
        case 1: printf("Nombre: \n");
                fflush(stdin);
                gets(aux);
                retorno = filtrarNombre(aux,personas,largo);
                getche();
            break;
        case 2: printf("Apellido: \n");
                fflush(stdin);
                gets(aux);
                retorno = filtrarApellido(aux,personas,largo);
                getche();
            break;
        case 3: printf("dni: \n");
                fflush(stdin);
                gets(aux);
                retorno = filtrarDni(get_char_int(aux),personas,largo);
                getche();
            break;
        default:printf("no es una opcion correcta");
                getche();
            break;
    }
    return retorno;
}
int get_char_int(char vec[])
{
     while(!valida_char_int(vec))
    {
        printf("ERROR...debe ingresar un numero:\n");
        fflush(stdin);
        gets(vec);
    }
    return atoi(vec);
}
int valida_char_int(char vec[])
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
void valida_char_int_noReturn (char vec[])
{
     while(!valida_char_int(vec)){
        printf("ERROR...debe ingresar un numero:\n");
        fflush(stdin);
        gets(vec);
    }
}
int get_char_int_noError(char vec[])
{
    int zice = strlen(vec);
    char aux[strlen(vec)];
    for(int i = 0 ; i < zice ; i++){
        if(vec[i] > 47 && vec[i] < 48 ){
            aux[i] = vec[i];
        }
    }
    return atoi(aux);
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
char* get_string(char string[])
{
    while(!valida_string(string))
    {
        printf("\nERROR... no puede ingresar numeros en este campo");
        printf("\nREINGRESE\n");
        fflush(stdin);
        gets(string);
        printf("\n");
    }
    return string;
}
*/
