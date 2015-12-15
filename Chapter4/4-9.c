/*************************************************************************
	> File Name: 4-9.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月15日 星期二 18时00分56秒
 ************************************************************************/

#include "apue.h"

int main(void)
{
	char *ptr;
	int size;

	if(chdir("/tmp") < 0)
		err_sys("chdir failed");
	ptr = path_alloc(&size);
	if(getcwd(ptr, size) == NULL)
		err_sys("getcwd failed");
	printf("cwd = %s\n", ptr);
	exit(0);
}
