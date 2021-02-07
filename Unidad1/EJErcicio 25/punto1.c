#define M 5
#define C 5
#include <stdio.h>

int main(int argc, char* argv[]) {
    int x = 2;
    int y = x*M + C;

    printf(" el resulrado  es : %d \n",y);

    printf("Ahora en respuesta a como deberia quedar en el preprocesador serà : \n");
    printf("int main(int argc, char* argv[]) \n");
    printf("int y = x*5+5; \n");
    printf("int x = 2; \n");
    

    return 0;
}