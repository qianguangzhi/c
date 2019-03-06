#include"../../include/multiple.h"

void cli_quit(int sockfd,struct sockaddr_in sockaddr,char myaccount[]){
	

	send_user user_info;
	bzero(&user_info,sizeof(user_info));
	user_info.command = QUIT;
	strcpy(user_info.my_account,myaccount);
	sendto(sockfd,(char*)&user_info,sizeof(user_info),0,(struct sockaddr*)&sockaddr,sizeof(sockaddr));

	return;
}

