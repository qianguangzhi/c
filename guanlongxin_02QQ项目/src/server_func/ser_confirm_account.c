#include"../../include/multiple.h"

int ser_confirm_account(int sockfd,Linkedlist* list,Linkedlist* listic,send_user user_info,struct sockaddr_in cliaddr){
	
	Node *check_info = list->head;
	Node *check = listic->head;
	int flag_success = 0;
	int flag_error = 0;

	char buff[128];
	bzero(buff,128);
	struct sockaddr_in cli_addr;
	struct sockaddr_in cli__addr;
	send_user send_msg;
	bzero(&send_msg,sizeof(send_msg));
	cli_addr = cliaddr;

	char str1[] = "帐号不存在";
	char str2[] = "密码错误";
	char str3[] = "登陆成功";
	char str4[] = "帐号已在其他终端登陆";
	
	while(check != NULL){
		if(strcmp(check->account,user_info.my_account) == 0){
			printf("重复登陆：登陆请求已拒绝\n");
			strcpy(buff,str4);
			sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,sizeof(cli_addr));
			return 0;
		}
		check = check->next;
	}

	while(check_info != NULL){

		if(strcmp(user_info.my_account,check_info->account) == 0 && \
													strcmp(user_info.my_code,check_info->code) == 0){
			strcpy(buff,str3);
			sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,sizeof(cli_addr));
			printf("账号 %s",user_info.my_account);
			printf("登陆成功...\n");

			Node* pstr = listic->head;
			strcpy(send_msg.my_account,user_info.my_account);	
			strcpy(send_msg.msg,"已上线\n");
			strcpy(send_msg.my_code,"system");
			
			while(pstr != NULL){
	
				memset(&cli__addr,0,sizeof(cli__addr));
				cli__addr.sin_family = AF_INET;//Ipv4协议族
				cli__addr.sin_port = pstr->sin_port;
				cli__addr.sin_addr.s_addr = pstr->s_addr;
				sendto(sockfd,(char *)&send_msg,sizeof(send_msg),0,(struct sockaddr*)&cli__addr,sizeof(cli__addr));		
		
			pstr = pstr->next;
			}
			flag_success++;
			break;
		}

		if(strcmp(user_info.my_account,check_info->account) == 0 && \
													strcmp(user_info.my_code,check_info->code) != 0){
			strcpy(buff,str2);
			sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,sizeof(cli_addr));
			printf("账号 %s",user_info.my_account);
			printf("登陆失败：无效的密码...\n");
			flag_error++;
			break;
		}
		check_info = check_info->next;
	}

	if(flag_success == 0 && flag_error == 0){
		
		strcpy(buff,str1);
		sendto(sockfd,buff,strlen(buff),0,(struct sockaddr*)&cli_addr,sizeof(cli_addr));
		printf("账号 %s",user_info.my_account);
		printf("登陆失败：尚未注册的帐号\n");
		return 0;
	}
	else if(flag_error != 0)
		return 0;
	
	return 1;
}

