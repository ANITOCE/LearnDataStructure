#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100

//图的邻接矩阵存储
typedef struct MGraph {  
	char vax;
	int vaxNum, arcNum;
	int edge[MaxVertexNum][MaxVertexNum];
};

//图的邻接表存储
typedef struct ArcNode {  //边节点
	int adjvex;  //指向节点在AdjList中的下标
	ArcNode* next;
	int info; //权值
};

typedef struct VNode {  //顶点节点
	char data;
	ArcNode* first;     //与该顶点邻接的n条边以链表的形式存储
}AdjList[MaxVertexNum];

typedef struct ALGraph {
	AdjList vertices;
	int vexNum, arcNum; //节点数与边数
};



MGraph InitGraph(MGraph* G);//初始化邻接矩阵图
ALGraph InitGraph(ALGraph* G);//初始化邻接表图
VNode InitVNode(char x);//初始化顶点节点
void VisitVNode(VNode* x);
void PrintGraph(ALGraph* G);//以邻接表的形式显示整个图G

void BFS(ALGraph* G);
void DFS(ALGraph* G);

int getVertexInG(ALGraph* G, VNode* x);
bool equalVertex(VNode* x, VNode* y);//x，y两节点是否相等
bool Adjacent(ALGraph* G, VNode* x,VNode* y);//是否存在边(x,y)
void Neighbors(ALGraph* G, VNode* x);//列出所有与x邻接的边
void InsertVertex(ALGraph* G, VNode* x);//插入节点x
void DeleteVertex(ALGraph* G, VNode* x);//删除节点x
void AddEdge(ALGraph* G, VNode* x, VNode* y);//若边(x,y)不存在，则添加
void RemeoveEdge(ALGraph* G, VNode* x, VNode* y);//若边(x,y)存在，则删除
VNode FirstNeighbor(ALGraph* G, VNode* x); //返回x的第一个邻接点
VNode NextNeighbor(ALGraph* G, VNode x, VNode y);//返回除y的下一个邻接点

int Get_edge_value(ALGraph* G, VNode* x, VNode* y);//获取边(x,y)的权值
void Set_edge_value(ALGraph* G, VNode* x, VNode* y);//设置边(x,y)的权值
