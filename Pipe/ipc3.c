#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>

void main(){

     int fd[2]; 
     char buffer[2];
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
              	numero1 = rand()%50;
              	numero2 = rand()%50;
               write (fd[1],numero1,sizeof(numero1));
              	write (fd[1],numero2,sizeof(numero2));
     }
     else
     
     {
               close(fd[0]); // Cierra el descriptor de lectura
               
              	
     			wait(NULL);
        
     }
}
