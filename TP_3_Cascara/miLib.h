/*#ifndef CHINOW_H_INCLUDED
#define CHINOW_H_INCLUDED
//ESTRUCTURAS////////////////////////////////////////
typedef struct{
    int legajo  , estado ;
    char nombre[20] , apellido[20];
}ePersona;
//FUNCIONES//////////////////////////////////////
int  getEmpty (ePersona[],int);
int  borrarPersona   (int,int);
int  filtrarNombre   (char[],ePersona[],int);
int  filtrarApellido (char[],ePersona[],int);
int  filtrarLegajo   (int,ePersona[],int);
int  filtrarParametro(int opcion,ePersona[],int largo);
void mostrarPersonas (ePersona[],int);
void ordenaNombre    (ePersona[],int);
void ordenaApellido  (ePersona[],int);
void ordenaLegajo    (ePersona[],int);
void ordenaParametro (int,ePersona[],int);
/////////////////////////////////////////////////////////////////////////////////////
int getEmpty(ePersona personas[] , int largo){
    int retorno = 0;
    for (int i = 0 ; i < largo ; i++){
        if (personas[i].estado == 0){
            retorno = i;
            break;
        }
    }
    return retorno;
}
//MUESTRA LAS PERSONAS SIN ORDEN///////////////////////////////////////////////////////////////////////
void mostrarPersonas(ePersona personas[],int largo){
    printf("entre al mostrar\n");
    for (int i = 0 ; i < largo ; i++ ){
        if(personas[i].estado != 0){
            printf("nombre: %s\n",  personas[i].nombre);
            printf("apellido: %s\n",personas[i].apellido);
            printf("legajo: %d\n",  personas[i].legajo);
            printf("estado: %d\n",  personas[i].estado);
        }
    }
}
//BORRA A LA PERSONA SELECIONADA////////////////////////////////////////////////////////////////////////////
int borrarPersona(int i, int largo){
    for(int i = 0 ; i < largo ; i++){

    }
}
//FILTRA POR EL NOMBRE Y DEVUELVA LA POSICION/////////////////////////////////////////
int filtrarNombre(char nombre[] , ePersona personas[] , int largo){
    int retorno;
    for(int i = 0 ; i < largo ; i++){
        if(nombre == personas[i].nombre){retorno = i;break;}
    }
    return retorno;
}
//FILTRA POR EL APELLIDO Y DEVUELVA LA POSICION/////////////////////////////////////////
int filtrarApellido(char apellido[] , ePersona personas[] , int largo){
    int retorno;
    for(int i = 0 ; i < largo ; i++){
        if(apellido == personas[i].apellido){retorno = i;break;}
    }
    return retorno;
}
//FILTRA POR LEGAJO Y DEVUELVA LA POSICION/////////////////////////////////////////
int filtrarLegajo(int legajo , ePersona personas[] , int largo){
    int retorno;
    for(int i = 0 ; i < largo ; i++){
        if(legajo == personas[i].legajo){retorno = i;break;}
    }
    return retorno;
}
//ORDENA POR NOMBRE////////////////////////////////////////////////////////////////
void ordenaNombre(ePersona personas[] , int largo){
    ePersona aux;
    for(int i = 0 ; i < largo ; i++){

        for(int j = i+1 ; j < largo ; j++){
            if(strcmp(personas[i].nombre,personas[j].nombre) > 0){
                        aux = personas[i];
                personas[i] = personas[j];
                personas[j] = aux;
            }
        }
    }
}
//ORDENA POR APELLIDO//////////////////////////////////////////////////////////////////
void ordenaApellido(ePersona personas[] , int largo){
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
//ORDENA POR LEGAJO//////////////////////////////////////////////////////////////////
void ordenaLegajo(ePersona personas[] , int largo){
    ePersona aux;
    for(int i = 0 ; i < largo ; i++){
        for(int j = i+1 ; j < largo ; j++){
            if(strcmp(personas[i].legajo,personas[j].legajo) > 0){
                        aux = personas[i];
                personas[i] = personas[j];
                personas[j] = aux;
            }
        }
    }
}
//ORDENA SEGUN LA OPCION QUE SE PASA POR PARAMETRO//////////////////////////////////////////////////////////////////
void ordenaParametro(int opcion,ePersona personas[],int largo){
    system("cls");
    printf("entre en ordenaParametro");
    switch(opcion){
        case 1: ordenaNombre(personas,largo);
                mostrarPersonas(personas,largo);
                getche();
            break;
        case 2: ordenaApellido(personas,largo);
                mostrarPersonas(personas,largo);
                getche();
            break;
        case 3: ordenaLegajo(personas,largo);
                mostrarPersonas(personas,largo);
                getche();
            break;
        default:printf("no es una opcion correcta");
                getche();
            break;
    }
}
int filtrarParametro(int opcion,ePersona personas[],int largo){
    int retorno = 0;
    system("cls");
    switch(opcion){
        case 1: //retorno = filtrarNombre(personas,largo);
                getche();
            break;
//        case 2: retorno = filtrarApellido(personas,largo);
                getche();
            break;
 //       case 3: retorno = filtrarLegajo(personas,largo);
                getche();
            break;
        default:printf("no es una opcion correcta");
                getche();
            break;
    }


#endif // CHINOW_H_INCLUDED*/

