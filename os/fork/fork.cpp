#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
fork写时复制：
  写时复制技术：内核只为新生成的子进程创建虚拟空间结构，它们来复制于父进程的虚拟究竟结构，
  但是不为这些段分配物理内存，它们共享父进程的物理空间，当父子进程中有更改相应段的行为发生时，
  再为子进程相应的段分配物理空间。
*/
int gloab = 6;
void fork_test() {
	printf("pid=%d\n", getpid());
	printf("before fork \n");

	pid_t pid;
	int var = 88;
	if ((pid = fork()) < 0)
	{
		printf("fork error\n");
	}
	else if (pid == 0)
	{
		gloab++;
		var++;
	}
	else
	{
		sleep(2);
	}

	if (pid == 0)
	{
		printf("this is child\n");
		printf("pid=%d gloab=%d var=%d\n", getpid(), gloab, var);
	}
	else
	{
		printf("pid=%d gloab=%d var=%d\n", getpid(), gloab, var);
	}

	exit(0);
}