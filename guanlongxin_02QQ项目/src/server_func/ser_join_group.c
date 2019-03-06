#include"../../include/multiple.h"

void ser_join_group(int sockfd,Linkedlist *list,send_user user_info,struct sockaddr_in cliaddr){

	Node *check_group = list->head;
	struct sockaddr_in cli_addr;
	bzero(&cli_addr,sizeof(cli_addr));
	char buff[128];
	cli_addr = cliaddr;
	int flag = 0;

	while(check_group != NULL){

		if(strcmp(check_group->account,user_info.my_account) == 0){	
			flag++;
			if(strcmp(check_group->group,"0") != 0){
				bzero(buff,128);
				strcpy(buff,"exit");
				printf("result = %s\n",buff);
				sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,sizeof(cliaddr));
			}
			else{
				strncpy(check_group->group,user_info.send_account,sizeof(user_info.send_account));
				ser_save(list);
				bzero(buff,128);
				strcpy(buff,"success");
				printf("result = %s\n",buff);
				sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,sizeof(cliaddr));
			}
			return;
		}
		check_group = check_group->next;
	}
	
	//遍历信息链表
	check_group = list->head;
	while(check_group != NULL){

		if(strcmp(check_group->group,user_info.send_account) == 0){
			flag++;
			break;
		}
		check_group = check_group->next;
	}
	if(flag == 0){

		bzero(buff,128);
		strcpy(buff,"not");
		printf("result = %s\n",buff);
		sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,sizeof(cliaddr));
	}
	
	return;
}










