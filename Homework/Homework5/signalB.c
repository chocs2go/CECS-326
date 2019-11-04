#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void Catch()
{
  printf("Got signal \n");
//  signal(SIGINT, catch);
}

void Ring(){
  printf("Ring Ring \n");
}

int main ()
{

  struct sigaction saCatch, saRing;
  saCatch.sa_handler = Catch;
  saRing.sa_handler = Ring;

  int i;
  sigaction(SIGINT, &saCatch, NULL);
  sigaction(SIGALRM, &saRing, NULL);
  alarm(6);

  for (i=0;i<20;i++){
    printf("%d\n",i);
    sleep(1);
  }
  return 0 ;

}

/* control c prints Got signal 2 */
/* after 6 seconds the program stops (Alarm clock) */
