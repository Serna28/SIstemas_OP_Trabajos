//Areglar


//DEfinimos las bibliotecas necesarias para el trabajo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//La estructura que fue dada por el profe en la pagina
typedef struct estudiante
{
    int cedula;
    char nombre[30];
    int semestre;
}estudiante;

typedef struct BasedeDatos
{
    int size;
    char nombre[30];
    int max;
    estudiante* Reg;    
}BasedeDatos;


//Variables GLobales para un manejo mas practico de estos

struct estudiante *Almacenamiento;
struct BasedeDatos *AlmacenamientoDatos;
struct BasedeDatos *Activa;


FILE *IN_File, *OUT_PUTFile;
int p =0;
int numRegis = 0;
int contbas=0;
char linea[50];
int wenitas=0;

//Las funciones que fueron necesarias para la ejecuacion de este proyecto

void funcionmkdb(char nombre[30], int cantRegis, int i);


void funciongdb(struct BasedeDatos *almacenar);

void funcionsdb(char nombre[20]);

void funcionsvdb();

void funcionradb();

void funcionlsdbs();

void funcionsvdb();

void funcionrsdb();

void funcionloadb();

void funcionmreg(int cedulaN, char nombreN[20], int semestreN);

void funcionrr(int cedulaN);

void funcionexito(char fileName[30]);


//Main donde se realizan los procesos basicos

int main(int argc, char const *argv[]){

     Activa = (BasedeDatos*)malloc(sizeof(BasedeDatos)*30);

    char p1[30], p3[50], nombre1[30], leer[30], c, nombreDBActiva[30];
    int cedula1, semestre1, Cbuscar, opcion=0, isa =0, dbnew=0,CONTADOR =0;

    do
    {

        
        if (strcmp(leer,"mkdb") == 0)
        {
            //POnerlo en una sola linea, arreglado
            printf("Ingresar los datos:\n");
            scanf("%s %d", p1, &numRegis);
            funcionmkdb(p1, numRegis,dbnew);
            dbnew++;
            printf("CREADA \n");
           
        }
        else if (strcmp(leer,"lsdbs") == 0)
        {
            funcionlsdbs();      
        }
        else if (strcmp(leer,"gdb") == 0)
        {
            funciongdb(Activa);
        }
        else if (strcmp(leer,"sdb") == 0)
        {
            printf("Ingrese el nombre de la base de datos a cambiar:\n");
            scanf("%s",nombreDBActiva);
            funcionsdb(nombreDBActiva);
        }
        else if (strcmp(leer,"svdb") == 0)
        {
            funcionsvdb();
            printf("guardado %s en un archivo\n",Activa->nombre);
        }
        else if (strcmp(leer,"radb") == 0)
        {
            funcionradb();
        }
        else if (strcmp(leer,"rsdb") == 0)
        {
            funcionrsdb();
        }

        else if (strcmp(leer,"mreg") == 0)
        {
            printf("Ingrese la cédula del nuevo registro:\n");
            scanf("%d",&cedula1);
            printf("Ingrese el nombre del nuevo registro:\n");
            scanf("%s",nombre1);
            printf("Ingrese el semestre del nuevo registro:\n");
            scanf("%d",&semestre1);
            funcionmreg(cedula1, nombre1, semestre1);
        }
        else if (strcmp(leer,"rr") == 0)
        {
            printf("Ingrese la cédula del estudiante a buscar:\n");
            scanf("%d",&Cbuscar);
            funcionrr(Cbuscar);
        }
        else if (strcmp(leer,"svdb") == 0)
        {
            funcionsvdb();
            printf("Se guardó la base de datos %s \n",Activa->nombre);
        }

        else if (strcmp(leer,"loadb")== 0)
        {
           printf("Ingrese el nombre del archivo: \n");
           scanf("%s",p3);
           funcionloadb();
            printf("Cargado correctamente \n");
        }
        
        else if (strcmp(leer,"exit") == 0)
        {
            printf("¿Desea guardar la base de %s datos antes de salir?\n(Sí = 0  No = 1)\n",Activa->nombre);
            scanf("%d", &isa);
            if (isa == 0)
            {
                printf("Ingrese el nombre del archivo de salida:\n");
                scanf("%s", nombre1);
                funcionexito(nombre1);
            }
            else break;
        }
        

    } while (opcion != 1 && opcion != 2);

    return 0;
}

//FUnciones, donde se hace todo el trabajo de cada punto, segun su funcion

void funcionmkdb(char nombre[40], int cantRegis,int i)
{
    if(i==0)
    {
        Almacenamiento = malloc(sizeof(struct estudiante)*cantRegis);
        AlmacenamientoDatos = malloc(sizeof(struct BasedeDatos)*10);
        AlmacenamientoDatos->size = cantRegis;
        strcpy(AlmacenamientoDatos->nombre,nombre);
        AlmacenamientoDatos->Reg = Almacenamiento;
        Activa = AlmacenamientoDatos;
        printf("%s fue creada correctamente\n", (AlmacenamientoDatos+i)->nombre);
    }
    else
    {
        Almacenamiento = malloc(sizeof(struct estudiante)*cantRegis);
        (AlmacenamientoDatos+i)->size = cantRegis;
        strcpy((AlmacenamientoDatos+i)->nombre,nombre);
        (AlmacenamientoDatos+i)->Reg = Almacenamiento;
        Activa = (AlmacenamientoDatos+i);
        printf("%s fue creada correctamente\n", (AlmacenamientoDatos+i)->nombre);       
    }
        
}

void funcionloadb()
{
    char fileNames[50];
    
    int contadores;

    IN_File = fopen(fileNames,"r");
    
    if (IN_File == NULL)
    {
        printf("No se cargo correctamente %s \n", fileNames);
        exit(8);
          
    }
    else
    {
    while (!feof(IN_File))
    {
        if (wenitas != EOF)
        {
            fscanf(IN_File,"%s %d %d\n",((Activa->Reg)+contadores)->nombre, &((Activa->Reg)+contadores)->cedula, &((Activa->Reg)+contadores)->semestre);

            contadores++;
        }
    }
    fclose(IN_File);
   }

   
}

void funcionlsdbs()
{
    int i = 0;
    printf("Base en nemoria : \n");
    while ((AlmacenamientoDatos+i)->size != 0)
    {
        printf("%s \n",(AlmacenamientoDatos+i)->nombre);
        i++;
    }
}

void funciongdb(struct BasedeDatos *almacenar)
{
    int cantFull = 0, cont = 0;
    printf("BD Activa: \n");
    printf("Nombre: %s \n Tamano: %d\n",almacenar->nombre,almacenar->size);
    while (((almacenar->Reg)+cantFull)->cedula != 0)
    {
        cantFull++;
    }
    printf("Registros Disponibles: %d\n",almacenar->size - cantFull);
}

void funcionsdb(char nombre[20]){
    int i = 0;
    while ((AlmacenamientoDatos+i)->size != 0)
    {
        if (strcmp((AlmacenamientoDatos+i)->nombre, nombre) == 0){
            Activa = (AlmacenamientoDatos+i);
            printf("La base de datos activa ahora es: %s\n",Activa->nombre);
        }
        i++;
    }    
}

void funcionsvdb(){

    char fileName[20];
    strcpy(fileName,Activa->nombre);
    OUT_PUTFile = fopen(fileName,"w");
    for (int i = 0; i < Activa->size; i++)
    {
        fprintf(OUT_PUTFile, "%s %d %d\n", (Almacenamiento+i)->nombre,(Almacenamiento+i)->cedula, (Almacenamiento+i)->semestre);
    }
//mirar fflush

    fclose(OUT_PUTFile);
    
}

void funcionradb(){

    int cont = 0;

    while (((Activa->Reg)+cont)->cedula != 0)
    {
        printf("%s %d %d\n", ((Activa->Reg)+cont)->nombre, ((Activa->Reg)+cont)->cedula, ((Activa->Reg)+cont)->semestre);
        cont ++;
    }
}

void funcionrsdb(){
    int cant = 0;
    while (((Activa->Reg)+cant)->cedula != 0)
    {
        cant++;
    }
    printf("Registros de la base de datos activa: %d\n",cant);
}

void funcionmreg(int cedulaN, char nombreN[20], int semestreN){
    for (int i = 0; i < Activa->size; i++)
    {
        if(((Activa->Reg)+i)->cedula == 0){
        strcpy(((Activa->Reg)+i)->nombre,nombreN);
            ((Activa->Reg)+i)->cedula = cedulaN;
            ((Activa->Reg)+i)->semestre = semestreN;
            break;
        }
    }
}

void funcionrr(int cedulaN){
    for (int i = 0; i < Activa->size; i++)
    {
        if(((Activa->Reg)+i)->cedula == cedulaN){
            printf("Nombre: %s \n Cédula: %d \nSemestre: %d\n",((Activa->Reg)+i)->nombre, ((Activa->Reg)+i)->cedula, ((Activa->Reg)+i)->semestre);
            break;
        }
    }
}

void funcionexito(char fileName[30])
{
    funcionsvdb(fileName);
    
}

