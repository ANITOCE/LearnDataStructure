#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode* next;
};

void InitList(LNode* L); //��ʼ����һ���ڵ�
LNode InitList();//����һ������ڵ�
void PrintList(LNode* L);//��ʾ��������

void DeleteNode(LNode* L);//��ָ���ڵ���������ɾ��
void ReviseNodeElem(LNode* L, int Elem);//�޸�ָ���ڵ��е�����


void InsertList(LNode* L, int n, int Elem);//��Ѱָ��λ�ã������в�������
bool InsertNextNode(LNode* L,int Elem);//��ָ���ڵ�����������
bool InsertPriorNode(LNode* L,int Elem);//��ָ���ڵ�ǰ���������

LNode* GetElem(LNode* L, int n);//���±����
LNode* LocateElem(LNode* L, int Elem);//��ֵ����

void List_Tallnesert(LNode* L);//ʹ��β�巨��ʼ��һ����10�ڵ��������ÿ���ڵ��ֵλ0
void List_HeadInsert(LNode* L);//ʹ��ͷ�巨��ʼ����������\

int Length(LNode* L);//���