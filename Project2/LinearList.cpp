#include"LinearList.h"
void swap(SeqListType* a, SeqListType* b);
bool DetectFree(SeqList* L, int n);


void InitList(SeqList* L)
{
	L->data = (SeqListType*)malloc(InitSize*sizeof(SeqList)); //分配了InitSize(10)个SeqList的空间
	L->Length = 0;
	L->MaxSize = InitSize;
	//printf("初始化完成！\n");
}

void DestryList(SeqList* L)
{
	free(L->data);
	printf("内存空间以释放！\n");
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
		printf("插入位置溢出！\n");
	else if (n>L->Length)
		printf("插入位置错误！\n");
	else{
		for (int len = L->Length; len > n; len--) {
			swap(&L->data[len], &L->data[len + 1]);
		}
		L->data[n] = Elem;
		L->Length++;
		//printf("%d 插入完成！\n", Elem);
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
		//printf("第%d位删除成功!\n",n);
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
		printf("%d删除成功!\n", Elem);
	}
}

bool LocateElem(SeqList* L, SeqListType Elem)
{
	for (int i = 0; i < L->Length; i++) {
		if (L->data[i] == Elem)
			return true;
	}
	printf("%d不存在！\n",Elem);
	return false;
}

bool PositionElem(SeqList* L, int n)
{
	if (n > L->MaxSize || n < 0) {
		printf("查询位置不存在！\n");
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
	for (int i = L->Length; i < L->MaxSize; i++) {   //将分配的额外空间置为NULL，防止数据污染
		L->data[i] = NULL;
	}
	
	free(p);
}

void ReduceSize(SeqList* L)   //单测试线性表的功能时无问题  测试时 嵌套进线性表为基础的栈时  调试完成后触发Debug assertion failed   ？？？？？？
{
	int n = 0;    //记录了至多以5为单位的额外空间
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
	free(p);      //单测试线性表的功能时无问题  测试时 嵌套进线性表为基础的栈时     ???????释放旧的内存空间会触发Debug Error

}


// /////////////////////  
bool DetectFree(SeqList* L, int n)   //检测当前的5个额外空间是否空闲
{
	for (int i = 0; i < 5; i++) {
		if (L->data[n - i] != NULL)   //从n开始向前检查5个位置
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

