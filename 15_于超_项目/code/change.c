#include"air.h"

void xiugai(int n,air_pcrft t)
{
		int i;
			printf("你要修改这条信息吗？\n");
			printf("%s  %s  %s  %d-%d-%d  %s  %s  %d\n",t->number,t->staddress,t->arraddress,t->time.year,t->time.month,t->time.day,t->stime,t->atime,t->value);
			printf("1 是 2 否\n");
            scanf("%d",&i);
            if(i==1)
			{
				printf("航班号 起点站 终点站 班期 起飞时间 到达时间 票价\n");
				scanf("%s%s%s%d%d%d%s%s%d",t->number,t->staddress,t->arraddress,&t->time.year,&t->time.month,&t->time.day,t->stime,t->atime,&t->value);
				n++;
				getchar();
			}
			if(i==2)
			{
				printf("跳转下一个(如果没有下一个直接跳出)\n");
			}
}

bool change(air_pcrft s)
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
			printf("请选择修改的方式：");
			scanf("%c",&c);
			getchar();
			switch(c)
			{
					case '1':aircrft_change(s);
                 	  break;
  
            		case '2':aircrft_change2(s);
            	      break;
  	
  	    	      	case '3':aircrft_change3(s);
                	  break;
  
           			case '4':aircrft_change4(s);
                	 break;
  
            		case '5':aircrft_change5(s);
            	      break;
  
        	    	case '6':aircrft_change6(s);
    	              break;
  	
            		case '7':aircrft_change7(s);
        	          break;

					case '8':goto ret;
	
					default:printf("没有这个选项\n");
			}

		}
	}
ret:printf("已经返回主菜单\n");
	return true;
}

void aircrft_change(air_pcrft s)
{
	air_pcrft t;
	char ch[20];
	char c;
	int n=0;

	printf("请输入要修改的航班号\n");
	scanf("%s",ch);
	getchar();
	
	for(t=s->next; t!=s; t=t->next)
		if(strcmp(ch,t->number)==0)
		{
			xiugai(n,t);
		}
		
		if(n==0)
			printf("没有这趟航班\n");

			printf("是否继续查找\n");
  	 	    printf("y继续/任意键退出\n");
        	 scanf("%c",&c);
        	  if(c == 'y')
            	  aircrft_change(s);
}

void aircrft_change2(air_pcrft s)
{
	air_pcrft t;
	char ch[20];
	char c;
	int n=0;
	printf("请输入要修改的起点站\n");
	scanf("%s",ch);
	getchar();
	
	for(t=s->next; t!=s; t=t->next)
		if(strcmp(ch,t->staddress)==0)
		{
			xiugai(n,t);
		}
		
		if(n==0)
			printf("没有这趟航班\n");

			printf("是否继续查找\n");
    	    printf("y继续/任意键退出\n");
        	 scanf("%c",&c);
        	  if(c == 'y')
            	  aircrft_change2(s);
}

void aircrft_change3(air_pcrft s)
{
	air_pcrft t;
	char ch[20];
	char c;
	int n=0;

	printf("请输入要修改的终点站\n");
	scanf("%s",ch);
	getchar();
	
	for(t=s->next; t!=s; t=t->next)
		if(strcmp(ch,t->arraddress)==0)
		{
			xiugai(n,t);
		}
		if(n==0)
			printf("没有这趟航班\n");

			printf("是否继续查找\n");
    	    printf("y继续/任意键退出\n");
        	 scanf("%c",&c);
        	  if(c == 'y')
            	  aircrft_change3(s);
}
void aircrft_change4(air_pcrft s)
{
	air_pcrft t;
	char c;
	int n=0;
	int a1,a2,a3;
	printf("请输入要修改的班期\n");
	scanf("%d%d%d",&a1,&a2,&a3);
	getchar();
	
	for(t=s->next; t!=s; t=t->next)
		if((a1 == t->time.year)&&(a2 == t->time.month)&&(a3 == t->time.day))
		{
			xiugai(n,t);
		}
		
		if(n==0)
			printf("没有这趟航班\n");

			printf("是否继续查找\n");
    	    printf("y继续/任意键退出\n");
        	 scanf("%c",&c);
        	  if(c == 'y')
            	  aircrft_change4(s);
}

void aircrft_change5(air_pcrft s)
{
	air_pcrft t;
	char ch[20];
	char c;
	int n=0;

	printf("请输入要修改的起飞时间\n");
	scanf("%s",ch);
	getchar();
	
	for(t=s->next; t!=s; t=t->next)
		if(strcmp(ch,t->stime)==0)
		{
			xiugai(n,t);
		}
		
		if(n==0)
			printf("没有这趟航班\n");

			printf("是否继续查找\n");
    	    printf("y继续/任意键退出\n");
        	 scanf("%c",&c);
        	  if(c == 'y')
            	  aircrft_change5(s);
}

void aircrft_change6(air_pcrft s)
{
	air_pcrft t;
	char ch[20];
	char c;
	int n=0;

	printf("请输入要修改的到达时间\n");
	scanf("%s",ch);
	getchar();
	
	for(t=s->next; t!=s; t=t->next)
		if(strcmp(ch,t->atime)==0)
		{
			xiugai(n,t);
		}
		
		if(n==0)
			printf("没有这趟航班\n");

			printf("是否继续查找\n");
    	    printf("y继续/任意键退出\n");
        	 scanf("%c",&c);
        	  if(c == 'y')
            	  aircrft_change6(s);
}

void aircrft_change7(air_pcrft s)
{
	air_pcrft t;
	int a;
	char c;
	int n=0;

	printf("请输入要修改的票价\n");
	scanf("%d",&a);
	getchar();
	
	for(t=s->next; t!=s; t=t->next)
		if(a == t->value)
		{
			xiugai(n,t);
		}
		
		if(n==0)
			printf("没有这趟航班\n");

			printf("是否继续查找\n");
    	    printf("y继续/任意键退出\n");
        	 scanf("%c",&c);
        	  if(c == 'y')
            	  aircrft_change7(s);
}
