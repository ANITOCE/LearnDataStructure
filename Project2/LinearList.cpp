#include"LinearList.h"
void swap(SeqListType* a, SeqListType* b);
bool DetectFree(SeqList* L, int n);


void InitList(SeqList* L)
{
	L->data = (SeqListType*)malloc(InitSize*sizeof(SeqList)); //������InitSize(10)��SeqList�Ŀռ�
	L->Length = 0;
	L->MaxSize = InitSize;
	//printf("��ʼ����ɣ�\n");
}

void DestryList(SeqList* L)
{
	free(L->data);
	printf("�ڴ�ռ����ͷţ�\n");
}

void PrintList(SeqList L)
{
	for (int i = 0; i < L.Length; i++) {
		printf("%c ", L.data[i]);
	}
	printf("\n");
}

bool isEmpty(SeqList L)
{
	for (int i = 0; i < L.Length; i++) {
		if (L.data[i] != NULL)
			return false;
	}
	return true;
}

void InsertList(SeqList* L, int n, SeqListType Elem)
{
	if (L->Length == L->MaxSize || n < 0)
		printf("����λ�������\n");
	else if (n>L->Length)
		printf("����λ�ô���\n");
	else{
		for (int len = L->Length; len > n; len--) {
			swap(&L->data[len], &L->data[len + 1]);
		}
		L->data[n] = Elem;
		L->Length++;
		//printf("%d ������ɣ�\n", Elem);
	}
}

SeqListType PositionDeleteElem(SeqList* L, int n)
{
	if (PositionElem(L, n)) {
		for (int i = n; i < L->Length; i++) {
			swap(&L->data[i], &L->data[i + 1]);
		}
		int Elem = L->data[L->Length];
		L->data[L->Length] = NULL;
		L->Length--;
		//printf("��%dλɾ���ɹ�!\n",n);
		return Elem;
	}
	return NULL;
}

void LocateDeleteElem(SeqList* L, SeqListType Elem)
{
	int i;
	if (LocateElem(L, Elem)) {
		for (i = LocateElem(L, Elem) + 1; i < L->Length; i++) {
			swap(&L->data[i], &L->data[i + 1]);
		}
		L->data[L->Length] = NULL;
		L->Length--;
		printf("%dɾ���ɹ�!\n", Elem);
	}
}

bool LocateElem(SeqList* L, SeqListType Elem)
{
	for (int i = 0; i < L->Length; i++) {
		if (L->data[i] == Elem)
			return true;
	}
	printf("%d�����ڣ�\n",Elem);
	return false;
}

bool PositionElem(SeqList* L, int n)
{
	if (n > L->MaxSize || n < 0) {
		printf("��ѯλ�ò����ڣ�\n");
		return false;
	}
	else {
		for (int i = 0; i < L->Length ; i++) {
			if (i == n)
				return true;
		}
	}	
	return false;
}

void IncreaseSize(SeqList* L, int len)
{
	SeqListType* p = L->data;
	L->data = (SeqListType*)malloc(sizeof(SeqList)*(L->MaxSize + len));
	L->MaxSize += len;

	for (int i = 0; i < L->Length; i++) {
		L->data[i] = p[i];
	}
	for (int i = L->Length; i < L->MaxSize; i++) {   //������Ķ���ռ���ΪNULL����ֹ������Ⱦ
		L->data[i] = NULL;
	}
	
	free(p);
}

void ReduceSize(SeqList* L)   //���������Ա�Ĺ���ʱ������  ����ʱ Ƕ�׽����Ա�Ϊ������ջʱ  ������ɺ󴥷�Debug assertion failed   ������������
{
	int n = 0;    //��¼��������5Ϊ��λ�Ķ���ռ�
	while (DetectFree(L, L->MaxSize - n - 1)) {
		if (L->MaxSize - n - 1 < 10)
			break;
		else
			n += 5;
	}
	SeqListType* p = L->data;
	L->data = (SeqListType*)malloc(L->MaxSize - n);
	L->MaxSize -= n;
	for (int i = 0; i < L->Length; i++) {
		L->data[i] = p[i];
	}
	free(p);      //���������Ա�Ĺ���ʱ������  ����ʱ Ƕ�׽����Ա�Ϊ������ջʱ     ???????�ͷžɵ��ڴ�ռ�ᴥ��Debug Error

}


// /////////////////////  
bool DetectFree(SeqList* L, int n)   //��⵱ǰ��5������ռ��Ƿ����
{
	for (int i = 0; i < 5; i++) {
		if (L->data[n - i] != NULL)   //��n��ʼ��ǰ���5��λ��
			return false;
	}
	return true;
}


void swap(SeqListType* a, SeqListType* b) {
	SeqListType t;
	t = *a;
	*a = *b;
	*b = t;
}

