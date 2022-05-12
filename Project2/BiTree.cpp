#include "BiTree.h"
#pragma once


BiTNode InitNode(BiTNode* node)
{
    node = (BiTNode*)malloc(sizeof(BiTNode));
    node->data = 0;
    node->left_child = NULL;
    node->right_child = NULL;
    return *node;
}

BiTNode InitNode(BiTNode* node, int Elem)
{
    node = (BiTNode*)malloc(sizeof(BiTNode));
    node->data = Elem;
    node->left_child = NULL;
    node->right_child = NULL;
    return *node;
}

void Visit(BiTNode node)
{
    printf("%d ", node.data);
}

void ReviseBiTNode(BiTNode* node, int Elem)
{
    node->data = Elem;
}

void left_LinkBitNode(BiTNode* node, BiTNode* child_node)
{
    node->left_child = child_node;
}

void right_LinkBitNode(BiTNode* node, BiTNode* child_node)
{
    node->right_child = child_node;
}

bool Empty(BiTNode node)
{
    if (node.data == NULL)
        return true;
    return false;
}

void PreOrder(BiTNode Tree)
{
    if (&Tree!=NULL) {           
        Visit(Tree);
        if (Tree.left_child!=NULL)      //在进入子节点前，加一个判空，就不会发生在进入递归函数时，触发空指针异常
            PreOrder(*Tree.left_child);
        if (Tree.right_child!=NULL)
            PreOrder(*Tree.right_child);
    }
}


void InOrder(BiTNode Tree)
{

    if (&Tree != NULL) {
        if (Tree.left_child != NULL)
            InOrder(*Tree.left_child);
        Visit(Tree);
        if (Tree.right_child != NULL)
            InOrder(*Tree.right_child);
    }
}

int TreeDepth(BiTNode Tree)
{
    int left_depth = 0, right_depth = 0;
    if (Tree.data == NULL)
        return 0;
    if (Tree.left_child != NULL)
        left_depth = TreeDepth(*Tree.left_child);
    if (Tree.right_child != NULL)
        right_depth = TreeDepth(*Tree.right_child);
    return (left_depth > right_depth) ? 1 + left_depth : 1 + right_depth;
}

void LevelOrder(BiTNode Tree)
{
    Queue Q = InitQueue();
    Q.front->node = Q.rear->node = Tree;
    while(!Empty(Q)){
        if (Q.front->node.left_child != NULL)
            EnQueue(&Q, *Q.front->node.left_child);
        if(Q.front->node.right_child!=NULL)
            EnQueue(&Q, *Q.front->node.right_child);  //若队列非空，则将当前头节点出队，并将头节点中的两个子节点入队，直至队列为空
        Visit(OutQueue(&Q));
        
    }

}

bool Search_Node(BiTNode Tree, int key)
{
    if (Tree.data == NULL)
        return false;
    if (key == Tree.data)
        return true;
    if (key > Tree.data) {
        if (Tree.right_child != NULL)
            Search_Node(*Tree.right_child, key);
        return false;
    }
    else {
        if (Tree.left_child != NULL) 
            Search_Node(*Tree.left_child, key);
        return false;
    }
}

void Insert_Node(BiTNode* Tree, int key)
{
    BiTNode node = InitNode(&node, key);
    if (Tree == NULL) {
        Tree = &node;
        return;
    }
    if (Search_Node(*Tree, key))
        return;
    if (key > Tree->data) {
        if (Tree->right_child == NULL) {
            Tree->right_child = &node;
            return;
        }
        Insert_Node(Tree->right_child, key);
    }
    if (key < Tree->data) {
        if (Tree->left_child == NULL) {
            Tree->left_child = &node;
            return;
        }
        Insert_Node(Tree->left_child, key);
    }
}


Queue InitQueue()
{
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = Q->rear = (singleList*)malloc(sizeof(singleList));
    Q->front->node = Q->rear->node = InitNode(&Q->front->node);
    Q->front->next = Q->rear->next = NULL;
    return *Q;
}

void EnQueue(Queue* Q, BiTNode node)
{
    singleList* sL = (singleList*)malloc(sizeof(singleList));
    sL->node = node;
    sL->next = NULL;
    if (Empty(*Q)) {
        Q->front = Q->rear = sL;
        Q->front->next = Q->rear->next = NULL; //若入队之前为空队列，则重置队列状态，并将新入队的节点作为头节点
    }
    else {
        Q->rear->next = sL;
        Q->rear = Q->rear->next;
        Q->rear->next = NULL;
    }  
}

BiTNode OutQueue(Queue* Q)
{
    BiTNode out = InitNode(&out);
    out = Q->front->node;
    if (Q->front == Q->rear) {
        Q->front = Q->rear = NULL;  //若出队的是队列中的最后一个元素，将整个队列置空，并返回出队的值
        return out;
    }
    Q->front = Q->front->next;
    return out;
}

bool Empty(Queue Q)
{
    if (Q.front == Q.rear && Q.front == NULL)
        return true;
    return false;
}

void PrintQueue(Queue Q)
{
    for (singleList* p = Q.front; p == Q.rear->next; p = p->next) {
        printf("%d ", p->node.data);
    }
    printf("\n");
}
