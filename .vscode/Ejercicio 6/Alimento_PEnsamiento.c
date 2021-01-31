#include <stdio.h>
#include <stdlib.h>

double FuncionMean(int arreglo[], int sizeArreglo);

//REcibir la direccion del primer elemento del arreglo
//variable que almacene direccion de un entero

double FUncionMean2(int *parreglo);

int main(void)
{
    //Crear un arreglo

    int arreglo[100];
    
    for(int i = 0;i < sizeof(arreglo) / sizeof(int);i++)
    {
      arreglo[i] = i;
    }

    printf("Promedio del los valores %f", FuncionMean(arreglo, (ssizeof(arreglo) / sizeof(int))))

    FuncionMean(arreglo, (sizeof(arreglo)) / (sizeof(int)));

    return 0;
}

double FuncionMean(int arreglo[], int sizeArreglo)
{
    double total = 0;

    for(int i =0; i < sizeArreglo;i++ ) //NO usar sizeof
    {
        total = total + arreglo[i];

    }

    return total/sizeArreglo;
}

double FuncionMean2(int *pArreglo)
{
    return 0.0;

}