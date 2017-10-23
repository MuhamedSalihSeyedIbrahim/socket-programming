// #include <stdio.h>
// #include <sys/socket.h>
// #include <stdlib.h>
// #include <netinet/in.h>
// #include <string.h>

// #define PORT 8080
// int main(int argc, char const *argv[])
// {
//   int soc;
  
//   if((soc = socket(PF_INET,SOCK_STREAM,0))==0){
//     printf("The socket not created\n");
//     exit(1);
//   }
//   printf("The socket created\n");
    

//   struct sockaddr_in add;
//   int add_len=sizeof(add);
//     add.sin_family = AF_INET;
//     add.sin_addr.s_addr = inet_addr("127.0.0.1");
//     add.sin_port = htons( PORT );

//     //memset(soc.sin_zero, '\0', sizeof soc.sin_zero);  
    
    
//     struct sockaddr_in addc;
//     int socc;
// if((connect(soc,(struct sockaddr*)&addc,(socklen_t*)&addc))<0){
//       printf("connection error\n");
//       exit(1);

//   }
//   printf("connection started\n");
   
//     char *hello="hello server",hi[1024]={0};
//     int recv;
//     recv= read(socc,hi,1024);
//     printf("%s\n",hi);
//     send(socc,hello,strlen(hello),0);
//     printf("the message sent");

// }

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
  int soc;
  char buffer[1024];
  struct sockaddr_in add;
  socklen_t addr_size;

 
  soc = socket(PF_INET, SOCK_STREAM, 0);
  

  add.sin_family = AF_INET;
 add.sin_port = htons(8080);
  add.sin_addr.s_addr = inet_addr("127.0.0.1");
  //memset(add.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  addr_size = sizeof add;
  connect(soc, (struct sockaddr *) &add, addr_size);
  send(soc,"hai to server from client\n",1024,0);
  printf("receiving started");
  recv(soc, buffer, 1024, 0);

  printf("Server: %s\n",buffer);   

  return 0;
}