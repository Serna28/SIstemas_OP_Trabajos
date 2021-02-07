     #include <stdio.h>
     #define M 5
     #define C 5
     #define MAP(val,m,c) x*m+c

     int main(int argc, char* argv[]) 
     {
         int x = 2;
         int y = MAP(x,M,C);
         printf("y: %d \n ", y);

         printf("COn esto podemos concluir de que incluir(#inclide) sirve para indicarle al preprocesador que cuando este se ejecute, el compilador debe incluir un archivo en el código");
         return 0;
     }