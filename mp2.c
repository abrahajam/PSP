#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main() {
  pid_t pid;
  pid_t PEPE,JUAN;
  
  PEPE = fork();
  if (PEPE == -1 ){ //Ha ocurrido un error
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);
  }
   
  if (PEPE == 0 ){
  	JUAN = fork();
    if (JUAN == -1 ){ //Ha ocurrido un error
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);
    }
  	if(JUAN == 0){
  		printf("Soy el proceso NIETO ... pid = %d ppid= %d 	\n",getpid(),getppid());	
  	}
  	else{
  	wait(NULL);
  	printf("Soy el proceso PADRE ... pid = %d ppid= %d 	\n",getpid(),getppid());	 
    }
  }
  else{   //Nos encontramos en Proceso padre
  	 wait(NULL); //espera la finalización del proceso hijo
  	printf("Soy el proceso ABUELO ... pid = %d ppid= %d	\n",getpid(),getppid());		 
  }
   exit(0);
}
