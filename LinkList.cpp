#include <stdio.h>
#pragma warning(disable : 4996)
#include <corecrt_malloc.h>
#include <iostream>

/*带头结点单链表*/

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;   

LinkList InitList(LinkList &L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;	
	return L;
}			//初始化链表		

LinkList List_HeadInsert(LinkList &L) {             //头插法建立链表
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL; 
	int x; LNode* s;
	scanf("%d", &x);
	while (x != 9999) {
	    s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;

}
LinkList List_TailInsert(LinkList& L) {                       //尾插法建立链表
	InitList(L);
	LNode *s, *r; int x;
	r = L;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->next = r->next;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	return L;
}

void List_print(LinkList L) {					//打印链表
	L = L->next;
	for (int i = 1; L != NULL; i++) {
		printf("第%d个元素是%d\n", i,L->data);
		L = L->next;
	}
}

int  Counter(LinkList L) {                      //计数器
	int i = 0;
	while (L->next) {
		L = L->next;
		i++;
	}
	return i;
	//printf("一共有%d个元素\n",i);
}

LinkList GetElem(LinkList L, int i){			//	按序号查找
	if (0 == i)
		return L;
	if (i > Counter(L))
		return NULL;
	for (int j = 0; j < i; j++) {
		L = L->next;
	}
	return L;

}

LinkList Get_Elem(LinkList L, int e) {			//  按值查找
	L = L->next;
	while (e != L->data && L) {
		L = L->next;
	}
	if (NULL == L)
		return NULL;
	return L;
}

bool insertAtIndex(LinkList L, int i,int e) {			//在链表L的第i位置插入一个元素e
	if (0 == i|| i>Counter(L)+1 ){
		return false;
	}
	LinkList p = GetElem(L, i-1);
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
	
}

bool deleteAtIndex(LinkList L, int i) {
	if (0 == i || i > Counter(L) + 1) {
		return false;
	}
	LinkList p = GetElem(L, i-1);
	//printf("删除的元素是%d\n",p->next->data);
	p->next = p->next->next;
	return true;

}

void print_separator(char symbol, int length) {				//打印分割线
	int i;
	for (i = 0; i < length; i++) {
		putchar(symbol);
	}
	putchar('\n');
}


//	//LinkList L, s;
//	//List_TailInsert(L);                             //尾插法建表
//	//List_print(L);									//打印链表
//	//print_separator('*', 50);						//打印分隔符		
//	//insertAtIndex(L, 2, 8);							//插入节点
//	//s = GetElem(L, 2);
//	//printf("拿到的元素是%d\n", s->data);
//	//List_print(L);									//打印链表
//	//print_separator('*', 50);						//打印分隔符
//	//deleteAtIndex(L, 2);							//删除节点
//	//List_print(L);									//打印链表					
//	//print_separator('*', 50);						//打印分隔符						
//	
//

