#include"air.h"

void shanchu(int n,air_pcrft t)
{
	int i;
					printf("你要删除这条信息吗？\n");
					printf("%s  %s  %s  %d-%d-%d  %s  %s  %d\n",t->number,\
						t->staddress,t->arraddress,t->time.year,t->time\
						.month,t->time.day,t->stime,t->atime,t->value);				
					printf("1 是 2 否\n");
					scanf("%d",&i);
					if(i==1)
					{
					t->prev->next = t->next;
					t->next->prev = t->prev;
					n++;
					}
					if(i==2)
					{
						printf("跳转下一个(如果没有下一个直接跳出)\n");
					}

}

bool delete(air_pcrft s)
{
	char c;
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
				printf("请选择删除的方式：");
				scanf("%c",&c);
			switch(c)
			{
				case '1':aircrft_delete(s);
					break;

				case '2':aircrft_delete2(s);
					break;

				case '3':aircrft_delete3(s);
					break;

				case '4':aircrft_delete4(s);
					break;

				case '5':aircrft_delete5(s);
					break;

				case '6':aircrft_delete6(s);
					break;

				case '7':aircrft_delete7(s);
					break;
				
				case '8':goto ret;
	
				default:printf("没有这个选项\n");
			}	
		}
	}
ret:printf("已返回主菜单\n");
	return true;
}


bool aircrft_delete(air_pcrft s)
{
	if(aircrft_empty(s))
	{
		printf("\n");
		printf("信息已空\n");
		printf("\n");
		return false;
	}
	else
	{
		air_pcrft t;
		int n=0;
		char ch[20],sb[20];
		char c;
	//	int i;

		printf("请输入要删除的航班号\n");
		scanf("%s",ch);
		getchar();
		
		printf("是否确认删除%s\n",ch);
		printf("\033[0;32;31m""1 删除 其它键 否\n""\033[m");
		scanf("%s",sb);
		getchar();
		if(strcmp(sb,"1")==0)		
		{
			for(t=s->next; t!=s; t=t->next)
				if(strcmp(ch,t->number)==0)
				{
					shanchu(n,t);
				}
		
		}
		else
		{
			goto ret1;
		}
			if(n == 0)
				printf("没有这趟航班\n");
		ret1:
			printf("是否按航班号继续删除\n");
			printf("y继续/任意键退出\n");
			scanf("%c",&c);
			if(c == 'y')
				aircrft_delete(s);
	}
	return true;
}

bool aircrft_delete2(air_pcrft s)
{
	if(aircrft_empty(s))
	{
		printf("\n");
		printf("信息已空\n");
		printf("\n");
		return false;
	}
	else
	{
	air_pcrft t;
	int n=0;
	char ch[20],sb[20];
	char c;

		printf("请输入要删除的起点站\n");
		scanf("%s",ch);
		getchar();
	
		printf("是否确认删除%s\n",ch);
		printf("\033[0;32;31m""1 删除 其它键 否\n""\033[m");
		scanf("%s",sb);
		getchar();
		if(strcmp(sb,"1")==0)		
		{

			for(t=s->next; t!=s; t=t->next)
				if(strcmp(ch,t->staddress)==0)
				{
					shanchu(n,t);
				}
		
		
		}
		else
		{
			goto ret1;
		}
		if(n == 0)
			printf("没有这趟航班\n");

		ret1:
			printf("是否继续删除\n");
			printf("y继续/任意键退出\n");
			scanf("%c",&c);
			if(c == 'y')
				aircrft_delete2(s);
	}
	return true;
}

bool aircrft_delete3(air_pcrft s)
{
	if(aircrft_empty(s))
	{
		printf("\n");
		printf("信息已空\n");
		printf("\n");
		return false;
	}
	else
	{
		air_pcrft t;
		int n=0;
		char ch[20],sb[20];
		char c;
	
		printf("请输入要删除的终点站\n");
		scanf("%s",ch);
		getchar();

		printf("是否确认删除%s\n",ch);
		printf("\033[0;32;31m""1 删除 其它键 否\n""\033[m");
		scanf("%s",sb);
		getchar();
		if(strcmp(sb,"1")==0)		
		{

			for(t=s->next; t!=s; t=t->next)
				if(strcmp(ch,t->arraddress)==0)
				{
					shanchu(n,t);
				}
		
		
		}
		else
		{
			goto ret1;
		}
		if(n == 0)
			printf("没有这趟航班\n");

		ret1:
			printf("是否继续删除\n");
			printf("y继续/任意键退出\n");
			scanf("%c",&c);
			if(c == 'y')
				aircrft_delete3(s);
	}
	return true;
}

bool aircrft_delete4(air_pcrft s)
{
	if(aircrft_empty(s))
	{
		printf("\n");
		printf("信息已空\n");
		printf("\n");
		return false;
	}
	else
	{
		air_pcrft t;
		int n=0;
		int a1,a2,a3;
		char c;
		char sb[20];

		printf("请输入要删除的班期\n");
		scanf("%d%d%d",&a1,&a2,&a3);
		getchar();

		printf("是否确认删除%d-%d-%d\n",a1,a2,a3);
		printf("\033[0;32;31m""1 删除 其它键 否\n""\033[m");
		scanf("%s",sb);
		getchar();

		if(strcmp(sb,"1")==0)		
		{

			for(t=s->next; t!=s; t=t->next)
				if((a1 == t->time.year)&&(a2 == t->time.month)&&(a3 == t->time.day))
				{
					shanchu(n,t);
				}
		
		
		}
		else
		{
			goto ret1;
		}
		if(n == 0)
			printf("没有这趟航班\n");

		ret1:
			printf("是否继续删除\n");
			printf("y继续/任意键退出\n");
			scanf("%c",&c);
			if(c == 'y')
				aircrft_delete4(s);
	}
	return true;
}

bool aircrft_delete5(air_pcrft s)
{
	if(aircrft_empty(s))
	{
		printf("\n");
		printf("信息已空\n");
		printf("\n");
		return false;
	}
	else
	{
		air_pcrft t;
		int n=0;
		char ch[20],sb[20];
		char c;
		printf("请输入要删除的起飞时间\n");
		scanf("%s",ch);
		getchar();
	
		printf("是否确认删除%s\n",ch);
		printf("\033[0;32;31m""1 删除 其它键 否\n""\033[m");
		scanf("%s",sb);
		getchar();

		if(strcmp(sb,"1")==0)		
		{

			for(t=s->next; t!=s; t=t->next)
				if(strcmp(ch,t->stime)==0)
				{
					shanchu(n,t);
				}
		
		
		}
		else
		{
			goto ret1;
		}
			if(n == 0)
				printf("没有这趟航班\n");
	
		ret1:
			printf("是否继续删除\n");
			printf("y继续/任意键退出\n");
			scanf("%c",&c);
			if(c == 'y')
				aircrft_delete5(s);
	}
	return true;
}

bool aircrft_delete6(air_pcrft s)
{
	if(aircrft_empty(s))
	{
		printf("\n");
		printf("信息已空\n");
		printf("\n");
		return false;
	}
	else
	{
		air_pcrft t;
		int n=0;
		char ch[20],sb[20];
		char c;
		printf("请输入要删除的到达时间\n");
		scanf("%s",ch);
		getchar();

		printf("是否确认删除%s\n",ch);
		printf("\033[0;32;31m""1 删除 其它键 否\n""\033[m");
		scanf("%s",sb);
		getchar();

		if(strcmp(sb,"1")==0)		
		{

			for(t=s->next; t!=s; t=t->next)
				if(strcmp(ch,t->atime)==0)
				{
					shanchu(n,t);
				}
		
		
		}
		else
		{
			goto ret1;
		}
			if(n == 0)
				printf("没有这趟航班\n");
	
		ret1:
			printf("是否继续删除\n");
			printf("y继续/任意键退出\n");
			scanf("%c",&c);
			if(c == 'y')
				aircrft_delete6(s);
	}
	return true;
}

bool aircrft_delete7(air_pcrft s)
{
	if(aircrft_empty(s))
	{
		printf("\n");
		printf("信息已空\n");
		printf("\n");
		return false;
	}
	else
	{
		air_pcrft t;
		int n=0;
		int a;
		char c;
		char sb[20];

		printf("请输入要删除的航班号\n");
		scanf("%d",&a);
		getchar();

		printf("是否确认删除%d\n",a);
		printf("\033[0;32;31m""1 删除 其它键 否\n""\033[m");
		scanf("%s",sb);
		getchar();
		if(strcmp(sb,"1")==0)		
		{

			for(t=s->next; t!=s; t=t->next)
				if(a == t->value)
				{
					shanchu(n,t);
				}
		
		
		}
		else
		{
			goto ret1;
		}
			if(n == 0)
				printf("没有这趟航班\n");
	
		ret1:
			printf("是否继续删除\n");
			printf("y继续/任意键退出\n");
			scanf("%c",&c);
			if(c == 'y')
				aircrft_delete7(s);
	}
	return true;
}
