/*************************************************************************
	> File Name: 4-5.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月15日 星期二 15时26分51秒
 ************************************************************************/
#include "apue.h"
#include <fcntl.h>

int main(void)
{
	if(open("foo", O_RDWR) < 0)
		err_sys("open error");
	if(unlink("foo") < 0)
		err_sys("unlink error");
	printf("file unlinked\n");
	sleep(5);
	printf("done\n");
	exit(0);
}
