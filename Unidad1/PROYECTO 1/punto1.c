
//DEfinimos las bibliotecas necesarias para el trabajo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//La estructura que fue dada por el profe en la pagina
struct estudiante
{
    int cedula;
    char nombre[30];
    int semestre;
}estudiantes;

//Variables GLobales para un manejo mas practico de estos

struct estudiante *Almacenamiento;
FILE *IN_File, *OUT_PUTFile;

int wenitas;
int numRegis = 0;
char linea[50];

//Las funciones que fueron necesarias para la ejecuacion de este proyecto

void funcionmkdb(char nombre[30], int cantRegis);

void funcionloaddb(char isa[30]);

void funcionsavedb(char isa[30]);

void readall(struct estudiante *almacenar);

int readSize(struct estudiante *almacenar);

void funcionmkreg(int cedulanueva, char nombrenuevo[30], int semestrenuevo);

void readreg_cedula(int BusCed);

void funcionexit(char isa[30]);

//Main donde se realizan los procesos basicos

int main(void){

    char p1[30], p3[30], nombre1[30], leer[30], c;
    int cedula1, semestre1, Cbuscar, opcion=0;

    do
    {
       //Me parecio mas sencillo ingresar comando y luego los nombres/registros
        printf("Ingrese comando \n");
        
        scanf("%s",leer);
        while ( (c = getchar()) != '\n' && c != EOF ) { }
        
        if (strcmp(leer,"mkdb") == 0)
        {
            printf("Ingresar el nombre de la base de datos:\n");
            scanf("%s", p1);
            printf("Ingrese la cantidad de registros de la base de datos:\n");
            scanf("%d", &numRegis);
            funcionmkdb(p1, numRegis);
            printf("CREADA \n");
           
        }
        else if (strcmp(leer,"loaddb") == 0)
        {
            printf("Ingrese el nombre del archivo:\n");
            scanf("%s", p3);
            funcionloaddb(p3);
            
        }
        else if (strcmp(leer,"savedb") == 0)
        {
            printf("Ingrese el nombre del archivo de salida:\n");
            scanf("%s", p3);
            funcionsavedb(p3);

        }
        else if (strcmp(leer,"readall") == 0)
        {
            printf("-----------------------\n");
            readall(Almacenamiento);
            printf("-----------------------\n");
        }
        else if (strcmp(leer,"readsize") == 0)
        {
            printf("%d\n",readSize(Almacenamiento));
        }
        else if (strcmp(leer,"mkreg") == 0)
        {
            printf("CEdula neuva:\n");
            scanf("%d",&cedula1);
            printf("NOmbr estudiante:\n");
            scanf("%s",nombre1);
            printf("Semestre actual:\n");
            scanf("%d",& semestre1);
            funcionmkreg(cedula1, nombre1, semestre1);
        }
        else if (strcmp(leer,"readreg") == 0)
        {
            printf("Ingrese la cedula del nuevo estudiante:\n");
            scanf("%d", &Cbuscar);
            readreg_cedula(Cbuscar);
        }
        else if (strcmp(leer,"exit") == 0)
        {
            printf("¿Desea guardar la base de datos antes de salir? \n(Sí = 0 --- No = 1)\n");
            scanf("%d", &opcion);
            if (opcion == 0)
            {
                printf("NOmbre del nuevo elemento de salida:\n");
                scanf("%s", p3);
                funcionsavedb(p3);            
            }
            else if (opcion ==1)
            {
                printf("Gracias por usarme");
                break;

            }
            else break;
            
        }

    } while (opcion != 1 && opcion != 2);

    return 0;
}

//FUnciones, donde se hace todo el trabajo de cada punto, segun su funcion

void funcionmkdb(char nombre[40], int cantRegis)
{

    Almacenamiento = malloc(sizeof(struct estudiante)*cantRegis);
}

void funcionloaddb(char isa[30]){

    int cedulas;
    char nombres[30];
    int semestres;
    int contadores = 0;

    IN_File = fopen(isa, "r");
    if (IN_File == NULL){
        printf("No se puede abrir %s \n", isa);
        
    }
    while (!feof(IN_File))
    {
        if (wenitas != EOF)
        {
            fscanf(IN_File, "%s %d %d \n",(Almacenamiento+contadores)->nombre, &(Almacenamiento+contadores)->cedula, &(Almacenamiento+contadores)->semestre);

            contadores++;
        }
    }
    fclose(IN_File);
}

void funcionsavedb(char isa[30]){

    OUT_PUTFile = fopen(isa,"w");
    for (int i = 0; i < numRegis; i++)
    {
        fprintf(OUT_PUTFile, "%s %d %d \n",(Almacenamiento+i)->nombre, (Almacenamiento+i)->cedula, (Almacenamiento+i)->semestre);

    }

    fclose(OUT_PUTFile);
}

void readall(struct estudiante *almacenar){

    int cont = 0;

    while ((almacenar+cont)->cedula != 0)
    {
        printf("%s %d %d \n",(almacenar+cont)->nombre,&(almacenar+cont)->cedula, &(almacenar+cont)->semestre);
        cont ++;
    }

}

int readSize(struct estudiante *almacenar){

    int cont = 0;

    while ((almacenar+cont)->cedula != 0)
    {
        cont ++;
    }
    return cont;
}

void funcionmkreg(int cedulanueva, char nombrenuevo[30], int semestrenuevo){

    for (int i = 0; i < numRegis; i++)
    {
        if ((Almacenamiento+i)->cedula == 0)
        {
            (Almacenamiento+i)->cedula = cedulanueva;
            strcpy((Almacenamiento+i)->nombre,nombrenuevo);
            (Almacenamiento+i)->semestre = semestrenuevo;
            break;
        }
    }
    
}

void readreg_cedula(int BusCed){

    char nombre[30];

    for (int i = 0; i < numRegis; i++)
    {
        if ((Almacenamiento+i)->cedula == BusCed)
        {
            printf("NOmbre del estudiante : %s \n", (Almacenamiento+i)->nombre);
            printf("La cédula: %d \n", (Almacenamiento+i)->cedula);
            printf("Semestre : %d \n",(Almacenamiento+i)->semestre);
        }
    }
}

void funcionexit(char isa[30]){

    funcionsavedb(isa);

}