#include "LinearQueue.h"

SqQueue InitQueue(SqQueue* Q)
{
	Q->Data = (SeqList*)malloc(sizeof(SeqList));
	InitList(Q->Data);
	Q->front = Q->rear = 0; 
	return *Q;
}

void EnQueue(SqQueue* Q, SeqListType Elem)
{
	InsertList(Q->Data, Q->rear, Elem);
	Q->rear += 1;
}

SeqListType OutQueue(SqQueue* Q)
{
	SeqListType Elem = PositionDeleteElem(Q->Data, Q->rear - 1);
	Q->front += 1;
	return Elem;
	
}

singleListQueue InitQueue(singleListQueue* Q)
{
	Q = (singleListQueue*)malloc(sizeof(singleListQueue));
	LNode List = InitList(&List);
	Q->front = Q->rear = &List;
	return *Q;
}

void EnQueue(singleListQueue* Q, LNodeType Elem)
{
	InsertNextNode(Q->rear, Elem);
	isEmpty(Q) ? Q->front = Q->rear = Q->rear->next : Q->rear = Q->rear->next;
}

LNodeType OutQueue(singleListQueue* Q)
{
	if (isEmpty(Q))
		return NULL;
	LNodeType outData = Q->front->data;
	if (Q->front == Q->rear) {
		Q->front->data = NULL;
		Q->rear->data = NULL;
		return outData;
	}
	LNode* outNode = Q->front;
	Q->front = Q->front->next;
	//free(outNode);
	return outData;
}

bool isEmpty(singleListQueue* Q)
{
	if (Q->front == Q->rear && Q->front->data == NULL)
		return true;
	return false;
}

