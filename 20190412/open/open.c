#include "headFile.h"

int main(int argc, char *argv[])
{
	ARGS_CHECK(argc,2);
	int fd;
	//打开文件
	//参数1 文件名  参数2 打开方式，有好多种
	/*
	   打开方式有10种 常用的有
	   O_RDONLY 只读打开
	   O_WRONLY 只写打开
	   O_RDWR 读写方式打开
	   O_CRETA 文件不存在则创建
	   O_APPEND 将文件长度置为0  没有打开也会置空  
	   O_NONBLOCK 非阻塞打开

	   */
	fd = open(argv[1],O_RDONLY|O_CREAT);
	ERROR_CHECK(fd,-1,"open");
	printf("fd = %d\n",fd);
	return 0;
}

