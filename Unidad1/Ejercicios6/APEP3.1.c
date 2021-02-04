#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
    printf("Que hace la funcion sizeof \n");
    printf("devuelve el tamaño en bytes que ocupa una variable o algún tipo de dato \n \n");
    
    char *buffer; //Creamos LA VARIABLE QUE ALMACENA LA DIRECCION DE OTRA VARIABLE
    char *string1 = "hola ";//Almacenamos la direccion de string 1 la cual es Hola, el espacio al final es para que no aparezca junto
    
    buffer = malloc(sizeof(char)*30);//retorna la dirección en el heap a partir de la cual se reservó el tamaño de memoria solicitado
    strcpy(buffer,string1); //Copia la cadena apuntada por origen en la cadena apuntada por destino, manda al buffer hola
    strcat(buffer,"Mundo"); //manda al buffer Mundo
    puts(buffer); //se usa para escribir una secuencia de caracteres al flujo de salida estándar, en este caso Hola mundo
    free(buffer); //se usa para liberar memoria asignada
    
    
    
    
    return (0);
}
