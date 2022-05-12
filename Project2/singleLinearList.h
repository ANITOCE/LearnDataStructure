#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
	int data;
	struct LNode* next;
};

void InitList(LNode* L); //初始化第一个节点
LNode InitList();//创建一个链表节点
void PrintList(LNode* L);//显示整个链表

void DeleteNode(LNode* L);//将指定节点在链表中删除
void ReviseNodeElem(LNode* L, int Elem);//修改指定节点中的数据


void InsertList(LNode* L, int n, int Elem);//搜寻指定位置，向其中插入数据
bool InsertNextNode(LNode* L,int Elem);//向指定节点后面插入数据
bool InsertPriorNode(LNode* L,int Elem);//向指定节点前面插入数据

LNode* GetElem(LNode* L, int n);//按下标查找
LNode* LocateElem(LNode* L, int Elem);//按值查找

void List_Tallnesert(LNode* L);//使用尾插法初始化一个有10节点的链表，是每个节点的值位0
void List_HeadInsert(LNode* L);//使用头插法初始化整个链表\

int Length(LNode* L);//求表长