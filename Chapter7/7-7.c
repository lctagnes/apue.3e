/*************************************************************************
	> File Name: 7-7.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月17日 星期四 16时44分55秒
 ************************************************************************/
#include <stdio.h>
#include "apue.h"
#define DATAFILE "datafile"

FILE *open_data(void)
{
	FILE *fp;
	char databuf[BUFSIZ];

	if((fp = fopen(DATAFILE, "r")) == NULL)
		return NULL;
	if(setvbuf(fp, databuf, _IOLBF, BUFSIZ) != 0)
		return NULL;
	return fp;
}

int main(void)
{
	FILE *fp;
	fp = open_data();
	return 0;
}
