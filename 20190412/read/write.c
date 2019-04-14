#include "headFile.h"

//系统调用写入文件
int main(int argc,char *argv[])
{
	ARGS_CHECK(argc,2);
	int fd;
	fd = open(argv[1],O_RDWR);
	ERROR_CHECK(fd,-1,"open");
	printf("fd = %d\n",fd);
	int arr[5] = {1,2,3,4,5};
	int ret;
	//函数功能 将写入文件
	//参数1 文件描述  参数2 要写入的  参数3 写入的大小 
	//出错返回-1 读完返回0 其他情况返回读写的个数
	ret = write(fd,arr,sizeof(arr));
	ERROR_CHECK(fd,-1,"write");
	return 0;
}
