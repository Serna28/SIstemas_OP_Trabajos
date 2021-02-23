#include <stdio.h>
#include <stdlib.h>


struct Alumno
{
    
    char materia [32];
    float nota[32];
    int creditos[32];

}alumnos;

int main()
{
    int numero_materias;

    printf("Digite el numero de materias en el semestre:\n");
    scanf("%d", &numero_materias); // Atención al operador &

    for(int i =1; i <= numero_materias;i++)
    {
       printf("Nombre Materia : \n");
       scanf("%s", &alumnos.materia);

    }
    printf("\n");

    for(int i =1;i<=numero_materias;i++)
    {

        printf("la nota de la materia [%i] fue: \n",i);
        scanf("%e", &alumnos.nota[i]);



        printf("los creditos de la materia [%i] fueron : \n",i);
        scanf("%i", &alumnos.creditos[i]);

    }

     for(int i =1;i<=numero_materias;i++)
    {
       printf("%d  ",alumnos.materia[i]);
       printf(" %i ",alumnos.creditos[i]);
       printf(" %f  \n",alumnos.nota[i]);


    }
  
    
}
