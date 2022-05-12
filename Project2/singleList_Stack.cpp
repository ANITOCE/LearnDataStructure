#include"singleList_Stack.h"

void S_InitStack(SqStack* S)
{
	S->node = (LNode*)malloc(sizeof(LNode));
	InitList(S->node);
	S->node->next = NULL;
	S->top = S->node;
	if (S == NULL)
		printf("内存分配失败！\n");
	else
		printf("初始化完成！\n");
}

void S_Push(SqStack* S,int Elem)
{
	if (InsertNextNode(S->top, Elem))
		S->top = LocateElem(S->node, Elem);//指向新插入的最后一个节点
	else
		printf("插入错误！\n"); 
	
}

LNode* S_Pop(SqStack* S)
{
	LNode* p = S->top;
	DeleteNode(S->top);     ///???????????     链表函数无法删除指定节点
	
	return p;
}

int S_GetTop(SqStack* S)
{
	return S->top->data;
}

