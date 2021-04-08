 #include<stdio.h>
 #include<stdlib.h>
 #include<unistd.h>

 int main(int argc, char  *argv[])
 {
         pid_t pid_hijo;
         char Valores[3][10]={"./Pro : \n","./Max : \n","./Min : \n"};
         
         for(int i = 0; i < 3 ; i++)
         {

             pid_hijo = fork();

             if(pid_hijo == 0)
             {
                execv(Valores[i], argv);
             }
             else
             {  
                wait(NULL);

             }
         }

         printf("FIn------------------------------ \n");

     return 0;
 }