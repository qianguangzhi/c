#include"air.h"

void aircrft_insert(air_pcrft s,air_pcrft new)
{

	new->next = s->next;
	s->next->prev = new;
	new->prev = s;
	s->next = new;
  

}
