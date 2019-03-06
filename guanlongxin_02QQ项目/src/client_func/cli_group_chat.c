#include"../../include/multiple.h"

void cli_group_chat(int sockfd,struct sockaddr_in sockaddr,char myaccount[]){
	
	
	send_user user_info;
	char buff[128];
	char check[128];
//	socklen_t sockaddrlen = sizeof(sockaddr);
	
	bzero(check,128);

	bzero(&user_info,sizeof(user_info));
	user_info.command = GROUP;
	strncpy(user_info.my_account,myaccount,strlen(myaccount));

	
//	sendto(sockfd,(char*)&user_info,sizeof(user_info),0,(struct sockaddr*)&sockaddr,sizeof(sockaddr));
//	recvfrom(sockfd,check,sizeof(check),0,(struct sockaddr*)&sockaddr,&sockaddrlen);

	if(strncmp(check,"failed",6) == 0){
		printf("尚未添加群，请创建或添加群后再试！\n");
		return;
	}

	while(1){
				
		bzero(buff,128);
		bzero(&user_info,sizeof(user_info));
		user_info.command = GROUP;
		strncpy(user_info.my_account,myaccount,strlen(myaccount));
		printf("Me:");
		fgets(buff,127,stdin);
		strcpy(user_info.msg,buff);
		sendto(sockfd,(char*)&user_info,sizeof(user_info),0,(struct sockaddr*)&sockaddr,sizeof(sockaddr));
		if(!strncmp(buff,"byebye",6))
			break;	
	}
	return;
}
