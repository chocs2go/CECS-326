/* file: deadlock1.c */
/* Rearrange the semaphores so the program no longer deadlocks */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
void main () {
  /* The two semaphores are numbered 0 and 1 */
  struct sembuf Wait0 = {0, -1, SEM_UNDO};
  struct sembuf Signal0 = {0,  1, SEM_UNDO};
  struct sembuf Wait1= {1, -1, SEM_UNDO};
  struct sembuf Signal1= {1,  1, SEM_UNDO};
  struct sembuf OpList[2];

  int pid; /* for knowing who the parent is */
  key_t mykey;
  int semid;
  int waitstatus;

  mykey = ftok("./deadlock1.c",'a');
  /* request 2 semaphores for my programs only */
  semid = semget(mykey, 2, IPC_CREAT | 0600 );
  semctl(semid,  0, SETVAL,  1);
  semctl(semid,  1, SETVAL,  1);
  /* fork one child */
  pid = fork();
  if ( 0 != pid ) {
    /* parent */
    OpList[0] = Wait0;
    OpList[1] = Wait1;
    semop(semid, OpList, 2); //OpList used to allocate all resources at the same time
    /* Place critical section here */
    printf("start process %d\n", getpid() );
    sleep(1);
    printf("end process %d\n\n", getpid() );
    OpList[0] = Signal0;
    OpList[1] = Signal1;
    semop(semid, OpList, 2);
    /* wait for any children to finish, the status is ignored */
    wait3(&waitstatus,0,NULL);
  }
  else {
    /* child */
    OpList[0] = Wait0;
    OpList[1] = Wait1;
    semop(semid, OpList, 2);
    /* place critical section here */
    printf("start process %d \n", getpid() );
    sleep(1);
    printf("end process %d \n\n", getpid() );
    OpList[0] = Signal0;
    OpList[1] = Signal1;
    semop(semid, OpList, 2);
  }
}
               
