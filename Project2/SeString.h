#include<stdio.h>
#include<stdlib.h>

#define InitSize 10

typedef struct String {
	char* data;
	int Length;
	int MaxSize;
};

String* InitString(String* Str);//��ʼ��
void StrAssign(String* Str, char* ch);//Ϊָ�����ַ�����ֵ,ch����ֱ��ʹ�� " " ΪStr��ֵ
void StrCopy(String* Str, String* Result);//���ַ���Str������Result�У�������Result��ԭ�е����ݣ�Result����Str��ȫ��ͬ
bool StrEmpty(String* Str);//�п�
int StrLength(String* Str);//���ַ����ĳ���
void PrintStr(String Str);//��������ӡ

void ClearStr(String* Str);//����ַ���
void DestroyString(String* Str);//����ָ���ַ����Ŀռ�

String Strcat(String* Str1, String* Str2);//��Str2ƴ����Str1���棬���������µ��ַ�����
String SubString(String Str, int pos, int len);//�����ַ���Str�ӵ�posλ��len���Ӵ� (�ж�pos��len�Ƿ����) pos����Ȼ��λ��Ӧ
int Index(String Str, String S);//��λ�ַ���S��Str�е�λ�ã�������
bool equal(String Str, String S);//�Ƚ������ַ���(ACSLL��)����ȷ���true�����ȷ���false
bool Sub_equal(String Str, String S);//���ַ���Str���Ƿ�����Ӵ�S ����Ϊtrue
int StrCompare(String Str, String S);//�Ƚ������ַ���������Str - S ��������ֵ=0Ϊ��ȡ�> 0ΪStr����S��< 0ΪStrС��S

int KMP_Index(String Str, String S);//ʹ��KMP�㷨ʵ�ֵ��ַ����Ķ�λ
