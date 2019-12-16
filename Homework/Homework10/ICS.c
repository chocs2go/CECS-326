#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <wait.h>

static struct sembuf Wait = {0, -1, SEM_UNDO};
static struct sembuf Signal = {0, 1, SEM_UNDO};

int main(){

  int count = 1;
  key_t mykey;
  int semid;
  int result;
  int i;
  mykey = ftok("./ICS.c", 'a');
  semid = semget(mykey, 1, IPC_CREAT | 0660);
  semctl(semid, 0, SETVAL, 1);
  printf("Semaphore ID = %d\n" , semid);
  result = fork();

  for (i = 0; i < 10; i++){
    semop(semid, &Wait, 1);
    if (result == 0){
      printf("%d\nN/S car enter intersection\n", count);
      sleep(1);
      printf("N/S car exit intersection\n\n");
      semop(semid, &Signal, 1);
    }
    else {
      printf("%d\nE/W car enter intersection\n", count);
      sleep(1);
      printf("E/W car exit intersection\n\n");
      semop(semid, &Signal, 1);
    }
    count = count + 1;
  }

  if (result >= 0){
    wait3(&result, 0, NULL);
    return result;
  }
  else{
    return 0;
  }
}
