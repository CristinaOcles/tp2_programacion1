#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED




typedef struct ePersona;




/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param tam es el tamaño del array se pasa como parametro
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[], int tam);






/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param tam es el tamaño del array se pasa como parametro
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int dni, int tam);





/**
 * Inicializa personas y pone su estado en 1 para indicar que esta vacio
 * @param lista el array se pasa como parametro.
 * @param tamaño del array se pasa como parametro.
 */
void inicializarPersonas(ePersona lista[], int tam);






/**
 * da el alta y guarda en un array datos
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param tam es el tamaño del array se pasa como parametro

 */
void altaPersonas(ePersona lista[], int tam);






/**
 * da de baja y pone el estado en vacio
 * @param lista el array se pasa como parametro.
 * @param tamaño del array se pasa como parametro.
 * @param dni se pasa como parametro.

 */
void bajaPersona (ePersona lista[], int tam, int dni);







/**
 * imprime personas
 * @param lista el array se pasa como parametro.
 * @param tamaño del array se pasa como parametro.
 */
void imprimirPersonas(ePersona lista[],int tam);








/**
 * ordena por nombre el array
 * @param lista el array se pasa como parametro.
 * @param tamaño del array se pasa como parametro.
 */
void ordenarPorNombre(ePersona lista[], int tam);






/**
 * imprime un grafico de edades
 * @param lista el array se pasa como parametro.
 * @param tamaño del array se pasa como parametro.
 */
void graficoEdades(ePersona lista[], int tam);

#endif // FUNCIONES_H_INCLUDED
