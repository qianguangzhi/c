#include"../include/multiple.h"

void ser_main(int socked,Linkedlist *list,Linkedlist *listic){
	
	int num;
	char getbuff;

	while(1){
				
		print_ser_main();
//		printf("1运行\t2维护\t3退出\n");
//		print_server_menu();
		printf("请输入编号:\t");
		printf("\n");
		scanf("%d",&num);
		while((getbuff = getchar()) != '\n' && getchar() != EOF);

		switch(num){

			//1.运行
			case 1:
				ser_running(socked,list,listic);
				break;

			//2.维护
			case 2:
//				ser_operation();
				break;
			
			//3.关闭服务器
			case 3:
//				ser_close();
				return;

			default:
				printf("输入错误\n");
				sleep(1);
				break;
		}
	}
	return;
}
