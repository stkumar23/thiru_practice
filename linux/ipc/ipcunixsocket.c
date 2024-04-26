/* Linux Inter Process Communication - Unix(IPC) Sockets
 * Parent and Child processes communicating using Socket descriptors
 * Using socketpair systemcall - #include <sys/socket.h>
 *
 * Author: Thiru
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>

int main()
{
  int sd[2]; // pair of socket descriptors
  char buf[80];

  if (socketpair(AF_UNIX, SOCK_STREAM, 0, sd) == -1) {
    perror("Could not open Sockets");
    exit(1);
  }

  if (!fork()) {
      // child process
      read(sd[1], &buf, sizeof(buf));
      printf("Child read: %s\n", buf);
      strcpy(buf, "Data received. Thanks!");
      write(sd[1], &buf, sizeof(buf));
      close(sd[1]);
      _exit(0);
  } else {
    // parent process
    strcpy(buf, "Linux IPC program demonstrates UNIX Sockets");
    write(sd[0], &buf, sizeof(buf));
    printf("Parent sent: %s\n", buf);
    read(sd[0], &buf, sizeof(buf));
    printf("Parent read: %s\n", buf);
    wait(NULL);
    close(sd[0]);
  }

  return 0;
}
