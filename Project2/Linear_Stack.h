#pragma once
#include<stdio.h>
#include<stdlib.h>

#include"LinearList.h" //这个栈是基于动态分配线性表实现的


typedef struct{
	SeqList* List;
	int top;
}SqStack;

void InitStack(SqStack* S);//初始化栈
void DestoryStack(SqStack* S);//销毁栈的内存空间

void Push(SqStack* S, int Elem);//将指定元素入栈
int Pop(SqStack* S);//将栈顶元素出栈，并返回

int GetTop(SqStack* S);//返回栈顶元素的值，不做修改
