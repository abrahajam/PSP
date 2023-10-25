#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main(){

     int fd[2]; 
     char buffer[30];
     int num;
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
     		int suma=0;
     		int num2=0;
     		
                close(fd[1]); // Cierra el descriptor de escritura
		while (buffer!="+"){
			if(buffer!="+"){
			read (fd[0],buffer,2);
                	printf("\t Número a sumar %s \n", buffer);
			}
			
		}
                
     }
     
     else
     
     {
                close(fd[0]); // Cierra el descriptor de lectura
                
                
                write(fd[1],"12",2);
                write(fd[1],"22",2);
                write(fd[1],"32",2);
                write(fd[1],"42",2);
                write(fd[1],"+",1);
                
                
                
                wait(NULL);    
     }
     
        
}
