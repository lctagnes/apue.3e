/*************************************************************************
	> File Name: 6-1.c
	> Author: lctagnes
	> Mail: agnes2729@sina.com 
	> Created Time: 2015年12月17日 星期四 15时09分49秒
 ************************************************************************/
#include "apue.h"
#include <pwd.h>
#include <stddef.h>
#include <string.h>

struct passwd * getpwnam(const char *name)
{
	struct passwd *ptr;
	setpwent();
	while((ptr = getpwent()) != NULL)
		if(strcmp(name, ptr->pw_name) == 0)
			break;
	endpwent();
	return ptr;
}

int main(void)
{
	struct passwd *pw;
	char *name = "lct";

	pw = getpwnam(name);
	if(!pw)
	{
		printf("%s is not exist\n", name);
		exit(0);
	}
	printf("pw->pw_name = %s\n", pw->pw_name);
	printf("pw->pw_passwd = %s\n", pw->pw_passwd);
	printf("pw->pw_uid = %d\n", pw->pw_uid);
	printf("pw->pw_gid = %d\n", pw->pw_gid);
	printf("pw->pw_gecos = %s\n", pw->pw_gecos);
	printf("pw->pw_dir = %s\n", pw->pw_dir);
	printf("pw->pw_shell = %s\n", pw->pw_shell);

	return 0;
}
