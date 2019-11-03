#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void catch()
{
  printf("  Got signal \n");
//  signal(SIGINT, catch);
}

void RingRing(){
  printf("    Ring Ring \n");
}

int main ()
{

  int i;
  signal(SIGINT, catch);
  signal(SIGALRM, RingRing);
  alarm(6);

  for (i=0;i<20;i++){
    printf("%d\n",i);
    sleep(1);
  }
  return 0 ;

}

/* control c prints Got signal 2 */
/* after 6 seconds the program stops (Alarm clock) */
