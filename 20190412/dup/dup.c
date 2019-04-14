#include<headFile.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	inf fd,fd1;
	fd = open(argv[1],O_RDWR);
	fd1 = dup(fd);
	printf("fd1 = %d\n",fd1);
	close(fd);//关闭文件
	char buf[128] = {0};
	int ret;
	ret = read(fd1,buf,sizeof(buf));
	printf("ret = %d,buf = %s\n",ret,buf);
	return 0;
}
