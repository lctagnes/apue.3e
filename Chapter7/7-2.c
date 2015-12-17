/*************************************************************************
	> File Name: 7-1.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月17日 星期四 15时21分48秒
 ************************************************************************/
#include "apue.h"

static void my_exit1(void);
static void my_exit2(void);

int main(void)
{
	if(atexit(my_exit2) != 0)
		err_sys("can't register my_exit2");

	if(atexit(my_exit1) != 0)
		err_sys("can't register my_exit1");

	if(atexit(my_exit1) != 0)
		err_sys("can't register my_exit1");

	printf("main is done\n");
	return 0;
}

static void my_exit1(void)
{
	printf("first exit handler\n");
}
static void my_exit2(void)
{
	printf("second exit handler\n");
}
