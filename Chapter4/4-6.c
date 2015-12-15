/*************************************************************************
	> File Name: 4-6.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月15日 星期二 15时37分46秒
 ************************************************************************/
#include "apue.h"
#include <fcntl.h>
#include <utime.h>

int main(int argc, char *argv[])
{
	int i, fd;
	struct stat statbuf;
	struct utimbuf timebuf;

	for(i = 1; i < argc; i++)
	{
		if(stat(argv[i], &statbuf) < 0)
		{
			err_ret("%s: stat error", argv[i]);
			continue;
		}
		if((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0)
		{
			err_ret("%s: open error", argv[i]);
			continue;
		}
		close(fd);
		timebuf.actime = statbuf.st_atime;
		timebuf.modtime = statbuf.st_mtime;
		if(utime(argv[i], &timebuf) < 0)
		{
			err_ret("%s: utime error", argv[i]);
			continue;
		}
	}
	exit(0);
}
