#include <stdlib.h> /* Needed for fork. */
#include <stdio.h>  /* Needed for printf. */
#include <stdbool.h> /* Needed for bool, optional. */
#include <unistd.h> /* Needed for for and exit. */
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

static struct sembuf Wait = {0, -2, SEM_UNDO};
static struct sembuf Signal = {0, 2, SEM_UNDO};

int main (){
  key_t mykey;
  int semid;
  int i;
  mykey = ftok("./LW.c", 'a');
    if ((semid = semget(mykey, 1, IPC_CREAT|IPC_EXCL|0660)) != -1){
      semctl(semid, 0, SETVAL, 5);
    }
    else{
      semid = semget(mykey,1, 0660);
    }
    printf("semID = %d\n", semid);

    /* Create a new process */
    for(i = 0; i <= 5; i++){
      semop(semid, &Wait, 1);
        printf("LightWeight Starting\n");
        //fflush(stdout);
        sleep(4);
        printf("LightWeight Ending\n");
        //fflush(stdout);
        semop(semid, &Signal, 1);
        sleep(8);
    }
    semctl(semid, 0, IPC_RMID, 0);
    return 0;
}

