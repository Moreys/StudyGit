#include "headFile.h"

int main(int argc,char *argv[])
{
	//检查参数是否合法
	//定义两个变量 存储读写返回值
	//打开写端
	//检查合法性
	//打开读端 
	//检查合法性
	//打印读写段返回值
	//写消息
	//定义接收数组
	//开始读消息
	//打印读取到的消息
	//返回
	int fdw,fdr;
	fdw = open(argv[1],O_WRONLY);
	fdr = open(argv[2],O_RDONLY);
	printf("fdw = %d,fdr = %d\n",fdw,fdr);
    write(fdw,"fdw",3);
	char buf[128] = {0};
    read(fdr,buf,sizeof(buf));
	printf("%s\n",buf);
	return 0;
}


