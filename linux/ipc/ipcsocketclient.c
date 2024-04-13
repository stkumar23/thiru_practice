/* Linux Inter Process Communication - Sockets
  Server and Client programs communicating using Sockets

  Author: Thiru
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "sock.h"

const char* books[] = {
  "Atomic Habits",
  "Who moved my cheese",
  "Thoughts"
};

int main()
{
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0) {
    printf("could not get the socket");
    exit(1);
  }

  struct hostent* hptr = gethostbyname(Host);
  if (!hptr) {
    printf("could not get host by the name");
    exit(2);
  }
  if (hptr->h_addrtype != AF_INET) {
    printf("bad address family");
    exit(3);
  }
  struct sockaddr_in saddr;
  memset(&saddr, 0, sizeof(saddr));
  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = ((struct in_addr*) hptr->h_addr_list[0])->s_addr;
  saddr.sin_port = htons(PortNumber);

  if (connect(fd, (struct sockaddr*)&saddr, sizeof(saddr)) < 0){
    printf("could not connect");
    exit(4);
  }

  puts("connect to server, about to write some stuff...\n");

  // read from the client
  for(int i=0; i<ConversationLen; i++) {
    if (write(fd, books[i], strlen(books[i])) > 0) {
      char buffer[BuffSize+1];
      memset(buffer, '\0', sizeof(buffer));
      if(read(fd, buffer, sizeof(buffer)) > 0)
        puts(buffer);
    }
  }

  puts("Client done, about to exit...");
  close(fd);

  return 0;
}
