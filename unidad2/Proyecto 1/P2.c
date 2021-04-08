#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *OUT_FILE, *IN_FILE;
    
    char  nOMBRES [100] [20];
    int Valores [100];
    int isa = 0;
    char ComandoE[20], ComandoS[20], name[30], nameS[30];
    int valorSalida = 0;

    strcpy(ComandoE, argv[1]);
    strcpy(ComandoS, argv[2]);

    IN_FILE =  fopen(ComandoE, "r");

    if(IN_FILE == NULL)
    {
        printf("NO se pudo abrir el archivo \n");
    }
    while(!feof(IN_FILE))
    {
        fscanf(IN_FILE, "%s %d", name, &Valores[isa]);
        strcpy(nOMBRES[isa], name);
        isa++;     
    }

OUT_FILE =  fopen(ComandoS, "w");

for(int i= isa-1; i >= 0; i--)
 {   
     fprintf(OUT_FILE,"%s %d\n", nOMBRES[i],Valores[i]);
 }
 fclose(IN_FILE);
 fclose(OUT_FILE);   
}