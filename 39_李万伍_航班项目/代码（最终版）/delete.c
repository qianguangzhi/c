#include "head.h"


void node_delete(node_plist head)
{
    int n,m,i=0,j,k;
    //存放用户输入的关键字
    char a[18];
    //存放用户输入的关键字
    int b[3];

    node_plist t;
    //定义一个结构体指针数组，存放部分重复航班的地址
    node_plist p[10];
    node_output(head);

    printf("选择你想要按哪种条件删除航班信息?\n");
    printf("1.航班号  2.起点站  3.终点站  4.班期  5.机型  6.起飞时间  7.到达时间 8.票价\n");

    scanf("%d",&n);
    switch(n)
    {
	//按航班号删除
	case 1: 
		printf("请输入:");
loop1:		scanf("%s",a);

		for(t = head->next; t != head; t = t->next)
		{
		    k = strcmp(a,t->info.number);	
		    if(k == 0)
		    {
			p[i] = t;  
			i++;					
		    }
		}
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop1;
		}
		printf("查到有以下航班,选择删除:\n");
		for(j = 0 ;j < i; j++)
		    printf("(%d):%s\n",j+1,p[j]->info.number);
		scanf("%d",&j);

		printf("你确定要删除这个航班信息吗?\n");
		printf("1.确定  2.返回\n");
		scanf("%d",&n);
		if(n == 2)
		    break;

		delete(p[j-1]); 	
		printf("删除成功\n");
		break;

	//按起点站删除
	case 2: 
		printf("请输入:");
loop2:		scanf("%s",a);

		for(t = head->next; t != head; t = t->next)
		{
		    k = strcmp(a,t->info.staddress);	
		    if(k == 0)
		    {
			p[i] = t;  
			i++;					
		    }
		}
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop2;
		}
		printf("查到有以下航班,选择删除:\n");
		for(j = 0 ;j < i; j++)
		    printf("(%d):%s\n",j+1,p[j]->info.number);
		scanf("%d",&j);

		printf("你确定要删除这个航班信息吗?\n");
		printf("1.确定  2.返回\n");
		scanf("%d",&n);
		if(n == 2)
		    break;

		delete(p[j-1]); 	
		printf("删除成功\n");
		break;

	//按终点站删除
	case 3:
		printf("请输入:");
loop3:		scanf("%s",a);

		for(t = head->next; t != head; t = t->next)
		{
		    k = strcmp(a,t->info.arraddress);	
		    if(k == 0)
		    {
			p[i] = t;  
			i++;					
		    }
		}
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop3;
		}
		printf("查到有以下航班,选择删除:\n");
		for(j = 0 ;j < i; j++)
		    printf("(%d):%s\n",j+1,p[j]->info.number);
		scanf("%d",&j);

		printf("你确定要删除这个航班信息吗?\n");
		printf("1.确定  2.返回\n");
		scanf("%d",&n);
		if(n == 2)
		    break;

		delete(p[j-1]); 	
		printf("删除成功\n");
		break;	

	//按班期删除
	case 4:
		printf("请输入完整的时间如:2018 6 24表示2018年6月24日 =_=!\n");			
loop4:		for(i = 0; i < 3; i++)
		    scanf("%d",&b[i]);

		for(t = head->next; t != head; t = t->next)
		{
		    if(b[0] == t->info.time.year && b[1] == t->info.time.month \
			    && b[2] == t->info.time.data)	
		    {
			p[i] = t;
			i++;  
		    }
		}
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop4;
		}
		printf("查到有以下航班,选择删除:\n");
		for(j = 0 ;j < i; j++)
		    printf("(%d):%s\n",j+1,p[j]->info.number);
		scanf("%d",&j);

		printf("你确定要删除这个航班信息吗?\n");
		printf("1.确定  2.返回\n");
		scanf("%d",&n);
		if(n == 2)
		    break;

		delete(p[j-1]); 	
		printf("删除成功\n");
		break;

	//按机型删除
	case 5:
		printf("请输入:\n");			
loop5:		scanf("%s",a);

		for(t = head->next; t != head; t = t->next)
		{
		    k = strcmp(a,t->info.TYPE);	
		    if(k == 0)
		    {
			p[i] = t;  
			i++;					
		    }
		}
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop5;
		}
		printf("查到有以下航班,选择删除:\n");
		for(j = 0 ;j < i; j++)
		    printf("(%d):%s\n",j+1,p[j]->info.number);
		scanf("%d",&j);

		printf("你确定要删除这个航班信息吗?\n");
		printf("1.确定  2.返回\n");
		scanf("%d",&n);
		if(n == 2)
		    break;

		delete(p[j-1]); 	
		printf("删除成功\n");
		break;

	//按起飞时间删除
	case 6:
		printf("请输入完整的时间如:12 30表示12:30  =_=!\n");			
loop6:		for(i = 0; i < 2; i++)
		    scanf("%d",&b[i]);

		for(t = head->next; t != head; t = t->next)
		{
		    if(b[0] == t->info.stime[0] && b[1] == t->info.stime[1])	
		    {
			p[i] = t;
			i++;  
		    }
		}
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop6;
		}
		printf("查到有以下航班,选择删除:\n");
		for(j = 0 ;j < i; j++)
		    printf("(%d):%s\n",j+1,p[j]->info.number);
		scanf("%d",&j);

		printf("你确定要删除这个航班信息吗?\n");
		printf("1.确定  2.返回\n");
		scanf("%d",&n);
		if(n == 2)
		    break;

		delete(p[j-1]); 	
		printf("删除成功\n");
		break;

	//按到达时间删除
	case 7:
		printf("请输入完整的时间如:12 30表示12:30  =_=!\n");			
loop7:		for(i = 0; i < 2; i++)
		    scanf("%d",&b[i]);

		for(t = head->next; t != head; t = t->next)
		{
		    if(b[0] == t->info.atime[0] && b[1] == t->info.atime[1])	
		    {
			p[i] = t;
			i++;  
		    }
		}
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop7;
		}
		printf("查到有以下航班,选择删除:\n");
		for(j = 0 ;j < i; j++)
		    printf("(%d):%s\n",j+1,p[j]->info.number);
		scanf("%d",&j);

		printf("你确定要删除这个航班信息吗?\n");
		printf("1.确定  2.返回\n");
		scanf("%d",&n);
		if(n == 2)
		    break;

		delete(p[j-1]); 	
		printf("删除成功\n");
		break;

	//按价格删除
	case 8:
		printf("请输入\n");			
loop8:		scanf("%d",&m);

		for(t = head->next; t != head; t = t->next)
		{
		    if(m == t->info.value)	
		    {
			p[i] = t;
			i++;  
		    }
		}
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop8;
		}
		printf("查到有以下航班,选择删除:\n");
		for(j = 0 ;j < i; j++)
		    printf("(%d):%s\n",j+1,p[j]->info.number);
		scanf("%d",&j);

		printf("你确定要删除这个航班信息吗?\n");
		printf("1.确定  2.返回\n");
		scanf("%d",&n);
		if(n == 2)
		    break;

		delete(p[j-1]); 	
		printf("删除成功\n");
		break;

    }	


}
