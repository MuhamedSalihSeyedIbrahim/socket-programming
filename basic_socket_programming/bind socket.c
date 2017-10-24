#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
int main(int argc, char const *argv[])
{
  int soc;
  
  if((soc = socket(PF_INET,SOCK_STREAM,0))==0){
    printf("The socket not created\n");
    exit(1);
  }
  else{
    printf("The socket created\n");
    }

  struct sockaddr_in add;
  int add_len=sizeof(add);
    add.sin_family = AF_INET;
    add.sin_addr.s_addr = INADDR_ANY;
    add.sin_port = htons( PORT );

  if(bind(soc,(struct sockaddr*)&add,add_len)<0){
        printf("The socket not binded\n");
        exit(1);
    }
  else{
       printf("The socket binded\n");
  }
  if(listen(soc,3)<0){
  printf("The listening error");
  exit(0);
  }
  else{
    printf("The listening started");
  }
}
