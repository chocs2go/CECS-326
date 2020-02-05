#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main () {
  int myqueue;
  int i = 0;
  key_t mykey;
  int status;
  int msgsz = sizeof(i);
  struct Mybuf {
    long mtype;
    int mvalue;
  };

  struct Mybuf buf;
  mykey = ftok( "./sndmes.c" , 'a' );
  myqueue = msgget(mykey, IPC_CREAT | 0600 );

  if ( -1 == myqueue) {
    printf("error in msgget");
    return 1;
  }
  /* no special instructions */
  buf.mtype = 1;
  for ( i = 0; i < 5; i++) {
    printf("Enter the multiplicand: ");
    scanf("%d", &buf.mvalue);
    status = msgsnd(myqueue, (struct msgbuf *)&buf, msgsz, 0);
    printf("Enter the multiplier: ");
    scanf("%d", &buf.mvalue);
    status = msgsnd(myqueue, (struct msgbuf *)&buf, msgsz, 0);
    status = msgrcv(myqueue, (struct msgbuf *)&buf, msgsz, 0, 0);
    printf("Product: %d\n", buf.mvalue);
  }
    return 0;
}

