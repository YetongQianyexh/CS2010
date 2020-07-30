//1.打印一个目录下面所有的文件的绝对路径名(目录下面还可能有目录)
#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

//argc 命令行参数个数
//argv 指针数组,每一个成员都是字符指针(char *),指向具体的命令行参数

//print_file_path:打印指定目录下面所有的文件名

void print_file_path(char *dirname)
{
	//打开目录
	DIR *dp = opendir(dirname);
	if(NULL == dp)
	{
		printf("%s",dirname);
		perror("opendir error");
		return;
	}

	//读取打开的目录的目录项
	struct dirent *dirp;
	while(dirp = readdir(dp))	//读取目录项
	{
		//判断读取到的目录项是文件还是目录
		if(strcmp(dirp->d_name,".")==0 || strcmp(dirp->d_name,"..")==0)
		{
			continue;
		}
		//获取文件的路径名
		char filename[128] = {0};
		
		int x = snprintf(filename,128,"%s/%s",dirname,dirp->d_name);
		if (x>=128)
		{
			fprintf(stderr,"bro,filename too length\n");
			return;
		}
		//获取文件属性
		struct stat st;
		stat(filename, &st);
		if(S_ISREG(st.st_mode))	
		{
			printf("filename = %s\n",filename);
			 
		}
		else if(S_ISDIR(st.st_mode))
		{
			printf("filename = %s\n",filename);
			print_file_path(filename);
			//如果目录的层次比较多,可能会造成程序崩溃
			//如:内存不够,文件描述符不够用(打开的目录太多)
			//尝试使用队列的方式去解决
			//如果是目录则入队
		}
	 
	}
	//关闭目录
	closedir(dp);
}

int main(int argc,char *argv[])
{
	if(argc !=2)
	{
		printf("bro, arg num error\n");
		return -1;
	}
	char path[128] = {0};//保存argv[1]的绝对路径
	char cur_path[128] = {0};//保存当前路径
	getcwd(cur_path,128);
	chdir(argv[1]);
	getcwd(path,128);
	chdir(cur_path);
	print_file_path(path);

	return 0;
}