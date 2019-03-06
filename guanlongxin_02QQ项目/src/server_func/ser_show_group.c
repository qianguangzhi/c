#include"../../include/multiple.h"

void ser_show_group(int sockfd,Linkedlist* list,struct sockaddr_in cliaddr){

	int flag = 0;
	Node send;
	Node *show = list->head;

	while(show != NULL){
		
		bzero(&send,sizeof(send));
		send = *show;
		bzero(&send.code,sizeof(send.code));

		if(strcmp(show->group,"0") != 0){

			flag++;
			if(show->next == NULL){
				strcpy(send.code,"none");//发送完成标志位
				sendto(sockfd,(char *)&send,sizeof(send),0,(struct sockaddr*)&cliaddr,sizeof(cliaddr)); 
				break;
			}
			else{
				strcpy(send.code,"left");
				sendto(sockfd,(char *)&send,sizeof(send),0,(struct sockaddr*)&cliaddr,sizeof(cliaddr)); 
			}
		}
		else{
			if(show->next == NULL && flag != 0){
				strcpy(send.code,"none");//发送完成标志位
				sendto(sockfd,(char *)&send,sizeof(send),0,(struct sockaddr*)&cliaddr,sizeof(cliaddr)); 
				break;
			}
		}

		show = show->next;
		if(show == NULL && flag == 0){
			strcpy(send.code,"nogroup");//发送完成标志位
			sendto(sockfd,(char *)&send,sizeof(send),0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
		} 		
	}
	printf("查看群\n");
	return;
}
