/*1、定义一个学生结构体类型struct student，里边含有学号，姓名，分数，定义结构体数组struct student s[3],给数组赋初值后，写入文件，然后通过lseek偏移到开头，然后再读取进行打印输出*/
#include "headFile.h"
typedef struct student{
	int id;
	char name[20];
	float score;
}Stu;
int main(int argc,char *argv[])
{
	Stu s[3] = {1001,"lele",98,1002,"momo",99,1003,"hah",66};
	for(int i = 0;i < 3;++i)
	{
		printf("%d %s %f\n",s[i].id,s[i].name,s[i].score);
	}
	int fd;
	fd = open(argv[1],O_RDWR|O_CREAT);
	ERROR_CHECK(fd,-1,"open");
	printf("fd = %d\n",fd);
	int ret;
	ret = write(fd,s,sizeof(s));
	ERROR_CHECK(fd,-1,"write");
	printf("ret = %d\n",ret);	
	lseek(fd,0,SEEK_SET);	
	memset(s,0,sizeof(s));
    ret = read(fd,s,sizeof(s));
    ERROR_CHECK(ret,-1,"read");
	for(int i =0;i < 3; i++)
	{
		printf("%d %s %f\n",s[i].id,s[i].name,s[i].score);
	}
	close(fd);
	return 0;
}
