/* Linux Inter Process Communication - Shared Memory
  MemWriter. Use this program with ipcmemreader.
  Compile using: -lrt -lpthread

  Author: Thiru
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include "shmem.h"

int main()
{
  int fd = shm_open(BackingFile, O_RDWR | O_CREAT, AccessPerms);
  if (fd < 0) {
    printf("Cant open shared mem segment");
    exit(1);
  }

  ftruncate(fd, ByteSize);
  caddr_t memptr = mmap(NULL, ByteSize, PROT_READ | PROT_WRITE,
                        MAP_SHARED, /* mapping visible to other processes */
                        fd, /* file descriptor */
                        0); /* offset: start at first byte */
  if ((caddr_t) -1 == memptr) {
    printf("Cant access segment");
    exit(2);
  }

  sem_t* semptr = sem_open(SemaphoreName, O_CREAT, AccessPerms, 0); // 0 - initial value
  if (semptr == (void*)-1) {
    printf("Cant get semaphore");
    exit(3);
  }

  strcpy(memptr, MemContents);

  if(sem_post(semptr) < 0) {
    printf("Cant sempost");
    exit(4);
  }

  sleep(12);

  // clean up
  munmap(memptr, ByteSize);
  close(fd);
  sem_close(semptr);
  shm_unlink(BackingFile);

  return 0;
}
