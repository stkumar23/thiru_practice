/* Linux Inter Process Communication - Message Queue - Writer
  Use this program with ipcmsgqueuereader. Run both the programs in
  the same terminal. Sequence is writer and then reader.

  Author: Thiru
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

  char* payloads[] = {"msg1", "msg2", "msg3", "msg4", "msg5", "msg6"};
  int types[] = {1, 1, 2, 2, 3, 3};

  for(int i = 0; i< MsgCount; i++) {
    queuedMessage msg;
    msg.type = types[i];
    strcpy(msg.payload, payloads[i]);

    msgsnd(qid, &msg, sizeof(msg), IPC_NOWAIT); // dont block - IPC_NOWAIT
  }

  return 0;
}
