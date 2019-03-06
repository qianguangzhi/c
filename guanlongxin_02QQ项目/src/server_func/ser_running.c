#include"../../include/multiple.h"

void *ser_pthread(void *arg){
	
	pthread_data pstu;
	pstu = *(pthread_data *)arg;
	pthread_detach(pthread_self());

	switch(pstu.user_info.command){
						
		case REGISTER:
			ser_register(pstu.sockfd,pstu.list,pstu.user_info,pstu.cliaddr);
			break;

		case LOADING:
			ser_loading(pstu.sockfd,pstu.list,pstu.listic,pstu.user_info,pstu.cliaddr);
			break;

		case SINGLE:
			ser_single_chat(pstu.sockfd,pstu.listic,pstu.user_info,pstu.cliaddr);
			break;

		case CREAT_GROUP:

			ser_creat_group(pstu.sockfd,pstu.list,pstu.user_info,pstu.cliaddr);
			break;
			
		case GROUP:
			ser_group_chat(pstu.sockfd,pstu.list,pstu.listic,pstu.user_info,pstu.cliaddr);
			break;

		case CHANGE:

	//		ser_change();//
			break;

		case SHOW_ONLINE:
			ser_show_online(pstu.sockfd,pstu.listic,pstu.cliaddr);
			break;

		case SHOW_GROUP:
			ser_show_group(pstu.sockfd,pstu.list,pstu.cliaddr);
			break;

		case JOIN_GROUP:
			ser_join_group(pstu.sockfd,pstu.list,pstu.user_info,pstu.cliaddr);
			break;

		case QUIT_GROUP:
			ser_quit_group(pstu.sockfd,pstu.list,pstu.user_info,pstu.cliaddr);
			break;

		case QUIT:
			ser_quit_cli(pstu.sockfd,pstu.listic,pstu.user_info);
			break;

		default:
			break;
		}

	return NULL;
}

void ser_running(int sockfd,Linkedlist *list,Linkedlist *listic){
	
	time_t tm;
	int fd;
	pthread_t tid;
	send_user user_info;//定义用户数据包结构体

	socklen_t clientlen;
	struct sockaddr_in cliaddr;

	pthread_data arg;//子线程数据包

	while(1){

		printf("Waiting for connected...\n");

		//等待连接
		memset(&cliaddr,0,sizeof(cliaddr));
		clientlen = sizeof(cliaddr);
		bzero(&user_info,sizeof(user_info));
		bzero(&arg,sizeof(arg));//子线程数据包赋值

		if((fd = recvfrom(sockfd,(char *)&user_info,sizeof(user_info),0,(struct sockaddr*)&cliaddr,&clientlen)) < 0){
			puts_error("Server accept");
			continue;
		}
	
		arg.fd = fd;
		arg.sockfd = sockfd;
		arg.list = list;
		arg.listic = listic;
		arg.user_info = user_info;
		arg.cliaddr = cliaddr;
		
		time(&tm);
		printf("\n%s",ctime(&tm));
		printf("IPaddr : %s\n",inet_ntoa(cliaddr.sin_addr));
		printf("Port   : %d\n",ntohs(cliaddr.sin_port));

		switch(user_info.command){

			case 1:
				printf("Command: REGISTER\n");
				break;
				
			case 2:
				printf("Command: LOADING\n");
				break;

			case 3:
				printf("Command: CHANGE\n");
				break;

			case 4:
				printf("Command: SINGLE\n");
				break;

			case 5:	
				printf("Command: GROUP\n");
				break;

			case 6:
				printf("Command: SHOW_ONLINE\n");
				break;
				
			case 7:
				printf("Command: CREAT_GROUP\n");
				break;
			
			case 8:
				printf("Command: SHOW_GROUP\n");
				break;

			case 9:
				printf("Command: JOIN_GROUP\n");
				break;

			case 10:
				printf("Command: QUIT_GROUP\n");
				break;

			case 11:
				printf("Command: QUIT\n");
				break;

			default:
				printf("Command: 错误指令\n");
				break;
		}


		if(pthread_create(&tid,NULL,(void *)ser_pthread,(void *)&arg) < 0)
			puts_error("Pthread");

		usleep(1000);
	}	
	return;
}

