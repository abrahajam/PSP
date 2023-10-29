#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>

void main(){

     int fd[2],fd2[2],num; 
     char buffer[2],num1[7];
     time_t t;
     pid_t pid;
    
     // Creamos el pipe
     pipe(fd); 
     pipe(fd2);
     
     //Se crea un proceso hijo
     pid = fork();

     if (pid==0)
     
     {
     		close(fd[1]); // Cierra el descriptor de escritura
     		close(fd2[0]);
     		int factorial=1,numero2=0,numero3;
     		char factorial1[7];
     		
     		read(fd[0],buffer,2);
     		close(fd[0]);
     		numero2 = atoi(buffer);
     		numero3 = numero2;

     		for(int i = 0; i < numero3;i++){
     			factorial *= numero2;
     			numero2--;
     		}
			
			sprintf(factorial1,"%d",factorial);
			write(fd2[1],factorial1,sizeof(factorial1));
     }
     else
     {
     	close(fd[0]); // Cierra el descriptor de lectura
     	close(fd2[1]);
     	
     	srand((unsigned) time(&t));
     	num = rand()%10;
     	sprintf(num1,"%d",num);
     	write (fd[1],num1,sizeof(num));
     	close(fd[1]);
        printf("\t El proceso padre genera el numero %s en el pipe \n", num1);
        
        wait(NULL);
        read(fd2[0],buffer,7);
        printf("\t El factorial calculado por el proceso hijo: %d !=%s \n", num,buffer);
     }
}
