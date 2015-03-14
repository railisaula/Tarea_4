#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

//Devuelve la suma de todos los numeros del arbol con la raiz dada.
int suma(NodoArbolBinario* raiz)
{
    if(raiz==NULL) //verificamos que exista algun valor en la raiz
        return 0; // sino existe valor retornamos cero
    int suma_total = raiz->num; // creando una variable que guarde el valor de la raiz
        suma_total += suma(raiz->hijo_der) + suma(raiz->hijo_izq); // suma de la raiz, el hijo derecho y el hijo izquierdo mediante recursividad

    return suma_total; // retornar la suma total
}

//Devuelve la cantidad de nodos que tiene el arbol con la raiz dada.
int cantidadNodos(NodoArbolBinario* raiz)
{
    int contador =0; // variable que contara la cantidad de nodos

    if(raiz==NULL) // verifica que el valor de la raiz exista
        return 0; // si no existe retorna cero

        contador++; // se le va sumando 1 al contador
        contador += cantidadNodos(raiz->hijo_der)+cantidadNodos(raiz->hijo_izq); // con recursividad se van sumando los nodos de izquierda y derecha

    return contador; // retornamos el valor de los nodos
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
int promedio(NodoArbolBinario* raiz)
{
     return suma(raiz)/cantidadNodos(raiz); // reutilizando las funiones suma y cantidad de nodos para sacar el promedio
    return -1;
}

//Devuelve la cantidad de pasos que tiene que dar el algoritmo para llegar a un numero dado.
//Ejemplo: http://www.comp.nus.edu.sg/~stevenha/visualization/bst.html
//Para llegar al nodo 7 se ocupan 3 pasos (15,6,7)
//Para llegar al nodo 5 se ocupan 4 pasos (15,6,4,5)
//Para llegar al nodo 15 se ocupa 1 paso (15)
int cuantosPasos(NodoArbolBinario* raiz,int num)
{
    int contador =1; // creando una variable que cuentes los pasos

    if(raiz==NULL) // verificar si la raiz existe
        return contador; // sino existe retornamos el valor del contador

    if(raiz->num == num) // si el valor de la raiz es el num que buscamos retorne el contador
        return contador; // retorna 1

    if(num>raiz->num) // verificamos si el numero es mayor que la raiz
        contador += cuantosPasos(raiz->hijo_der,num); // si es mayor buscamos por los hijos de la derecha y se cuentan los pasos

    if(num<raiz->num) // verificamos si el numero es menor que la raiz
        contador += cuantosPasos(raiz->hijo_izq,num); // si es menor buscamos por los hijos de la izquierda y se cuentan los pasos

    return contador; // retorna los pasos
}

//Devuelve verdadero si el arbol dado esta ordenado estilo AVL, de lo contrario devuelve falso.
int sumaHojas(NodoArbolBinario* raiz)
{
    if(raiz==NULL)//si la raiz es igual a nulo entonces que retorne cero
        return 0;

    if(raiz->hijo_izq==NULL&&raiz->hijo_der==NULL)//revisamos que el hizo izquierdo y el hijo izquierdo son iguales a nulo
        {
            return 1;//al cumplirse la revicion retornamos 1
        }
    else
        {
            return sumaHojas(raiz->hijo_izq) +sumaHojas(raiz->hijo_der);//hacemos recursividad
        }

}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}
