#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>

void main(){

     int fd[2],suma=0,resta=0,mut=0,div=0;
    
     char buffer[2],num1[2],num2[2];
     pid_t pid;
     time_t t;
     int numero1,numero2;

     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
     		close(fd[0]); // Cierra el descriptor de escritura
     		srand((unsigned) time(&t));
     		
              	numero1 = rand()%51+1;
              	
              	numero2 = rand()%51+1;
              	
              	sprintf(num1,"%d",numero1);
              	sprintf(num2,"%d",numero2);
              	
               write (fd[1],num1,sizeof(numero1));
              	write (fd[1],num2,sizeof(numero2));
     }
     else
     
     {
     		wait(NULL);
               close(fd[1]); // Cierra el descriptor de lectura
               
               read(fd[0],buffer,2);
               numero1 = atoi(buffer);
               read(fd[0],buffer,2);
               numero2 = atoi(buffer);
               
               suma = numero1 + numero2;
               printf("%d + %d = %d\n",numero1,numero2,suma);
               resta = numero1 - numero2;
               printf("%d - %d = %d\n",numero1,numero2,resta);
               mut = numero1 * numero2;
               printf("%d * %d = %d\n",numero1,numero2,mut);
               div = numero1 / numero2;
               printf("%d / %d = %d\n",numero1,numero2,div);
               
               
        
     }
}
