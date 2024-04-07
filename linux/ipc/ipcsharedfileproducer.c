/* Linux Inter Process Communication - Shared Files
  Producer program. Program which writes the data into a file

  Author: Thiru
  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#define FILENAME "/tmp/msg.txt"

// main()
int main()
{
  struct flock lock;
  lock.l_type = F_WRLCK;    // rw access
  lock.l_whence = SEEK_SET; // base for seek offsets
  lock.l_start = 0;         // first byte in file
  lock.l_len = 0;           // until EOF
  lock.l_pid = getpid();    // process id

  char data[] = "This is sample program demonstrates the Linux IPC - Shared File\n";

  int fd;
  if((fd = open(FILENAME, O_RDWR | O_CREAT, 0666)) < 0) {
    printf("File open failed\n");
    exit(1);
  }

  if(fcntl(fd, F_SETLK, &lock) < 0) {
    printf("fnctl failed to get lock\n");
    exit(2);
  } else {
    write(fd, data, strlen(data));
  }

  // release the lock
  lock.l_type = F_UNLCK;
  if(fcntl(fd, F_SETLK, &lock) < 0) {
    printf("explicit unlocking failed\n");
    exit(3);
  }

  close(fd);

  return 0;
}
