#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
  int clien=socket(PF_INET, SOCK_STREAM, 0);

  struct sockaddr_in client;
  socklen_t clientsize=sizeof client;
  client.sin_family = AF_INET;
  client.sin_port = htons(8080);
  client.sin_addr.s_addr = inet_addr("127.0.0.1");

  
  connect(clien, (struct sockaddr *) &client, clientsize);

  char client_msg[1024] = "client-server connected!\n", server_msg[1024];

  send(clien,client_msg , 1024, 0);
  printf("client-server connected!\n");
  while (strcmp(client_msg, "~1") != 0)
  {

    recv(clien, server_msg, 1024, 0);
    printf("Server: %s\n", server_msg);

   printf("client:");  
   scanf("%s", client_msg);
    send(clien,client_msg,1024,0);   
  } 

  return 0;
}
