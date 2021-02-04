#include <stdio.h>

//Creamos la matriz 
char nombres[3][20] = {"fulana","Megano","Perano"};

int main(void)
{
    char i; //declaramos el char i
    char *a; //en el puntero Contenemos la direccion de la variable a
    char(*b)[20]; //en el puntero Contenemos la direccion b en la posicion 20
    
    a= (char *)nombres;// la variable a sera igual a la direccion del primer elemento del arreglo que es tipo char(recordando que nombres es un numero finalmente)
    
    printf("El nombre es %s \n",a);
    
    b = (char (*)[20])nombres[0];//La variable b sera igual a las direcciones de vector nombres
    
    for(i =0; i < 3;i++) //este for recorre el "tamaño" del array
    {
        printf("El nombre [%d] es %s \n",i,(char *)(b+i));//Imprimimos cada elemento del array 
    }
    
    return (0);
}
