#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){

	pid_t pid,pid2,pid3,pid4,pid5,pid_abuelo,pid_abuelo2;
	pid_abuelo2=getpid();
	pid=fork();
	
	if(pid==0){
	pid_abuelo=getpid();
		pid2=fork();
		if(pid2==0){
		
			pid4=fork();
			if(pid4==0){
				printf("Soy el proceso P5 pid = %d pid abuelo = %d \n",getpid(),pid_abuelo);	
			}
			else{
			wait(NULL);
			printf("Soy el proceso P3 pid = %d pid abuelo = %d \n",getpid(),pid_abuelo2);	
			}
		}
		else{
		pid_abuelo=getpid();
			pid3=fork();
			wait(NULL);
			if(pid3==0){
				pid5=fork();
				if(pid5==0){
					printf("Soy el proceso P6 pid = %d pid abuelo = %d \n",getpid(),pid_abuelo);		
				}
				else{
				wait(NULL);
					printf("Soy el proceso P4 pid = %d pid abuelo = %d \n",getpid(),pid_abuelo2);		
				}		
			}
			else{
			wait(NULL);
		printf("Soy el proceso P2 pid = %d \n",getpid());		
			}
		}
	}
	else{
		wait(NULL);
		printf("Soy el proceso P1 pid = %d \n",getpid());	
	}
	exit(0);
}
