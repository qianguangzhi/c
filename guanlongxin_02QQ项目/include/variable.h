#ifndef __VARIABLE_H__
#define __VARIABLE_H__

/*
//宏定义服务器IP
#define IPADDR "192.168.7.114"
#define C_IPADDR "192.168.7.54"
#define PORT 9999
#define BACKLOG 5

//宏定义命令
#define REGISTER 1 //注册 
#define LOADING  2 //登陆
#define CHANGE   3 //修改密码
#define SINGLE   4 //私聊
#define GROUP    5 //群聊

//定义用户发送数据包结构体
typedef struct user{
	
	char my_account[20];//帐号
	char my_code[20];   //密码
		
	char send_account[20]; //发送对象
	char msg[20];     //信息内容
	int command;      //操作指令
	
}send_user; 


typedef struct link{
	
	char account[20];
	char code[20];
	struct link prev;
	struct link next;

}Node;

typedef struct{

	Node* head;
	Node* tail;

}Linkedlist;


//定义服务器接收数据包
//typedef struct ser{
	
				//IP
				//端口号
				//
//	send_user user_info;

//};

//定义服务器存储用户信息结构题

//定义在线用户结构体

*/
#endif
