/* file: deadlock2.c */
/* You must correct this program. */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
int main () {
  /* The 5 semaphores (for the forks) are numbered 0 throug 4.
     The philosophers are also numbered 0 through 4. The fork
     on your left fork matches your philosopher number; the one on
     your right is one more than you number (except for philsopher 4
     whose right fork is number 0)
   */
  struct sembuf Waits[5] ;
  struct sembuf Signals[5] ;
  struct sembuf OpList[2];
  int i;
  int eat_round;
  int pid; /* for knowing who the parent is */
  key_t mykey;
  int semid;
  int waitstatus;
}

return 0;
