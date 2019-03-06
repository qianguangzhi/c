#include"../../include/multiple.h"

void ser_group_chat(int sockfd,Linkedlist* list,Linkedlist* listic,send_user user_info,struct sockaddr_in cliaddr){
	
	Node *group_ = list->head;
	Node *send_ = listic->head;

	struct sockaddr_in send_msg;
	char group[20];
	char buff[128];
	char account[20];
	bzero(buff,128);
	bzero(group,20);

	//遍历查看组名
	while(group_ != NULL){

		if(strncmp(group_->account,user_info.my_account,strlen(user_info.send_account)) == 0){
			strncpy(group,group_->group,strlen(group_->group));
			break;
		}
		group_ = group_->next;
	}

	group_ = list->head;

	while(group_ != NULL){
	
		bzero(account,20);
		if(strncmp(group_->group,group,strlen(group)) == 0){
			strncpy(account,group_->account,strlen(group_->account));
			send_ = listic->head;
			while( send_!= NULL ){

				memset(&send_msg,0,sizeof(send_msg));
				if(strncmp(account,send_->account,strlen(send_->account)) == 0){
					
					if(strncmp(user_info.my_account,send_->account,strlen(send_->account)) == 0){
						send_ = send_->next;
						continue;
					}

					send_msg.sin_family = AF_INET;
					send_msg.sin_port = send_->sin_port;
					send_msg.sin_addr.s_addr = send_->s_addr;	
					printf("群消息-------\n");
					printf("发送人：%s",user_info.my_account);
					printf("接收人：%s\n",send_->account);
			
					strncpy(user_info.my_code,"group",5);
					sendto(sockfd,(char *)&user_info,sizeof(user_info),0,(struct sockaddr*)&send_msg,sizeof(send_msg));

					break;
				}
				send_ = send_->next;
			}
		}
		group_ = group_ ->next;
	}

	return;
}
