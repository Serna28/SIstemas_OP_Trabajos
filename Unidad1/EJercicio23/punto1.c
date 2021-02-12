#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char *isa;

void XOR(FILE * IN_FILE, FILE * OUT_FILE);
void NOT(FILE * IN_FILE, FILE * OUT_FILE);

int main(int argc, char * argv[])
{
 
    FILE *IN_FILE;
    FILE *OUT_FILE;
    IN_FILE = fopen(argv[1], "r");
    OUT_FILE =fopen(argv[2], "w");
    isa = argv[3];

    if(IN_FILE == NULL)
    {
        printf("NO se pueden abrir, ya que estan vacios/null \n");
    }

    if((strncmp("XOR", isa, 3)== 0))
    {
        XOR(IN_FILE,OUT_FILE);
    }
    else if ((strncmp("NOT", isa, 3)== 0))
    {
        NOT(IN_FILE,OUT_FILE);
    }

    else
    {
        printf("DIgite una opcion valida por favot");
    }



}

    //Hora de CAmbiar letricas


    void XOR(FILE * IN_FILE, FILE * OUT_FILE)
    

    { 
        int isa;
        while(1)
        {
            isa = fgetc(IN_FILE);
            if(isa == EOF)
            {
                break; //SAlimos
            }
            isa = isa^0xFF; //Ayuda de profe y amigos
            fputc(isa,OUT_FILE);
        }

    }

    void NOT(FILE * IN_FILE, FILE * OUT_FILE)
    {
        int isa;

        while(1)
        {
            isa = fgetc(IN_FILE);
            if(isa == EOF)
            {
                break; //Salimos
            }

        }
            isa = ~isa;
            fputc(isa,OUT_FILE);
        
    }