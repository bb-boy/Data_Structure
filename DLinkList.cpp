#include <stdio.h>
#include <malloc.h>
#pragma warning(disable : 4996)

/*带头结点双链表*/

typedef int ElemType;
typedef struct DLinkNode {
	ElemType data;
	struct DLinkNode* prior;
	struct DLinkNode* next;
}DLinkNode, *DLinkList;

DLinkList InitDLink(DLinkList &L) {           //初始化链表
	L = (DLinkList)malloc(sizeof(DLinkNode));
	L->prior = NULL, L->next = NULL;
	return L;
}

int  Counter(DLinkList L) {                      //计数器
	int i = 0;
	while (L->next) {
		L = L->next;
		i++;
	}
	return i;
	//printf("一共有%d个元素\n",i);
}

DLinkList GetElem(DLinkList L, int i) {
	//按位查找
	int a = Counter(L);
	if (i > a) {
		printf("error input.\n");
		return NULL;
	}
	else if (0 == i) {
		printf("this is head node.\n");
		return L;
	}
	for (int j = 0; j < i; j++) {
		L = L->next;
	}
	return L;
}



DLinkList DList_HeadInsert(DLinkList& L) {			//头插法建立双链表
	InitDLink(L);
	ElemType x;
	scanf("%d", &x);
	while (x != 9999) {
		DLinkList s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = x;
		s->next = L->next;
		if(L->next != NULL)
			L->next->prior = s;
		s->prior = L;
		L->next = s;
		scanf("%d", &x);
	}	
	return L;	
}

DLinkList DList_TailInsert(DLinkList& L) {             //尾插法建立双链表
	InitDLink(L);
	ElemType x;
	DLinkList r = L;
	scanf("%d", &x);
	while (x != 9999) {
		DLinkList s = (DLinkList)malloc(sizeof(DLinkNode));
		s->data = x;
		r->next = s;
		s->prior = r;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

bool insertAtIndex(DLinkList L, int i,ElemType e) {          //L的第i个位置插入e
	int a = Counter(L);
	if (0==i||i > ( a+ 1)) {
		return false;
	}
	DLinkList s, t;
	s = (DLinkList)malloc(sizeof(DLinkNode));
	t= GetElem(L, i - 1);
	s->data = e;
	s->prior = t;
	s->next = t->next;
	if(t->next != NULL)
		t->next->prior = s;
	t->next = s;
	return true;
}

bool deletetAtIndex(DLinkList L, int i) {               //删除L中第i节点
	int a = Counter(L);
	if (0 == i || i > (a + 1)) {
		return false;
	}
	DLinkList s = GetElem(L,i);
	s->prior->next = s->next;
	if (s->next != NULL)
		s->next->prior = s->prior;
	printf("删除的元素是%d\n", s->data);
	return true;
}

void sum(DLinkList L) {								//打印节点数
	printf("节点一共有%d个\n", Counter(L));
}

void PrinLt(DLinkList L) {                           //顺序打印链表
	for (int i = 1;L->next != NULL; i++) {
		printf("第%d个节点是%d\n", i, L->next->data);
		L = L->next;
	}
}

void printseparator(char symbol, int length) {				//打印分割线
	int i;
	for (i = 0; i < length; i++) {
		putchar(symbol);
	}
	putchar('\n');
}

//int main() {
//	DLinkList s, c;
//	DList_TailInsert(s);
//	//DList_HeadInsert(s);
//	PrinLt(s);
//	
//	//c = GetElem(s, 2);
//	//printf("拿到的节点是%d\n", c->data);
//	sum(s);
//	printseparator('*', 80);
//	insertAtIndex(s, 3, 0);
//	PrinLt(s);
//	sum(s);
//	printseparator('*', 80);
//	deletetAtIndex(s, 3);
//	PrinLt(s);
//	sum(s);
//	printseparator('*', 80);
//	
//	
//}