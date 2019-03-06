#ifndef _AIR_H_
#define _AIR_H_

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"print.h"
#include<unistd.h>

//int q=1;
//char a[q][10];
struct data
{
	int year;
	int month;
	int day;
};

typedef struct aircrft
{
	char number[20];//航班号
	char staddress[20];//起点站
	char arraddress[20];//终点站
	struct data time;//班期
	char stime[20];//起飞时间
	char atime[20];//到达时间
	int value;//票价
	struct aircrft *next,*prev;
}air_crft,*air_pcrft;

extern bool buy_air_ticket(air_pcrft s); 

extern void aircrft_init(air_pcrft *Q);
extern void aircrft_insert(air_pcrft s,air_pcrft new);
extern void aircrft_list(air_pcrft s);
extern bool aircrft_show(air_pcrft s);

extern void menu();
extern void menutwo();

extern bool inquire(air_pcrft s);
extern void aircrft_inquire(air_pcrft s);
extern void aircrft_inquire2(air_pcrft s);
extern void aircrft_inquire3(air_pcrft s);
extern void aircrft_inquire4(air_pcrft s);
extern void aircrft_inquire5(air_pcrft s);
extern void aircrft_inquire6(air_pcrft s);
extern void aircrft_inquire7(air_pcrft s);

extern bool change(air_pcrft s);
extern void aircrft_change(air_pcrft s);
extern void aircrft_change2(air_pcrft s);
extern void aircrft_change3(air_pcrft s);
extern void aircrft_change4(air_pcrft s);
extern void aircrft_change5(air_pcrft s);
extern void aircrft_change6(air_pcrft s);
extern void aircrft_change7(air_pcrft s);
extern void xiugai(int n,air_pcrft t);

extern bool delete(air_pcrft s);
extern bool aircrft_delete(air_pcrft s);
extern bool aircrft_delete2(air_pcrft s);
extern bool aircrft_delete3(air_pcrft s);
extern bool aircrft_delete4(air_pcrft s);
extern bool aircrft_delete5(air_pcrft s);
extern bool aircrft_delete6(air_pcrft s);
extern bool aircrft_delete7(air_pcrft s);
extern void shanchu(int n,air_pcrft t);

extern bool sort(air_pcrft s);
extern void aircrft_sort(air_pcrft s);
extern void aircrft_sort2(air_pcrft s);
extern void aircrft_sort3(air_pcrft s);
extern void aircrft_sort4(air_pcrft s);
extern void aircrft_sort5(air_pcrft s);
extern void aircrft_sort6(air_pcrft s);
extern void aircrft_sort7(air_pcrft s);

extern bool aircrft_empty(air_pcrft s);
extern void aircrft_sort(air_pcrft s);
extern void shutdown();
extern void paixv(air_pcrft a,air_pcrft w,air_pcrft q);
#endif
