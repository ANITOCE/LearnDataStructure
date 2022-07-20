#include"BiTree.h"
#include"Graph.h"


int main() {
	
	ALGraph G = InitGraph(&G);
	VNode A = InitVNode('A');
	VNode B = InitVNode('B');
	VNode C = InitVNode('C');
	InsertVertex(&G, &A);
	InsertVertex(&G, &B);
	InsertVertex(&G, &C);
	AddEdge(&G, &A, &B);
	AddEdge(&G, &A, &C);
	AddEdge(&G, &B, &C);
	PrintGraph(&G);
	return 0;
}
	