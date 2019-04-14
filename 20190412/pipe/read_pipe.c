#include "headFile.h"

int main(int argc,char *argv[])
{
	//int fd;
	//定义文件打开的返回值
	//打开文件
	//检查打开文件是否合法
	//打印返回值
	//创建缓冲区
	//读取文件
	//打印读取到的文件
	int fd;
	fd = open(argv[1],O_RDWR|O_CREAT,0666);
	printf("%d\n",fd);
	char buf[128] = {0};
	fd = read(fd,buf,5);
	printf("%s\n",buf);
	return 0;
}
