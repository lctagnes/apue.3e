/*************************************************************************
	> File Name: 1-8.c
	> Author: CuitingLin
	> Mail: agnes2729@sina.com 
	> Created Time: Sun 13 Dec 2015 05:34:52 PM CST
 ************************************************************************/

#include "apue.h"
#include <errno.h>

int main(int argc, char *argv[])
{
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);
	exit(0);
}
