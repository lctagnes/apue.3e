/*************************************************************************
	> File Name: 5-3.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月16日 星期三 10时30分53秒
 ************************************************************************/
#include "apue.h"
void pr_stdio(const char *, FILE *);

int main(void)
{
	FILE *fp;
	fputs("enter any character\n", stdout);
	if(getchar() == EOF)
		err_sys("getchar error");
	fputs("one line to stdout error\n", stderr);

	pr_stdio("stdin", stdin);
	pr_stdio("stdout", stdout);
	pr_stdio("stderr", stderr);

	if((fp = fopen("/etc/mtab", "r")) == NULL)
		err_sys("fopen error");
	if(getc(fp) == EOF)
		err_sys("getc error");
	pr_stdio("/etc/mtab", fp);
	exit(0);
}

void pr_stdio(const char *name, FILE *fp)
{
	printf("stream = %s, ", name);

	if(fp->_IO_file_flags & _IO_UNBUFFERED)
		printf("unbuffered");
	if(fp->_IO_file_flags & _IO_LINE_BUF)
		printf("line buffered");
	else
		printf("fully buffered");
	printf(", buffered size = %d\n", fp->_IO_buf_end - fp->_IO_buf_base);
}
