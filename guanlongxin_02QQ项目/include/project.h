#ifndef __PROJECT_H__
#define __PROJECT_H__


//定义颜色*****************
#define RED "\033[0;32;31m"
#define BLUE "\033[0;32;34m"
#define GREEN "\033[0;31;32m"
#define YELLOW "\033[0;32;33m"
#define WHITE "\033[0;32;37m"

//宏定义服务器IP************
#define IPADDR "192.168.7.114"
#define BROADCAST "255.255.255.255"
#define PORT 9999
//#define IPADDR "192.168.7.88"


//宏定义操作命令*************

#define REGISTER	1 //注册 
#define LOADING		2 //登陆
#define CHANGE		3 //修改密码
#define SINGLE		4 //私聊
#define GROUP		5 //群聊
#define SHOW_ONLINE	6 //查看全部在线账户
#define CREAT_GROUP	7 //创建群
#define SHOW_GROUP	8 //查看群
#define JOIN_GROUP	9 //加入群
#define QUIT_GROUP	10//退出群
#define QUIT        11//客户端退出

//数据存储结构体**************
typedef struct link{
	
	char account[20];
	char code[20];
	char group[20];
	in_port_t sin_port;      //端口号
	uint32_t s_addr;         //IP
	struct link *prev;
	struct link *next;

}Node;

//链表头尾指针****************
typedef struct{

	Node* head;
	Node* tail;

}Linkedlist;

//传输数据结构体***************
typedef struct user{
	
	char my_account[20];    //帐号
	char my_code[20];       //密码
	char send_account[20];  //发送对象
	char msg[128];          //信息内容
	int command;            //操作指令
	
}send_user; 

//客户端线程结构体**************
typedef struct recv_pthread{	

	int sockfd;
	struct sockaddr_in sockaddr;

}pthread_recv;

//服务器子线程数据包*****************
typedef struct pthreadser{

	int sockfd;
	Linkedlist* list;
	Linkedlist* listic;

}pthread_ser;



//客户端子线程数据包******************
typedef struct pthread{
	
	int fd;
	int sockfd;
	Linkedlist* list;
	Linkedlist* listic;
	send_user user_info;
	struct sockaddr_in cliaddr;

}pthread_data;

//系统提示*************************************************
void puts_error(char *pstu);

//客户端*************************************************
void cli_main(int sockfd,struct sockaddr_in sockaddr,char myaccount[]);
void cli_register(int sockfd,struct sockaddr_in sockaddr);
void cli_login(int sockfd,struct sockaddr_in sockaddr,char myaccount[]);
void cli_quit();
void cli_chat(int sockfd,struct sockaddr_in sockaddr,char myaccount[]);
int cli_confirm_account(int sockfd,struct sockaddr_in sockaddr,char myaccount[]);
void cli_recv(int sockfd,struct sockaddr_in sockaddr);
void cli_show_online(int sockfd,struct sockaddr_in sockaddr);
void cli_creat_group(int sockfd,struct sockaddr_in sockaddr,char myaccount[]);
void cli_group_chat(int sockfd,struct sockaddr_in sockaddr,char myaccount[]);
void cli_chating(int sockfd,struct sockaddr_in sockaddr,char myaccount[]);
void cli_join_group(int sockfd,struct sockaddr_in sockaddr,char myaccount[]);
void cli_quit_group(int sockfd,struct sockaddr_in sockaddr,char myaccount[]);
void cli_quit(int sockfd,struct sockaddr_in sockaddr,char myaccount[]);


//服务器************************************************
void ser_main(int sockfd,Linkedlist *list,Linkedlist* listic);
void ser_running(int sockfd,Linkedlist *list,Linkedlist *listic);
void ser_operation();
void ser_close();
void ser_register(int sockfd,Linkedlist *list,send_user user_info,struct sockaddr_in cliaddr);
void ser_loading(int sockfd,Linkedlist *list,Linkedlist* listic,send_user user_info,struct sockaddr_in cliaddr);
void ser_single_chat(int sockfd,Linkedlist *listic,send_user user_info,struct sockaddr_in cliaddr);
void ser_show_online(int sockfd,Linkedlist* listic,struct sockaddr_in cliaddr);
int ser_confirm_account(int sockfd,Linkedlist *list,Linkedlist *listic,send_user user_info,struct sockaddr_in cliaddr);
void ser_creat_group(int sockfd,Linkedlist *list,send_user user_info,struct sockaddr_in cliaddr);
void ser_group_chat(int sockfd,Linkedlist *list,Linkedlist* listic,send_user user_info,struct sockaddr_in cliaddr);
void ser_join_group(int sockfd,Linkedlist *list,send_user user_info,struct sockaddr_in cliaddr);
void ser_show_group(int sockfd,Linkedlist *list,struct sockaddr_in cliaddr);
void ser_quit_group(int sockfd,Linkedlist *list,send_user user_info,struct sockaddr_in cliaddr);
void ser_quit_cli(int sockfd,Linkedlist *listic,send_user user_info);
void ser_save(Linkedlist* listichain);
void ser_init(Linkedlist* listichain);

//链表***************************************************
Linkedlist* Create_Linkedlist();
void Add_Node_After_Tail(Linkedlist *list,Node *node);
void Delete_Node(Linkedlist* list,char myaccount[]);

//打印图形***********************************************
void print_start();
void print_loading();
void print_register1();
void print_register2();
void print_register3();
void print_confirm1();
void print_confirm2();
void print_confirm3();
void print_confirm4();
void print_confirm5();
void print_confirm6();
void print_confirm7();
void print_cli_chat();
void print_cli_chating();
void print_ser_start();
void print_ser_main();

#endif

