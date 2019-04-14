#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int ElemType;
#define N 10
typedef struct Student
{
	ElemType id;
	struct Student *pNext;
}Stu,*pStu;

//遍历链表
void foreachLink(pStu pHead);
//插入节点头插
void insterHead(pStu *ppHead,pStu *ppTail);
//插入节点尾插
void inserTail(pStu *ppHead,pStu *ppTail);
//有序插入
void inserOrder(pStu *ppHead,pStu *ppTail);

//删除节点 
void deleteNode(pStu pHead,int val);
//清空链表
void clearLink(pStu pHead);
//销毁链表
void destoryLink(pStu pHead);
//链表逆置
void reverLink(pStu pHead);
//查找链表中点
void findMid(pStu pHead);

//是否有环
void isHaveloop(pStu pHead);
//倒数第几个元素
void lastNode(pStu pHead);
//两个聊表的公共元素
void commNode(pStu linkOne,pStu linkTwo);
//求两个链表的交点
void intersetNode(pStu linkOne,pStu linkTwo);


