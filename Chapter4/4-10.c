/*************************************************************************
	> File Name: 4-10.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月15日 星期二 18时01分02秒
 ************************************************************************/
#include "apue.h"
#ifdef SOLARIS
#include <sys/mkdev.h>
#endif

int main(int argc, char *argv[])
{
	int i;
	struct stat buf;

	for(i = 1; i < argc; i++)
		{
			printf("%s: ", argv[i]);
			if(stat(argv[i], &buf) < 0)
				{
					err_sys("stat error");
					continue;
				}
			printf("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));
			if(S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
				{
					printf("(%s) rdev = %d/%d", (S_ISCHR(buf.st_mode)) ? "charcter" : "block", major(buf.st_dev), minor(buf.st_dev));
				}
			printf("\n");
		}
	exit(0);
}
