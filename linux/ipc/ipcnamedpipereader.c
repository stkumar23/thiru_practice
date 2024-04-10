/* Linux Inter Process Communication - Named Pipe
  Parent and Child processes communicating using Pipe - Reader
  Use this program with ipcnamedpipewriter. Run this program after the
  writer program.

  Author: Thiru
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
  char msg;
  const char* pipeName = "./fifoChannel";

  int fd = open(pipeName, O_RDONLY);
  if(fd < 0) {
    printf("Could not open named pipe for reading");
    exit(1);
  }


  while(read(fd, &msg, 1) > 0) {
    write(STDOUT_FILENO, &msg, sizeof(msg));
  }

  close(fd);
  unlink(pipeName);

  return 0;
}
