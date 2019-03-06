#include"../../include/multiple.h"

void cli_register(int sockfd,struct sockaddr_in sockaddr){
		
	struct user user_info;

	char buff[128];
	char check[20];

	socklen_t sockaddrlen = sizeof(sockaddr);
	
	while(1){
			
		user_info.command = REGISTER;
//		system("clear");
//		printf("请输入帐号:\t");
		print_register1();
		fgets(user_info.my_account,16,stdin);
//		print_register2();
//		printf("请输入密码:\t");		
//		fgets(user_info.my_code,16,stdin);
		strcpy(user_info.my_code,getpass(YELLOW"                    请输入密码："RED"*********"));
		
		strcpy(check,getpass(YELLOW"                    请再次输入："RED"*********"));
		if(strcmp(check,user_info.my_code) != 0){
			print_confirm5();
			return;
		}
		
		if(strlen(check) < 6){
			print_confirm7();
			return;
		}

		sendto(sockfd,(char*)&user_info,sizeof(user_info),0,(struct sockaddr*)&sockaddr,sockaddrlen);		
		recvfrom(sockfd,buff,128,0,(struct sockaddr*)&sockaddr,&sockaddrlen);	

		if(strncmp(buff,"注册失败，帐号已存在",30) == 0){
			print_confirm6();
			usleep(25000);
			return;	
		}	
		if(strncmp(buff,"注册失败，系统无法分配内存",39) == 0){
			printf("注册失败，系统无法分配内存\n");
			usleep(25000);
			continue;	
		}
		if(strncmp(buff,"注册成功",12) == 0){
			print_register3();
			usleep(25000);
			break;	
		}
	}
	return;
}
