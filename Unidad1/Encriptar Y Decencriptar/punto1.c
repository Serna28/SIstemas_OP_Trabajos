#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

const char entrada[MAX];
const char salida[MAX];
int eleccion =0;

void XOR(FILE * IN_FILE, FILE * salida);
void NOT(FILE * IN_FILE, FILE * salida);

int main()
{
    printf("INgrese el nombre del archivo \n");
    scanf("%s", entrada);
    printf("INgrese el nombre del archivo de salida \n");
    scanf("%s", salida);
    FILE *IN_FILE;
    FILE *OUT_FILE;
    IN_FILE = fopen(entrada, "r");
    OUT_FILE =fopen(salida, "w");

    if(IN_FILE == NULL)
    {
        printf("NO se pueden abrir, ya que estan vacios/null \n");
    }

    printf("LO quiere por NOT (1) O por XOR(0)");
    scanf("%d", &eleccion);

    if(eleccion ==0)
    {
        XOR(IN_FILE,OUT_FILE);
    }
    else if (eleccion ==1)
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