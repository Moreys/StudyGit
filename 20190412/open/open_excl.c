#include "headFile.h"

int main(int argc,char *argv[])
{
	ARGS_CHECK(argc,2);
	int fd;
	//打开文件三个三叔
	//参数1 文件名，参数2 打开方式， 参数3 权限会受到掩码的影响
	fd = open(argv[1],O_RDONLY|O_CREAT|O_EXCL,0600);
	ERROR_CHECK(fd,-1,"open");
	printf("fd = %d\n",fd);
	return 0;
}
