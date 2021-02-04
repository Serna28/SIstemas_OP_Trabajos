#include <stdio.h>

int promedio();

int main(void)
{
  
  int arreglo[100];
  
  for(int i =0; i < 100;i++)
  {
      arreglo[i] = i+1;
    printf("Array en la poscicion: %d es : %d \n",i+1,arreglo[i]); // No poner +1 se descuadra
  }
  
  promedio();
  return 0;  
}
  
  

int promedio()
{
    
  int arreglo[100];
  int promedio =0;
  float promediado;
  float final;
    
     for(int i =0; i < 100;i++)
  {
      arreglo[i] = i+1;
      promedio += arreglo[i];
      
   
  
  }
  promediado = sizeof(arreglo) / sizeof(arreglo[0]); //Toca hacer esta division porque lo da en bytes
  final = promedio / promediado;
  printf("La suma de los numeros es : %d \n",promedio);
  printf("El numero de posciciones finales son  : %f \n",promediado );
  printf("El promedio es de : %f ", final);
}
  