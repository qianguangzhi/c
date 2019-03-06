#include"air.h"

void shutdown()
{
	
	printf("\033[0;32;34m""   *******\n""\033[m");
	sleep(1);
	printf("\033[0;32;32m""    *****\n""\033[m");
	sleep(1);
	printf("\033[1;31m""     ***\n""\033[m");
	sleep(1);
	printf("\033[0;32;31m""      *\n""\033[m");
	sleep(1);
	printf("\033[0;32;31m""      *\n""\033[m");
	sleep(1);
	printf("\033[1;31m""     ***\n""\033[m");
	sleep(1);
	printf("\033[0;32;32m""    *****\n""\033[m");
	sleep(1);
	printf("\033[0;32;34m""   *******\n""\033[m");
	
	sleep(1);
	exit(1);

}
