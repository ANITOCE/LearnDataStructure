#include"LinearList.h"   //��������ǻ��ڶ�̬���Ա�ʵ�ֵ�

typedef struct {
	SeqList* Data;
	int front;    //��ͷ
	int rear;     //��β  ָ������һ��Ԫ�ص���һλ����ز���Ӧ - 1
}SqQueue;

void InitQueue(SqQueue* Q);  //��ʼ��һ������

void EnQueue(SqQueue* Q, int Elem);  //��һ��Ԫ�����

int OutQueue(SqQueue* Q);  //����βԪ�س���


