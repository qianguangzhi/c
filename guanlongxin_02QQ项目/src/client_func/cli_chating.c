#include"../../include/multiple.h"

void* recv_(void* arg){

	pthread_recv pstu;
	pstu = *(pthread_recv*)arg;
	cli_recv(pstu.sockfd,pstu.sockaddr);
	return NULL;
}

void cli_chating(int sockfd,struct sockaddr_in sockaddr,char myaccount[]){
		
	char getbuff;
	int num;
	pthread_t tid;
	pthread_recv arg;

	arg.sockfd = sockfd;
	arg.sockaddr = sockaddr;
	pthread_create(&tid,NULL,(void*)recv_,(void*)&arg);

	while(1){
		
		print_cli_chat();
		scanf("%d",&num);
		while((getbuff = getchar()) != '\n' && getchar() != EOF);
		
		switch(num){
		
			case 1:
				cli_chat(sockfd,sockaddr,myaccount);
				break;
				
			case 2:
				cli_group_chat(sockfd,sockaddr,myaccount);
				break;

			case 3:	
				pthread_cancel(tid);
				return;
			
			default:
				printf("输入错误\n");
				break;			
		}				
	}
	return;
}
