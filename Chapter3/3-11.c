/*************************************************************************
	> File Name: 3-11.c
	> Author: CuitingLin
	> Mail: agnes2729@sina.com 
	> Created Time: Sun 13 Dec 2015 06:45:50 PM CST
 ************************************************************************/

#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int val;

	if(argc != 2)
		err_quit("usage: a.out <description#>");

	if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
		err_sys("fcntl error for fd %d\n", atoi(argv[1]));

	switch(val & O_ACCMODE)
	{
		case O_RDONLY:
			printf("read only");
			break;

		case O_WRONLY:
			printf("write only");
			break;

		case O_RDWR:
			printf("read write");
			break;

		default:
			err_dump("unknow access mode");
	}

	if(val & O_APPEND)
		printf(", append");

	if(val & O_NONBLOCK)
		printf(", nonblocking");

	if(val & O_SYNC)
		printf(", synchronous writes");

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
	if(val & O_FSYNC)
		printf(", synchronous writes");
#endif
	putchar('\n');

	exit(0);
}
