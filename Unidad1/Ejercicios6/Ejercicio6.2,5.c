#include <stdio.h>


typedef struct cdsMusic_t
{
   char Titulo[40];
   char Artista[40];
   char Genero[15];
   int Numcan;
   int Lanzamiento;
   int Precio;
} 

cdsMusic;

int main(void)
{

   cdsMusic cd1 = {"Brindo con el alma","Diomedes Díaz","Vallenato",11,1986,19900};

   printf("Título: %s\n", cd1.Tituloitulo);
   printf("Artista: %s\n",cd1.Artista);
   printf("Género: %s\n",cd1.Genero);
   printf("Número de canciones: %d\n",cd1.Numcam);
   printf("Fecha de lanzamiento: %d\n",cd1.Lanzamiento);
   printf("Precio: %d\n",cd1.Precio);
   
   return 0;
}

