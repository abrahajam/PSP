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
     		read(fd[0], buffer,2); 
     		printf("\tNumero a sumar es: %s\n",buffer);
        	while (1) {
        		read(fd[0], buffer,2); 
			suma+= (int )buffer;
            	       if(buffer[0]=='+'){
            	       printf("\tRecibido carácter +\n");
            	       break;
            	       }
            	       printf("\tNumero a sumar es: %s\n",buffer);
          	        	
            	        
        	}
        	 printf("\tLa suma total es: %d\n",suma);
     }
     else
     
     {
                close(fd[0]); // Cierra el descriptor de lectura
               write (fd[1],"12",2);
               write (fd[1],"22",2);
               write (fd[1],"32",2);
               write (fd[1],"42",2);
               write (fd[1],"+",2);
              	
     			wait(NULL);
        
     }
}
