#include <stdio.h> //Se debe importar, se me olvido y tuve un lapso mental


int main()
{
    //Pregunta 1
    printf("\n");

    printf( " ¿Qué es un lenguaje imperativo y qué otro lenguaje imperativo usted conoce muy bien? \n");
    printf(" Un lenguage imperativo son las instrucciones que se ejecutan unas tras otras, de manera secuencial, salvo cuando se encuentran estructuras de control condicionales o bucles \n");
    printf(" Y Hasta el momento solo conozco C,C++,C#, Java y emsambladores por arquitectura \n");
    printf(" \n");

    printf("------------------------------------ \n");


    //pregunta 2

    printf(" ¿Cuál es la diferencia con un lenguaje declarativo (no olvide el ejemplo)? \n");
    printf("  los lenguajes imperativos proporcionan la receta, mientras que los declarativos, fotos del plato preparado \n");


    printf(" -----------------------------------------  \n");

    //Pregunta 3

    printf(" C no tiene garbage collection ¿Qué lenguaje que usted conoce tiene garbage collection y para qué sirve? \n");
    printf(" Garbage Collector es un programa que administra la memoria automáticamente, en donde la desasignación de objetos es manejada por Java en lugar del programador \n");

    printf(" ------------------------------------------ \n");

    //Pregunta 4

    printf(" ¿Qué es la biblioteca estándar de C y para qué sirve?\n");
    printf(" es una recopilación de archivos de cabecera y bibliotecas con rutinas, estandarizadas por un comité de la Organización Internacional para la Estandarización (ISO), que implementan operaciones comunes, tales como las de entrada y salida o el manejo de cadenas.\n");

    printf(" ---------------------------------------------------------- \n");

    //Pregunta 5
    
    printf(" ¿Cuál es la diferencia entre el código compilado de un programa en C con uno en Java?\n");
    printf(" C es más rápido de ejecutar que EN Java pero se tarda más a compilar y ejecutar un programa que en Java. \n");

    printf(" ---------------------------------------------------------- \n");
    

    //Pregunta 7
    
    printf(" En el programa anterior se utilizó stdio.h ¿Dónde está almacenado este archivo en Linux?\n");
    printf(" Segun el comando locate, esta en /usr/include/stdio.h \n");

    printf(" ---------------------------------------------------------- \n");

    //Pregunta 8
    
    printf(" Escriba la secuencia de bytes correspondiente a la cadena de caracteres: “Hola Mundo\r\n”\n");
    printf(" 0x48 0x6f 0x6c 0x61 0x4d 0x75 0x6e 0x64 0x6f 0x5c 0x72 0x5c 0x6e\n");

    printf(" ---------------------------------------------------------- \n");

    //Pregunta 9
    
    printf(" Dado el siguiente conjunto de instrucciones cuales son los valores de las variables a lo largo de la ejecución del código \n");

    int i, j,k = 5;
    k++;

    printf("%d es el valor de k\n",k);
    --k;
    printf("%d es el valor de k\n",k);

    k=5;
    printf("%d es el valor de k\n", k);

    i=4*k++;
    
    printf("%d es el valor de i\n",i);

    k=5;
    printf("%d es el valor de k\n", k);
    
    j=4 * ++k;
    
    printf("%d es el valor de j\n",j);

    printf(" ---------------------------------------------------------- \n");

    //Pregunta 10
    
    printf(" ¿Qué código ASCII le corresponde al caracter de nueva línea (newline) y cuál es la secuencia de escape de nueva línea?\n");
    printf(" Según lo que investigue, el salto de linea es el caracter 010\n");
    printf(" y su secuencia de linea sería (/n) \n");

    printf(" ---------------------------------------------------------- \n");

    //Pregunta 11
    
    printf(" Si mediante el teclado se ingresa la secuencia de caracteres UdeA y luego ENTER, indique el secuencia de bytes que será almacenada en el flujo de entrada \n");
    printf(" 00000000  55 64 65 41 0a |UdeA.|00000005 \n");

    printf(" ---------------------------------------------------------- \n");

    //Pregunta 12
    
    printf("Explicar el programa Lab2\n");
    printf("LO que hace este programa, es que pide al usuario que digite caracteres, por eso se declara como char, luego se realiza un ciclo, el cual va almacenando los caracteres que el usuario ingrese, todo esto hasta que este digite ('X'), lo cual da fin al programa\n");
    printf("Existen 2 espacios(new line) entre el ultitmo caracter y la primera 'X'\n");

    printf(" ---------------------------------------------------------- \n");

    //Pregunta 13
    
    printf(" \n");
    printf(" \n");

    printf(" ---------------------------------------------------------- \n");

    //Pregunta 14
    
    printf(" \n");
    printf(" \n");

    printf(" ---------------------------------------------------------- \n");

    //Pregunta 15
    
    printf(" \n");
    printf(" \n");

    printf(" ---------------------------------------------------------- \n");

    //Pregunta 16
    
    printf(" \n");
    printf(" \n");

    printf(" ---------------------------------------------------------- \n");

    //Pregunta 17
    
    printf(" \n");
    printf(" \n");

    printf(" ---------------------------------------------------------- \n");


   
    return 0;


}