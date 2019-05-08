#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
forkдʱ���ƣ�
  дʱ���Ƽ������ں�ֻΪ�����ɵ��ӽ��̴�������ռ�ṹ�������������ڸ����̵����⾿���ṹ��
  ���ǲ�Ϊ��Щ�η��������ڴ棬���ǹ������̵�����ռ䣬�����ӽ������и�����Ӧ�ε���Ϊ����ʱ��
  ��Ϊ�ӽ�����Ӧ�Ķη�������ռ䡣
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