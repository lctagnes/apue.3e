/*************************************************************************
	> File Name: 4-3.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月15日 星期二 15时07分09秒
 ************************************************************************/
#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(void)
{
	umask(0);
	if(creat("foo", RWRWRW) < 0)
		err_sys("creat error for foo");
	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if(creat("bar", RWRWRW) < 0)
		err_sys("creat error for bar");
	exit(0);
}
