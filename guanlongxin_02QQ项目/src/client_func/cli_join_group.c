
#include"../../include/multiple.h"

void cli_join_group(int sockfd,struct sockaddr_in sockaddr,char myaccount[]){

	
	socklen_t sockaddrlen = sizeof(sockaddr);
	send_user user_info;
	user_info.command = SHOW_GROUP;

	Node recv_;
	char join[20];
	char result[20];
	int sum;

	system("clear");
	sendto(sockfd,(char *)&user_info,sizeof(user_info),0,(struct sockaddr*)&(sockaddr),sockaddrlen);
	printf(BLUE"====================================\n");
	sum = 0;

	while(1){

		sum++;
		bzero(&recv_,sizeof(recv_));	
		recvfrom(sockfd,(char *)&recv_,sizeof(recv_),0,(struct sockaddr*)&(sockaddr),&sockaddrlen);
		if(strncmp(recv_.code,"nogroup",7) == 0){
			printf("暂无群信息，请尝试创建\n");
			sleep(2);
			return;
		}
		printf(YELLOW " Group%d "GREEN" \t%s\t\n",sum,recv_.group);
		if(strncmp(recv_.code,"none",4) == 0)
			break;	
	}

	printf(BLUE"====================================\n");
	printf(GREEN"请输入要加入的群帐号,退出输入0\n"RED);

	bzero(join,20);	
	bzero(result,20);
	fgets(join,20,stdin);
	
	if(strcmp(join,"0") == 0)//放弃加入
		return;

	bzero(&user_info,sizeof(user_info));
	user_info.command = JOIN_GROUP;//发送加群请求
	strncpy(user_info.my_account,myaccount,strlen(myaccount));
	strncpy(user_info.send_account,join,strlen(join));

	sendto(sockfd,(char *)&user_info,sizeof(user_info),0,(struct sockaddr*)&(sockaddr),sockaddrlen);
		
	recvfrom(sockfd,result,sizeof(result),0,(struct sockaddr*)&(sockaddr),&sockaddrlen);
	
	printf("recv_result = %s\n",result);
	if(strncmp(result,"success",7) == 0)
		printf(GREEN"加入成功\n");

	else if(strncmp(result,"not",3) == 0)
		printf(GREEN"没有这个群\n");

	else if(strncmp(result,"exit",4) == 0)
		printf(GREEN"你已在一个群中\n");

	sleep(1);
	return;
}
