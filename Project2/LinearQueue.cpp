#include "LinearQueue.h"

void InitQueue(SqQueue* Q)
{
	Q->Data = (SeqList*)malloc(sizeof(SeqList));
	InitList(Q->Data);
	Q->front = Q->rear = 0; 
}

void EnQueue(SqQueue* Q, int Elem)
{
	InsertList(Q->Data, Q->rear, Elem);
	Q->rear += 1;
}

int OutQueue(SqQueue* Q)
{
	int Elem = PositionDeleteElem(Q->Data, Q->rear - 1);
	Q->front += 1;
	return Elem;
	
}
