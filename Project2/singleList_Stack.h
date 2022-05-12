#pragma once
#include"singleLinearList.h"  //这个栈是基于单链表实现的

typedef struct {
	struct LNode* node;   //链栈中的存取数据的节点，将构成单链表
	LNode* top;   //永远指向链表的最后一个节点
}SqStack;


void S_InitStack(SqStack* S);//初始化栈
void S_DestoryStack(SqStack* S);//销毁栈的内存空间

void S_Push(SqStack* S, int Elem);//将指定元素入栈
LNode* S_Pop(SqStack* S);//将栈顶元素出栈，并返回

int S_GetTop(SqStack* S);//返回栈顶元素的值，不做修改


