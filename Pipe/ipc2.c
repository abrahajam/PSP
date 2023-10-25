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

                read (fd[0],&num2,sizeof(int));
                printf("\t Número a sumar %d \n", num2);
                suma = num2;
                printf("\t La suma total es igual a: %d \n", suma);
     
     }
     
     else
     
     {
                close(fd[0]); // Cierra el descriptor de lectura
                
                scanf("%d",&num);
                write(fd[1],&num,sizeof(int));
                
                
                
                wait(NULL);    
     }
     
        
}
