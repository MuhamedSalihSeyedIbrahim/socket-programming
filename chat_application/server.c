#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>


int main(int argc, char const *argv[])
{
  struct sockaddr_in server;
  int serve=socket(PF_INET,SOCK_STREAM,0);
    
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_port = htons(8080);

  bind(serve, (struct sockaddr *)&server, sizeof(server));
  listen(serve,3);
    
    
  struct sockaddr_in client;
  int clien = accept(serve, (struct sockaddr *)&client, (socklen_t *)&client);

  char server_msg[1024], client_msg[1024];

  recv(clien, client_msg, 1024, 0);
  printf("%s",client_msg);

  while (strcmp(server_msg,"~1")!=0)
  {
    printf("server:"); //getline(&server_msg, 1024, stdin);
    scanf("%s", server_msg);
    send(clien, server_msg, strlen(server_msg), 0);

    recv(clien, client_msg, 1024, 0);
    printf("client: %s\n", client_msg);
  }
}
