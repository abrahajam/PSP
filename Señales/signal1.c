#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

void signal_funcion(int signum){
	time_t hora;
        char *fecha ;
        time(&hora);
        fecha = ctime(&hora);
	if (signum == SIGINT)
    		printf("Fin del proceso %d: %s",getpid(),fecha);
    	exit(EXIT_SUCCESS);
}
  
int main() 
{	

	time_t hora;
        char *fecha ;
        time(&hora);
        fecha = ctime(&hora);
        printf("Inicio del proceso %d: %s",getpid(),fecha);
	signal(SIGINT,signal_funcion); 
	while (1) 
    	{ 
        sleep(1); 
    	} 
    return 0; 
        
} 
