#pragma once
#include<stdio.h>
#include<stdlib.h>
#define InitSize 10

typedef struct{
	int* data;
	int MaxSize;
	int Length;
}SeqList;

void InitList(SeqList* L); //��ʼ����̬���Ա�����ÿ��Ԫ��Ϊ0
void DestryList(SeqList* L);//�������Ա�ռ�õ��ڴ�
void PrintList(SeqList L);//����ÿһ��Ԫ�أ�����ʾ

void InsertList(SeqList* L,int i,int Elem);//����Ԫ�أ�����ѡ�����λ��
int PositionDeleteElem(SeqList* L,int n);//ɾ��ĳһλ�õ�Ԫ��,����ɾ��Ԫ�ص�ֵ
void LocateDeleteElem(SeqList* L, int Elem);//Ѱ��ĳһԪ�ز�ɾ��

bool LocateElem(SeqList* L,int Elem);//��ֵ����
bool PositionElem(SeqList* L,int n);//��λ����

void IncreaseSize(SeqList* L,int len);//�������Ա���ڴ�ռ�
void ReduceSize(SeqList* L);//��⵱ǰ�Ķ���ռ�(5)�Ƿ���У����������ͷŸÿռ䣬������С��InitSize(10)
