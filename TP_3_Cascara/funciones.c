#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "miLib.h"

int agregarPelicula(EMovie movie)
{
    int retorno = 0;
    FILE* f = fopen("datos.bin","ab");

    if(f != NULL)
    {
        if(fwrite(&movie,sizeof(EMovie),1,f)>0)
        {
            retorno = 1;
        }
    }
    fclose(f);
    return retorno;
}
int borrarPelicula(EMovie movie)
{
    int retorno = 0;
    EMovie auxMovie;
    FILE* f  ;
    FILE* auxF;
    f    = fopen("datos.bin","rb");
    auxF = fopen("temp.bin","wb");

    while(fread(&auxF, sizeof(auxF), 1, f) > 0 && strcmp(auxMovie.titulo,movie.titulo) != 0)
    {
        fwrite(&auxF, sizeof(auxF), 1, auxF);
    }

    fseek(f, -1 * sizeof (auxMovie), SEEK_CUR);
    fseek(auxF, -1 * sizeof (auxMovie), SEEK_CUR);

    while(fread(&auxMovie, sizeof(auxMovie), 1, f) > 0)
    {
        retorno = 1;
        fwrite(&auxMovie, sizeof(auxMovie), 1, auxF);
    }
    if(fclose(f) == 0 && fclose(auxF) == 0)
    {
        remove("datos.bin");
        rename("temp.bin", "datos.bin");
    }
    return retorno;
}

EMovie* newMovie (char titulo[],char genero[],int duracion,char descripcion[],int puntaje)
{
    EMovie* newMovie = malloc(sizeof(EMovie));

    strcpy(newMovie->titulo,titulo);
    strcpy(newMovie->genero,genero);
    newMovie->duracion = duracion;
    strcpy(newMovie->descripcion, descripcion);
    newMovie->puntaje = puntaje;
    strcpy(newMovie->linkImagen,puntaje);

    return newMovie;
}
EMovie altaPelicula()
{
    EMovie movie;
    char aux[100];

    system("cls");
    printf("* *** **ALTA** *** *---\n");
    printf("* INGRESE          *---\n");
    printf("* Titulo:\t        *---\n");
    fflush(stdin);
    gets(aux);
    strcpy(movie.titulo,get_string(aux));
    printf("* Genero:\t        *---\n");
    fflush(stdin);
    gets(aux);
    strcpy(movie.genero,get_string(aux));
    fflush(stdin);
    printf("* Duracion:\t   *---\n");
    fflush(stdin);
    gets(aux);
    movie.duracion = get_char_int(aux);
    printf("* Descripcion:\t   *---\n");
    fflush(stdin);
    gets(aux);
    strcpy(movie.descripcion,get_string(aux));
    printf("* Puntaje:\t       *---\n");
    fflush(stdin);
    movie.puntaje = get_char_int(aux);
    /////////////////////////////////////
     return movie ;
    getche();
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
void mostrarPelicula  (EMovie movie)
{
    printf("Titulo:   %s\n",  movie.titulo);
    printf("Genero:   %s\n",  movie.genero);
    printf("Descripcion:   %s\n",  movie.descripcion);
    printf("Puntaje:   %d\n",  movie.puntaje);
    printf("Duracion:   %d\n",  movie.duracion);
}
void listarPeliculas()
{
    FILE* f = fopen("datos.bin","rb");
    EMovie movie;


    while(!feof(f))
    {
       if(fread(&movie,sizeof(EMovie),1,f)>0)
        {
            mostrarPelicula(movie);
        }
    }


}
EMovie getMovie ()
{
    char aux[50];
    EMovie retorno;
    printf("INGRESE TITULO DE LA PELICULA\n");
    printf("QUE QUIERE BORRAR\t");
    fflush(stdin);
    gets(aux);
    strcpy(retorno.titulo,get_string(aux));
    return retorno;
}

void generarPagina(EMovie lista[], char nombre[])
{


}
