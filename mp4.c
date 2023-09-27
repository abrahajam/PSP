//1. /*Al escribir por pantalla CCC el pid es 1000 y al entrar en el if y crear el fork no se sabria cual seria el siguiente en crearse podria ser primero la 
ejecución de AAA o la de BBB*/
//2. Salida: CCC AAA BBB. Si que podría generarse otra salida ya que el padre no espera al hijo
//codigo modificado:
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
 printf("CCC \n");
 if (fork()!=0)
 {
 wait(NULL);
 printf("AAA \n");
 } else {
 
 printf("BBB \n");
 }
 exit(0);
}
