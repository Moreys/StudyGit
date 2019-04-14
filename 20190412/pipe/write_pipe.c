#include "headFile.h"

int main(int argc,char *argv[])
{
	//检查参数是否合法
	if(argc != 2)
	{
		printf("error argc");
		return -1;
	}
	//定义文件返回承接
	//打开文件
	//检查是否合法
	//打印一下返回的参数
	//等待3秒
	//写文件
	//返回
	int fd;
	fd = open(argv[1],O_RDWR|O_CREAT,0666);
	if(fd  == -1)
	{
		perror("open");
		return -1;
	}
	printf("%d\n",fd);
	sleep(3);
	write(fd,"hello",5);
	return 0;
}
