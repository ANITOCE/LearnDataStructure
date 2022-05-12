#include "singleLinearList.h"


void InitList(LNode* L)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL) {
		printf("�ڴ����ʧ�ܣ�\n");
	}	
	//L->data = 0;
	L->next = NULL;
}

LNode InitList()
{
	LNode* node = (LNode*)malloc(sizeof(LNode));
	if (node == NULL)
		printf("�ڴ����ʧ�ܣ�\n");
	node->next = NULL;
	return *node;
}


void PrintList(LNode* L)
{
	LNode* p = L->next;
	if (p == NULL)
		printf("����Ϊ�գ�\n");
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
		int temp;               //����ָ���ڵ�����һ���ڵ�����ݣ���nextָ����һ���ڵ��next���ͷſռ�
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
		printf("����λ�ô���\n");
	LNode* p = GetElem(L->next, n);
	if(InsertNextNode(p, Elem))
		printf("%d ����ɹ���\n", Elem);
	else
		printf("%d ����ʧ�ܣ�\n", Elem);
	

}

bool InsertNextNode(LNode* L, int Elem)
{
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		printf("�ڵ����ݷ���ʧ�ܣ�\n");
		return false;
	}
	LNode* p = L;
	s->data = Elem;
	s->next = p->next;
	p->next = s;
	//printf("%d β����ɹ���\n", Elem);
	return true;
}

bool InsertPriorNode(LNode* L, int Elem)
{
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		printf("�ڴ����ʧ�ܣ�\n");
		return false;
	}
	s->data = Elem;
	s->next = L->next;
	int p = L->data;
	InsertNextNode(s, p);
	return true;
}

LNode* GetElem(LNode* L, int n)//????    ͷ�ڵ�Ϊ���޷����ؽڵ㣬ʹ�ò��뷢����ָ���쳣
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
