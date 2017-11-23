#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];

}EMovie;
/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);
/////////////////////////////////////////////////////////

int get_char_int(char vec[]);
int valida_char_int(char vec[]);
char* get_string(char[]);
int  valida_string(char[]);
void listarPeliculas();
void mostrarPelicula  (EMovie movie);
EMovie altaPelicula();
EMovie getMovie();
EMovie* newMovie (char titulo[],char genero[],int duracion,char descripcion[],int puntaje);

#endif // FUNCIONES_H_INCLUDED
