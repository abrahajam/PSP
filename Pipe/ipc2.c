#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

void main(){

     int fd[2]; 
     char buffer[30];
     char num;
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
     		int suma=0;
     		char num2=0;
     		printf("\t Mensaje leido del pipe: %d \n", num2);
                close(fd[1]); // Cierra el descriptor de escritura
                     		printf("\t Mensaje leido del pipe: %d \n", num2);
                read (fd[0],&num2,sizeof(char));
                printf("\t Mensaje leido del pipe: %d \n", num2);
                
     }
     
     else
     
     {
                close(fd[0]); // Cierra el descriptor de lectura
                
                scanf("%hhd",&num);
                write(fd[1],&num,sizeof(char));
                
                wait(NULL);    
     }
     
        
}
