#include "headFile.h"

int main(int argc,char *argv[])
{
	ARGS_CHECK(argc,2);
	int fd;
	fd = open(argv[1],O_RDWR);
	ERROR_CHECK(fd,-1,"open");
	printf("fd = %d\n",fd);
	char *p;
	struct stat buf;
	fstat(fd,&buf);
	/*mmap 系统调用 功能  读大文件到内存，只给cpu发送一条指令确定是否能进行写入，而具体的写入不经过cpu  写入的时候cpu还可以进行其他的操作
	  函数原型：void* mmap(void* start,size_t length,int prot,int flags,int fd,off_t offset);
	  参数1 映射的开始地址
	  参数2 映射区的长度
	  参数3 期望的内存保护标志
	  参数4 映射对象的的类型
	  参数5 有效的文件描述词
	  参数6 被映射对象内容的起点
	 */
	p = (char*)mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	ERROR_CHECK(p,-1,"mmap");
	strcpy(p,"HELLO");
	munmap(p,buf.st_size);
	return 0;
}
