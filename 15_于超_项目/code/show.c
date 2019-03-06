#include"air.h"

bool aircrft_show(air_pcrft s)
{
	air_pcrft t;
		if(aircrft_empty(s))
		{
			printf("\n");
			printf("还没有录入信息\n");
			printf("\n");
			return false;
		}
		else
		{
		printf("航班号 起点站 终点站 班期 起飞时间 到达时间 票价\n");
			for(t=s->next;t!=s;t=t->next)
			{
				printf("%s  %s  %s  %d-%d-%d  %s  %s  %d\n",t->number,t->staddress,t->arraddress,t->time.year,t->time.month,t->time.day,t->stime,t->atime,t->value);
			}
		}
		printf("\n");
		return true;
}
