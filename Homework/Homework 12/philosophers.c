/* You need to switch from 2 to 5 semaphores.
   Initialize the 5 semaphores to unlocked.
   You still only need two semaphores in the OpList.
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int main () {
  struct sembuf Wait[5]
   = {
       {0,-1,SEM_UNDO},
       {1,-1,SEM_UNDO},
       {2,-1,SEM_UNDO},
       {3,-1,SEM_UNDO}
       {4,-1,SEM-UNDO}
     };

  struct sembuf Signal[5]
   = {
       {0,1,SEM_UNDO},
       {1,1,SEM_UNDO},
       {2,1,SEM_UNDO},
       {3,1,SEM_UNDO},
       {4,1,SEM_UNDO}
     };

  int ch, i, pid;
  key_t mykey;
  int semid;
  union wait waitstatus;
  struct sembuf OpList[5];

  mykey = ftok("philosophers",'a');
  semid = semget(mykey, 5, IPC_CREAT | 0600 );

  semctl(semid,0,SETVAL,0);
  semctl(semid,1,SETVAL,0);
  semctl(semid,2,SETVAL,0);
  semctl(semid,3,SETVAL,0);
  semctl(semid,4,SETVAL,0);

  for (i = 0; i < 5; i++){
    pid = fork();
    if(pid == 0) break;
  }
  if(pid == 0){
    pid = getpid();

    for(int i = 0; i < 5; i++){
      OpList[i] = Wait[i];
      semop(semid, OpList, 1);

      OpList[i] = Wait[(i+1 % 5)];
      semop(semid, OpList, 1);

      printf("Waiting\n");
      semop(semid,OpList,2);
      printf("Unlocked\n");
    }
    else { /* parent*/
      sleep(3);
      OpList[0] = Signal[0];
      OpList[1] = Signal[1];
      semop(semid,OpList,2);
      wait3(&ch,0,NULL);
    }
  for (i = 0 ; i < 5 ; i++ )
  {
    pid = fork();
    if (pid == 0) break;
  }
  if (pid == 0)
  {
    pid = getpid();
    /* do the philosopher thing */
    return 0;
  }
  else
  {
    for (i = 0 ; i < 5 ; i++){
      wait3(&ch,0,NULL);
    }
    /* remove the semaphore */
    return 0;
  }
}
      
