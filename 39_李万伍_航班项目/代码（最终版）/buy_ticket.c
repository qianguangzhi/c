#include "head.h"


void node_buy_ticket(node_plist head, node_plist p[], int *i, char j[])
{   
    
    char n[18],m;
    int k,flag=0;
   
    node_plist t;
    node_output(head);

loop:
    printf("请选择航班号\n");
    scanf("%s",n);
    flag = 0;
    for(t = head->next; t != head; t=t->next)
    {
	k = strcmp(n,t->info.number);
	if(k == 0)
	{
	    p[*i] = t;
	    flag++;
	}
    }
    if(flag == 0)
    {
	printf("查无此航,请重新输入\n");
	goto loop;
    }
loop1:
    printf("请选择座位(本航班为奢华航班,只有5个位置):\n");
    printf("A    B    C    D    F\n");
    getchar();

    scanf("%c",&j[*i]);
    if(j[*i] != 'A' && j[*i] != 'B' && j[*i] != 'C' && j[*i] != 'D' && j[*i] != 'F')
    {
	printf("请看清楚再选!\n");
	goto loop1;
    }
    (*i)++;
    
    for(k = 0; k < *i-1; k++)
    {
	if(p[k]->info.number == p[*i-1]->info.number && j[k] == j[*i-1])
	{
	    (*i)--;
	    printf("该座位已售!\n");
	    goto loop;
	}
    }	

    printf("购票成功!您是否要继续购票? Y/N\n");
    getchar();
    scanf("%c",&m);
    if(m == 'Y')
	goto loop;
    if(m == 'N')
	printf("请去主界面结算\n");
  

}
	

	
