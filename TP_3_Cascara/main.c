#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "miLib.h"




int main()
{
    char seguir='s';
    int opcion=0;

    FILE* f = fopen("datos.bin", "rb");
    EMovie* lista = malloc(ftell(f));
    while(feof(f))
    {
        fread(lista, sizeof(EMovie), 1, f);
    }


    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    if(agregarPelicula(altaPelicula()))
                    {
                        printf("se agrego la pelicula correctamente\n");
                    }
                    else
                    {
                        printf("ocurrio un eror al agregar la pelicula\n");
                    }

                break;

            case 2: if(borrarPelicula(getMovie()))
                    {
                        printf("se borro la pelicula correctamente\n");
                    }
                    else
                    {
                        printf("ocurrio un error o la pelicula no existe\n");
                    }
                break;
            case 3:
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
