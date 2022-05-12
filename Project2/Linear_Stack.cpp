#include "Linear_Stack.h"

void InitStack(SqStack* S)
{
	S->List = (SeqList*)malloc(sizeof(SeqList));   //
	InitList(S->List);
	S->top = -1;
	if (S == NULL)
		printf("内存分配失败！\n");
	else
		printf("初始化完成！\n");
}

void Push(SqStack* S, int Elem)
{
	if (S->top == S->List->MaxSize) {
		IncreaseSize(S->List, InitSize);   //若栈空间不足，额外分配InitSize(10)的空间
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
