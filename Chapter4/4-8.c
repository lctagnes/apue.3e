/*************************************************************************
	> File Name: 4-8.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月15日 星期二 18时00分41秒
 ************************************************************************/
#include "apue.h"

int main(void)
{
	if(chdir("/tmp") < 0)
		fprintf(stderr, "chdir failed");
	printf("chdir to /tmp succeeded\n");
	exit(0);
}
