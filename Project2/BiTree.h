#pragma once
#include<stdio.h>
#include<stdlib.h>
//��������� �ǻ�������ʵ�ֵģ���Լ�˴洢�ռ䣬����˱���Ч��

typedef struct BiTNode {
	int data;
	BiTNode* left_child, * right_child;
};

typedef struct ThreadNode {
	BiTNode Node;
	int left_tag, right_tag;    //ʹ��tag��¼���н������ָ���Ƿ�ָ��������0ָ���ӽڵ㣬1ָ������
};

typedef struct singleList {
	BiTNode node;
	singleList* next;
};

typedef struct Queue {  // ���������Ƕ�׵�����ʵ�ֵģ��ڲ�α����У����е�Ԫ�ظ���δ֪��ʹ��������ڴ洢
	singleList* front;//��ͷָ��
	singleList* rear;//��βָ�� 
};

BiTNode InitNode(BiTNode* node);//��ʼ�����еĽڵ�,����ָ��ΪNULL������Ϊ0
BiTNode InitNode(BiTNode* node, int Elem);//��ʼ�����еĽڵ㣬��������ΪElem
void ReviseBiTNode(BiTNode* node, int Elem);//�޸�ָ���ڵ��е�����
void left_LinkBitNode(BiTNode* node,BiTNode* child_node);//�ڵ�chile_node�������� node�����ӽ��
void right_LinkBitNode(BiTNode* node, BiTNode* child_node);//�ڵ�chile_node�������� node���Һ��ӽ��
bool Empty(BiTNode node);//�п� ��Ϊtrue �ǿ�Ϊfalse

void Visit(BiTNode node);  //����ָ���ڵ��е�����
void Visit(ThreadNode node);//���������������ڵ��е�����

void PreOrder(BiTNode Tree);//����������е�����,��ָ�������Ϊ��������
void InOrder(BiTNode Tree);//�������
void PostOrder();//�������
int TreeDepth(BiTNode Tree);//�����������
void LevelOrder(BiTNode Tree);//��α��� �Ӹ��ڵ㿪ʼ����

//������������������
void CreatTree(BiTNode* Tree,int* data);  //���ô�������鴴������������
void SortTree(BiTNode* Tree);//��顢�޸Ĵ���Ķ�������������Ķ�����ת��Ϊƽ�������
bool Search_Node(BiTNode Tree, int key);//����ָ���ڵ�,tureΪ���д��ڸ�ֵ,falseΪ�����ڸ�ֵ
void Delete_Node(BiTNode Tree, int key);//ɾ������Ŀ��ֵ�Ľڵ�
void Insert_Node(BiTNode* Tree, int key);//��Ŀ��ֵ��������

//���л������� 
void InitQueue(Queue* Q);  //��ʼ��һ�����У�����Ŀ������ڵ�����ͷ
Queue InitQueue();//����һ������
void EnQueue(Queue* Q, BiTNode node);  //��һ��Ԫ�����,Q�������ͷ�ڵ㣬
BiTNode OutQueue(Queue* Q);  //����βԪ�س���,����ʾ���е�ֵ
bool Empty(Queue Q);
void PrintQueue(Queue Q);//��ʾ��ǰ��������

