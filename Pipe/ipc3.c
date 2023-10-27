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
     		close(fd[1]); // Cierra el descriptor de escritura
     		
     }
     else
     
     {
                close(fd[0]); // Cierra el descriptor de lectura
                srand((unsigned) time(&t));
              	numero1 = rand()%50;
              	numero2 = rand()%50;
              	printf("\tNumero a sumar: %d\n",numero1);
		printf("\tNumero a sumar: %d\n",numero2);
              	
     			wait(NULL);
        
     }
}
