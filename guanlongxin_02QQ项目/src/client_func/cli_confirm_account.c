#include"../../include/multiple.h"

int cli_confirm_account(int sockfd,struct sockaddr_in sockaddr,char myaccount[]){

	send_user user_info;
	char buff[128];

	char str1[] = "帐号不存在";
	char str2[] = "密码错误";
	char str3[] = "登陆成功";
	char str4[] = "帐号已在其他终端登陆";
	
	socklen_t sockaddrlen = sizeof(sockaddr);

	while(1){	
		
		bzero(&user_info,sizeof(user_info));
		user_info.command = LOADING;

//		system("clear");
//		printf("请输入帐号\n");
		print_register1();
		fgets(user_info.my_account,16,stdin);
	//	print_register2();
//		printf("请输入密码\n");
//		fgets(user_info.my_code,16,stdin);
	//	char code[20];
		strcpy(user_info.my_code,getpass(YELLOW"                    请输入密码："RED"*********"));
		
		sendto(sockfd,(char*)&user_info,sizeof(user_info),0,(struct sockaddr*)&sockaddr,sockaddrlen);		
		recvfrom(sockfd,buff,128,0,(struct sockaddr*)&sockaddr,&sockaddrlen);	

		if(strncmp(buff,str1,15) == 0){
			print_confirm1();
//			printf("%s\n",str1);
			return 0;	
		}		
		if(strncmp(buff,str2,12) == 0){
//			printf("%s\n",str2);
			print_confirm2();
			return 0;	
		}
		if(strncmp(buff,str3,12) == 0){
//			printf("%s\n",str3);
			print_confirm4();
			strcpy(myaccount,user_info.my_account);
			break;
		}	

		if(strncmp(buff,str4,30) == 0){
			print_confirm3();
			return 0;
		}	
		sleep(1);
	}
	return 1;
}

