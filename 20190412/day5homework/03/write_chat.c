#include <headFile.h>
int main(int argc,char *argv[])
{
	int fdw,fdr;
	fdw = open(argv[1],O_WRONLY);
	ERROR_CHECK(fdw,-1,"open");
	fdr = open(argv[2],O_RDONLY);
	ERROR_CHECK(fdr,-1,"open");
	printf("%d%d\n",fdw,fdr);
	char buf[128] = {0};
	fd_set readset;
	int ret;
	while(1)
	{
		//清空
		//默认先读一遍，从当前位置读 0
		//开始写
		//重新清空
		//再次读
		//打印
		FD_ZERO(&readset);
		FD_SET(STDIN_FILENO,&readset);
		FD_SET(fdr,&readset);
		ret = select(fdr + 1,&readset,NULL,NULL,NULL);
		if(ret>0)
		{
			if(FD_ISSET(fdr,&readset))
			{
				memset(buf,0,sizeof(buf));
				ret = read(fdr,buf,sizeof(buf));//这里一开始也要检测对方是否有数据发过来，有的话进行处理
				if(0 == ret)
				{
					printf("退出");
					break;
				}
				printf("%s\n",buf);
			}
			if(FD_ISSET(0,&readset))
			{
				memset(buf,0,sizeof(buf));
				ret =read(0,buf,sizeof(buf));
				if(0 == ret)
				{
					printf("断开");
					break;
				}
				write(fdw,buf,strlen(buf)-1);
			}
		}
	}
	close(fdr);
	close(fdw);
	return 0;
}

