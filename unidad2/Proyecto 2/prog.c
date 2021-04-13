#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

typedef struct linea
{
   char nombre[30],ocupacion[30];
   int edad;

} personajes;
typedef struct parametro
{
   char Salida[30];
   int cifra;
} param;

personajes *ptrPersonaje;

//ALfabetico
void *alfabetico(void *parametros)
{
   int boole =0;
   param *isa = (param *)parametros;
   FILE *salidita;
   salidita = fopen(isa->Salida, "w");
   personajes *vecAlfabetico;
   vecAlfabetico = (personajes(*))malloc((isa->cifra + 1) * sizeof(personajes));

   for (int i = 0; i < isa->cifra; i++)
   {
      vecAlfabetico[i]=ptrPersonaje[i];
      vecAlfabetico[i].ocupacion[0]=toupper(vecAlfabetico[i].ocupacion[0]);
   }
   personajes auxiliar;
   
   for (int i = 0; i < isa->cifra; i++)
   {
      boole =0;

      for (int j = 0; j < isa->cifra - (i + 1); j++)
      {
         if (strcmp(vecAlfabetico[j].ocupacion, vecAlfabetico[j + 1].ocupacion) > 0)
         {
            auxiliar = vecAlfabetico[j];
            vecAlfabetico[j] = vecAlfabetico[j + 1];
            vecAlfabetico[j + 1] = auxiliar;
            boole =1;
         }
      }
      if (boole !=0)
      {
        break;
      }
   }
   for (int i = 0; i < isa->cifra; i++)
   {
      fprintf(salidita,"%s %s %d",vecAlfabetico[i].nombre,vecAlfabetico[i].ocupacion,vecAlfabetico[i].edad);
      fprintf(salidita,"\n");
   }

   fclose(salidita);
   free(vecAlfabetico);

   return NULL;
}

//COnrario

void *COntrario(void *parametros)
{
   FILE *salidita;
   param *isa = (param *)parametros;
   personajes *volteadoVec;
   volteadoVec = (personajes(*))malloc((isa->cifra + 1) * sizeof(personajes));
   
   for (int i = 0; i < isa->cifra; i++)
   {
      volteadoVec[i]=ptrPersonaje[i];
      volteadoVec[i].ocupacion[0]=toupper(volteadoVec[i].ocupacion[0]);
   }
   salidita = fopen(isa->Salida, "w");

   for (int i = isa->cifra-1; i >= 0; i--)
   {
      fprintf(salidita, " %s  %s  %d  ", volteadoVec[i].nombre, volteadoVec[i].ocupacion,volteadoVec[i].edad);
      fprintf(salidita, "\n");
   }
   fclose(salidita);
   free(volteadoVec);
   return 0;
}

//Main

int main(int argc, char const *argv[])
{
   FILE *Entrada;
   char nombreT[30],ocupacionT[30],aux[30];
   int edadT = 0,cifra = 0;
   Entrada = fopen(argv[1], "r");
   while (1)
   {
    if (feof(Entrada))
    {
      break;
    }
    else
    {
      fscanf(Entrada, "%s %s %s", aux, aux, aux);
      cifra++;
    }
   }

   ptrPersonaje = (personajes(*))malloc((cifra + 1) * sizeof(personajes));
   printf("----- Archivo Original -----\n");

   fclose(Entrada);

   Entrada = fopen(argv[1], "r");

   for (int i = 0; i < cifra; i++)
   {
      fscanf(Entrada, "%s %s %d", nombreT, ocupacionT,&edadT);
      ocupacionT[0]=toupper(ocupacionT[0]);
      strcpy(ptrPersonaje[i].nombre, nombreT);
      strcpy(ptrPersonaje[i].ocupacion, ocupacionT);
      ptrPersonaje[i].edad = edadT;
      printf("|%s | %s | %d |\n", ptrPersonaje[i].nombre, ptrPersonaje[i].ocupacion,ptrPersonaje[i].edad);
   }
   printf(" \n");
   fclose(Entrada);

   pthread_t id_hilo1;

   param hilo1_param;

   strcpy(hilo1_param.Salida, argv[2]);
   hilo1_param.cifra = cifra;
   pthread_create(&id_hilo1, NULL, &COntrario, &hilo1_param);

   pthread_t id_hilo2;
   param hilo2_param;

   strcpy(hilo2_param.Salida, argv[3]);
   hilo2_param.cifra = cifra;
   pthread_create(&id_hilo2, NULL, &alfabetico, &hilo2_param);

   pthread_join(id_hilo1, NULL);

   pthread_join(id_hilo2, NULL);

   Entrada = fopen(argv[2], "r");

   printf("----- HILO 1 -----\n");

   for (int i = 0; i < cifra; i++)
   {
      fscanf(Entrada, "%s %s %d", nombreT,ocupacionT,&edadT);     
      printf(" | %s | %s | %d |", nombreT,ocupacionT,edadT);
      printf("\n");
   }
   fclose(Entrada);
   printf("\n");
   Entrada = fopen(argv[3], "r");
   printf("----- HILO 2 -----\n");

   for (int i = 0; i < cifra; i++)
   {
      fscanf(Entrada, "%s %s %d", nombreT,ocupacionT,&edadT);
      printf(" | %s |  %s | %d |", nombreT,ocupacionT,edadT);
      printf("\n");
   }
   fclose(Entrada);
   free(ptrPersonaje);
   return 0;
}