//#include <stdio.h>
//#include <malloc.h>
//#pragma warning(disable : 4996)
//
///*��ͷ���Ķ���*/
//
//typedef int ElemType;
//typedef struct QueueNode {
//	ElemType data;
//	struct QueueNode* next;
//}QueueList,*Queue;
//
//typedef struct  {
//	Queue front, rear;
//}QueuePoint;
//
//QueuePoint InitQueue(QueuePoint &p) {     //��ʼ������
//	p.front = p.rear = NULL;
//	return p;
//	
//}
//
//bool isEmpty(QueuePoint p) {						//�ж϶����Ƿ�Ϊ��
//	if (p.front == NULL|| p.rear == NULL)
//		return true;
//	return false;
//}
//
//void CreateQueue(QueuePoint& p) {               //��������
//	int a;
//	Queue s;
//	scanf("%d", &a);
//	while (a != 9999) {
//		s = (Queue)malloc(sizeof(QueueList));
//		s->data = a;
//		if (isEmpty(p)) 
//			p.front = p.rear = s;
//		else {
//			p.rear->next = s;
//			p.rear = s;
//		}
//		s->next = NULL;
//		scanf("%d", &a);
//	}	
//}
//
//void EnQueue(QueuePoint& p, ElemType a) {
//	Queue s =(Queue)malloc(sizeof(QueueList));
//	s->data = a;
//	if (isEmpty(p))
//		p.front = p.rear = s;
//	else {
//		p.rear->next = s;
//		p.rear = s;
//	}
//	s->next = NULL;
//}
//
//bool DelQueue(QueuePoint& p) {                       //ɾ�����нڵ�
//	if (isEmpty(p))
//		return false;
//	Queue q;
//	q = p.front;
//	p.front = p.front->next;
//	if (NULL == p.front)
//		p.rear = NULL;
//	return true;
//
//}
//
//void printQueue(QueuePoint p) {                                //��ӡ����
//	int i = 1;
//	while(p.front != NULL) {
//		printf("��%d��Ԫ����%d\n", i, p.front->data);
//		i++;
//		p.front = p.front->next;
//	}
//}

//int main() {
//	QueuePoint p;
//	InitQueue(p);
//	if (isEmpty(p))
//		printf("�����ǿյ�\n");
//	CreateQueue(p);
//	printQueue(p);
//	printf("********************************************\n");
//	if (isEmpty(p))
//		printf("�����ǿյ�\n");
//	DelQueue(p); 
//	DelQueue(p);
//	DelQueue(p);
//	DelQueue(p);
//
//	EnQueue(p, 3);
//	printQueue(p);
//	DelQueue(p);
//	printQueue(p);
//	if (isEmpty(p))
//		printf("�����ǿյ�\n");
//	
//
//}