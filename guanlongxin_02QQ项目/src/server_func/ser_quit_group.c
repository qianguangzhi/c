#include"../../include/multiple.h"

void ser_quit_group(int sockfd,Linkedlist *list,send_user user_info,struct sockaddr_in cliaddr){

	Node *check_group = list->head;
	struct sockaddr_in cli_addr;
	bzero(&cli_addr,sizeof(cli_addr));
	cli_addr = cliaddr;
	send_user send_info;
	bzero(&send_info,sizeof(send_info));
	socklen_t cliaddrlen = sizeof(cliaddr);

	//遍历信息链表
	while(check_group != NULL){

		if(strcmp(check_group->account,user_info.my_account) == 0){
			if(strcmp(check_group->group,"0") == 0){
				printf("退出群：未加入群\n");
				strcpy(send_info.send_account,"0");
				sendto(sockfd,(char*)&send_info,sizeof(send_info),0,(struct sockaddr*)&cli_addr,sizeof(cliaddr));
				break;
			}
			else{
				printf("退出群：退出确认\n");
				strcpy(send_info.send_account,check_group->group);
				sendto(sockfd,(char*)&send_info,sizeof(send_info),0,(struct sockaddr*)&cli_addr,sizeof(cliaddr));

				bzero(&send_info,sizeof(send_info));
				recvfrom(sockfd,(char*)&send_info,sizeof(send_info),0,(struct sockaddr*)&cli_addr,&cliaddrlen);

				if(strncmp(send_info.my_code,"quit",4) == 0){
					strcpy(check_group->group,"0");
					ser_save(list);
					printf("退出群：已退出\n");
					break;
				}
				else{
					printf("退出群：放弃退出\n");
					break;
				}
			}
		}
		check_group = check_group->next;
	}
	return;
}
