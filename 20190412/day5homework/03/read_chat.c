#include "headFile.h"
#include <sys/select.h>
#include <sys/time.h>

int main(int argc,char *argv[])
{
	//先读段则进行先读操作，打开的文件类型也是一样的，先读打开只读文件，后写则打开只写文件
	//创建一个接收的数组
	//循环读取和发送
	//每次读取和写入都要情况缓冲区 
	//每次读取以后都要打印
	int fdw,fdr;
	fdr = open(argv[1],O_RDONLY);
	ERROR_CHECK(fdr,-1,"open");
	fdw = open(argv[2],O_WRONLY);
	ERROR_CHECK(fdw,-1,"open");
	printf("%d %d\n",fdr,fdw);
	char buf[128] = {0};
	/*运用I/O多路转接模型实现即时通讯不受发送次数的限制
	  使用select接口int select(int maxfdp, fd_set *readset, fd_set *writeset, fd_set *exceptset,struct timeval *timeout);
	1、定义需要的fd_set
	2、定义timeval类型
	3、定义承接的返回值
	  */
	fd_set readset;
	int ret;
	struct timeval time;
	while(1)
	{
		//先初始化fd
		//增加两个set 一个用来监控 一个用来接收
		//初始化检测时间
		//设置等待时间
		//使用select进行监控
		//判断是否超时
		  //超时  再次判断接收端在线是否是fd有设置
					//在线
			//初始化数组，
		//开始接收
		//接收的时候判断是否断开，断开则退出，
		//打印接收到的结果
		//判断是否超时，，
		//重置数组
		//开始读取是否还有消息
		//没有消息则检测是否写入
		//判断是否断开，
		//断开则跳出
		//另一种情况则提示超时
		//关闭写文件
		//关闭读文件
		//返回
		FD_ZERO(&readset);
		FD_SET(STDIN_FILENO,&readset);
		FD_SET(fdr,&readset);
		memset(&time,0,sizeof(time));
		time.tv_sec = 3;//设置等待时间，不然就一直打印后面的
		ret = select(fdr+1,&readset,NULL,NULL,&time);
		if(ret > 0)
		{
			if(FD_ISSET(fdr,&readset))//判断是否有数据 有数据进行操作
			{
				memset(buf,0,sizeof(buf));
				ret = read(fdr,buf,sizeof(buf));
				if(0 == ret)
				{
					printf("等待输入");
					break;	
				}
				printf("%s\n",buf);
			}
			if(FD_ISSET(0,&readset))//没有数据的时候进行  没有数据还有两种情况，一种是断开，一种是等待输入
			{
				memset(buf,0,sizeof(buf));
				ret = read(0,buf,sizeof(buf));
				if(0 == ret)//看看是否断开
				{
					printf("断开，再见");
					break;
				}
				write(fdw,buf,strlen(buf) -1);
			}
		}
		else
		{
			printf("超时");
		}
	}
	close(fdr);
	close(fdw);
	return 0;
}
				
		
