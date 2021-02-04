#include <stdio.h>

int main(void)
{
  int numero_materias; // Aquí alojaremos el valor leído
    int nota[100];
    int creditos[100];

    printf("Digite el numero de materias en el semestre:\n");
    scanf("%d", &numero_materias); // Atención al operador &
    printf("El numero de materias en el semestre son: %d \n", numero_materias);

    typedef char cadenaCaracteres [50]; //Definimos el tipo cadenaCaracteres
    cadenaCaracteres arrayCadenas[5]; //Creamos un vector de cadenas

     char cadena[numero_materias];

    for(int i =1; i <= numero_materias;i++)
    {
       printf("Nombre Materia : \n");
       scanf("%s",arrayCadenas[i]);
    }

    printf("\n");

    for(int i =1;i<=numero_materias;i++)
    {

        printf("la nota de la materia [%s] fue : \n",arrayCadenas[i]);
        scanf("%i",&nota[i]);



        printf("los creditos de la materia [%s] fueron : \n",arrayCadenas[i]);
        scanf("%i",&creditos[i]);

    }

    for(int i =1;i<=numero_materias;i++)
    {
       printf("%s  ",arrayCadenas[i]);
       printf(" %i ",creditos[i]);
       printf(" %i  \n",nota[i]);
    }




}