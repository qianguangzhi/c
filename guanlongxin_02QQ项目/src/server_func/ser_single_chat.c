#include"../../include/multiple.h"

void ser_single_chat(int sockfd,Linkedlist *listic,send_user user_info,struct sockaddr_in cliaddr){
	
	Node *single = listic->head;
	
	struct sockaddr_in send_msg;
	memset(&send_msg,0,sizeof(send_msg));

	while( single!= NULL ){

		if(strncmp(single->account,user_info.send_account,strlen(user_info.send_account)) == 0){

			send_msg.sin_family = AF_INET;
			send_msg.sin_port = single->sin_port;
			send_msg.sin_addr.s_addr = single->s_addr;	
			sendto(sockfd,(char *)&user_info,sizeof(user_info),0,(struct sockaddr*)&send_msg,sizeof(send_msg));
			break;
		}

		printf("在线 %s\n",single->account);
		single = single->next;
	}

	return;
}
