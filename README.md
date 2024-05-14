# LearnDataStructure
## lzz对数据结构的学习

### 线性表 LinearList
- 结构
``` SeqList
typedef struct{
	SeqListType* data;
	int MaxSize;
	int Length;
}SeqList;
```
- 基本操作
``` 
void InitList(SeqList* L); //初始化动态线性表，；令每个元素为0
void DestryList(SeqList* L);//销毁线性表占用的内存
void PrintList(SeqList L);//遍历每一个元素，并显示
bool isEmpty(SeqList L); //判空

void InsertList(SeqList* L,int i, SeqListType Elem);//插入元素，可以选择插入位置
SeqListType PositionDeleteElem(SeqList* L,int n);//删除某一位置的元素,返回删除元素的值
void LocateDeleteElem(SeqList* L, SeqListType Elem);//寻找某一元素并删除

bool LocateElem(SeqList* L, SeqListType Elem);//按值查找
bool PositionElem(SeqList* L,int n);//按位查找

void IncreaseSize(SeqList* L,int len);//增加线性表的内存空间
void ReduceSize(SeqList* L);//检测当前的额外空间(5)是否空闲，若空闲则释放该空间，但不会小于InitSize(10)
```
### 单链表 singleLinearList
- 结构
```
typedef struct LNode{
	LNodeType data;
	LNode* next;
};
```
-基本操作
```
LNode InitList(LNode* L); //初始化第一个节点
LNode InitList();//创建一个链表节点
void PrintList(LNode* L);//显示整个链表

void DeleteNode(LNode* L);//将指定节点在链表中删除
void ReviseNodeElem(LNode* L, LNodeType Elem);//修改指定节点中的数据


void InsertList(LNode* L, int n, LNodeType Elem);//搜寻指定位置，向其中插入数据
bool InsertNextNode(LNode* L, LNodeType Elem);//向指定节点后面插入数据
bool InsertPriorNode(LNode* L, LNodeType Elem);//向指定节点前面插入数据

LNode* GetElem(LNode* L, int n);//按下标查找
LNode* LocateElem(LNode* L, LNodeType Elem);//按值查找

void List_Tallnesert(LNode* L);//使用尾插法初始化一个有10节点的链表，是每个节点的值位0
void List_HeadInsert(LNode* L);//使用头插法初始化整个链表\

int Length(LNode* L);//求表长
```

### 字符串 SeString
- 结构
```
typedef struct String {
	char* data;
	int Length;
	int MaxSize;
};
```
- 基本操作
```
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
```

### 栈(线性栈/链栈)与队列 Linear_Stack/singleList_Stack LinearQueue
- 结构
  - 线性栈
  ```
  typedef struct{
	  SeqList* List;
	  int top;
  }SqStack;
  ```
  - 链栈
  ```
  typedef struct {
	  struct LNode* node;   //链栈中的存取数据的节点，将构成单链表
	  LNode* top;   //永远指向链表的最后一个节点
  }SqStack;
  ```
  - 队列
    - 基于线性表实现的队列
    ```
    typedef struct {
	    SeqList* Data;
	    int front;    //队头
	    int rear;     //队尾  指向的最后一个元素的下一位，相关操作应 - 1
    }SqQueue;
    ```
    - 基于链表的队列
    ```
    typedef struct {  
	    LNode* front;
	    LNode* rear;
    }singleListQueue;
    ```
- 基本操作
  - 栈操作
  ```
  void InitStack(SqStack* S);//初始化栈
  void DestoryStack(SqStack* S);//销毁栈的内存空间

  void Push(SqStack* S, int Elem);//将指定元素入栈
  int Pop(SqStack* S);//将栈顶元素出栈，并返回

  int GetTop(SqStack* S);//返回栈顶元素的值，不做修改
  ```
  ```
  void S_InitStack(SqStack* S);//初始化栈
  void S_DestoryStack(SqStack* S);//销毁栈的内存空间

  void S_Push(SqStack* S, int Elem);//将指定元素入栈
  LNode* S_Pop(SqStack* S);//将栈顶元素出栈，并返回

  int S_GetTop(SqStack* S);//返回栈顶元素的值，不做修改
  ```
  - 队列操作
  ```
  SqQueue InitQueue(SqQueue* Q);  //初始化一个队列
  void EnQueue(SqQueue* Q, SeqListType Elem);  //将一个元素入队
  SeqListType OutQueue(SqQueue* Q);  //将队尾元素出队
  ```
  ```
  singleListQueue InitQueue(singleListQueue* Q);
  void EnQueue(singleListQueue* Q, LNodeType Elem);
  LNodeType OutQueue(singleListQueue* Q);
  bool isEmpty(singleListQueue* Q);
  ```

### 二叉树 BiTree
- 结构
```
typedef struct BiTNode {
	int data;
	BiTNode* left_child, * right_child;
};

typedef struct ThreadNode {
	BiTNode Node;
	int left_tag, right_tag;    //使用tag记录树中结点左右指针是否指向线索，0指向子节点，1指向线索
};

typedef struct singleList {
	BiTNode node;
	singleList* next;
};

typedef struct Queue {  // 这个队列是嵌套单链表实现的，在层次遍历中，树中的元素个数未知，使用链表便于存储
	singleList* front;//队头指针
	singleList* rear;//队尾指针 
};
```
- 基本操作
```
BiTNode InitNode(BiTNode* node);//初始化树中的节点,左右指针为NULL，数据为0
BiTNode InitNode(BiTNode* node, int Elem);//初始化树中的节点，其中数据为Elem
void ReviseBiTNode(BiTNode* node, int Elem);//修改指定节点中的数据
void left_LinkBitNode(BiTNode* node,BiTNode* child_node);//节点chile_node将连接至 node的左孩子结点
void right_LinkBitNode(BiTNode* node, BiTNode* child_node);//节点chile_node将连接至 node的右孩子结点
bool Empty(BiTNode node);//判空 空为true 非空为false

void Visit(BiTNode node);  //访问指定节点中的数据
void Visit(ThreadNode node);//访问线索二叉树节点中的数据

void PreOrder(BiTNode Tree);//先序遍历树中的数据,将指定结点作为根结点遍历
void InOrder(BiTNode Tree);//中序遍历
void PostOrder();//后序遍历
int TreeDepth(BiTNode Tree);//返回树的深度
void LevelOrder(BiTNode Tree);//层次遍历 从根节点开始遍历

//二叉排序树基础操作
void CreatTree(BiTNode* Tree,int* data);  //利用传入的数组创建二叉排序树
void SortTree(BiTNode* Tree);//检查、修改传入的二叉树，将传入的二叉树转换为平衡二叉树
bool Search_Node(BiTNode Tree, int key);//查找指定节点,ture为树中存在该值,false为不存在该值
void Delete_Node(BiTNode Tree, int key);//删除符合目标值的节点
void Insert_Node(BiTNode* Tree, int key);//将目标值插入树中

//队列基础操作 
void InitQueue(Queue* Q);  //初始化一个队列，并将目标的树节点存入对头
Queue InitQueue();//创建一个队列
void EnQueue(Queue* Q, BiTNode node);  //将一个元素入队,Q是链表的头节点，
BiTNode OutQueue(Queue* Q);  //将队尾元素出队,并显示其中的值
bool Empty(Queue Q);
void PrintQueue(Queue Q);//显示当前整个队列
```

### 图 Graph
- 结构
	- 邻接表存储
	```
	typedef struct ArcNode {  //边节点
		int adjvex;  //指向节点在AdjList中的下标
		ArcNode* next;
		int info; //权值
	};

	typedef struct VNode {  //顶点节点
		char data;
		ArcNode* first;     //与该顶点邻接的n条边以链表的形式存储
	}AdjList[MaxVertexNum];

	typedef struct ALGraph {
		AdjList vertices;
		int vexNum, arcNum; //节点数与边数
	};
	```
	- 邻接矩阵
	```
	typedef struct MGraph {  
		char vax;
		int vaxNum, arcNum;
		int edge[MaxVertexNum][MaxVertexNum];
	};
	```
- 基本操作
```
MGraph InitGraph(MGraph* G);//初始化邻接矩阵图
ALGraph InitGraph(ALGraph* G);//初始化邻接表图
VNode InitVNode(char x);//初始化顶点节点
void VisitVNode(VNode* x);
void PrintGraph(ALGraph* G);//以邻接表的形式显示整个图G

void BFSreverse(ALGraph* G);
void BFS(ALGraph* G, VNode* x);
void DFS(ALGraph* G);

int getVertexInG(ALGraph* G, VNode* x);
bool equalVertex(VNode* x, VNode* y);//x，y两节点是否相等
bool Adjacent(ALGraph* G, VNode* x,VNode* y);//是否存在边(x,y)
void Neighbors(ALGraph* G, VNode* x);//列出所有与x邻接的边
void InsertVertex(ALGraph* G, VNode* x);//插入节点x
void DeleteVertex(ALGraph* G, VNode* x);//删除节点x
void AddEdge(ALGraph* G, VNode* x, VNode* y);//若边(x,y)不存在，则添加
void RemeoveEdge(ALGraph* G, VNode* x, VNode* y);//若边(x,y)存在，则删除
VNode* FirstNeighbor(ALGraph* G, VNode* x); //返回x的第一个邻接点
VNode* NextNeighbor(ALGraph* G, VNode* x, VNode* y);//返回除y的下一个邻接点

int Get_edge_value(ALGraph* G, VNode* x, VNode* y);//获取边(x,y)的权值
void Set_edge_value(ALGraph* G, VNode* x, VNode* y);//设置边(x,y)的权值

```
