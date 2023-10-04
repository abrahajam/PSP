#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	pid_t pid,pid2,pid3;
	
	if(getpid()%2==0){
		printf("Soy el proceso P1 pid = %d ppid= %d \n",getpid(),getppid());
	}
	else{
		printf("Soy el proceso P1 pid = %d \n",getpid());
	}
	pid=fork();
	
	if(pid==0){
		if(getpid()%2==0){
		printf("Soy el proceso P2 pid = %d ppid= %d \n",getpid(),getppid());
		}
		else{
		printf("Soy el proceso P2 pid = %d \n",getpid());
		}
	}
	else{
		pid2=fork();
		wait(NULL);
		if(pid2==0){
			if(getpid()%2==0){
			printf("Soy el proceso P3 pid = %d ppid= %d 	\n",getpid(),getppid());
			}
			else{
			printf("Soy el proceso P3 pid = %d \n",getpid());
			}
			pid3=fork();
			if(pid3==0){
				if(getpid()%2==0){
				printf("Soy el proceso P4 pid = %d ppid= %d \n",getpid(),getppid());
				}
				else{
				printf("Soy el proceso P4 pid = %d \n",getpid());
				}		
			}
			else{
				wait(NULL);
			}
		}
		else{
			wait(NULL);
		}
			 
	}
	exit(0);
}
