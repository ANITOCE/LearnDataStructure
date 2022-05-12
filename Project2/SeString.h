#include<stdio.h>
#include<stdlib.h>

#define InitSize 10

typedef struct String {
	char* data;
	int Length;
	int MaxSize;
};

String* InitString(String* Str);//初始化
void StrAssign(String* Str, char* ch);//为指定的字符串赋值,ch可以直接使用 " " 为Str赋值
void StrCopy(String* Str, String* Result);//将字符串Str复制于Result中，将覆盖Result中原有的内容，Result将与Str完全相同
bool StrEmpty(String* Str);//判空
int StrLength(String* Str);//求字符串的长度
void PrintStr(String Str);//遍历并打印

void ClearStr(String* Str);//清空字符串
void DestroyString(String* Str);//销毁指定字符串的空间

String Strcat(String* Str1, String* Str2);//将Str2拼接至Str1后面，并返回至新的字符串中
String SubString(String Str, int pos, int len);//返回字符串Str从第pos位起长len的子串 (判断pos与len是否溢出) pos与自然数位对应
int Index(String Str, String S);//定位字符串S在Str中的位置，并返回
bool equal(String Str, String S);//比较两个字符串(ACSLL码)，相等返回true，不等返回false
bool Sub_equal(String Str, String S);//在字符串Str中是否存在子串S 存在为true
int StrCompare(String Str, String S);//比较两个字符串，返回Str - S ，即返回值=0为相等、> 0为Str大于S、< 0为Str小与S

int KMP_Index(String Str, String S);//使用KMP算法实现的字符串的定位
