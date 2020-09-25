/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int counter = 0;


void start(int signum){
  counter++;
  printf("%d seconds\n", counter);
  alarm(1);  
}

void stop(int signum){
  printf("\nRan for %d seconds\n", counter);
  exit(0);
}

int main(int argc, char * argv[]){
  signal(SIGALRM, start);
  signal(SIGINT, stop);
  
  alarm(1);
  while(1);
  
  return 0;
  
}