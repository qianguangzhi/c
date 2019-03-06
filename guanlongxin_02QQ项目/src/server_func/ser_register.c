#include"../../include/multiple.h"

void ser_register(int sockfd,Linkedlist *list,send_user user_info,struct sockaddr_in cliaddr){

	Node *check_account;
	check_account = list->head;	

	struct sockaddr_in cli_addr;
	cli_addr = cliaddr;
	char buff[128];
	
	while(check_account != NULL){
		if(strcmp(check_account->account,user_info.my_account) == 0){
			printf("注册失败，帐号已存在...\n\n");
			bzero(buff,128);
			strcpy(buff,"注册失败，帐号已存在...\n");
			sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,sizeof(cliaddr));
			return;
		}
		check_account = check_account->next;
	}
	
	Node* new_account = malloc(sizeof(Node));

	if(NULL == new_account){
		printf("注册失败，系统无法分配内存\n\n`");
		bzero(buff,128);
		strcpy(buff,"注册失败，系统无法分配内存\n");
		sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,sizeof(cliaddr));
		return;
	}
	
	bzero(new_account,sizeof(Node));//*****************************************8
	strcpy(new_account->account,user_info.my_account);
	strcpy(new_account->code,user_info.my_code);
	strcpy(new_account->group,"0");
	
	Add_Node_After_Tail(list,new_account);
	ser_save(list);

	bzero(buff,128);
	printf("注册帐号：成功\n\n");
	strcpy(buff,"注册成功\n");
	sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,sizeof(cliaddr));

	return;
}
