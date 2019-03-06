#include"../../include/multiple.h"

void ser_creat_group(int sockfd,Linkedlist *list,send_user user_info,struct sockaddr_in cliaddr){

	Node *check_group = list->head;
	struct sockaddr_in cli_addr;
	char buff[128];
	bzero(&cli_addr,sizeof(cli_addr));
	cli_addr = cliaddr;

	//遍历信息链表
	while(check_group != NULL){

		if(strcmp(check_group->group,user_info.send_account) == 0){
			printf("exist\n\n");
			bzero(buff,128);
			strcpy(buff,"exist");
			sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,sizeof(cliaddr));
			return;
		}
		check_group = check_group->next;
	}
	
	check_group = list->head;
	while(check_group != NULL){

		if(strcmp(check_group->account,user_info.my_account) == 0){
			if(strcmp(check_group->group,"0") == 0 ){
				printf("success\n");
				bzero(buff,128);
				strcpy(buff,"success");
				strcpy(check_group->group,user_info.send_account);
				sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,sizeof(cliaddr));
				printf("send to complete!\n");
				break;
			}
			else{
				printf("failed\n");
				bzero(buff,128);
				strcpy(buff,"failed");
				sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,sizeof(cliaddr));
				break;
			}
		}
		check_group = check_group->next;
	}
	return;
}
