/*************************************************************************
	> File Name: 4-7.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月15日 星期二 16时49分17秒
 ************************************************************************/

#include "apue.h"
#include <dirent.h>
#include <limits.h>

typedef int Myfunc(const char*, const struct stat*, int);
static Myfunc myfunc;
static int myftw(const char*, Myfunc*);
static int dopath(Myfunc*);
static long nreg, ndir, nblk, nfifo, nchr, nlink, nsock, nnum;
static char *fullpath;
const int PATH_LEN = 1024;
#define FTW_F 1
#define FTW_D 2
#define FTW_DNR 3
#define FTW_NS 4

int main(int argc, char *argv[])
{
	int ret;
	
	if(argc != 2)
		fprintf(stderr, "Usage: ftw <starting-pathname>\n");
	
	ret = myftw(argv[1], myfunc);
	nnum = nreg + ndir + nblk + nfifo + nchr + nlink + nsock;
	
	printf("reglar file = %7ld\n", nreg);
	printf("directory file = %7ld\n", ndir);
	printf("block file = %7ld\n", nblk);
	printf("char file = %7ld\n", nchr);
	printf("FIFO file = %7ld\n", nfifo);
	printf("link file = %7ld\n", nlink);
	printf("socket file = %7ld\n", nsock);
	printf("total file = %7ld\n", nnum);

	return ret;
	
}


static int myftw(const char *pathname , Myfunc *func)
{
	int res;
	fullpath = (char *)malloc(PATH_LEN);
	strncpy(fullpath, pathname, PATH_LEN);
	fullpath[PATH_LEN - 1] = '\0';
	res = dopath(func);

	free(fullpath);
	return res;
}

static int dopath(Myfunc *func)
{
	struct stat statbuf;
	struct dirent *dirp;

	DIR *dp;
	int ret;
	char *ptr;

	int temp;
	
	temp = lstat(fullpath, &statbuf);
	if(temp < 0)
		{
			return func(fullpath, &statbuf, FTW_NS);
		}
	
	temp = S_ISDIR(statbuf.st_mode);
	if(temp == 0)
	{
		return func(fullpath, &statbuf, FTW_F);
	}
	
	ret = func(fullpath, &statbuf, FTW_D);
	if(ret != 0)
		return ret;
	
	ptr = fullpath + strlen(fullpath);
	*ptr++ = '/';
	*ptr = 0;

	dp = opendir(fullpath);
	if(NULL == dp)
		return func(fullpath, &statbuf, FTW_DNR);
	
	while((dirp = readdir(dp)) != NULL)
	{
		if(strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
			continue;
		strcpy(ptr, dirp->d_name);
		ret = dopath(func);
		if(ret!= 0)
			break;
	}

	ptr[-1] = 0;
	if(closedir(dp) < 0)
	{	
		fprintf(stderr, "can't close directory %s\n", fullpath);
	}
	return ret;
}

static int myfunc(const char *pathname, const struct stat *statptr, int type)
{
	switch(type)
	{
		case FTW_F:
			switch(statptr->st_mode & S_IFMT)
			{
				case S_IFREG:
					nreg++;
					printf("reg:%s\n", fullpath);
					break;
				case S_IFBLK:
					nblk++;
					printf("blk:%s\n", fullpath);
					break;
				case S_IFCHR:
					nchr++;
					printf("chr:%s\n", fullpath);
					break;
				case S_IFIFO:
					nfifo++;
					printf("fifo:%s\n", fullpath);
					break;
				case S_IFLNK:
					nlink++;
					printf("link:%s\n", fullpath);
					break;
				case S_IFSOCK:
					nsock++;
					printf("sock:%s\n", fullpath);
					break;
				case S_IFDIR:
					fprintf(stderr, "for S_IFDIR for %s\n", pathname);
					exit(1);
			}
			break;
		case FTW_D:
			ndir++;
			printf("dir:%s\n", fullpath);
			break;
		case FTW_DNR:
			fprintf(stderr, "can't read directory %s\n", pathname);
			break;
		case FTW_NS:
			fprintf(stderr, "stat error %s\n", pathname);
			break;
		default:
			fprintf(stderr, "unknown type %d for pathname %s\n", type, pathname);
	}
	return 0;
}