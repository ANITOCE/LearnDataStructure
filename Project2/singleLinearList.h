#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef char LNodeType;

typedef struct LNode{
	LNodeType data;
	LNode* next;
};

LNode InitList(LNode* L); //��ʼ����һ���ڵ�
LNode InitList();//����һ������ڵ�
void PrintList(LNode* L);//��ʾ��������

void DeleteNode(LNode* L);//��ָ���ڵ���������ɾ��
void ReviseNodeElem(LNode* L, LNodeType Elem);//�޸�ָ���ڵ��е�����


void InsertList(LNode* L, int n, LNodeType Elem);//��Ѱָ��λ�ã������в�������
bool InsertNextNode(LNode* L, LNodeType Elem);//��ָ���ڵ�����������
bool InsertPriorNode(LNode* L, LNodeType Elem);//��ָ���ڵ�ǰ���������

LNode* GetElem(LNode* L, int n);//���±����
LNode* LocateElem(LNode* L, LNodeType Elem);//��ֵ����

void List_Tallnesert(LNode* L);//ʹ��β�巨��ʼ��һ����10�ڵ��������ÿ���ڵ��ֵλ0
void List_HeadInsert(LNode* L);//ʹ��ͷ�巨��ʼ����������\

int Length(LNode* L);//���