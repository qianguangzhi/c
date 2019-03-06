#include"../../include/multiple.h"

void ser_show_online(int sockfd,Linkedlist* listic,struct sockaddr_in cliaddr){

	Node send;
	Node *show = listic->head;

	while(show != NULL){
		
		bzero(&send,sizeof(send));
		send = *show;
		bzero(&send.code,sizeof(send.code));
		if(show->next == NULL){
			strcpy(send.code,"none");//发送完成标志位
			sendto(sockfd,(char *)&send,sizeof(send),0,(struct sockaddr*)&cliaddr,sizeof(cliaddr)); 
			break;
		}
		else{

			strcpy(send.code,"left");
			sendto(sockfd,(char *)&send,sizeof(send),0,(struct sockaddr*)&cliaddr,sizeof(cliaddr)); 
		}
		
		printf("show online = %s\n",show->account);
		show = show->next;

	}
	printf("查看全部在线账户\n");
	return;
}
