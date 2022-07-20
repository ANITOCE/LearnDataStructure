#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MaxVertexNum 100

//ͼ���ڽӾ���洢
typedef struct MGraph {  
	char vax;
	int vaxNum, arcNum;
	int edge[MaxVertexNum][MaxVertexNum];
};

//ͼ���ڽӱ�洢
typedef struct ArcNode {  //�߽ڵ�
	int adjvex;  //ָ��ڵ���AdjList�е��±�
	ArcNode* next;
	int info; //Ȩֵ
};

typedef struct VNode {  //����ڵ�
	char data;
	ArcNode* first;     //��ö����ڽӵ�n�������������ʽ�洢
}AdjList[MaxVertexNum];

typedef struct ALGraph {
	AdjList vertices;
	int vexNum, arcNum; //�ڵ��������
};



MGraph InitGraph(MGraph* G);//��ʼ���ڽӾ���ͼ
ALGraph InitGraph(ALGraph* G);//��ʼ���ڽӱ�ͼ
VNode InitVNode(char x);//��ʼ������ڵ�
void VisitVNode(VNode* x);
void PrintGraph(ALGraph* G);//���ڽӱ����ʽ��ʾ����ͼG

void BFS(ALGraph* G);
void DFS(ALGraph* G);

int getVertexInG(ALGraph* G, VNode* x);
bool equalVertex(VNode* x, VNode* y);//x��y���ڵ��Ƿ����
bool Adjacent(ALGraph* G, VNode* x,VNode* y);//�Ƿ���ڱ�(x,y)
void Neighbors(ALGraph* G, VNode* x);//�г�������x�ڽӵı�
void InsertVertex(ALGraph* G, VNode* x);//����ڵ�x
void DeleteVertex(ALGraph* G, VNode* x);//ɾ���ڵ�x
void AddEdge(ALGraph* G, VNode* x, VNode* y);//����(x,y)�����ڣ������
void RemeoveEdge(ALGraph* G, VNode* x, VNode* y);//����(x,y)���ڣ���ɾ��
VNode FirstNeighbor(ALGraph* G, VNode* x); //����x�ĵ�һ���ڽӵ�
VNode NextNeighbor(ALGraph* G, VNode x, VNode y);//���س�y����һ���ڽӵ�

int Get_edge_value(ALGraph* G, VNode* x, VNode* y);//��ȡ��(x,y)��Ȩֵ
void Set_edge_value(ALGraph* G, VNode* x, VNode* y);//���ñ�(x,y)��Ȩֵ
