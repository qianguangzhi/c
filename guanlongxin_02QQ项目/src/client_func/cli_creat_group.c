#include"../../include/multiple.h"


void cli_creat_group(int sockfd,struct sockaddr_in sockaddr,char myaccount[]){
	
	send_user user_info;
	bzero(&user_info,sizeof(user_info));
	socklen_t sockaddrlen = sizeof(sockaddr);
	
	user_info.command = CREAT_GROUP;
	strncpy(user_info.my_account,myaccount,strlen(myaccount));

	char group_account[20];
	char buff[20];
	char code[5];

	bzero(buff,20);
	bzero(group_account,20);
	bzero(code,5);

	printf("请输入群帐号:");
	fgets(group_account,20,stdin);
	strcpy(user_info.send_account,group_account);	

	sendto(sockfd,(char*)&user_info,sizeof(user_info),0,(struct sockaddr*)&sockaddr,sockaddrlen);
	recvfrom(sockfd,buff,sizeof(buff),0,(struct sockaddr*)&sockaddr,&sockaddrlen);
	
	printf("buff = %s\n",buff);
	
	if(strncmp(buff,"success",7) == 0){
		printf("创建群成功\n");
		sleep(1);
	}
		
	if(strncmp(buff,"failed",6) == 0){
		printf("创建失败，您已在一个群中\n");
		sleep(1);
	}
	
	if(strncmp(buff,"exist",5) == 0){
		printf("创建失败，群已存在\n");
		sleep(1);
	}

	sleep(1);

	return;
}
