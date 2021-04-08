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
        printf("Problema al abrir el archivo \n");
    }
    while(!feof(IN_FILE))
    {
     
        fscanf(IN_FILE, "%s %d", name, &Valores[isa]);
        strcpy(nOMBRES[isa], name);

        isa++;
     
    }
    for(int m = 1; m < isa; m++)
    {
        for(int i = isa-1; i >= m; i--)
        {
            if(Valores[i-1] > Valores[i])
            {
         
            valorSalida =  Valores[i-1];
            Valores[i-1] = Valores[i];
            Valores[i] = valorSalida;

            strcpy(nameS, nOMBRES[i-1]);
            strcpy(nOMBRES[i-1], nOMBRES[i]);
            strcpy(nOMBRES[i], nameS);
         
            }
          
        }
    }
    OUT_FILE =  fopen(ComandoS, "w");

    for(int k = isa-1; k > 0; k--)
    {   
        
        fprintf(OUT_FILE,"%s %d\n", nOMBRES[k],Valores[k]);
    }



     
    fclose(IN_FILE);
    fclose(OUT_FILE);
    
}