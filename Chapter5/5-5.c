/*************************************************************************
	> File Name: 5--5.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月16日 星期三 11时27分39秒
 ************************************************************************/
#include "apue.h"

int main(int argc, char *argv[])
{
	if(argc != 3)
		err_quit("usage: a.out <directory><prefix>");
	printf("%s\n", tempnam(argv[1][0] != ' '? argv[1]:NULL, argv[2][0] != ' '?argv[2]:NULL));
	exit(0);
}
