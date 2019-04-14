#include "headFile.h"

//制造文件空洞洞
int main(int argc,char *argv[])
{
	ARGS_CHECK(argc,2);
	int fd;
	fd = open(argv[1],O_RDWR);
	ERROR_CHECK(fd,-1,"open");
	printf("%d\n",fd);
	int ret;
	//lseek 文件偏移 
	//参数1 要偏移的文件名 ，参数2 偏移的数量，参数3 要偏移的位置
	//返回偏移的数量
	//通常用于多进程通信的时候的共享内存
	ret = lseek(fd,1024,SEEK_SET);
	printf("lseek ret = %d\n",ret);
	char c = 'H';
	//写入文件一个文件，为结束标志符
	write(fd,&c,sizeof(c));
	close(fd);
	return 0;
}
