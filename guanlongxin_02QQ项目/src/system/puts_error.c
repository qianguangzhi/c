#include"../../include/multiple.h"

//输出系统错误信息
void puts_error(char *pstu){

	perror("%s failed...\n");
	exit(1);

}
