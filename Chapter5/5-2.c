/*************************************************************************
	> File Name: 5-2.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月16日 星期三 10时17分59秒
 ************************************************************************/
#include "apue.h"

int main(void)
{
	char buf[MAXLINE];

	while(fgets(buf, MAXLINE, stdin) != NULL)
	{
		if(fputs(buf, stdout) == EOF)
			err_sys("output error");
	}
	if(ferror(stdin))
		err_sys("input error");
	exit(0);
}
