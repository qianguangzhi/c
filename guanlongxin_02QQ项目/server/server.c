#include"../include/multiple.h"

int main(){

	int sockfd = -1;
	Linkedlist *list;
	Linkedlist *listic;
	
	list = Create_Linkedlist();
	listic = Create_Linkedlist();
	
	//初始化数据
	ser_init(list);
	print_ser_start();
	

	struct sockaddr_in seraddr;
	memset(&seraddr,0,sizeof(seraddr));

	//查看此结构体 man 7 ip
	seraddr.sin_family = AF_INET;//Ipv4协议族
	seraddr.sin_port = htons(PORT);//指定服务端接收端口：网络字节序
	seraddr.sin_addr.s_addr = inet_addr(IPADDR);//指定本地IP
	
	//建立流式套接字
	if((sockfd = socket(AF_INET,SOCK_DGRAM,0)) < 0)
		puts_error("Server socket");
	
	//绑定本地IP以及端口
	if(bind(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr)) < 0)
		puts_error("Server bind");
	
	//初始化存档链表
	//读取存档
	//服务器主程序
	ser_main(sockfd,list,listic);

	return 0;
}
