/* Linux Inter Process Communication - Message Queue - Reader
  Use this program with ipcmsgqueuewriter.

  Author: Thiru
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "queue.h"

int main()
{
  key_t key = ftok(PathName, ProjectId);
  if (key < 0) {
    printf("could not get key");
    exit(1);
  }

  int qid = msgget(key, 0666 | IPC_CREAT);;
  if (qid < 0) {
    printf("could not get queue id");
    exit(2);
  }

  // order can be redefined
  int types[] = {3, 1, 2, 1, 3, 2}; // different order from sender. demo
  for(int i=0; i<MsgCount; i++) {
    queuedMessage msg;
    if(msgrcv(qid, &msg, sizeof(msg), types[i], MSG_NOERROR | IPC_NOWAIT) < 0)
      printf("Could not get messge\n");

    printf("%s received as type %d\n", msg.payload, (int)msg.type);
  }

  // remove the queue
  if (msgctl(qid, IPC_RMID, NULL) < 0)
    printf("Could not remove the queue\n");

  return 0;
}
