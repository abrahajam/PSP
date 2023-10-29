#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>

void main(){

     int fd[2],fd2[2];
     char buffer[2],letra[] = "TRWAGMYFPDXBNJZSQVHLCKE",letra2[2];
     time_t t;
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     pipe(fd2);
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
     		close(fd[0]); // Cierra el descriptor de lectura
     		close(fd2[1]);
     		int dni;
     		printf("Introduce el numero de tu DNI:");
     		scanf("%d",&dni);
     		
     		write(fd[1],&dni,sizeof(dni));
			
		read(fd2[0],buffer,1);
		printf("La letra del NIF es: %s \n", buffer);
			
     }
     else
     {
     	
        
        int dni;
        close(fd[1]); // Cierra el descriptor de escritura
        close(fd2[0]);
     	
     	read(fd[0],&dni,8);
	
	dni %= 23;
	letra2[0]=letra[dni];
	write(fd2[1],letra2,1);
     	wait(NULL);
        
     }
}
