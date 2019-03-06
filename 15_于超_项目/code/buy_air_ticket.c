#include"air.h"

bool buy_air_ticket(air_pcrft s)
{

	air_pcrft t;
	int a1,a2,a3,n,g;
	int j=0,w=0;
	char ch[20];
//	char a[5][2];

 if(aircrft_empty(s))
      {
          printf("\n");
          printf("还没有录入信息\n");
          printf("\n");
          return false;
      }
 else
	{

	printf("请输入你要购买的班期:\n");
	scanf("%d%d%d",&a1,&a2,&a3);
	getchar();
	for(t=s->next; t!=s; t=t->next)
	{
	if((a1==t->time.year)&&(a2==t->time.month)&&(a3==t->time.day))
	{
	w++;
	printf("你要购买这趟航班吗？\n");
	printf("%s  %s  %s  %d-%d-%d  %s  %s  %d\n",t->number,t->staddress,t->arraddress,t->time.year,t->time.month,t->time.day,t->stime,t->atime,t->value);
	
	printf("1 购买 2 否\n");
	scanf("%d",&n);
	getchar();
	if(n==1)
		{
		printf("  请选择座位\n");
		printf("**************\n");
		printf("窗 1A 过 1B 窗\n");
		printf("窗 2A 道 2B 窗\n");
		printf("**************\n");

		printf("请选择\n");
		scanf("%s",ch);
		getchar();
//		for(i=0;i<10;i++)
//		if(strcmp(ch,a[i][2])==0)
//			printf("这个座位被买了\n");
		printf("请选择付款方式\n");
		printf("1 扫码支付 2 现金支付\n");
		printf("*********\n");
		printf("*** *** *\n");
		printf("* * ** **\n");
		printf("*** ** **\n");
		printf("*********\n");
		scanf("%d",&g);
	
		if((strcmp(ch,"1A")==0)||(strcmp(ch,"1B")==0)||(strcmp(ch,"2A")==0)||(strcmp(ch,"2B")==0))
		{
//			strcpy(a[q++][2],ch);
			j++;
		if((g==1)||(g==2))	
			{
			sleep(1);
			printf("\033[0;32;31m""***\n""\033[m");
			sleep(1);
			printf("\033[0;32;32m""***\n""\033[m");
			sleep(1);
			printf("\033[1;32m""***\n""\033[m");
			printf("购票成功\n");
			}
		else
			{
			sleep(1);
			printf("\033[0;32;31m""***\n""\033[m");
			sleep(1);
			printf("\033[0;32;32m""***\n""\033[m");
			sleep(1);
			printf("\033[1;32m""***\n""\033[m");
			printf("付款失败\n");
			}
		}

		if(j==0)
		printf("没有这个座位\n");
		}
	if(n==2)
		{
           printf("跳转下一个(如果没有下一个直接跳出)\n");
        }
	}
	
	if(w==0)
		printf("没有这趟航班 \n");
	}
	}
	return true;
}
