#include "head.h"

void node_balance(node_plist head, node_plist p[], int *i, char k[])
{
    int j,sum = 0;
    node_plist t;

    printf("您购买的航班简要信息如下:\n");
    printf("航班号     座位     价格\n");

    for(j = 0; j < *i; j++)
    {
	for(t = head->next; t != head; t = t->next)
	    if(t == p[j])
	    {
		sum += t->info.value;
		printf("(%d):%s\t%c\t%d\n",j+1,t->info.number,k[j],t->info.value);
	    }
    }
    printf("机票总价:%d\n",sum);
}
