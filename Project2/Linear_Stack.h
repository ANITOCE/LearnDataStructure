#pragma once
#include<stdio.h>
#include<stdlib.h>

#include"LinearList.h" //���ջ�ǻ��ڶ�̬�������Ա�ʵ�ֵ�


typedef struct{
	SeqList* List;
	int top;
}SqStack;

void InitStack(SqStack* S);//��ʼ��ջ
void DestoryStack(SqStack* S);//����ջ���ڴ�ռ�

void Push(SqStack* S, int Elem);//��ָ��Ԫ����ջ
int Pop(SqStack* S);//��ջ��Ԫ�س�ջ��������

int GetTop(SqStack* S);//����ջ��Ԫ�ص�ֵ�������޸�
