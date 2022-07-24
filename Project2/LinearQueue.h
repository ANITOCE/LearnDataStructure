#include"LinearList.h"   //��������ǻ��ڶ�̬���Ա�ʵ�ֵ�
#include"singleLinearList.h"

typedef struct {
	SeqList* Data;
	int front;    //��ͷ
	int rear;     //��β  ָ������һ��Ԫ�ص���һλ����ز���Ӧ - 1
}SqQueue;

typedef struct {  //��������ǻ��ڵ�����ʵ�ֵ�
	LNode* front;
	LNode* rear;
}singleListQueue;

SqQueue InitQueue(SqQueue* Q);  //��ʼ��һ������
void EnQueue(SqQueue* Q, SeqListType Elem);  //��һ��Ԫ�����
SeqListType OutQueue(SqQueue* Q);  //����βԪ�س���

singleListQueue InitQueue(singleListQueue* Q);
void EnQueue(singleListQueue* Q, LNodeType Elem);
LNodeType OutQueue(singleListQueue* Q);
bool isEmpty(singleListQueue* Q);
