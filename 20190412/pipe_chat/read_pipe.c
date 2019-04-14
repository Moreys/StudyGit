#include "headFile.h"

int main(int argc,char *argv[])
{
	//定义两个返回值，一个接收一个发送
	//先打开读端
	//检查打开文件是否合法
	//打开写端
	//检测是否合法
	//打印读写段的返回值
	//创建缓冲区
	//读取文件
	//打印读取到的文件
	//写文件
	//返回
	int fdw,fdr;
	fdr = open(argv[1],O_RDONLY);
	fdw = open(argv[2],O_WRONLY);
	printf("fdr = %d,fdw = %d\n",fdr,fdw);
	char buf[128] = {0};
	read(fdr,buf,sizeof(buf));
	printf("%s\n",buf);
	write(fdw,"fdr",3);
	return 0;
}
