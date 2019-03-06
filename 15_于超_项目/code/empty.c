#include"air.h"

bool aircrft_empty(air_pcrft s)
{

	if(s->next==s)
		return true;
	else
		return false;

}
