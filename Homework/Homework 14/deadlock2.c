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
  
   mykey = ftok("deadlock2.out",'a');
  /* request 5 semaphores for my programs only */
  if (mykey == -1) {
    printf("File for key did not exist\n");
    return 1;
  }
  semid = semget(mykey, 5, IPC_CREAT | 0600 );
  for (i = 0; i < 5 ; i++ ) {
    /* initialize the wait, signal and count for each semaphore */
    Waits[i].sem_op = -1;
    Signals[i].sem_op = 1;
    Waits[i].sem_num = i;
    Signals[i].sem_num = i;
    Waits[i].sem_flg = SEM_UNDO;
    Signals[i].sem_flg = SEM_UNDO;
    semctl(semid,  i, SETVAL,  1);
  }
  
}

return 0;
