#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	pid_t pid,pid2,pid3,suma;
	
	suma=getpid()+getppid();
	printf("Soy el proceso P1 pid = %d ppid= %d suma = %d \n",getpid(),getppid(),suma);
	
	pid=fork();
	
	if(pid==0){
	suma=getpid()+getppid();
	printf("Soy el proceso P2 pid = %d ppid= %d suma = %d \n",getpid(),getppid(),suma);
		pid2=fork();
		if(pid2==0){
		suma=getpid()+getppid();
		printf("Soy el proceso P3 pid = %d ppid= %d suma = %d \n",getpid(),getppid(),suma);
			pid3=fork();
			if(pid3==0){
			suma=getpid()+getppid();
			printf("Soy el proceso P4 pid = %d ppid= %d suma = %d \n",getpid(),getppid(),suma);
			}
			else{
				wait(NULL);
			}
		}
		else{
			wait(NULL);
		}
	}
	else{
		wait(NULL);
	}
	exit(0);
}
