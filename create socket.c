#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
int main(int argc, char const *argv[])
{
  int soc;
  soc = socket(PF_INET,SOCK_STREAM,0);
  if(soc){
    printf("the socket created");
  }
}