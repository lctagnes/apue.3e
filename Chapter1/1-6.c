#include "apue.h"
int main(void)
{
	printf("hello apue from process ID %d\n", getpid());
	exit(0);
}
