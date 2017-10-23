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
  printf("The socket created\n");
    

  struct sockaddr_in add;
  int add_len=sizeof(add);
    add.sin_family = AF_INET;
    add.sin_addr.s_addr = INADDR_ANY;
    add.sin_port = htons( PORT );

  if(bind(soc,(struct sockaddr*)&add,add_len)<0){
        printf("The socket not binded\n");
        exit(1);
    }
  printf("The socket binded\n");
  
  
  if(listen(soc,3)<0){
      printf("listening error\n");
      exit(1);

  }
  printf("The listening started\n");
    
    
    struct sockaddr_in addc;
    int socc;
if((socc=accept(soc,(struct sockaddr*)&addc,(socklen_t*)&addc))<0){
      printf("accepting error\n");
      exit(1);

  }
  else{
      printf("Accepting started\n");
    }
    

    char *hello="hello",hi[1024]={0};
    int recv;
    recv= read(socc,hi,1024);
    printf("%s\n",hi);
    send(socc,hello,strlen(hello),0);
    printf("the message sent");

}