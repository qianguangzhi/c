#include "head.h"


void node_modify(node_plist head)
{
    int n,i=0,k;
    //存放用户输入的关键字
    char a[18];
    //存放用户输入的关键字
    int b[3];

    node_plist t;
    node_output(head);
    //定义一个结构体指针数组，存放部分重复航班的地址
    node_plist p[10];

    printf("选择你想要按哪种条件修改航班信息?\n");
    printf("1.航班号  2.起点站  3.终点站  4.班期  5.机型  6.起飞时间  7.到达时间 8.票价\n");

    scanf("%d",&n);
    switch(n)
    {
	//按航班号修改
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
			printf("(%d):%s\t%s\t%s\t%d-%d-%d\t%s\t%d:%d\t%d:%d\t%d\n",i,\
				t->info.number,t->info.staddress,t->info.arraddress,\
				t->info.time.year,t->info.time.month,t->info.time.data,\
				t->info.TYPE,t->info.stime[0],t->info.stime[1],\
				t->info.atime[0],t->info.atime[1],t->info.value);
		    }
		} 
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop1;
		}
		printf("你想要修改哪趟航班:");
		scanf("%d",&i);

		printf("修改为:\n");
		scanf("%s%s%s%d%d%d%s%d%d%d%d%d",p[i-1]->info.number,p[i-1]->info.staddress,\
			p[i-1]->info.arraddress,&p[i-1]->info.time.year,&p[i-1]->info.time.month,\
			&p[i-1]->info.time.data,p[i-1]->info.TYPE,&p[i-1]->info.stime[0],\
			&p[i-1]->info.stime[1],&p[i-1]->info.atime[0],&p[i-1]->info.atime[1],\
			&p[i-1]->info.value);
		printf("修改成功\n");
		break;

	//按起点站修改
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
			printf("(%d):%s\t%s\t%s\t%d-%d-%d\t%s\t%d:%d\t%d:%d\t%d\n",i,\
				t->info.number,t->info.staddress,t->info.arraddress,\
				t->info.time.year,t->info.time.month,t->info.time.data,\
				t->info.TYPE,t->info.stime[0],t->info.stime[1],\
				t->info.atime[0],t->info.atime[1],t->info.value);
		    }
		} 
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop2;
		}
		printf("你想要修改哪趟航班:");
		scanf("%d",&i);

		printf("修改为:\n");
		scanf("%s%s%s%d%d%d%s%d%d%d%d%d",p[i-1]->info.number,p[i-1]->info.staddress,\
			p[i-1]->info.arraddress,&p[i-1]->info.time.year,&p[i-1]->info.time.month,\
			&p[i-1]->info.time.data,p[i-1]->info.TYPE,&p[i-1]->info.stime[0],\
			&p[i-1]->info.stime[1],&p[i-1]->info.atime[0],&p[i-1]->info.atime[1],\
			&p[i-1]->info.value);
		printf("修改成功\n");
		break;

	//按终点站修改
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
			printf("(%d):%s\t%s\t%s\t%d-%d-%d\t%s\t%d:%d\t%d:%d\t%d\n",i,\
				t->info.number,t->info.staddress,t->info.arraddress,\
				t->info.time.year,t->info.time.month,t->info.time.data,\
				t->info.TYPE,t->info.stime[0],t->info.stime[1],\
				t->info.atime[0],t->info.atime[1],t->info.value);
		    }
		} 
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop3;
		}
		printf("你想要修改哪趟航班:");
		scanf("%d",&i);

		printf("修改为:\n");
		scanf("%s%s%s%d%d%d%s%d%d%d%d%d",p[i-1]->info.number,p[i-1]->info.staddress,\
			p[i-1]->info.arraddress,&p[i-1]->info.time.year,&p[i-1]->info.time.month,\
			&p[i-1]->info.time.data,p[i-1]->info.TYPE,&p[i-1]->info.stime[0],\
			&p[i-1]->info.stime[1],&p[i-1]->info.atime[0],&p[i-1]->info.atime[1],\
			&p[i-1]->info.value);
		printf("修改成功\n");
		break;	

	//按班期修改
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
			printf("(%d):%s\t%s\t%s\t%d-%d-%d\t%s\t%d:%d\t%d:%d\t%d\n",i,\
				t->info.number,t->info.staddress,t->info.arraddress,\
				t->info.time.year,t->info.time.month,t->info.time.data,\
				t->info.TYPE,t->info.stime[0],t->info.stime[1],\
				t->info.atime[0],t->info.atime[1],t->info.value);
		    }
		}
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop4;
		}
		printf("你想要修改哪趟航班:");
		scanf("%d",&i);

		printf("修改为:\n");
		scanf("%s%s%s%d%d%d%s%d%d%d%d%d",p[i-1]->info.number,p[i-1]->info.staddress,\
			p[i-1]->info.arraddress,&p[i-1]->info.time.year,&p[i-1]->info.time.month,\
			&p[i-1]->info.time.data,p[i-1]->info.TYPE,&p[i-1]->info.stime[0],\
			&p[i-1]->info.stime[1],&p[i-1]->info.atime[0],&p[i-1]->info.atime[1],\
			&p[i-1]->info.value);
		printf("修改成功\n");
		break;

	//按机型修改
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
			printf("(%d):%s\t%s\t%s\t%d-%d-%d\t%s\t%d:%d\t%d:%d\t%d\n",i,\
				t->info.number,t->info.staddress,t->info.arraddress,\
				t->info.time.year,t->info.time.month,t->info.time.data,\
				t->info.TYPE,t->info.stime[0],t->info.stime[1],\
				t->info.atime[0],t->info.atime[1],t->info.value);
		    }
		} 
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop5;
		}
		printf("你想要修改哪趟航班:");
		scanf("%d",&i);

		printf("修改为:\n");
		scanf("%s%s%s%d%d%d%s%d%d%d%d%d",p[i-1]->info.number,p[i-1]->info.staddress,\
			p[i-1]->info.arraddress,&p[i-1]->info.time.year,&p[i-1]->info.time.month,\
			&p[i-1]->info.time.data,p[i-1]->info.TYPE,&p[i-1]->info.stime[0],\
			&p[i-1]->info.stime[1],&p[i-1]->info.atime[0],&p[i-1]->info.atime[1],\
			&p[i-1]->info.value);
		printf("修改成功\n");
		break;

	//按起飞时间修改
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
			printf("(%d):%s\t%s\t%s\t%d-%d-%d\t%s\t%d:%d\t%d:%d\t%d\n",i,\
				t->info.number,t->info.staddress,t->info.arraddress,\
				t->info.time.year,t->info.time.month,t->info.time.data,\
				t->info.TYPE,t->info.stime[0],t->info.stime[1],\
				t->info.atime[0],t->info.atime[1],t->info.value);
		    }
		}
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop6;
		}
		printf("你想要修改哪趟航班:");
		scanf("%d",&i);

		printf("修改为:\n");
		scanf("%s%s%s%d%d%d%s%d%d%d%d%d",p[i-1]->info.number,p[i-1]->info.staddress,\
			p[i-1]->info.arraddress,&p[i-1]->info.time.year,&p[i-1]->info.time.month,\
			&p[i-1]->info.time.data,p[i-1]->info.TYPE,&p[i-1]->info.stime[0],\
			&p[i-1]->info.stime[1],&p[i-1]->info.atime[0],&p[i-1]->info.atime[1],\
			&p[i-1]->info.value);
		printf("修改成功\n");
		break;

	//按到达时间修改
	case 7:
		printf("请输入完整的时间如:12 30表示12:30  =_=!\n");			
loop7:		for(i = 0; i < 2; i++)
		    scanf("%d",&b[i]);
		i = 0;

		for(t = head->next; t != head; t = t->next)
		{
		    if(b[0] == t->info.atime[0] && b[1] == t->info.atime[1])	
		    {
			p[i] = t;
			i++;  
			printf("(%d):%s\t%s\t%s\t%d-%d-%d\t%s\t%d:%d\t%d:%d\t%d\n",i,\
				t->info.number,t->info.staddress,t->info.arraddress,\
				t->info.time.year,t->info.time.month,t->info.time.data,\
				t->info.TYPE,t->info.stime[0],t->info.stime[1],\
				t->info.atime[0],t->info.atime[1],t->info.value);
		    }
		}
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop7;
		}
		printf("你想要修改哪趟航班:");
		scanf("%d",&i);

		printf("修改为:\n");
		scanf("%s%s%s%d%d%d%s%d%d%d%d%d",p[i-1]->info.number,p[i-1]->info.staddress,\
			p[i-1]->info.arraddress,&p[i-1]->info.time.year,&p[i-1]->info.time.month,\
			&p[i-1]->info.time.data,p[i-1]->info.TYPE,&p[i-1]->info.stime[0],\
			&p[i-1]->info.stime[1],&p[i-1]->info.atime[0],&p[i-1]->info.atime[1],\
			&p[i-1]->info.value);
		printf("修改成功\n");
		break;

	//按价格修改
	case 8:
		printf("请输入\n");			
loop8:		scanf("%d",&n);

		for(t = head->next; t != head; t = t->next)
		{
		    if(n == t->info.value)	
		    {
			p[i] = t;
			i++;  
			printf("(%d):%s\t%s\t%s\t%d-%d-%d\t%s\t%d:%d\t%d:%d\t%d\n",i,\
				t->info.number,t->info.staddress,t->info.arraddress,\
				t->info.time.year,t->info.time.month,t->info.time.data,\
				t->info.TYPE,t->info.stime[0],t->info.stime[1],\
				t->info.atime[0],t->info.atime[1],t->info.value);
		    }
		}
		if(i == 0)
		{	
		    printf("查无此航班,请重新输入\n");
		    goto loop8;
		}
		printf("你想要修改哪趟航班:");
		scanf("%d",&i);

		printf("修改为:\n");
		scanf("%s%s%s%d%d%d%s%d%d%d%d%d",p[i-1]->info.number,p[i-1]->info.staddress,\
			p[i-1]->info.arraddress,&p[i-1]->info.time.year,&p[i-1]->info.time.month,\
			&p[i-1]->info.time.data,p[i-1]->info.TYPE,&p[i-1]->info.stime[0],\
			&p[i-1]->info.stime[1],&p[i-1]->info.atime[0],&p[i-1]->info.atime[1],\
			&p[i-1]->info.value);
		printf("修改成功\n");
		break;

    }	


}

