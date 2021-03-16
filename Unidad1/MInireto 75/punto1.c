 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 typedef struct arma
    {
     int balas;
    }metralleta;

    metralleta* nueva_arma(); 
 typedef struct jugador
    {
     char* name;
     metralleta* arma;

    }jugador;

    jugador* nuevo_jugador();
    void crear( jugador*, char*);
    void Destruir(jugador*);
    void recoger_arma( jugador*, metralleta*);
    void piu(jugador*);
    void tirar( jugador*);

    //Funciones
    void constructorArma(metralleta*, int);
    void disparar(metralleta*);
    void recargar(metralleta*);
 
    int main(int argc, char const *argv[])
    {
        //Variables
        char p1[5];
        char c;
        int isa=1;

       metralleta* armita = nueva_arma(); //Se crea el arma
       constructorArma(armita,25);
       char nombrejugador[20];
       jugador* jugador = nuevo_jugador();
       printf("Welcome to the matrix, elija su nombre(keanu reeves no vale) \n");
       scanf("%s", nombrejugador);
       crear(jugador,nombrejugador);
      
       do
       {          
          printf("Que Deseas hacer? \n1- Buscar un Arma: 1 \n2- Buscar Traidores: 2 \n");
          scanf("%s", p1);

          if ((strncmp("1", p1, 1) == 0))
          {
              while ( (c = getchar()) != '\n' && c != EOF ) { }
              recoger_arma(jugador,armita);
              isa=0;
          }
          if ((strncmp("2", p1, 1) == 0))
          {
              while ( (c = getchar()) != '\n' && c != EOF ) { }
              printf("Aparece Keavu Reeves pidiendote que lleves un arma, afuera es peligroso  \n ");
          }                 
       } while (isa);
       
        isa=1;
       do
       {            
          printf("Que desea hacer, \n1- soltar arma 1 \n2- Buscar Traidores: 2 \n3- REcargar : 3 \n4- Disparar normal 4 \n5- Disparar en automatico 5 \n6- Borrar Personaje 6 \n");
          scanf("%s", p1);
          if ((strncmp("1", p1, 1) == 0))
          {
             tirar(jugador);
             while ( (c = getchar()) != '\n' && c != EOF ) { }
          }
          else if ((strncmp("2", p1, 1) == 0))
          {
              while ( (c = getchar()) != '\n' && c != EOF ) { }
              printf("TIenes un traidor enfrente de ti, liquidalo \n");
          }
          else if ((strncmp("3", p1, 1) == 0))
          {
              while ( (c = getchar()) != '\n' && c != EOF ) { }
              recargar(armita);
          }
          else if ((strncmp("4", p1, 1) == 0))
          {
              while ( (c = getchar()) != '\n' && c != EOF ) { }
              
              piu(jugador);            
          }
          else if ((strncmp("5", p1, 1) == 0)){
              while ( (c = getchar()) != '\n' && c != EOF ) { }
              while (armita->balas>0)
              {
                  piu(jugador);
              }

              printf("No tienes tanta fuerza, el arma se voltea y te un piu \n");
              Destruir(jugador);
          }
          else if  ((strncmp("6", p1, 1) == 0))
          {
              while ( (c = getchar()) != '\n' && c != EOF ) { }
              Destruir(jugador);
          }
          else if (armita->balas == 0)
          {
              while ( (c = getchar()) != '\n' && c != EOF ) { }
              printf("REcarga! \n");
          }
                        
       } while (isa);

    }
    

    //Arma
    metralleta* nueva_arma()
    {
        return (metralleta*) malloc(sizeof(metralleta));
    }

    void constructorArma(metralleta* arma, int balitas)
    {

    arma->balas=0;
    if(balitas>0)
    {
        arma->balas=balitas;
     }
    }

    void disparar(metralleta* arma)
    {
        arma->balas--;
        printf("Piu \n");
    }


    void recargar(metralleta* arma)
    {
        arma->balas=10;
        printf("Recarga exitosa puedes destruir traidores \n");
    }



    //JUgador

    jugador* nuevo_jugador()
    {
        return (jugador*)malloc(sizeof(jugador));
    }

    void crear(jugador* jugador,char* nombre)
    {
        jugador->name = (char*)malloc((strlen(nombre)+1)*sizeof(char));
        strcpy(jugador->name,nombre);
        jugador->arma=NULL; // El jugador no necesita una arma para existir
    }

    void Destruir(jugador* jugador)
    {
        free(jugador->name);
    }

    void recoger_arma(jugador* jugador,metralleta* ak47)
    {
        jugador->arma=ak47;
    }

    void piu(jugador* jugador)
    {
        if (jugador->arma)
        {
            disparar(jugador->arma);
        }
        else
        printf("NO tienes arma \n ");
        
    }

    void tirar(jugador* jugador)
    {
        jugador->arma=NULL;
    }