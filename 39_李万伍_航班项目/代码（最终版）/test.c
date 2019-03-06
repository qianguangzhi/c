#include "head.h"

int main(void)
{
    int n,i=0;
    //定义一个字符型数组,用来存放: 选座
    char j[10];
    //定义一个结构体指针数组,存放用户购票所选航班的链表地址
    node_plist p[18];
    node_plist head;
    //在堆上申请空间
    init(&head);
    while (1)
    {
	
	n = node_show();
	
	if(n == 1)
	    node_input(head);       

	if(n == 2)
	    node_output(head);	

	if(n == 3)
	    node_delete(head);	
	
	if(n == 4)
	    node_search(head);	

	if(n == 5)
	    node_modify(head);
	
	if(n == 6)
	    node_sort(head);

	if(n == 7)
	    node_buy_ticket(head,p,&i,j);

	if(n == 8)
	    node_balance(head,p,&i,j);

	if(n == 9)
	{
	    node_quit(&head);
	    break;	  		
	}
    }

    return 0;
}
/*本程序未完善之处
  1.排序按班期排序，只做了按月日排序，年默认，可以修改；*/
