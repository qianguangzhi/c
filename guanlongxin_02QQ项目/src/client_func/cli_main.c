#include"../../include/multiple.h"

void cli_main(int sockfd,struct sockaddr_in sockaddr,char myaccount[]){
	
	int num;
	char getbuff;

	while(1){
		
		print_loading();
		scanf("%d",&num);
		while((getbuff = getchar()) != '\n' && getchar() != EOF);

		switch(num){

			//1.注册
			case 1:
				cli_register(sockfd,sockaddr);
				break;

			//2.登陆
			case 2:
				cli_login(sockfd,sockaddr,myaccount);
				break;

			//3.退出客户端
			case 3:
		//		cli_quit(sockfd,sockaddr,myaccount);
				return;

			default:
				printf("输入错误!\n");
				sleep(1);
				break;
		}
	}
	return;
}
