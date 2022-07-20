#include"Graph.h"

ALGraph InitGraph(ALGraph* G)
{
	G = (ALGraph*)malloc(sizeof(ALGraph));
	G->arcNum = 0;
	G->vexNum = 0;
	return *G;
}

VNode InitVNode(char x)
{
	VNode* newVertex = (VNode*)malloc(sizeof(VNode));
	newVertex->data = x;
	newVertex->first = nullptr;
	return *newVertex;
}

void PrintGraph(ALGraph* G)
{
	for (int i = 0; i < G->vexNum; i++) {
		ArcNode* Node = G->vertices[i].first;
		printf("½Úµã %c", G->vertices[i].data);
		while (Node != nullptr) {
			printf("--> %c", G->vertices[Node->adjvex].data);
			Node = Node->next;
		}
		printf("\n");
	}
}

int getVertexInG(ALGraph* G, VNode* x)
{
	for (int i = 0; i < G->vexNum; i++) {
		if (equalVertex(&G->vertices[i], x)) {
			return i;
		}
	}
	return -1;
}

bool equalVertex(VNode* x, VNode* y)
{
	if (x->data == y->data)
		return true;
	return false;
}

bool Adjacent(ALGraph* G, VNode* x, VNode* y)
{
	ArcNode* Node = x->first;
	while (Node != nullptr) {
		if (equalVertex(&G->vertices[Node->adjvex], y)) {
			return true;
		}
		Node = Node->next;
	}
	return false;
}

void InsertVertex(ALGraph* G, VNode* x)
{
	G->vertices[G->vexNum] = *x;
	G->vexNum++;
}

void AddEdge(ALGraph* G, VNode* x, VNode* y)
{
	if (!Adjacent(G, x, y)) {
		ArcNode* newEdge = (ArcNode*)malloc(sizeof(ArcNode));
		newEdge->adjvex = getVertexInG(G, y);
		newEdge->next = nullptr;
		newEdge->info = 1;
		int x_position = getVertexInG(G, x);
		if (G->vertices[x_position].first == nullptr) {
			G->vertices[x_position].first = newEdge;
			G->arcNum++;
			return;
		}
		ArcNode* Node = G->vertices[x_position].first;
		while (Node->next != nullptr) {
			Node = Node->next;
		}
		Node->next = newEdge;
		G->arcNum++;
	}
}

VNode FirstNeighbor(ALGraph* G, VNode* x)
{
	return G->vertices[x->first->adjvex];
}

VNode NextNeighbor(ALGraph* G, VNode* x, VNode* y)
{
	if (equalVertex(&G->vertices[x->first->adjvex], y)) {
		int nextNode = x->first->next->adjvex;
		return G->vertices[nextNode];
	}
	return G->vertices[x->first->adjvex];
}
