#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef char LNodeType;

typedef struct LNode{
	LNodeType data;
	LNode* next;
};

LNode InitList(LNode* L); //初始化第一个节点
LNode InitList();//创建一个链表节点
void PrintList(LNode* L);//显示整个链表

void DeleteNode(LNode* L);//将指定节点在链表中删除
void ReviseNodeElem(LNode* L, LNodeType Elem);//修改指定节点中的数据


void InsertList(LNode* L, int n, LNodeType Elem);//搜寻指定位置，向其中插入数据
bool InsertNextNode(LNode* L, LNodeType Elem);//向指定节点后面插入数据
bool InsertPriorNode(LNode* L, LNodeType Elem);//向指定节点前面插入数据

LNode* GetElem(LNode* L, int n);//按下标查找
LNode* LocateElem(LNode* L, LNodeType Elem);//按值查找

void List_Tallnesert(LNode* L);//使用尾插法初始化一个有10节点的链表，是每个节点的值位0
void List_HeadInsert(LNode* L);//使用头插法初始化整个链表\

int Length(LNode* L);//求表长