/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
int t = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  t = 1;
  alarm(1); //exit after printing
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1);
  while(1){
    while(t==0);
    printf("Turing was right!\n");
    t = 0;
    
  }//busy wait for signal to be delivered
   return 0;//never reached
}