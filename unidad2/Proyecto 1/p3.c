#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    
    FILE *IN_FILE;
    pid_t pid_hijo;

    char c;
    char ejecutables[2][20] = {"./p1", "./P2"};


    for(int i = 0; i < 2; i++)
    {
      pid_hijo = fork();

      if(pid_hijo == 0)

       {
        execv(ejecutables[i], argv);
       }
    }


wait(NULL);
wait(NULL);


IN_FILE =  fopen(argv[2], "r");

printf("Archivo de p1 \n");

if(IN_FILE == NULL)

  {
    printf("NO se pudo abrir correctamente \n");
  }

  c = fgetc(IN_FILE);

  while(!feof(IN_FILE))
  {
    printf("%c", c);
    c = fgetc(IN_FILE);
  }

  fclose(IN_FILE);
  IN_FILE =  fopen(argv[3], "r");

  printf("\n-------------------")

  printf("Cambio de archivo \n");

  printf("-------------------\n");


  printf("Archivo de p2 \n");

  if(IN_FILE == NULL)

  {
    printf("No se Puede Abrir Correctamente \n");
  }

  c = fgetc(IN_FILE);

  while(!feof(IN_FILE))
  {
    printf("%c", c);
    c = fgetc(IN_FILE);
  }

  fclose(IN_FILE);
}