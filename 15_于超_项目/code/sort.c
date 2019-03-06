#include"air.h"

void paixv(air_pcrft a,air_pcrft w,air_pcrft q)
{
		q->value=a->value;
		a->value=w->value;
		w->value=q->value;
		
		strcpy(q->atime,a->atime);
		strcpy(a->atime,w->atime);
		strcpy(w->atime,q->atime);
		
		strcpy(q->stime,a->stime);
		strcpy(a->stime,w->stime);
		strcpy(w->stime,q->stime);
		
		q->time.day=a->time.day;
		a->time.day=w->time.day;
		w->time.day=q->time.day;
			

		q->time.month=a->time.month;
		a->time.month=w->time.month;
		w->time.month=q->time.month;

		q->time.year=a->time.year;
		a->time.year=w->time.year;
		w->time.year=q->time.year;
	
		strcpy(q->arraddress,a->arraddress);
		strcpy(a->arraddress,w->arraddress);
		strcpy(w->arraddress,q->arraddress);

		strcpy(q->staddress,a->staddress);
		strcpy(a->staddress,w->staddress);
		strcpy(w->staddress,q->staddress);

		strcpy(q->number,a->number);
		strcpy(a->number,w->number);
		strcpy(w->number,q->number);

}
bool sort(air_pcrft s)
{
	char a;
	if(aircrft_empty(s))
     {
          printf("\n");
          printf("还没有录入信息\n");
          printf("\n");
          return false;
	}
	else
	{
		while(1)
		{
			
			menutwo();
			printf("请选择排序的方式:\n");
			scanf("%c",&a);
			system("clear");

			switch(a)
			{
				case '1':aircrft_sort(s);
					break;

				case '2':aircrft_sort2(s);
					break;

				case '3':aircrft_sort3(s);
					break;

				case '4':aircrft_sort4(s);
					break;

				case '5':aircrft_sort5(s);
					break;

				case '6':aircrft_sort6(s);
					break;

				case '7':aircrft_sort7(s);
					break;

				case '8':goto ret;
					
				default:printf("没有这个选项\n");

			}

		}
	}
ret:printf("已经返回主菜单\n");
	return true;
}

void aircrft_sort(air_pcrft s)

{
	air_pcrft a,w,q;
	aircrft_init(&q);
	char y[20];
	printf("1 升序 2 降序\n");
	printf("请选择：");
	scanf("%s",y);
	getchar();
	if(strcmp(y,"1")==0)
	for(w=s->next;w!=s;w=w->next)
	{
		for(a=s->next;a!=s;a=a->next)
		{
			if(strcmp(w->number,a->number)<0)
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

		}

	}
	else if(strcmp(y,"2")==0)
	for(w=s->next;w!=s;w=w->next)
	{
		for(a=s->next;a!=s;a=a->next)
		{
			if(strcmp(w->number,a->number)>0)
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

		}

	}
	else
		printf("没有这个选项\n");
}

void aircrft_sort2(air_pcrft s)
{
	air_pcrft a,w,q;
	aircrft_init(&q);
	char y[20];
	printf("1 升序 2 降序\n");
	printf("请选择：");
	scanf("%s",y);
	getchar();
	if(strcmp(y,"1")==0)
	for(w=s->next;w!=s;w=w->next)
	{
		for(a=s->next;a!=s;a=a->next)
		{
			if(strcmp(w->staddress,a->staddress)<0)
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

		}

	}
	else if(strcmp(y,"2")==0)
	for(w=s->next;w!=s;w=w->next)
	{
		for(a=s->next;a!=s;a=a->next)
		{
			if(strcmp(w->staddress,a->staddress)>0)
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

		}

	}
	else
		printf("没有这个选项\n");

}

void aircrft_sort3(air_pcrft s)
{
	air_pcrft a,w,q;
	aircrft_init(&q);
	char y[20];
	printf("1 升序 2 降序\n");
	printf("请选择：");
	scanf("%s",y);
	getchar();
	if(strcmp(y,"1")==0)
	for(w=s->next;w!=s;w=w->next)
	{
		for(a=s->next;a!=s;a=a->next)
		{
			if(strcmp(w->arraddress,a->arraddress)<0)
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

		}

	}
	else if(strcmp(y,"2")==0)
	for(w=s->next;w!=s;w=w->next)
	{
		for(a=s->next;a!=s;a=a->next)
		{
			if((w->arraddress)>(a->arraddress))
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

		}

	}
	else
		printf("没有这个选项\n");

}

void aircrft_sort5(air_pcrft s)
{
	air_pcrft a,w,q;
	aircrft_init(&q);
	char y[20];
	printf("1 升序 2 降序\n");
	printf("请选择：");
	scanf("%s",y);
	getchar();
	if(strcmp(y,"1")==0)
	for(w=s->next;w!=s;w=w->next)
	{
		for(a=s->next;a!=s;a=a->next)
		{
			if(strcmp(w->stime,a->stime)<0)
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

		}

	}
	else if(strcmp(y,"2")==0)
	for(w=s->next;w!=s;w=w->next)
	{
		for(a=s->next;a!=s;a=a->next)
		{
			if(strcmp(w->stime,a->stime)>0)
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

		}

	}
	else
		printf("没有这个选项\n");

}

void aircrft_sort6(air_pcrft s)
{
	air_pcrft a,w,q;
	aircrft_init(&q);
	char y[20];
	printf("1 升序 2 降序\n");
	printf("请选择：");
	scanf("%s",y);
	getchar();
	if(strcmp(y,"1")==0)
	for(w=s->next;w!=s;w=w->next)
	{
		for(a=s->next;a!=s;a=a->next)
		{
			if(strcmp(w->atime,a->atime)<0)
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

		}

	}
	else if(strcmp(y,"2")==0)
	for(w=s->next;w!=s;w=w->next)
	{
		for(a=s->next;a!=s;a=a->next)
		{
			if(strcmp(w->atime,a->atime)>0)
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

		}

	}
	else
		printf("没有这个选项\n");

}

void aircrft_sort7(air_pcrft s)
{
	air_pcrft a,w,q;
	aircrft_init(&q);
	char y[20];
	printf("1 升序 2 降序\n");
	printf("请选择：");
	scanf("%s",y);
	getchar();
	if(strcmp(y,"1")==0)
	for(w=s->next;w!=s;w=w->next)
	{
		for(a=s->next;a!=s;a=a->next)
		{
			if((w->value)<(a->value))
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

		}

	}
	else if(strcmp(y,"2")==0)
	for(w=s->next;w!=s;w=w->next)
	{
		for(a=s->next;a!=s;a=a->next)
		{
			if((w->value)>(a->value))
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

		}

	}
	else
		printf("没有这个选项\n");

}

void aircrft_sort4(air_pcrft s)
{
	air_pcrft a,w,q;
	aircrft_init(&q);
	char y[20];
	printf("1 升序 2 降序\n");
	printf("请选择：");
	scanf("%s",y);
	getchar();
	if(strcmp(y,"1")==0)
	for(w=s->next;w!=s;w=w->next)
	{
		for(a=s->next;a!=s;a=a->next)
		{
			if((w->time.year)<(a->time.year))
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

			else if(((w->time.month)<(a->time.month))&&((w->time.year)\
							==(a->time.year)))
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

			else if(((w->time.day)<(a->time.day))&&((w->time.month)==\
					(a->time.month))&&((w->time.year)==(a->time.year)))

			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);			
			}	

		}

	}
	else if(strcmp(y,"2")==0)
	for(w=s->next;w!=s;w=w->next)
	{
		for(a=s->next;a!=s;a=a->next)
		{
			if((w->time.year)>(a->time.year))
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

			else if(((w->time.month)>(a->time.month))&&\
					((w->time.year)==(a->time.year)))
			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);
			}

			else if(((w->time.day)>(a->time.day))&&((w->time.month)\
				==(a->time.month))&&((w->time.year)==(a->time.year)))

			{
				printf("\033[0;32;32m""---排序完毕---\n""\033[m");	
				paixv(a,w,q);			
			}	

		}

	}
	else
		printf("没有这个选项\n");

}
