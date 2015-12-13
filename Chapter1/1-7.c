/*************************************************************************
	> File Name: 1-7.c
	> Author: CuitingLin
	> Mail: agnes2729@sina.com 
	> Created Time: Sun 13 Dec 2015 04:53:38 PM CST
 *************************************************************************/

#include "apue.h"
#include <sys/wait.h>

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	printf("%% ");
	while(fgets(buf, MAXLINE, stdin) != NULL)
	{
		if(buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;

		if((pid = fork()) < 0)
		{				
			err_sys("fork error");
		}else if(pid == 0){		
			execlp(buf, buf, (char *)0);
			err_ret("couldn't execute:%s", buf);
			exit(127);
		}

		
		if((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");
		printf("%% ");
	}

	exit(0);
}
