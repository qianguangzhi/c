#include"../../include/multiple.h"

void ser_quit_cli(int sockfd,Linkedlist *listic,send_user user_info){

	Delete_Node(listic,user_info.my_account);
	
	send_user send_msg;	
	bzero(&send_msg,sizeof(send_msg));
	struct sockaddr_in cliaddr;
	
	
	Node* pstr = listic->head;

	strcpy(send_msg.my_account,user_info.my_account);	
	strcpy(send_msg.msg,"已下线\n");
	strcpy(send_msg.my_code,"system");
	
			
	while(pstr != NULL){
	
		memset(&cliaddr,0,sizeof(cliaddr));
		cliaddr.sin_family = AF_INET;//Ipv4协议族
		cliaddr.sin_port = pstr->sin_port;
		cliaddr.sin_addr.s_addr = pstr->s_addr;
		sendto(sockfd,(char *)&send_msg,sizeof(send_msg),0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));		
		
		pstr = pstr->next;
	}

	return;
}

