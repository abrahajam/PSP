//Proceso que escribe en PIPE FIFO
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 
#include <time.h>

int main()
{
   int fp,p,fp2;
   fp = open("FIFO1", 1);
   time_t t;
   char num1[2],buffer[8];
  
  
   srand((unsigned) time(&t));
   int num = rand()%11;
   sprintf(num1,"%d",num);
  
   printf("Mandando información al pipe FIFO... %s\n",num1);
   write(fp,&num1, sizeof(int));
  
   close(fp);
   /////////////////////////////////
   p=mkfifo("FIFO1", S_IFIFO|0666);//permiso de lectura y escritura
   fp2 = open("FIFO2",0);
   read(fp2,buffer,7);
   printf("Mandando información al pipe FIFO... %s\n",buffer);
   close(fp2);
   return 0; 
}
