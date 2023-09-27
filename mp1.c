#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	pid_t pid;
	
	pid=fork();
	
	if (pid == -1 ){ //Ha ocurrido un error
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);
  }
	
	if(pid==0){
		printf("Nombre del alumno: Abraham\n");
		printf("Soy el proceso HIJO ... pid = %d \n",getpid());
	}
	else{
		wait(NULL);
		printf("Soy el proceso PADRE ... pid = %d 	\n",getpid());	 
	}
	exit(0);
}
