#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	printf("hello\n"); //只打印一次
	int a;
	pid_t pid = fork();
	//下面的代码就有两个进程在执行
	if(pid > 0)
	{
		printf("i am father\n");
		while(1)
		{
			printf("hello\n");
			sleep(1);
		}
		wait(NULL);
		//&a
	}else if(pid == 0)
	{
		printf("i am son\n");
		//&a
		while(1)
		{
			printf("word\n");
			sleep(1);
		}
	}
	return 0;
}

