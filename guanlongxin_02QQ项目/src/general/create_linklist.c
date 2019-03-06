#include"../include/multiple.h"


//创建空链表
//**********************************************
Linkedlist *Create_Linkedlist(){
	
	Linkedlist* list = malloc(sizeof(Linkedlist));
	if(NULL == list)
		puts_error("Create_Linklist:Malloc");

	list->head = NULL;
	list->tail = NULL;
	return list;
}

//头节点前插入节点
//**********************************************
void Add_Node_Before_Head(Linkedlist* list,Node *node){

	node->prev = NULL;
	node->next = NULL;
	
	//链表为空
	if(NULL == list->head){

		list->head = node;
		list->tail = node;
	}

	//链表不为空
	else{

		list->head->prev = node;
		node->next = list->head;
		list->head = node;
	}
	return;
}

//尾节点后插入节点
//**********************************************
void Add_Node_After_Tail(Linkedlist* list,Node *node){
	
	node->prev = NULL;
	node->next = NULL;
	
	//链表为空
	if(NULL == list->head){

		list->head = node;
		list->tail = node;
	}

	//链表不为空
	else{

		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
	return;
}


//删除指定节点
//****************************************
void Delete_Node(Linkedlist* list,char myaccount[]){
	
	Node *temp,*pstu = list->head;
	while(pstu != NULL){	
		temp = pstu;
		if(strcmp(pstu->account,myaccount) == 0){
			
			if(list->head == list->tail){
				list->head = NULL;
				list->tail = NULL;
			}
			else if(pstu == list->head){
				
				list->head->next->prev = NULL;
				list->head = list->head->next;
			}
			else if(pstu == list->tail){
				
				list->tail->prev->next = NULL;
				list->tail = list->tail->prev;
			}
			else{
				pstu->prev->next = pstu->next;
				pstu->next->prev = pstu->prev;
			}
			pstu = pstu->next;
			free(temp);
			temp = NULL;
			break;
		}
		pstu = pstu->next;
	}
	return;
}

