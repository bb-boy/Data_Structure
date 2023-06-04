#include <stdio.h>
#pragma warning(disable : 4996)
#include <corecrt_malloc.h>
#include <iostream>

/*��ͷ��㵥����*/

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;   

LinkList InitList(LinkList &L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;	
	return L;
}			//��ʼ������		

LinkList List_HeadInsert(LinkList &L) {             //ͷ�巨��������
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
LinkList List_TailInsert(LinkList& L) {                       //β�巨��������
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

void List_print(LinkList L) {					//��ӡ����
	L = L->next;
	for (int i = 1; L != NULL; i++) {
		printf("��%d��Ԫ����%d\n", i,L->data);
		L = L->next;
	}
}

int  Counter(LinkList L) {                      //������
	int i = 0;
	while (L->next) {
		L = L->next;
		i++;
	}
	return i;
	//printf("һ����%d��Ԫ��\n",i);
}

LinkList GetElem(LinkList L, int i){			//	����Ų���
	if (0 == i)
		return L;
	if (i > Counter(L))
		return NULL;
	for (int j = 0; j < i; j++) {
		L = L->next;
	}
	return L;

}

LinkList Get_Elem(LinkList L, int e) {			//  ��ֵ����
	L = L->next;
	while (e != L->data && L) {
		L = L->next;
	}
	if (NULL == L)
		return NULL;
	return L;
}

bool insertAtIndex(LinkList L, int i,int e) {			//������L�ĵ�iλ�ò���һ��Ԫ��e
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
	//printf("ɾ����Ԫ����%d\n",p->next->data);
	p->next = p->next->next;
	return true;

}

void print_separator(char symbol, int length) {				//��ӡ�ָ���
	int i;
	for (i = 0; i < length; i++) {
		putchar(symbol);
	}
	putchar('\n');
}


//	//LinkList L, s;
//	//List_TailInsert(L);                             //β�巨����
//	//List_print(L);									//��ӡ����
//	//print_separator('*', 50);						//��ӡ�ָ���		
//	//insertAtIndex(L, 2, 8);							//����ڵ�
//	//s = GetElem(L, 2);
//	//printf("�õ���Ԫ����%d\n", s->data);
//	//List_print(L);									//��ӡ����
//	//print_separator('*', 50);						//��ӡ�ָ���
//	//deleteAtIndex(L, 2);							//ɾ���ڵ�
//	//List_print(L);									//��ӡ����					
//	//print_separator('*', 50);						//��ӡ�ָ���						
//	
//

