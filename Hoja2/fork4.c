#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
	pid_t pid,pid2,pid3,pid4;
	int acumulado = getpid();
	
	printf("Soy el proceso P1 acumulado = %d \n",acumulado);	
	pid=fork();
	
	if(pid==0){
		if(getpid()%2==0){
		acumulado +=10;
	printf("Soy el proceso P2 acumulado = %d \n",acumulado);	
		}
		else{
		acumulado -= 100;
			printf("Soy el proceso P2 acumulado = %d \n",acumulado);	
		}

		pid2=fork();
		if(pid2==0){
			if(getpid()%2==0){
				acumulado +=10;
				printf("Soy el proceso P5 acumulado = %d \n",acumulado);	
			}
			else{
				acumulado -= 100;
				printf("Soy el proceso P5 acumulado = %d \n",acumulado);	
			}		
		}
		else{
		wait(NULL);
		}
	}
	else{
	pid3=fork();
	wait(NULL);
	
		
		
		
		if(pid3==0){
			if(getpid()%2==0){
		acumulado +=10;
	printf("Soy el proceso P3 acumulado = %d \n",acumulado);	
		}
		else{
		acumulado -= 100;
	printf("Soy el proceso P3 acumulado = %d \n",acumulado);	
				}
			pid4=fork();
			if(pid4==0){
			if(getpid()%2==0){
				acumulado +=10;
				printf("Soy el proceso P4 acumulado = %d \n",acumulado);
			}
			else{
				acumulado -= 100;
				printf("Soy el proceso P4 acumulado = %d \n",acumulado);	
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
