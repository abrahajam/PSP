#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>
#include <string.h>


void main(){

     int fd[2]; 
     char buffer[24];
     time_t hora;
     char *fecha ;

     pid_t pid;
     
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
                close(fd[1]); // Cierra el descriptor de escritura
                printf("Soy el proceso hijo con pid %d \n",getpid());
                read(fd[0], buffer, 24);
                
                printf("\t Mensaje leido del pipe: %s \n", buffer);
     
     }
     
     else
     {
     		time(&hora);
		fecha = ctime(&hora) ;

                close(fd[0]); // Cierra el descriptor de lectura
                write(fd[1], fecha, 24);  
                wait(NULL);    
     }
     
        
}
