#include"../../include/multiple.h"

void cli_login(int sockfd,struct sockaddr_in sockaddr,char myaccount[]){
		
	if(cli_confirm_account(sockfd,sockaddr,myaccount) == 0)
		return;

	char getbuff;
	int num;

	while(1){
		
		print_cli_chating();
		scanf("%d",&num);
		while((getbuff = getchar()) != '\n' && getchar() != EOF);
		
		switch(num){
		
			case 1:
				cli_chating(sockfd,sockaddr,myaccount);
				break;
				
			case 2:
				cli_creat_group(sockfd,sockaddr,myaccount);
				break;

			case 3:
				cli_quit_group(sockfd,sockaddr,myaccount);
				break;
			
			case 4:
				cli_show_online(sockfd,sockaddr);
				break;

			case 5:	
				cli_join_group(sockfd,sockaddr,myaccount);
				break;

			case 6:
				cli_quit(sockfd,sockaddr,myaccount);
				return;
			
			default:
				break;			
		}				
	}
	return;
}
