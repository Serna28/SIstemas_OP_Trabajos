 #include <stdio.h>

 int main(int argc, char* argv[]) {

     #ifdef CONDITION
     printf("CODIGO IF\n");
     #else
     printf("CODIGO ELSE\n");
     #endif


     printf("COn el primer codigo, sale con un monton de externals \n");
     printf("COn el segundo codigo, sale con un monton de externals tambien \n");
     printf("Ahora con el tercer y ultimo comando, sale la respuesta else");
     return 0;
 }