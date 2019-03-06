#include "head.h"

//初始化
void init(node_plist *Head)
{
    *Head = (node_plist)malloc(sizeof(node_list));
    if(*Head == NULL)
    {	
	perror("malloc failed");
	exit(1);
    }

    (*Head)->next = *Head;
    (*Head)->prev = *Head;

}

//向节点后面插入数据
void insert(node_plist new, node_plist p)
{
    new->next = p->next;
    p->next->prev = new;
    new->prev = p;
    p->next = new;
}

//向节点前面插入数据(本程序未调用)
void insert_before(node_plist new, node_plist p)
{
    new->prev = p->prev;
    p->prev->next = new;
    new->next = p;
    p->prev = new;
}

//删除自身数据节点
void delete(node_plist p)
{
    p->prev->next = p->next;
    p->next->prev = p->prev;
}

//录入航班信息
void node_input(node_plist head)

{
    int i;
    node_plist new;
    printf("您需要输入以下信息:\n");
    printf("航班号  起点站  终点站  班期  机型  起飞时间  到达时间  票价\n");
    while(1)	
    {	
	new = (node_plist)malloc(sizeof(node_list));
	if(new == NULL)
	{
	    perror("malloc failed");
	    exit(1);
	}
	scanf("%s%s%s%d%d%d%s%d%d%d%d%d",new->info.number,new->info.staddress,\
		new->info.arraddress,&new->info.time.year,&new->info.time.month,\
		&new->info.time.data,new->info.TYPE,&new->info.stime[0],&new->info.stime[1],\
		&new->info.atime[0],&new->info.atime[1],&new->info.value);

	//向节点后插入数据
	insert(new,head);
	//每次插入后移动节点(如果老是在主界面切来切去,没有意义)
	head = new;		

	printf("您还要继续输入吗?  1.YES  2.NO\n");	
	scanf("%d",&i);
	if(i == 2)
	    break;
	else
	    continue;

    }

}
