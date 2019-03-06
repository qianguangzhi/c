#include"../../include/multiple.h"


void cli_recv(int sockfd,struct sockaddr_in sockaddr){

	send_user recv_msg;
	time_t tm;
	socklen_t sockaddrlen = sizeof(sockaddr);

	while(1){
		
		bzero(&recv_msg,sizeof(recv_msg));
		recvfrom(sockfd,(char*)&recv_msg,sizeof(recv_msg),0,(struct sockaddr*)&sockaddr,&sockaddrlen);
		
		if(strcmp(recv_msg.my_code,"left") == 0 || strcmp(recv_msg.my_code,"none") == 0){
			sleep(2);
			continue;
		}

		time(&tm);
		system("clear");
		if(strncmp(recv_msg.my_code,"group",5) == 0)
			printf("新群消息！！！\n");
		else if(strncmp(recv_msg.my_code,"system",6) == 0)
			printf("系统通知！！！\n");
		else
			printf("新私人消息！！！\n");
		printf(BLUE"=========================================\n");
		printf(YELLOW"%s",ctime(&tm));
		printf(GREEN"%s",recv_msg.my_account);
		printf(BLUE"-----------------------------------------\n");
		printf(GREEN"%s",recv_msg.msg);
		printf(BLUE"=========================================\n");
		printf("退出请输入0 + ENTER");
		fflush(stdout);

	}
	return;
}
