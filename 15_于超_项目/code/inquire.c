#include"air.h"

bool inquire(air_pcrft s)
{

	char n;


	if(aircrft_empty(s))
	{
		printf("\n");
		printf("还没有录入信息\n");
		printf("\n");
		return false;
	}
	else
	{

		while(1)
		{
		system("clear");
		menutwo();
		printf("请选择查找的方式：");
		
		scanf("%c",&n);
		getchar();
			switch(n)
			{
				case '1':aircrft_inquire(s);
					break;

				case '2':aircrft_inquire2(s);
					break;
			
				case '3':aircrft_inquire3(s);
					break;

				case '4':aircrft_inquire4(s);
					break;

				case '5':aircrft_inquire5(s);
					break;

				case '6':aircrft_inquire6(s);
					break;

				case '7':aircrft_inquire7(s);
					break;
	
				case '8':goto ret;

				default:printf("没有这个选项\n");

			}

		}
	}
ret:printf("已经返回主菜单\n");
	return true;
}

void aircrft_inquire(air_pcrft s)
{
	air_pcrft q;
	char ch[18];
	char c;
	int n=0;

	printf("请输入要查询的航班号\n");
	scanf("%s",ch);
		getchar();

	for(q=s->next;q!=s;q=q->next)
		if(strcmp(ch,q->number)==0)
		{
			printf("航班号 起点站 终点站 班期 起飞时间 到达时间 票价\n");
			printf("%s %s %s %d-%d-%d %s %s %d\n",q->number,q->staddress,q->arraddress,q->time.year,q->time.month,q->time.day,q->stime,q->atime,q->value);
			n++;
		}
		if(n == 0)
			printf("没有这个航班\n");


		printf("是否继续查找\n");
		printf("y继续/任意键退出\n");
		scanf("%c",&c);
		if(c == 'y')
			aircrft_inquire(s);
	
}

void aircrft_inquire2(air_pcrft s)
{
	air_pcrft q;
	char ch[18];
	char c;
	int n=0;

	printf("请输入要查询的起点站\n");
	scanf("%s",ch);
		getchar();

	for(q=s->next;q!=s;q=q->next)
		if(strcmp(ch,q->staddress)==0)
		{
			printf("航班号 起点站 终点站 班期 起飞时间 到达时间 票价\n");
			printf("%s %s %s %d-%d-%d %s %s %d\n",q->number,q->staddress,q->arraddress,q->time.year,q->time.month,q->time.day,q->stime,q->atime,q->value);
			n++;
		}
		if(n == 0)
			printf("没有这个航班\n");


		printf("是否继续查找\n");
		printf("y继续/任意键退出\n");
		scanf("%c",&c);
		if(c == 'y')
			aircrft_inquire2(s);
}

void aircrft_inquire3(air_pcrft s)
{

	air_pcrft q;
	char ch[18];
	char c;
	int n=0;

	printf("请输入要查询的终点站\n");
	scanf("%s",ch);
	getchar();

	for(q=s->next;q!=s;q=q->next)
		if(strcmp(ch,q->arraddress)==0)
		{
			printf("航班号 起点站 终点站 班期 起飞时间 到达时间 票价\n");
			printf("%s %s %s %d-%d-%d %s %s %d\n",q->number,q->staddress,q->arraddress,q->time.year,q->time.month,q->time.day,q->stime,q->atime,q->value);
			n++;
		}
		if(n == 0)
			printf("没有这个航班\n");


		printf("是否继续查找\n");
		printf("y继续/任意键退出\n");
		scanf("%c",&c);
		if(c == 'y')
			aircrft_inquire3(s);

}

void aircrft_inquire4(air_pcrft s)
{
	air_pcrft q;
	char c;
	int n=0;
	int a1,a2,a3;
	printf("请输入要查询的班期\n");
	scanf("%d%d%d",&a1,&a2,&a3);
		getchar();

	for(q=s->next;q!=s;q=q->next)
		if((q->time.year == a1)&&(q->time.month == a2)&&(q->time.day == a3))
		{
			printf("航班号 起点站 终点站 班期 起飞时间 到达时间 票价\n");
			printf("%s %s %s %d-%d-%d %s %s %d\n",q->number,q->staddress,q->arraddress,q->time.year,q->time.month,q->time.day,q->stime,q->atime,q->value);
			n++;
		}
		if(n == 0)
			printf("没有这个航班\n");


		printf("是否继续查找\n");
		printf("y继续/任意键退出\n");
		scanf("%c",&c);
		if(c == 'y')
			aircrft_inquire4(s);
	
}

void aircrft_inquire5(air_pcrft s)
{
	air_pcrft q;
	char ch[18];
	char c;
	int n=0;

	printf("请输入要查询的起飞时间\n");
	scanf("%s",ch);
		getchar();

	for(q=s->next;q!=s;q=q->next)
		if(strcmp(ch,q->stime)==0)
		{
			printf("航班号 起点站 终点站 班期 起飞时间 到达时间 票价\n");
			printf("%s %s %s %d-%d-%d %s %s %d\n",q->number,q->staddress,q->arraddress,q->time.year,q->time.month,q->time.day,q->stime,q->atime,q->value);
			n++;
		}
		if(n == 0)
			printf("没有这个航班\n");


		printf("是否继续查找\n");
		printf("y继续/任意键退出\n");
		scanf("%c",&c);
		if(c == 'y')
			aircrft_inquire5(s);
	
}

void aircrft_inquire6(air_pcrft s)
{
	air_pcrft q;
	char ch[18];
	char c;
	int n=0;

	printf("请输入要查询的到达时间\n");
	scanf("%s",ch);
		getchar();

	for(q=s->next;q!=s;q=q->next)
		if(strcmp(ch,q->atime)==0)
		{
			printf("航班号 起点站 终点站 班期 起飞时间 到达时间 票价\n");
			printf("%s %s %s %d-%d-%d %s %s %d\n",q->number,q->staddress,q->arraddress,q->time.year,q->time.month,q->time.day,q->stime,q->atime,q->value);
			n++;
		}
		if(n == 0)
			printf("没有这个航班\n");


		printf("是否继续查找\n");
		printf("y继续/任意键退出\n");
		scanf("%c",&c);
		if(c == 'y')
			aircrft_inquire6(s);
	
}

void aircrft_inquire7(air_pcrft s)
{
	air_pcrft q;
	char c;
	int n=0;
	int a;
	printf("请输入要查询的票价\n");
	scanf("%d",&a);
		getchar();

	for(q=s->next;q!=s;q=q->next)
		if(a == q->value)
		{
			printf("航班号 起点站 终点站 班期 起飞时间 到达时间 票价\n");
			printf("%s %s %s %d-%d-%d %s %s %d\n",q->number,q->staddress,q->arraddress,q->time.year,q->time.month,q->time.day,q->stime,q->atime,q->value);
			n++;
		}
		if(n == 0)
			printf("没有这个航班\n");


		printf("是否继续查找\n");
		printf("y继续/任意键退出\n");
		scanf("%c",&c);
		if(c == 'y')
			aircrft_inquire7(s);
	
}
