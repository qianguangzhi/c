#include"../../include/multiple.h"


void ser_loading(int sockfd,Linkedlist *list,Linkedlist* listic,send_user user_info,struct sockaddr_in cliaddr){

	int ret;
	ret = ser_confirm_account(sockfd,list,listic,user_info,cliaddr);
	
	if(ret == 0)
		return;

	Node* new_load = malloc(sizeof(Node));

	if(NULL == new_load)
		printf("Server loading malloc failed");
	
	strcpy(new_load->account,user_info.my_account);
	new_load->sin_port = cliaddr.sin_port;
	new_load->s_addr = cliaddr.sin_addr.s_addr;
	Add_Node_After_Tail(listic,new_load);
	
	return;
}
