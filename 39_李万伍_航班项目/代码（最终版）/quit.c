#include "head.h"


void node_quit(node_plist *Head)
{
    free(*Head);
    *Head = NULL;

    printf("数据已清空,bye!\n");
}
