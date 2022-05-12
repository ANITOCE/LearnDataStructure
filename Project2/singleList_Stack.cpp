#include"singleList_Stack.h"

void S_InitStack(SqStack* S)
{
	S->node = (LNode*)malloc(sizeof(LNode));
	InitList(S->node);
	S->node->next = NULL;
	S->top = S->node;
	if (S == NULL)
		printf("�ڴ����ʧ�ܣ�\n");
	else
		printf("��ʼ����ɣ�\n");
}

void S_Push(SqStack* S,int Elem)
{
	if (InsertNextNode(S->top, Elem))
		S->top = LocateElem(S->node, Elem);//ָ���²�������һ���ڵ�
	else
		printf("�������\n"); 
	
}

LNode* S_Pop(SqStack* S)
{
	LNode* p = S->top;
	DeleteNode(S->top);     ///???????????     �������޷�ɾ��ָ���ڵ�
	
	return p;
}

int S_GetTop(SqStack* S)
{
	return S->top->data;
}

