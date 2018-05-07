#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20




int main()
{

    ePersona personas[TAM];
    inicializarPersonas(personas, TAM);


    char seguir='s';
    int opcion=0;
    int pedirDni;

    while(seguir=='s')
    {
        printf("\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);
        printf("\n");

        switch(opcion)
        {
        case 1:
            altaPersonas(personas, TAM);

            break;
        case 2:

            printf("Ingrese dni: ");
            scanf("%d", &pedirDni);

            bajaPersona(personas, TAM, pedirDni);

            break;
        case 3:
            ordenarPorNombre(personas, TAM);
            break;
        case 4:
            graficoEdades(personas, TAM);
            break;
        case 5:
            seguir = 'n';
            break;
        }
    }

    return 0;
}







