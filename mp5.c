//1.
//2. AAA CCC CCC BBB. Sí, la salida podría ser diferente por los diferentes forks ademas de que el los padres no esperana a sus hijos por lo que podria salir cualquier cosa
//Código modificado.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
 pid_t pid1, pid2;
 printf("AAA \n");
 pid1 = fork();
 if (pid1==0)
 {
 printf("BBB \n");
 }
 else
 {
 wait(NULL);
 pid2 = fork();
 wait(NULL);
 printf("CCC \n");
 }
 exit(0);
}
