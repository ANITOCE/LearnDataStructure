#include"LinearList.h"   //这个队列是基于动态线性表实现的

typedef struct {
	SeqList* Data;
	int front;    //队头
	int rear;     //队尾  指向的最后一个元素的下一位，相关操作应 - 1
}SqQueue;

void InitQueue(SqQueue* Q);  //初始化一个队列

void EnQueue(SqQueue* Q, int Elem);  //将一个元素入队

int OutQueue(SqQueue* Q);  //将队尾元素出队


