#include"../include/multiple.h"

int main(){
	
	int sockfd = -1;
	struct sockaddr_in sockaddr;
	char myaccount[20] = {};//记录当前客户端成功登陆账户

	//指定连接的服务器的IP地址和端口
	memset(&sockaddr,0,sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(PORT);
	sockaddr.sin_addr.s_addr = inet_addr(IPADDR);

	if((sockfd = socket(AF_INET,SOCK_DGRAM,0)) < 0)
		puts_error("Socket");

	//初始化存档链表
	//读取存档
	//客户端主程序
	print_start();
	cli_main(sockfd,sockaddr,myaccount);
	
	return 0;
}
