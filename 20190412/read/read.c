#include "headFile.h"

int main(int argc, char *argv[])
{
	ARGS_CHECK(argc,2);
	int fd;
	fd = open(argv[1],O_RDONLY);
	ERROR_CHECK(fd,-1,"open");
	printf("fd = %d\n",fd);
	char buf[128] = {0};
	int ret;
	//函数功能 读文件 
	/*
	   参数1 文件，参数2 读取到的位置，参数3 每次读取的大小
	   返回：返回字节数 
	   成功为非负数
	   失败为：-1 
	   读完了为0
	   */
	ret = read(fd,buf,sizeof(buf));
	ERROR_CHECK(ret,-1,"read");
	printf("buf = %s\n",buf);
	return 0;
}

