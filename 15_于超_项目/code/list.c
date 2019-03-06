#include"air.h"

void aircrft_list(air_pcrft s)
{
	air_pcrft new;
	char ch;
	//给新节点申请空间
	new = (air_pcrft)malloc(sizeof(air_crft));
	if(NULL == new)
	{
		perror("malloc failed");
		exit(1);
	}
	//输入数据
	printf("航班号 起点站 终点站 班期 起飞时间 到达时间 票价\n");
	scanf("%s%s%s%d%d%d%s%s%d",new->number,new->staddress,new->arraddress,&new->time.year,&new->time.month,&new->time.day,new->stime,new->atime,&new->value);
	getchar();
	//将新节点插入链表中
	aircrft_insert(s,new);
	
	printf("是否继续录入信息\n");
	printf("y继续/任意键退出\n");
	scanf("%c",&ch);
	if(ch=='y')
		aircrft_list(s);
	
//	aircrft_show(s);
}
