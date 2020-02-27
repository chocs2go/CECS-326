#include <stdio.h> /* printf */
#include <unistd.h> /* fork and exit */
#include <stdlib.h> /* fork */
#include <sys/types.h> /* semaphore */
#include <sys/ipc.h> /* semaphore */
#include <sys/sem.h> /* semaphore */
#include <sys/shm.h> /* shared memory */
/* writer.c */

//counter operations not needed in writer
static struct sembuf Wait[3] = { {0, -3, SEM_UNDO}, {1, -3, SEM_UNDO}, {2, -3, SEM_UNDO} };
static struct sembuf Signal[3] = { {0, 3, SEM_UNDO}, {1, 3, SEM_UNDO}, {2, 3, SEM_UNDO} };
struct sembuf OpList[3];

int main() {

  key_t mykey;
  int semid, shmid;
  int i, c;
  int *mem;
  mykey = ftok("./readers.c", 'a');
  if ((semid = semget(mykey, 4, IPC_CREAT | IPC_EXCL | 0660)) != -1) {
    semctl(semid, 0, SETVAL, 3); //semaphore 1 - reader
    semctl(semid, 1, SETVAL, 3); //semaphore 2 - reader
    semctl(semid, 2, SETVAL, 3); //semaphore 3 - writer
    semctl(semid, 3, SETVAL, 0); //semaphore 4 - counter
  } else {
    semid = semget(mykey, 4, 0660);
