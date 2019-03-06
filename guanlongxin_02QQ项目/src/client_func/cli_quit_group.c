#include"../../include/multiple.h"

void cli_quit_group(int sockfd,struct sockaddr_in sockaddr,char myaccount[]){

	char confirm[5];
	bzero(confirm,5);
	send_user user_info;
	bzero(&user_info,sizeof(user_info));
	socklen_t sockaddrlen = sizeof(sockaddr);
	user_info.command = QUIT_GROUP;
	strncpy(user_info.my_account,myaccount,strlen(myaccount));

	//发送退群请求
	sendto(sockfd,(char *)&user_info,sizeof(user_info),0,(struct sockaddr*)&(sockaddr),sockaddrlen);

	//接收服务器反馈
	bzero(&user_info,sizeof(user_info));
	recvfrom(sockfd,(char *)&user_info,sizeof(user_info),0,(struct sockaddr*)&(sockaddr),&sockaddrlen);
	
	if(strcmp(user_info.send_account,"0") != 0){

		printf(GREEN"您当前所在群为:%s",user_info.send_account);
		printf(BLUE"========================================\n");
		printf(GREEN"是否退出（Y/N）？\n");
		fgets(confirm,2,stdin);

		if(strncmp(confirm,"Y",1) == 0 || strncmp(confirm,"y",1) == 0){

			bzero(&user_info,sizeof(user_info));
			user_info.command = QUIT_GROUP;
			strncpy(user_info.my_code,"quit",4);
			sendto(sockfd,(char *)&user_info,sizeof(user_info),0,(struct sockaddr*)&(sockaddr),sockaddrlen);
			printf("已退出该群\n");
			sleep(1);
		}
		else{

			strncpy(user_info.my_code,"stay",4);
			bzero(&user_info,sizeof(user_info));
			user_info.command = QUIT_GROUP;
			sendto(sockfd,(char *)&user_info,sizeof(user_info),0,(struct sockaddr*)&(sockaddr),sockaddrlen);
			printf("放弃退出\n");
			sleep(1);
		}
	}
	else{

		strncpy(user_info.my_code,"stay",4);
		bzero(&user_info,sizeof(user_info));
		user_info.command = QUIT_GROUP;
		sendto(sockfd,(char *)&user_info,sizeof(user_info),0,(struct sockaddr*)&(sockaddr),sockaddrlen);
		printf("您尚未加入任何群，无需退出\n");
		sleep(1);
	}
	return;
}

