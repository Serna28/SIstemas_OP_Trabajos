#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct estudiante
 {
     int cedula;
     char nombre[30];
     int semestre;
 }estudiante;

typedef struct baseDatos
 {
     char NameDB[30];
     int CantRegis;
     int CantRegUsa;
     struct estudiante* Reg;

 }basesitas;

FILE *OUT_FILE, *IN_FILE;
estudiante *Almacenamiento;
basesitas *AlmacenamientoDatos;
basesitas *Activa;

//GLobales
int numRegis = 0, numRegisUs = 0, uso = 0, ContBDS = 0;
char nombreBD[30];

//FUnciones utlizadas
void mdb (char nombre[30], int numRegis);
void mreg (char nombre[30],int cedula, int semestre); 
void svdb ();
void radb();
void ldb(char nombreArchivo[30]);
void rsdb();
void rr(int cedula2);
void exitProgram();
void lsdbs();
void gdb();
void sdb(char nombre [30]);

//Main
int main()
{

 
 char leer [100],CARGARARCHIVO[30], NombreEstu[30], Activa[30]; //error es por el nombre
 int cedula = 0, semestre = 0;

do
{
    printf("Ingrese el Comando a realizar \n");
    fscanf(stdin, "%s", leer);
    getc(stdin);


    if(strncmp(leer,"mkdb", 3)==0)
    {
        printf("Ingrese los datos \n");
        scanf("%s %d", nombreBD, &numRegis);
       mdb(nombreBD,numRegis);

       printf("Creada");

         
       
    }

    else if(strncmp(leer,"lsdbs", 4)==0)
    {
      lsdbs();
    }
    else if(strncmp(leer,"gdb", 3)==0)
    {   
      gdb();
    }    
    else if(strncmp(leer,"ldb", 3)==0)
    {
        printf("Ingrese el nombre del archivo a cargar : \n");
        fscanf(stdin, "%s", CARGARARCHIVO);
        ldb(CARGARARCHIVO);
        
    }
    else if(strncmp(leer,"svdb",3)==0)
    {      
        svdb( );
        
    }
    else if(strncmp(leer,"radb", 4)==0)
    {       
         radb(numRegis);
    }
    else if(strncmp(leer,"rsdb",4)==0)
    {
        rsdb();
    }
    else if(strncmp(leer,"mreg", 4)==0)
    {    
        printf("ingrese nombre del estudiante : \n");
        fscanf(stdin, "%s", NombreEstu);
        printf("Ingrese cedula : \n");
         fscanf(stdin, "%d", &cedula);
         printf("Ingrese semestre : \n");
         fscanf(stdin, "%d", &semestre);
         mreg(NombreEstu,cedula, semestre);
    }
    else if(strncmp(leer,"rr", 2)==0)
    {
        printf("Ingrese la cedula a uscar");

        fscanf(stdin, "%d", &cedula);
        rr(cedula);
       

    }


     else if(strncmp(leer,"sdb", 3)==0)
    {
       fscanf(stdin, "%s",Activa);
       sdb(Activa);
    }

    else if(strncmp(leer,"exit", 4)==0)
    {
       exitProgram();
       break;
    }
 

}while(1);

free(Almacenamiento);
free(AlmacenamientoDatos);


}
//Funciones, donde practicamente se hace la magia

void mdb (char nombre[30], int numRegis)
{       
        //se queda, funciona bien
        if(ContBDS == 0)
        {
          
           Almacenamiento = malloc(sizeof(struct estudiante)*numRegis*2);
           AlmacenamientoDatos = malloc(sizeof(struct baseDatos)*20); //Asignar
          strcpy((AlmacenamientoDatos)->NameDB,nombre);
          AlmacenamientoDatos-> Reg = Almacenamiento;
          AlmacenamientoDatos-> CantRegis = numRegis;
          Activa  = AlmacenamientoDatos;
        }
        else
        {  

         printf("Entra Por %d vez \n", ContBDS);
         Almacenamiento = malloc(sizeof(struct estudiante)*numRegis*2);
          strcpy((AlmacenamientoDatos+ContBDS)->NameDB,nombre);
         (AlmacenamientoDatos+ContBDS)-> Reg = (Almacenamiento+ContBDS);
         (AlmacenamientoDatos+ContBDS)-> CantRegis = numRegis;
          Activa  =(AlmacenamientoDatos+ContBDS);        
        }
        printf("Creada la base de datos : %s  \n", ((AlmacenamientoDatos+ContBDS)->NameDB));
        ContBDS++;
        ContBDS++;
}

void mreg (char nombre[30],int cedula, int semestre)
{
     printf("El nombre es : %s \n Cedula : %d \n Semestre : %d \n",nombre,cedula,semestre);

       for(int i=0; i < numRegis; i++)
    {
        if( ((Activa->Reg)+i)->cedula==0) 
        {
         ((Activa->Reg)+i)->cedula = cedula;
        strcpy( ((Activa->Reg)+i)->nombre,nombre);
        ((Activa->Reg)+i)->semestre = semestre;
        numRegisUs++;
        Activa-> CantRegUsa ++;
        break;
        }
        
    }

}

void radb()
{
   
    printf("Base De Datos Activa es %s \n Tamaño : %d \n Registros usados :  %d  \n",Activa -> NameDB, Activa -> CantRegis, Activa -> CantRegUsa);
    for(int i=0; i < numRegis; i++)
    {
        printf("%d", i+1);
        printf("Nombre : %s \n",  ((Activa->Reg)+i)->nombre);
        printf("Cedula : %d \n ", ((Activa->Reg)+i)->cedula);
        printf("Semestre : %d \n", ((Activa->Reg)+i)->semestre);
    }
}

void svdb ( )
{
    
    printf("Base de Datos:  %s \n Registros: %d \n",Activa-> NameDB, numRegis);
    OUT_FILE =  fopen(Activa-> NameDB, "w");
    fprintf(OUT_FILE, "%s %d \n",Activa-> NameDB, numRegis);

    for(int i=0; i < numRegis; i++)
    {
        fprintf(OUT_FILE,"%s ", ((Activa->Reg)+i)->nombre);
        fprintf(OUT_FILE,"%d ", ((Activa->Reg)+i)->cedula);       
        fprintf(OUT_FILE,"%d \n",((Activa->Reg)+i)->semestre);
        
    }

    printf("Se guardo la DB \n");

    fclose(OUT_FILE);
}

void ldb(char FileName[30])
{   
    IN_FILE =  fopen(FileName, "r");

    if(IN_FILE == NULL)
    {
        printf("No se Puede Abrir Correctamente \n");
        exit(8);
    }

    char nombreBD[30];    
    int cedula = 0;
    char nombre[30];
    int semestre = 0;


    fscanf(IN_FILE, "%s", nombreBD);
    fscanf(IN_FILE, "%d", &numRegis);

    mdb(nombreBD, numRegis);
    for(int i = 0; i < numRegis; i++)
    {  
         fscanf(IN_FILE, "%s", nombre);
         fscanf(IN_FILE, "%d", &cedula); 
         fscanf(IN_FILE, "%d", &semestre);

         if(cedula != 0)
         {
            mreg(nombre,cedula,semestre);
         }

    }
    fclose(IN_FILE);
}

void rsdb()
{
    printf("Base de datos : %s \n Registros :  %d \n Registros Usados: %d \n",Activa-> NameDB, Activa -> CantRegis, Activa -> CantRegUsa);
}

void rr(int cedula2)
{
    int entro = 0;
     for(int i=0; i < numRegis; i++)
    {
        if(((Activa->Reg)+i)->cedula == cedula2)
        {
            printf(" Cedula es %d ", ((Activa->Reg)+i)->cedula);
            printf("El nombre  es %s ", ((Activa->Reg)+i)->nombre);
            printf("El semestre es  es %d \n", ((Activa->Reg)+i)->semestre);
            entro = 1;

        }

        
    }

        if(entro == 0)
        {
            printf("No se encontro Registro, srry \n");
        }
        
}

void exitProgram()
{
        int salir = 0;
        printf("La Base de Datos Activa : %s \n", Activa-> NameDB );
        printf("¿Desea Guardar La base de datos? Si lo desea Digite 1 de Lo contrario Cualquier tecla \n");
        fscanf(stdin, "%d", &salir);
        if(salir == 1)
        {
           
            svdb(nombreBD, numRegis); 

        }
        else
        {   
            printf("BYEEEEE");

        }

       
}

void lsdbs()
{
    int isa = 0;
    printf("Las Bases De Datos en Memoria Son %d \n",ContBDS/2);
    
    for(int i = 0; i < ContBDS; i=i+2)
    {
        printf("Base #:  %d \n Nombre :  %s \n Tamaño :  %d \n Registros usados :  %d \n",isa+1,(AlmacenamientoDatos+i) -> NameDB, (AlmacenamientoDatos+i) -> CantRegis, (AlmacenamientoDatos+i) -> CantRegUsa);
        isa++;
    }
}

void gdb()
{
    printf("Base de datos Activa :  %s \n Tamaño :  %d \n Registro Usados : %d  \n",Activa -> NameDB, Activa -> CantRegis, Activa -> CantRegUsa);
}

void sdb(char nombre [30])
{
    int isa = 0;
    for(int i = 0; i < ContBDS; i++)
    {
        if(strcmp((AlmacenamientoDatos+i)-> NameDB, nombre) == 0)
        {
            Activa = (AlmacenamientoDatos+i);
            printf("La Base De Datos Ha Sido Activada Satisfactoriamente\n");
            isa = 1;
            break;
        }
      
    }

    if(isa == 0)
    {
        printf("La Base No Fue encontrada\n");
    }
}
