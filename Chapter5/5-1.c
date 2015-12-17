/*************************************************************************
	> File Name: 5-1.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月16日 星期三 10时12分15秒
 ************************************************************************/
#include "apue.h"
int main(void)
{
	int c;
	while((c = fgetc(stdin)) != EOF)
	{
		if(fputc(c, stdout) == EOF)
			err_sys("output error");
	}
	if(ferror(stdin))
		err_sys("input error");
	exit(0);
}
