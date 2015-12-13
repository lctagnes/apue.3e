/*************************************************************************
	> File Name: 3-2.c
	> Author: CuitingLin
	> Mail: agnes2729@sina.com 
	> Created Time: Sun 13 Dec 2015 06:27:16 PM CST
************************************************************************/

#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
	int fd;

	if((fd = creat("file.hole", FILE_MODE)) < 0)
		err_sys("creat error");

	if(write(fd, buf1, 10) != 10)
		err_sys("buf1 write error");

	if(lseek(fd, 15583, SEEK_SET) == -1)
		err_sys("lseek error");

	if(write(fd, buf2, 10) != 10)
		err_sys("buf2 write error");

	exit(0);
}
