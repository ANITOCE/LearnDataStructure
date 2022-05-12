#include "Linear_Stack.h"

void InitStack(SqStack* S)
{
	S->List = (SeqList*)malloc(sizeof(SeqList));   //
	InitList(S->List);
	S->top = -1;
	if (S == NULL)
		printf("�ڴ����ʧ�ܣ�\n");
	else
		printf("��ʼ����ɣ�\n");
}

void Push(SqStack* S, int Elem)
{
	if (S->top == S->List->MaxSize) {
		IncreaseSize(S->List, InitSize);   //��ջ�ռ䲻�㣬�������InitSize(10)�Ŀռ�
	}
	S->top++;
	InsertList(S->List, S->top, Elem);
}

int Pop(SqStack* S)
{
	int Elem = GetTop(S);
	PositionDeleteElem(S->List, S->top);
	S->top--;
	return Elem;
}

int GetTop(SqStack* S)
{
	return S->List->data[S->top];
}
