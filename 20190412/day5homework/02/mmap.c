/*2、新建一个文件，里边内容为hello，通过mmap映射该文件后，修改hello为world，然后解除映射*/
#include "headFile.h"

int main(int argc,char *argv[])
{
	ARGS_CHECK(argc,2);
	int fd;
	fd = open(argv[1],O_RDWR|O_CREAT,0666);
	ERROR_CHECK(fd,-1,"open");
	printf("fd = %d\n",fd);
	ftruncate(fd,4096);//给文件分配大小
	char *p = NULL;//通过指针进行读取文件
	struct stat buf;
	fstat(fd,&buf);
	p = (char*)mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);//进行文件映射，
	ERROR_CHECK(p,(char*)-1,"mmap");
	memcpy(p,"word",5);//通过拷贝将需要改变的字符拷贝到之前的地方去
	munmap(p,buf.st_size);//接触映射s
	return 0;
}
