#pragma once
#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
typedef char SeqListType;

typedef struct{
	SeqListType* data;
	int MaxSize;
	int Length;
}SeqList;

void InitList(SeqList* L); //��ʼ����̬���Ա�����ÿ��Ԫ��Ϊ0
void DestryList(SeqList* L);//�������Ա�ռ�õ��ڴ�
void PrintList(SeqList L);//����ÿһ��Ԫ�أ�����ʾ
bool isEmpty(SeqList L); //�п�

void InsertList(SeqList* L,int i, SeqListType Elem);//����Ԫ�أ�����ѡ�����λ��
SeqListType PositionDeleteElem(SeqList* L,int n);//ɾ��ĳһλ�õ�Ԫ��,����ɾ��Ԫ�ص�ֵ
void LocateDeleteElem(SeqList* L, SeqListType Elem);//Ѱ��ĳһԪ�ز�ɾ��

bool LocateElem(SeqList* L, SeqListType Elem);//��ֵ����
bool PositionElem(SeqList* L,int n);//��λ����

void IncreaseSize(SeqList* L,int len);//�������Ա���ڴ�ռ�
void ReduceSize(SeqList* L);//��⵱ǰ�Ķ���ռ�(5)�Ƿ���У����������ͷŸÿռ䣬������С��InitSize(10)
