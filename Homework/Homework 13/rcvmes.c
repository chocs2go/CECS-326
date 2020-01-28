#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main () {
  int myqueue;
  int i;
  int multiplicand = 0;
  int multiplier = 0;
  key_t mykey;
  int status;
  int msgsz = sizeof(multiplier);
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
    status = msgrcv(myqueue, (struct msgbuf *)&buf, msgsz, 0, 0);
    multiplicand = buf.mvalue;
    status = msgrcv(myqueue, (struct msgbuf *)&buf, msgsz, 0, 0);
    multiplier = buf.mvalue;
    buf.mvalue = multiplicand * multiplier;
    status = msgsnd(myqueue, (struct msgbuf *)&buf, msgsz, 0);
  }
    return 1;
}


