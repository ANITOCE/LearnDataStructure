#pragma once
#include<stdio.h>
#include<stdlib.h>
//这个二叉树 是基于链表实现的，节约了存储空间，提高了遍历效率

typedef struct BiTNode {
	int data;
	BiTNode* left_child, * right_child;
};

typedef struct ThreadNode {
	BiTNode Node;
	int left_tag, right_tag;    //使用tag记录树中结点左右指针是否指向线索，0指向子节点，1指向线索
};

typedef struct singleList {
	BiTNode node;
	singleList* next;
};

typedef struct Queue {  // 这个队列是嵌套单链表实现的，在层次遍历中，树中的元素个数未知，使用链表便于存储
	singleList* front;//队头指针
	singleList* rear;//队尾指针 
};

BiTNode InitNode(BiTNode* node);//初始化树中的节点,左右指针为NULL，数据为0
BiTNode InitNode(BiTNode* node, int Elem);//初始化树中的节点，其中数据为Elem
void ReviseBiTNode(BiTNode* node, int Elem);//修改指定节点中的数据
void left_LinkBitNode(BiTNode* node,BiTNode* child_node);//节点chile_node将连接至 node的左孩子结点
void right_LinkBitNode(BiTNode* node, BiTNode* child_node);//节点chile_node将连接至 node的右孩子结点
bool Empty(BiTNode node);//判空 空为true 非空为false

void Visit(BiTNode node);  //访问指定节点中的数据
void Visit(ThreadNode node);//访问线索二叉树节点中的数据

void PreOrder(BiTNode Tree);//先序遍历树中的数据,将指定结点作为根结点遍历
void InOrder(BiTNode Tree);//中序遍历
void PostOrder();//后序遍历
int TreeDepth(BiTNode Tree);//返回树的深度
void LevelOrder(BiTNode Tree);//层次遍历 从根节点开始遍历

//二叉排序树基础操作
void CreatTree(BiTNode* Tree,int* data);  //利用传入的数组创建二叉排序树
void SortTree(BiTNode* Tree);//检查、修改传入的二叉树，将传入的二叉树转换为平衡二叉树
bool Search_Node(BiTNode Tree, int key);//查找指定节点,ture为树中存在该值,false为不存在该值
void Delete_Node(BiTNode Tree, int key);//删除符合目标值的节点
void Insert_Node(BiTNode* Tree, int key);//将目标值插入树中

//队列基础操作 
void InitQueue(Queue* Q);  //初始化一个队列，并将目标的树节点存入对头
Queue InitQueue();//创建一个队列
void EnQueue(Queue* Q, BiTNode node);  //将一个元素入队,Q是链表的头节点，
BiTNode OutQueue(Queue* Q);  //将队尾元素出队,并显示其中的值
bool Empty(Queue Q);
void PrintQueue(Queue Q);//显示当前整个队列

