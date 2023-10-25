#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include<stdbool.h>
void main(){

     int fd[2]; 
     char buffer[30];
     char num;
     bool sumar = true;
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
     		int suma=0;
     		char num2=0;
                close(fd[1]); // Cierra el descriptor de escritura
                     		
                read (fd[0],buffer,sizeof(buffer));
                printf("\t Numero a sumar: %s\n", buffer);
                
     }
     
     else
     
     {
                close(fd[0]); // Cierra el descriptor de lectura
                
               
                
                	
              	write(fd[1],"12123",5);
              	write(fd[1],"43251",5);
              	write(fd[1],"62323",5);
              	write(fd[1],"82143",5);
                
                
                wait(NULL);    
     }
     
        
}
