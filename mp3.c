#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	pid_t pid,pid2;
	
	pid=fork();
	
	if (pid == -1 ){ //Ha ocurrido un error
    printf("ERROR !!! No se ha podido crear el proceso hijo...");
    exit(-1);
  }
	
	if(pid==0){
		
		printf("Soy el proceso P2 me voy a dormir...\n");
		sleep(10);
		printf("DESPIERTO\n");
	}
	else{
		pid2=fork();
		wait(NULL);
		if(pid2==0){
			printf("Soy el proceso P3 ... ppid = %d pid= %d \n",getppid(),getpid());
		}
		else{
			wait(NULL);
		}
	}
	exit(0);
}
