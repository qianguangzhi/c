#include"../../include/multiple.h"

void cli_chat(int sockfd,struct sockaddr_in sockaddr,char myaccount[]){
	
	send_user user_info;
	char buff[128];
	char account[20];
//	cli_show_online(sockfd,sockaddr);
	
	bzero(&user_info,sizeof(user_info));
	bzero(account,20);
	printf(GREEN"————————————————————————————————————\n");
	printf(GREEN"请输入对方帐号："RED);
	fgets(account,20,stdin);


	while(1){

	
		bzero(&user_info,sizeof(user_info));
		user_info.command = SINGLE;//单聊指令
		bzero(buff,128);
		strcpy(user_info.my_account,myaccount);
		strcpy(user_info.send_account,account);
		printf("Me:");
		
		fgets(buff,127,stdin);
		strcpy(user_info.msg,buff);
		sendto(sockfd,(char*)&user_info,sizeof(user_info),0,(struct sockaddr*)&sockaddr,sizeof(sockaddr));
		if(!strncmp(buff,"byebye",6))
			break;	
	}
	return;
}
