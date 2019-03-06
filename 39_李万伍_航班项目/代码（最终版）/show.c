#include "head.h"

int node_show()
{
    int n;	
//    system("clear");
    printf("\n*****************************************\n");
    printf("|**  1.录入航班信息   2.显示航班信息  **|\n");
    printf("|**  3.删除航班信息   4.查询航班信息  **|\n");
    printf("|**  5.修改航班信息   6.排序航班信息  **|\n");
    printf("|**  7.买票           8.结算          **|\n");
    printf("|**  9.关机                           **|\n");
    printf("*****************************************\n");
loop:
    scanf("%d",&n);
    getchar();
    if(n < 1 || n > 9 )
    {
	printf("输入不正确,请看清楚再输入\n");
	goto loop;
    }
    return n;
}
