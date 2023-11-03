//Proceso que lee del PIPE FIFO
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 



int main(void)
{
   int fp,fp2,numero=0,numero2=0,p,factorial=1;  
   char  buffer[2],factorial1[8];
 
   p=mkfifo("FIFO1", S_IFIFO|0666);//permiso de lectura y escritura
  
   fp = open("FIFO1", 0); 
   read(fp, buffer, 2); 

   numero = atoi(buffer);
   numero2 = numero;
   
   for(int i = 0; i < numero2;i++){
   	factorial *= numero;
  	numero--;
   }
   
   sprintf(factorial1,"%d",factorial);
   close(fp); 
   /////////////////////////////////////////
   fp2 = open("FIFO2", 1);  
   
   write(fp2,factorial1,sizeof(factorial1));
   
   close(fp2);
  return(0);
}
