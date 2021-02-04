#include <stdio.h>

int main(void)
{
     printf("¿Cuántos caracteres tiene el archivo ? \n")
     printf(" 68 | 6f | 6c | 61 | 20 | 6d | 75 | 6e | 64 | 6f | 0a | tiene 11 \n");
     printf(" \n");

     printf(" ¿Qué hace fopen y que quiere decir “r” ? \n");
     printf(" Esta función sirve para abrir y crear ficheros en disco | r = abrir un archivo para lectura, el fichero debe existir.\n");

     printf(" \n");

     printf(" ¿Qué es EOF? \n");
     printf(" es un concepto para determinar el final de un archivo. \n");
     printf(" \n");

     printf(" ¿Cuál es la diferencia entre las funciones fgetc y getc?\n");
     printf(" Lee un carácter desde un fichero | La función getc lee el siguiente carácter de un flujo de fichero y devuelve el valor numérico de ese carácter \n");

     printf(" \n");

     printf(" ¿Por qué el valor que retorna fgetc debe almacenarse en una varibale int?\n");
     printf(" devuelve un int ya que debe poder devolver todos los caracteres posibles además de un indicador de fin de archivo \n");
     
     printf(" \n");
     
     printf(" ¿Qué hace fputc o putc? \n");
     printf(" Guarda un carácter en fichero \n");

     printf(" \n");

     printf(" ¿Qué valor retorna la función fputc? | ¿outputFile debe estar abierto?\n");
     printf(" Retorna el carácter escrito | el archivo debe estar abierto \n");

     printf(" \n");

     printf("¿Por qué es muy importante cerrar un archivo antes de terminar un programa? | ¿Una vez se cierra un archivo con fclose es posible leer o escribir el archivo? \n");
     printf(" Para liberar memoria | Una vez el archivo se cierre, debe volverse a abrir para realizar cualquier operción \n");

     printf(" \n");
}