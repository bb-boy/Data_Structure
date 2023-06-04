#include <stdio.h>
#include <malloc.h>
#pragma warning(disable : 4996)

/*��ͷ���˫����*/

typedef int ElemType;
typedef struct DLinkNode {
	ElemType data;
	struct DLinkNode* prior;
	struct DLinkNode* next;
}DLinkNode, *DLinkList;

DLinkList InitDLink(DLinkList &L) {           //��ʼ������
	L = (DLinkList)malloc(sizeof(DLinkNode));
	L->prior = NULL, L->next = NULL;
	return L;
}

int  Counter(DLinkList L) {                      //������
	int i = 0;
	while (L->next) {
		L = L->next;
		i++;
	}
	return i;
	//printf("һ����%d��Ԫ��\n",i);
}

DLinkList GetElem(DLinkList L, int i) {
	//��λ����
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



DLinkList DList_HeadInsert(DLinkList& L) {			//ͷ�巨����˫����
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

DLinkList DList_TailInsert(DLinkList& L) {             //β�巨����˫����
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

bool insertAtIndex(DLinkList L, int i,ElemType e) {          //L�ĵ�i��λ�ò���e
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

bool deletetAtIndex(DLinkList L, int i) {               //ɾ��L�е�i�ڵ�
	int a = Counter(L);
	if (0 == i || i > (a + 1)) {
		return false;
	}
	DLinkList s = GetElem(L,i);
	s->prior->next = s->next;
	if (s->next != NULL)
		s->next->prior = s->prior;
	printf("ɾ����Ԫ����%d\n", s->data);
	return true;
}

void sum(DLinkList L) {								//��ӡ�ڵ���
	printf("�ڵ�һ����%d��\n", Counter(L));
}

void PrinLt(DLinkList L) {                           //˳���ӡ����
	for (int i = 1;L->next != NULL; i++) {
		printf("��%d���ڵ���%d\n", i, L->next->data);
		L = L->next;
	}
}

void printseparator(char symbol, int length) {				//��ӡ�ָ���
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
//	//printf("�õ��Ľڵ���%d\n", c->data);
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