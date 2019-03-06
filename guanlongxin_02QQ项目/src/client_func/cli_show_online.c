#include"../../include/multiple.h"

void cli_show_online(int sockfd,struct sockaddr_in sockaddr){

	
	socklen_t sockaddrlen = sizeof(sockaddr);
	send_user user_info;
	user_info.command = SHOW_ONLINE;
	Node recv_;

	system("clear");
	sendto(sockfd,(char *)&user_info,sizeof(user_info),0,(struct sockaddr*)&(sockaddr),sockaddrlen);

	printf(BLUE"====================================\n");

	while(1){

		bzero(&recv_,sizeof(recv_));	
		recvfrom(sockfd,(char *)&recv_,sizeof(recv_),0,(struct sockaddr*)&(sockaddr),&sockaddrlen);
		printf(YELLOW "    | >__< | "GREEN" \t%s",recv_.account);

		if(strncmp(recv_.code,"none",4) == 0)
			break;
	}
	printf(BLUE"====================================\n");
	printf(GREEN"请按回车继续\n"WHITE);
	getchar();
	return;
}
