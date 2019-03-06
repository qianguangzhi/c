#include"../../include/multiple.h"

//读取数据
//******************************************
void ser_init(Linkedlist* listchain){

    Node* link;
//    int i;
    FILE* init = fopen("../save/save.bin","r");
   // InitSystemFlash();
    if(init == NULL){
	
		system("clear");
		printf("\n\n\n\n\t\t\t\t\t");
		printf("读取存档失败！！");
		usleep(20000000);
		return;
    }
    while(!feof(init) && !ferror(init)){

		link = malloc(sizeof(Node));

		if(link == NULL){
			system("clear");
			printf("\n\n\n\n\t\t\t\t\t");
			printf("读取存档失败！！");
			usleep(20000000);
			break;
		}
	
		if(fread(link,sizeof(Node),1,init) == 0)
			break;
		Add_Node_After_Tail(listchain,link);
    }
    fclose(init);
}
   

//*********************************************
void ser_save(Linkedlist* listchain){

    FILE* init = fopen("../save/save.bin","w");
    Node* pointer = listchain->head;

    if(init == NULL){
    	system("clear");
		printf("\n\n\n\n\t\t\t\t\t");
		printf("存档失败！！");
		usleep(20000000);
		return;
    }
    
    for(pointer = listchain->head;pointer != NULL;pointer = pointer->next)
		fwrite(pointer,sizeof(Node),1,init);
    fclose(init);
}

