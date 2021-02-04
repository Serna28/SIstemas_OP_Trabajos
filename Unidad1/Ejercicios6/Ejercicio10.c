#include <stdio.h>

int main(void)
{
  int A[6]={2,3,1,0,9,6};
    int *ptr1;
    int *ptr2 = &A[5];
    ptr1 = A;
    ptr1+=2;
    *ptr1=5;
     ptr2--;
    *(ptr2)=*ptr1+*(ptr2-1)+*(ptr2+1);
    
    printf("valor de a: %d \n",A[0]);
    printf("valor de a: %d \n",A[1]);
    printf("valor de a: %d \n",A[2]);
    printf("valor de a: %d \n",A[3]);
    printf("valor de a: %d \n",A[4]);
    printf("valor de a: %d \n",A[5]);

}