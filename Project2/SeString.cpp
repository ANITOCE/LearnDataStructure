#include"SeString.h"

void IncreaseSize(String* Str);//�Զ�Ϊ�ַ������ 5 ���ַ��ռ�
void ReduceSize();//���� N*5 ���ַ����еĿ��пռ�
bool DetectFree();//��⵱ǰ�ַ������Ƿ��� 5 �����пռ� ��Ϊtrue ��Ϊfalse

int* getKMP_next(String S);
 
String* InitString(String* Str)
{
	Str->data = (char*)malloc(sizeof(char) * InitSize);
	*Str->data = '\0';      //����ʼ�ռ��е������ÿգ���ֹ�����ݵĳ���
	Str->Length = 0;
	Str->MaxSize = InitSize;
	return Str;
}

void StrAssign(String* Str, char* ch)
{
	const char* p = ch;
	while (*p++) {
		Str->Length++;
	}
	while (1) {
		if (Str->Length > Str->MaxSize)
			IncreaseSize(Str);
		else
			break;
	}
	
	for (int i = 0; i < Str->Length; i++) {        //////   ��ch�ĳ���С��InitSize(10)ʱ���޷��������ch���ȵ����ݣ������� ch + ������
		Str->data[i] = ch[i];  
	}
	Str->data[Str->Length] = '\0';
	
	
}

void StrCopy(String* Str, String* Result)
{
	ClearStr(Result);
	Result->data = Str->data;
	Result->Length = Str->Length;
}

bool StrEmpty(String* Str)
{
	if (Str->data == '\0')
		return true;
	else
		return false;
}

int StrLength(String* Str)
{
	return Str->Length;
}

void PrintStr(String Str)
{
	printf("%s \n", Str.data);
}

void ClearStr(String* Str)
{
	Str->data = '\0';
	Str->Length = 0;
}

String Strcat(String* Str1, String* Str2)   
{
	String p;
	p.data= Str1->data;
	p.Length = Str1->Length;
	for (int i = 0; i < Str1->Length; i++) {
		p.data[i + p.Length] = Str2->data[i];
	}
	p.Length += Str2->Length;

	return p;
}

String SubString(String Str, int pos, int len)
{
	String Rusult;
	InitString(&Rusult);
	if (pos + len - 1 > Str.Length || pos - 1 > Str.Length || pos < 0 || len < 0) {      //  ��鴫��Ĳ����Ƿ����
		*Rusult.data = '\0';
		return Rusult;
	}
	for (int i = 0; i < len; i++) {
		Rusult.data[i] = Str.data[pos - 1];
		Rusult.Length++;
		pos++;
	}
	Rusult.data[Rusult.Length] = '\0';
	return Rusult;
}

int Index(String Str, String S)
{
	if (S.Length > Str.Length)
		return -1;
	int i = 0;
	while (i < Str.Length) {
		if (equal(S, SubString(Str, i + 1, S.Length))) {
			return i + 1;
		}
		i++;
	}

	return -1;
}

bool equal(String Str, String S)
{
	if (Str.Length != S.Length)
		return false;
	else {
		for (int i = 0; i < Str.Length && i < S.Length; i++) {
			if (Str.data[i] != S.data[i])
				return false;
		}
	}

	return true;
}

bool Sub_equal(String Str, String S)
{
	int i = 0, n = Str.Length, m = S.Length;
	while (i < Str.Length) {
		if (equal(S, SubString(Str, i + 1, m))) {
			return true;
		}
		i++;
	}
	return false;
}

int KMP_Index(String Str, String S)
{
	int* next = getKMP_next(S);
	for (int i = 0, j = 0; i < Str.Length; i++) {         //iΪ����Str��ָ�룬jΪ�Ӵ�S��ָ�룬i���Ϻ��ƣ�j����next�����ƶ�
		while (j > 0 && Str.data[i] != S.data[j]) {
			j = next[j - 1];
		}
		if (Str.data[i] == S.data[j]) 
			j++;
		if (j == S.Length)
			return i - S.Length + 1;
	}

	return -1;
}



int* getKMP_next(String S) {
	int* next = (int*)malloc(sizeof(int) * S.Length);
	int i = 0, j = 0;                 //iΪǰ׺ָ�룬jΪ��׺ָ�룬j�����Ϻ���
	for (next[i] = 0, j = 1; j < S.Length; j++) {
		while (i > 0 && S.data[i] != S.data[j]) {
			i = next[i - 1];             //����ͬ��ǰ׺����ת��ǰһ���ַ���Ӧ��next���±꣬���¼���Ƿ���ֱͬ��iΪ0	
		}
		if (S.data[i] == S.data[j]) {
			i++;
			next[j] = i;
		}
		else
			next[j] = 0;	
	}
	return next;
}

void IncreaseSize(String* Str)
{
	char* p = Str->data;
	Str->data = (char*)malloc(sizeof(char) * (Str->MaxSize + 5));
	Str->MaxSize += 5;
	for (int i = 0; i < Str->Length; i++) {
		Str->data[i] = p[i];
	}
	Str->data[Str->Length] = '\0';
}
