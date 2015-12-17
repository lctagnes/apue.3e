/*************************************************************************
	> File Name: 5-4.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月16日 星期三 11时06分10秒
 ************************************************************************/
#include "apue.h"

int main(void)
{
	char name[L_tmpnam], line[MAXLINE];
	FILE *fp;

	printf("%s\n",tmpnam(NULL));
	
	tmpnam(name);
	printf("%s\n", name);

	if((fp = tmpfile()) == NULL)
		err_sys("tmpfile error");
	fputs("one line of output\n", fp);
	rewind(fp);
	if(fgets(line, sizeof(line), fp) == NULL)
		err_sys("fgets error");
	fputs(line, stdout);
	exit(0);
}
