#include"Graph.h"


int main() {
	
	ALGraph G = InitGraph(&G);
	VNode A = InitVNode('A');
	VNode B = InitVNode('B');
	VNode C = InitVNode('C');
	VNode D = InitVNode('D');
	VNode E = InitVNode('E');
	InsertVertex(&G, &A);
	InsertVertex(&G, &B);
	InsertVertex(&G, &C);
	InsertVertex(&G, &D);
	InsertVertex(&G, &E);
	AddEdge(&G, &A, &B);
	AddEdge(&G, &A, &C);
	AddEdge(&G, &B, &E);
	AddEdge(&G, &B, &C);
	AddEdge(&G, &D, &C);
	PrintGraph(&G);
	printf("\n");
	BFSreverse(&G);
	return 0;
}
	