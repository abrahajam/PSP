#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
void main(){

     int fd[2]; 
     char buffer[2];
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
     		close(fd[1]); // Cierra el descriptor de escritura
     		int suma=0,num=0;
     		char num2;
        	while (1) {
        		read(fd[0], buffer,2); 

        		
            	        if(buffer[1]=='+'){
            	        	printf("\tRecibido carácter +\n");
            	        	break;
            	        }
            	        
        	}
     }
     else
     
     {
                close(fd[0]); // Cierra el descriptor de lectura
               write (fd[1],"12",2);
               write (fd[1],"22",2);
               write (fd[1],"32",2);
               write (fd[1],"42",2);
               write (fd[1],"+",1);
              	
     			wait(NULL);
        
     }
}
