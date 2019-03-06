#ifndef _HEAD_H_
#define _HEAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct flight
{
    char number[18];
    char staddress[18];
    char arraddress[18];
    struct data
    {
	int year;
	int month;
	int data;
    }time;
    char TYPE[8];
    int stime[2];
    int atime[2];
    int value;
}datatype;

typedef struct node
{
    datatype info;
    struct node *prev,*next;
}node_list,*node_plist;


extern void init(node_plist *Head);
extern void insert(node_plist new, node_plist p);
extern void insert_before(node_plist new, node_plist p);
extern void delete(node_plist p); 

extern int node_show();
extern void node_input(node_plist head);
extern void node_output(node_plist head);
extern void node_delete(node_plist head);   
extern void node_search(node_plist head);
extern void node_modify(node_plist head);
extern void node_sort(node_plist head);
extern void node_buy_ticket(node_plist head, node_plist p[], int *i,char j[]);
extern void node_balance(node_plist head, node_plist p[], int *i, char k[]);
extern void node_quit(node_plist *Head);

#endif
