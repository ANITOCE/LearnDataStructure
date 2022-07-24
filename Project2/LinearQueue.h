#include"LinearList.h"   //这个队列是基于动态线性表实现的
#include"singleLinearList.h"

typedef struct {
	SeqList* Data;
	int front;    //队头
	int rear;     //队尾  指向的最后一个元素的下一位，相关操作应 - 1
}SqQueue;

typedef struct {  //这个队列是基于单链表实现的
	LNode* front;
	LNode* rear;
}singleListQueue;

SqQueue InitQueue(SqQueue* Q);  //初始化一个队列
void EnQueue(SqQueue* Q, SeqListType Elem);  //将一个元素入队
SeqListType OutQueue(SqQueue* Q);  //将队尾元素出队

singleListQueue InitQueue(singleListQueue* Q);
void EnQueue(singleListQueue* Q, LNodeType Elem);
LNodeType OutQueue(singleListQueue* Q);
bool isEmpty(singleListQueue* Q);
