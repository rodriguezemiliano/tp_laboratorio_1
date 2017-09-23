#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;
/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona personas[], int largo);
////////////////////////////////////////////////////////////////////////////////////////
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int  buscarPorDni(int dni, ePersona personas[], int largo);
///////////////////////////////////////////////////////////////////////////////////////////
/**
 * Obtiene un entero validado de una cadena de carateres.
 * @param cadena de carateres que se pasa como parametro.
 * @return un entero validado.
 */
int  get_int(char[]);
////////////////////////////////////////////////////////////////////
/**
 * Valida un string.
 * @param str es la cadena de caracteres que se pasa como parametro.
 * @return no devuelve nada.
 */
void get_string(char str[]);
/////////////////////////////////////////////////////////////////////////
/**
 * Obtiene un entero.
 * @param str el array de carateres se pasa como parametro.
 * @return un entero que sirve para evaluar 0 si contiene una letra y 1 si contiene solo numeros.
 */
int  valida_int(char str[]);
////////////////////////////////////////////////////////////////////////////////
/**
 * Obtiene un entero.
 * @param str el array de carateres que se pasa como parametro.
 * @return un entero que sirve para evaluar 0 si contiene un numero 1 si contiene solo letras.
 */
int  valida_string(char str[]);
/////////////////////////////////////////////////////////////////////////////////
/**
 * muestra las personas del array.
 * @param personas es el array de personas que se pasa como parametro.
 * @return no devuelve nada.
 */
void mostrarPersonas(ePersona personas[],int largo);
//////////////////////////////////////////////////////////////////////////////////
/**
 * muestra la persona pasa por parametro.
 * @param persona es un elemento del array que se pasa por parametro.
 * @return no devuelve nada.
 */
void mostrarPersona (ePersona personas);
/////////////////////////////////////////////////////////////////////////////////
/**
 * Da de baja una persona.
 * @param persona es el elemento a dar de baja del array.
 * @return no devuelve nada.
 */
void bajaPersona(ePersona[],int);
/////////////////////////////////////////////////////////////////////////////////
/**
 * inicia el campo estado en 0 de todos los elementos del array personas.
 * @param personas es el array de personas que se pasa como parametro.
 * @return no devuelve nada.
 */
void inicializaEstadoPersonas(ePersona[],int);
//////////////////////////////////////////////////////////////////////////////////
/**
 * Valida que el dni pasado por parametro no este repetido en el array de personas.
 * @param personas es el array de personas que se pasa como parametro.
 * @return si encuentra el dni dentro del array devuelve -1, si no lo ecuentra devuelve el dni pasado por parametro.
 */
int  validaDniUnico(int, ePersona[], int );
//////////////////////////////////////////////////////////////////////////////////
/**
 * Ordena el array por nombre, de la a / z.
 * @param personas es el array de personas que se pasa como parametro.
 * @return no devuelve nada.
 */
void ordenarNombre(ePersona personas[] , int largo);
////////////////////////////////////////////////////////////////////////////////////////
/**
 * Hace el grafico: cuenta la cantidad de menores, aldutos, mayores y calcula el maximo pora ser pasados por parametro a otra funcion que dibuja el grafico.
 * @param personas es el array de personas que se pasa como parametro.
 * @return no devuelve nada.
 */
void graficoEdad(ePersona personas[], int largo);
//////////////////////////////////////////////////////////////////////////
/**
 * Imprime los * del grafico.
 * @param contarores es un array de la cantidad de menores, adultos y mayores.
 * @param es el maximo de los tres contadores
 * @return no devuelve nada.
 */
void graficoEdadMatriz(int contarores[],int);
#endif // FUNCIONES_H_INCLUDED
