#include <stdio.h>
#include <stdlib.h>

char OriginFile[40];
char DestinationFile[40];

int main(void)
{
   FILE *orgFile;
   FILE *desFile;
   int counter = 0;
   int ch;

   printf("Nombre archivo origen: ");
   scanf("%s",OriginFile);
   printf("Nombre archivo destino: ");
   scanf("%s",DestinationFile);

   orgFile = fopen(OriginFile,"r");
   if(orgFile == NULL) 
   {
      printf("Error origin file");
      exit(EXIT_FAILURE);
   }

   desFile = fopen(DestinationFile,"w");
   if(desFile == NULL) 
   {
      printf("Error destination file");
      exit(EXIT_FAILURE);
   }

   while (!feof(orgFile))
   {
     ch = fgetc(orgFile);
     if(ch != EOF)
     {
        fputc(ch,desFile);
        counter++;
     }
   }
   printf("%d characters were written\n",counter);
   fclose(orgFile);
   fclose(desFile); 
   return 0;
}