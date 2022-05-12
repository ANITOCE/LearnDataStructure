#include "singleLinearList.h"


void InitList(LNode* L)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		printf("内存分配失败！\n");
	}	
	//L->data = 0;
	L->next = NULL;
}

LNode InitList()
{
	LNode* node = (LNode*)malloc(sizeof(LNode));
	if (node == NULL)
		printf("内存分配失败！\n");
	node->next = NULL;
	return *node;
}


void PrintList(LNode* L)
{
	LNode* p = L->next;
	if (p == NULL)
		printf("链表为空！\n");
	else
	{
		while (p != NULL)
		{
			printf("%d ", p->data);
			p = p->next;
		}
	}
}

void DeleteNode(LNode* L)
{
	LNode* p = L->next;
	if (L->next == NULL) {
		L = NULL;
		free(L);
		//L = NULL;
	}
	else {
		int temp;               //交换指定节点与下一个节点的数据，将next指向下一个节点的next，释放空间
		temp = L->data;
		L->data = L->next->data;
		L->next->data = temp;

		L->next = L->next->next;
		free(p);
	}

}

void ReviseNodeElem(LNode* L, int Elem)
{
	L->data = Elem;
}

void InsertList(LNode* L, int n, int Elem)
{
	if (n < 0)
		printf("插入位置错误！\n");
	LNode* p = GetElem(L->next, n);
	if(InsertNextNode(p, Elem))
		printf("%d 插入成功！\n", Elem);
	else
		printf("%d 插入失败！\n", Elem);
	

}

bool InsertNextNode(LNode* L, int Elem)
{
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		printf("节点内容分配失败！\n");
		return false;
	}
	LNode* p = L;
	s->data = Elem;
	s->next = p->next;
	p->next = s;
	//printf("%d 尾插入成功！\n", Elem);
	return true;
}

bool InsertPriorNode(LNode* L, int Elem)
{
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		printf("内存分配失败！\n");
		return false;
	}
	s->data = Elem;
	s->next = L->next;
	int p = L->data;
	InsertNextNode(s, p);
	return true;
}

LNode* GetElem(LNode* L, int n)//????    头节点为空无法返回节点，使得插入发生空指针异常
{
	if (n < 0)
		return NULL;
	LNode* p = L;
	//p = p->next;
	int i = 0;
	while (p->next != NULL && i <= n) {		
		if (i == n)
			return p;
		p = p->next;
		i++;
	}
	return NULL;
}

LNode* LocateElem(LNode* L, int Elem)
{
	LNode* p = L;
	while (p != NULL) {
		if (p->data == Elem) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void List_Tallnesert(LNode* L)
{
	LNode* p = L;
	for (int i = 0; i < 10; i++) {
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = 0;
		s->next = NULL;
		p->next = s;
		p = p->next;
	}
}

int Length(LNode* L)
{
	LNode* p = L->next;
	int i = 0;
	while (p->next != NULL)
	{
		p = p->next;
		i++;
	}
	return i;
}
