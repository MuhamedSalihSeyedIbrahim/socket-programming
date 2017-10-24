#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

int main(){
  int server, nBytes;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size, client_addr_size;
  int i;

  server = socket(PF_INET, SOCK_DGRAM, 0);

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(8080);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  bind(server, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

  addr_size = sizeof serverStorage;

  while(1){
    recvfrom(server,buffer,1024,0,(struct sockaddr *)&serverStorage, &addr_size);
    printf("client: %s\n", buffer);
    printf("server:");printf("%s",buffer);
    sendto(server,buffer,1024,0,(struct sockaddr *)&serverStorage,addr_size);
  }

  return 0;
}
