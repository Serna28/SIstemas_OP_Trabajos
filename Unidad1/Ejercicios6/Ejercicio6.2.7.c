#include <stdio.h>

typedef struct estudiante_t
{
   char Nombre[40];
   int numEstudiante;
   int agnoMatricula;
   double nota;
} estudiante;

void funcChange(estudiante *);

int main(void)
{
   estudiante estud1 = {"Diomedez", 4, 2009, 4.5};
   estudiante *ptrEstruct;
   char command = '0';
   ptrEstruct = &estud1;

   printf("Nombre del estudiante , ID , Año ,Nota: %s, %d , %d , %.2lf \n",ptrEstruct->Nombre,ptrEstruct->numEstudiante, ptrEstruct->agnoMatricula,ptrEstruct->nota);
   printf("Ingrese ('e') para actualizar valores o ('s') para salir: ");
   scanf("\n %c",&command);
   if(command != 'e') return 0;
   else funcChange(ptrEstruct);
   printf("Estudiante nombre,ID,año,nota: %s,%d,%d,%.2lf\n",ptrEstruct->Nombre,ptrEstruct->numEstudiante, ptrEstruct->agnoMatricula,ptrEstruct->nota);

   return 0;
}

void funcChange(estudiante *pE)
{
   printf("Ingrese así nombre ID año nota separados por espacio: ");
   scanf("%s %d %d %lf",pE->Nombre,&pE->numEstudiante,&pE->agnoMatricula,&pE->nota);
}
