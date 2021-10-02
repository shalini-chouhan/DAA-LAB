#include <sys/types.h>     
#include <sys/socket.h>
#include<stdio.h>
#include <arpa/inet.h>
#include<unistd.h>
#include<string.h>
int ispalindrome(int n){
int temp=n;
int dig,num=0;
while(temp>0){
dig=temp%10;
num=num*10+dig;
temp=temp/10;
}
if(num==n)
return 1;
else{
return 0;
}
}
int main()
{

      int sockfd,bnd,l1,flag=0;
	int num;
	char str[4];
     sockfd=socket(AF_INET,SOCK_DGRAM,0);
      if(sockfd>0){
	printf("Socket is created : %d\n",sockfd);
	}
      else{
printf("Socket is not created\n");
}
 struct sockaddr_in server;
server.sin_family=AF_INET;
server.sin_port=htons(5000);
server.sin_addr.s_addr=inet_addr("127.0.0.1");

 bnd=bind(sockfd, (const struct sockaddr *) &server,sizeof(server));
if(bnd==0)
printf("Bind is successful : %d\n",bnd);
else
printf("Bind is unsuccessful\n");
l1=sizeof(server);
recvfrom(sockfd, &num, sizeof(num), 0,
                        (struct sockaddr *) &server, &l1);
printf("Number recieved from client : %d\n",num);
if(ispalindrome(num)){
strcpy(str,"yes");
}
else{
strcpy(str,"no");
}
sendto(sockfd, str , strlen(str), 0,
                      (const struct sockaddr *) &server, sizeof(server));

close (sockfd);
}
