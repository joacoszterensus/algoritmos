#include <stdio.h>
#include <stdlib.h>

int esPar(int num){
    return num%2==0;
}
int sumaImpares(int num) {
    int suma = 0;
    for (int i = 1; i < num; i += 2) {
        suma += i;
    }
    return suma;
}
int* memoriaDe(int num) {
    int *ptr = (int *)malloc(sizeof(int)); // Asigna memoria dinámica para almacenar el entero
    *ptr = num; // Almacena el valor de num en la memoria asignada
    return ptr; // Devuelve el puntero a la memoria asignada
}
int main (){        
printf("hola mundo\n"); // para correr el codigo "gcc <nombre del archivo>"
                     // desp ./a.out
int numero;
printf("ingrese un numero: ");
scanf("%d",&numero);

// if (esPar(numero)){
//     printf("%d es un numero par",numero);
// }else{    printf("%d es un numero impar",numero);
// }

// PUNTEROS 
// &<variable>      -> devuelve el puntero (direccion de memoria)
// * representa a los punteros
// int a=2
//int* puntero=&a
//int b=puntero --> devuelve direccion de memoria de a
//int b=&puntero -->devuelve a
//segmentation fault es el error que devuelve cuando un puntero esta apuntando a memoria la cual no le pertenece al programa

int *ptr_numero = memoriaDe(numero);
printf("%p", (void *)ptr_numero); // Imprime la dirección de memoria
free(ptr_numero); // Liberar la memoria asignada
}