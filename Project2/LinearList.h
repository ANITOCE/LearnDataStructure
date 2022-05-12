#pragma once
#include<stdio.h>
#include<stdlib.h>
#define InitSize 10

typedef struct{
	int* data;
	int MaxSize;
	int Length;
}SeqList;

void InitList(SeqList* L); //初始化动态线性表，；令每个元素为0
void DestryList(SeqList* L);//销毁线性表占用的内存
void PrintList(SeqList L);//遍历每一个元素，并显示

void InsertList(SeqList* L,int i,int Elem);//插入元素，可以选择插入位置
int PositionDeleteElem(SeqList* L,int n);//删除某一位置的元素,返回删除元素的值
void LocateDeleteElem(SeqList* L, int Elem);//寻找某一元素并删除

bool LocateElem(SeqList* L,int Elem);//按值查找
bool PositionElem(SeqList* L,int n);//按位查找

void IncreaseSize(SeqList* L,int len);//增加线性表的内存空间
void ReduceSize(SeqList* L);//检测当前的额外空间(5)是否空闲，若空闲则释放该空间，但不会小于InitSize(10)
