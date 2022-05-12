#include"BiTree.h"


int main() {
	
	BiTNode node1 = InitNode(&node1, 1), node2 = InitNode(&node2, 2), node3 = InitNode(&node3, 3);
	BiTNode node6 = InitNode(&node6, 6), node4 = InitNode(&node4, 4), node5 = InitNode(&node5, 5);

	left_LinkBitNode(&node4, &node2);
	right_LinkBitNode(&node4, &node6);
	left_LinkBitNode(&node2, &node1);
	right_LinkBitNode(&node2, &node3);
	left_LinkBitNode(&node6, &node5);
	Insert_Node(&node4, 7);
	InOrder(node4);
	

	
	return 0;
}
	