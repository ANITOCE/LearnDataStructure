#pragma once
#include"singleLinearList.h"  //���ջ�ǻ��ڵ�����ʵ�ֵ�

typedef struct {
	struct LNode* node;   //��ջ�еĴ�ȡ���ݵĽڵ㣬�����ɵ�����
	LNode* top;   //��Զָ����������һ���ڵ�
}SqStack;


void S_InitStack(SqStack* S);//��ʼ��ջ
void S_DestoryStack(SqStack* S);//����ջ���ڴ�ռ�

void S_Push(SqStack* S, int Elem);//��ָ��Ԫ����ջ
LNode* S_Pop(SqStack* S);//��ջ��Ԫ�س�ջ��������

int S_GetTop(SqStack* S);//����ջ��Ԫ�ص�ֵ�������޸�


