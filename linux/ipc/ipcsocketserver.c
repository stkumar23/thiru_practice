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

int main()
{
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0) {
    printf("could not get the socket");
    exit(1);
  }

  struct sockaddr_in saddr;
  memset(&saddr, 0, sizeof(saddr));
  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = htonl(INADDR_ANY);
  saddr.sin_port = htons(PortNumber);

  if (bind(fd, (struct sockaddr*)&saddr, sizeof(saddr)) < 0){
    printf("could not bind");
    exit(2);
  }

  // listen to socket
  if (listen(fd, MaxConnects) < 0){
    printf("could not listen");
    exit(3);
  }

  fprintf(stderr, "listening on port %i for clients...\n", PortNumber);

  while(1) {
    struct sockaddr_in caddr;
    unsigned int len = sizeof(caddr);
    int client_fd = accept(fd, (struct sockaddr*)&caddr, &len);
    if (client_fd < 0) {
      printf("could not accept");
      continue;
    }

    // read from the client
    for(int i=0; i<ConversationLen; i++) {
      char buffer[BuffSize+1];
      memset(buffer, '\0', sizeof(buffer));
      int count = read(client_fd, buffer, sizeof(buffer));
      if (count > 0) {
        puts(buffer);
        write(client_fd, buffer, sizeof(buffer)); // echo as confirmation
      }
    }
    close(client_fd);
  }

  return 0;
}
