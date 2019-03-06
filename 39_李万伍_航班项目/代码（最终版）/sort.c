#include "head.h"

//信息排序
void node_sort(node_plist head)
{
    int n,m;
    node_plist t,p,k;

    printf("选择你要按哪种条件排序?\n");
    printf("1.航班号  2.起点站  3.终点站  4.班期  5.机型  6.起飞时间  7.到达时间  8.票价\n");
    scanf("%d",&n);
    switch(n)
    {
	//按航班号排序
	case 1:
	    for(k = head->next; k != head; k = k->next)
		for(t = head->next; t->next != head; )
		{
		    m = strcmp(t->info.number,(t->next)->info.number);
		    if(m > 0)	
		    {		
			p = t;		
			t = t->next;
			//剪切节点p		
			delete(p); 
			//插入到节点t的后面	
			insert(p,t); 
		    }
		    else
			t = t->next;
		}	
	    printf("排序成功！\n");
	    break;

	//按起点站排序
	case 2:
	    for(k = head->next; k != head; k = k->next)
		for(t = head->next; t->next != head; )
		{
		    m = strcmp(t->info.staddress,(t->next)->info.staddress);
		    if(m > 0)	
		    {		
			p = t;		
			t = t->next;		
			delete(p);   
			insert(p,t); 
		    }
		    else
			t = t->next;
		}	
	    printf("排序成功！\n");
	    break;

	//按终点站排序    
	case 3:
	    for(k = head->next; k != head; k = k->next)
		for(t = head->next; t->next != head; )
		{
		    m = strcmp(t->info.arraddress,(t->next)->info.arraddress);
		    if(m > 0)	
		    {		
			p = t;		
			t = t->next;		
			delete(p);   
			insert(p,t); 
		    }
		    else
			t = t->next;
		}	
	    printf("排序成功！\n");
	    break;

	//按班期排序(只做了按月,日排序;年默认相等)
	case 4:
	    for(k = head->next; k != head; k = k->next)
		for(t = head->next; t->next != head; )
		{
		    if((t->info.time.month > (t->next)->info.time.month) || \
			    ((t->info.time.month == (t->next)->info.time.month) && \
			     (t->info.time.data > (t->next)->info.time.data)))	
		    {		
			p = t;		
			t = t->next;		
			delete(p);  
			insert(p,t); 
		    }
		    else
			t = t->next;
		}	
	    printf("排序成功！\n");
	    break;

	//按机型排序
	case 5:
	    for(k = head->next; k != head; k = k->next)
		for(t = head->next; t->next != head; )
		{
		    m = strcmp(t->info.TYPE,(t->next)->info.TYPE);
		    if(m > 0)	
		    {		
			p = t;		
			t = t->next;		
			delete(p);   
			insert(p,t); 
		    }
		    else
			t = t->next;
		}	
	    printf("排序成功！\n");
	    break;

	//按起飞时间排序
	case 6:
	    for(k = head->next; k != head; k = k->next)
		for(t = head->next; t->next != head; )
		{
		    if((t->info.stime[0] > (t->next)->info.stime[0]) || \
			    ((t->info.stime[0] == (t->next)->info.stime[0]) && \
			     (t->info.stime[1] > (t->next)->info.stime[1])))	
		    {		
			p = t;		
			t = t->next;		
			delete(p);   
			insert(p,t); 
		    }
		    else
			t = t->next;
		}	
	    printf("排序成功！\n");
	    break;

	//按到达时间排序
	case 7:
	    for(k = head->next; k != head; k = k->next)
		for(t = head->next; t->next != head; )
		{
		    if((t->info.atime[0] > (t->next)->info.atime[0]) || \
			    ((t->info.atime[0] == (t->next)->info.atime[0]) && \
			     (t->info.atime[1] > (t->next)->info.atime[1])))	
		    {		
			p = t;		
			t = t->next;		
			delete(p);   
			insert(p,t); 
		    }
		    else
			t = t->next;
		}	
	    printf("排序成功！\n");
	    break;

	//按票价排序
	case 8:
	    for(k = head->next; k != head; k = k->next)
		for(t = head->next; t->next != head; )
		{
		    if(t->info.value > (t->next)->info.value) 	
		    {		
			p = t;		
			t = t->next;		
			delete(p);   
			insert(p,t); 
		    }
		    else
			t = t->next;
		}	
	    printf("排序成功！\n");
	    break;
    }
}


















#if 0
printf("航班号  起点站  终点站  班期        机型   起飞时间  到达时间  票价\n");

for(t=head->next; t!=head; t=t->next)
printf("%s\t%s\t%s\t%d-%d-%d   %s\t%d:%d\t%d:%d\t%d\n",\
	t->info.number,t->info.staddress,t->info.arraddress,\
	t->info.time.year,t->info.time.month,t->info.time.data,\
	t->info.TYPE,t->info.stime[0],t->info.stime[1],t->info.atime[0],\
	t->info.atime[1],t->info.value);
printf("\n");
}
#endif
