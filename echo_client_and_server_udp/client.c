#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
  int clien, portNum, nBytes;
  char buffer[1024];
  struct sockaddr_in client;
  socklen_t addr_size;

  clien = socket(PF_INET, SOCK_DGRAM, 0);

  client.sin_family = AF_INET;
  client.sin_port = htons(8080);
  client.sin_addr.s_addr = inet_addr("127.0.0.1");

  addr_size = sizeof client;

  while(1){
    printf("Type a sentence to send to server:\n");
    fgets(buffer,1024,stdin);
    printf("You typed: %s",buffer);
    nBytes = strlen(buffer) + 1;
    sendto(clien,buffer,nBytes,0,(struct sockaddr *)&client,addr_size);
    nBytes = recvfrom(clien,buffer,1024,0,NULL, NULL);
    printf("Received from server: %s\n",buffer);

  }

  return 0;
}
