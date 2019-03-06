#include"air.h"

void aircrft_init(air_pcrft *Q)
{
	*Q = (air_pcrft)malloc(sizeof(air_crft));
	if(NULL == *Q)
	{
		perror("malloc failed");
		exit(1);
	}
	(*Q)->next = *Q;
	(*Q)->prev = *Q;

}	
