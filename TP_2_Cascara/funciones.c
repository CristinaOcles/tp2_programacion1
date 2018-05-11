#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>



void inicializarPersonas(ePersona lista[], int tam)
{

    for (int i=0 ; i<tam; i++)
    {
        lista[i].estado = 1;      // 1 representa el campo vacio
    }
}


int obtenerEspacioLibre(ePersona lista[], int tam)
{

    int indice = -1;            //valor por defecto si no se encontro un indice

    for (int i=0; i<tam; i++)
    {
        if (lista[i].estado==1)
        {
            indice = i;   //pasado del indice a la variable para poder ser devuelto
            break;
        }
    }
    return indice;

}




int buscarPorDni(ePersona lista[], int dni, int tam)
{
    int indice = -1;

    for (int i=0; i<tam; i++)
    {
        if (lista[i].estado==0 && lista[i].dni==dni)
        {
            indice =i;                  //retornamos el indice donde hay coincidencias De DNI
            printf("Ya existe una persona con ese DNI:  %s  \n", lista[i].nombre);

            break;
        }
    }

    return indice;
}




void altaPersonas(ePersona lista[], int tam)
{
    ePersona nuevaPersona;

    int dni;
    int indice;
    int busqueda;


    indice = obtenerEspacioLibre(lista, tam);

    if (indice == -1)
    {
        printf("no se puede ingresar mas personas, sistema lleno \n");

    }
    else
    {
        printf("ingrese dni: ");
        scanf("%d",&dni);

    }

    busqueda = buscarPorDni(lista, dni, tam);

    if (busqueda == -1)
    {
        nuevaPersona.estado = 0;
        nuevaPersona.dni = dni;

        printf("\n-Ingrese nombre: ");
        fflush(stdin);
        gets(nuevaPersona.nombre);

        printf("\n-Ingrese Edad: ");
        scanf ("%d",&nuevaPersona.edad);

        lista [indice] = nuevaPersona;

        printf("\n-Alta de personas Exitosa\n");
    }
}



void bajaPersona (ePersona lista[], int tam, int dni)
{

    int respuesta;
    int indice;

    indice = buscarPorDni(lista, dni, tam);

    for(int i =0; i<tam; i++)
    {

        if (indice>=0)
        {
            printf("Desea eliminar a: %s ?  \n", lista[indice].nombre);
            printf("1-Si \n");
            printf("2-No \n");
            scanf("%d",&respuesta);


            while (respuesta!=1 && respuesta!=2)
            {
                printf("Error Reingrese respuesta \n");
                printf("Desea eliminar a: %s ?\n", lista[indice].nombre);
                printf("1-Si \n");
                printf("2-No \n");
                scanf("%d",&respuesta);
            }

            switch (respuesta)
            {

            case 1:
                lista[indice].estado = -1;
                break;
            case 2:
                printf("Se ha cancelado la baja de la persona: %s \n", lista[indice].nombre);
                break;
            }

            break;
        }
    }
}




void imprimirPersonas(ePersona lista[],int tam)
{

    printf("\n\t\t**Nombre**\t\t**Edad**\t\t**DNI**\t\t\t\n");

    for (int i =0; i<tam; i++)
    {
        if (lista[i].estado==0)
        {
            printf("%20s\t\t\t   %2d\t\t\t   %10d\t\t\t\t\n", lista[i].nombre, lista[i].edad, lista[i].dni);
        }
    }

}


void ordenarPorNombre(ePersona lista[], int tam)
{

    ePersona aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp (lista[i].nombre, lista[j].nombre)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;

            }
        }

    }

    imprimirPersonas(lista, tam);
}


void graficoEdades(ePersona lista[], int tam)
{
    printf("\n----------grafico de edades----------\n");
    printf("\nmenores de 18 // de 19 a 35 anios// mayores de 35 \n" );

    int menor18=0;
    int entre19y35=0;
    int mayor35=0;

    int flagMen;
    int flagEntre;


    for (int i=0; i<tam; i++)
    {
        if (lista[i].edad<19 && lista[i].estado == 0)
        {
            menor18++;
        }
        else if (lista[i].edad >18 && lista[i].edad <36 && lista[i].estado == 0)
        {
            entre19y35++;
        }
        else if (lista[i].edad >35 && lista[i].estado == 0)
        {
            mayor35++;
        }
    }



    for (int i=0; i<tam; i++)
    {

        flagMen = 0;
        flagEntre = 0;


        if(lista[i].estado == 0)
        {

            if (menor18>0)
            {
                printf("*");
            }
            if ( entre19y35> 0)
            {
                printf("\t\t*");

                entre19y35--;
                flagEntre = 1;

                menor18--;
                flagMen = 1;
            }
            if (mayor35>0)
            {
                if (flagEntre ==0 && flagMen ==0)
                {
                    printf ("\t\t\t\t      *");
                }
                else
                {
                    printf("\t              *");
                }
                mayor35--;
            }

            if (flagMen ==0)
            {
                entre19y35--;
            }
            if (flagEntre==0)
            {
                menor18--;
            }

            printf("\n");
        }


    }





}
