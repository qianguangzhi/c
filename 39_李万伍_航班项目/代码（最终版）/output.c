#include "head.h"

//输出：(可按起飞时间排序)
void node_output(node_plist head)
{

    node_plist t;
#if 0
    for(k = head->next; k != head; k = k->next)
	for(t = head->next; t->next != head; )
	{
	    if((t->info.stime[0] > (t->next)->info.stime[0]) || \
		    ((t->info.stime[0] == (t->next)->info.stime[0]) && \
		     (t->info.stime[1] > (t->next)->info.stime[1])))	
	    {		
		p = t;		
		t = t->next;
		//剪切节点p
		node_delete(p);
		//将节点p插入到节点t的后面	
		node_insert(p,t); 
	    }
	    else
		t = t->next;
	}	
#endif
    printf("航班号\t起点站\t终点站\t班期\t机型\t起飞时间\t到达时间\t票价\n");

    for(t=head->next; t!=head; t=t->next)
	printf("%s\t%s\t%s\t%d-%d-%d\t%s\t%d:%d\t%d:%d\t%d\n",\
		t->info.number,t->info.staddress,t->info.arraddress,\
		t->info.time.year,t->info.time.month,t->info.time.data,\
		t->info.TYPE,t->info.stime[0],t->info.stime[1],t->info.atime[0],\
		t->info.atime[1],t->info.value);
    printf("\n");
}
