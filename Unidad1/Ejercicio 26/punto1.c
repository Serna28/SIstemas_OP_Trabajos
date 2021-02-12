#include <stdio.h>

 #define CONDITION

 int main(int argc, char* argv[]) {

     #ifdef CONDITION
     printf("CODIGO IF\n");
     #else
     printf("CODIGO ELSE\n");
     #endif

     printf("Este nos va a imprimir el primer if, osea, CODIGO IF ya que esta definido como condicion");
     return 0;
 }