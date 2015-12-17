/*************************************************************************
	> File Name: 7-3.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月17日 星期四 15时29分09秒
 ************************************************************************/
#include "apue.h"

int main(int argc, char *argv[])
{
	int i;
	for(i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);
	exit(0);
}
