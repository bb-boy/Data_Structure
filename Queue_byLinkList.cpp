#include <stdio.h.>
#include <malloc.h>

/*����ʵ�ִ�ͷ������*/

typedef int ElemType;
typedef struct LinkNode {				//���нڵ�
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct {					 //LinkNode��ָ��
	LinkNode* front, * rear;
}LinkQueue;

void Init_LinkQueue(LinkQueue &s) {					//��ʼ����rear��frontָ��ָ��ͷ�ڵ�
	s.front = s.rear = (LinkNode*)malloc(sizeof(LinkNode));
	s.rear->next = NULL;
}

bool IsEmpty(LinkQueue p) {                        //ʹ��frontָ���п�
	if (p.front->next == NULL)
		return true;
	else
		return false;
}

bool EnLinkQueue(LinkQueue& p,ElemType e) {			//β�巨���
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	p.rear->next =s;
	s->next = NULL;
	p.rear = s;
	return true;

}

bool DeLinkQueue(LinkQueue& p) {                       //ɾ���ڵ�
	if (IsEmpty(p)) {
		printf("�޷�ִ��ɾ������������Ϊ��");
		return false;
	}
	
	LinkNode* r = p.front->next;
	p.front->next = p.front->next->next;
	free(r);
	if (p.front->data == NULL)
		p.rear = p.front;

	return true;

}

bool Get_QLFront(LinkQueue s){
	if (IsEmpty(s)) {
		printf("����һ���ձ�\n");
		return false;
	}
	printf("��ͷԪ����%d\n", s.front->next->data);
	return true;

}

void PrtLQue(LinkQueue p) {                        //��front��rear��ӡ����
	for (int i = 1; p.front->next != NULL; i++) {
		printf("��%d��Ԫ����%d\n", i, p.front->next->data);
		p.front=p.front->next;
	}
}



//int main() {
//	
//	LinkQueue s;
//	Init_LinkQueue( s);
//	if (IsEmpty(s))
//		printf("���Ǹ��ն���\n");
//	EnLinkQueue(s, 2);
//	//if (IsEmpty(s))
//	//	printf("���Ǹ��ն���\n");
//	EnLinkQueue(s, 3);
//
//	EnLinkQueue(s, 4);
//	PrtLQue(s);
//	DeLinkQueue(s); 
//	Get_QLFront(s);
//	DeLinkQueue(s);
//	Get_QLFront(s);
//	DeLinkQueue(s);
//	Get_QLFront(s);
//}