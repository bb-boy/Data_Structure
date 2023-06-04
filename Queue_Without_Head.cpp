//#include <stdio.h>
//#include <malloc.h>
//#pragma warning(disable : 4996)
//
///*无头结点的队列*/
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
//QueuePoint InitQueue(QueuePoint &p) {     //初始化队列
//	p.front = p.rear = NULL;
//	return p;
//	
//}
//
//bool isEmpty(QueuePoint p) {						//判断队列是否为空
//	if (p.front == NULL|| p.rear == NULL)
//		return true;
//	return false;
//}
//
//void CreateQueue(QueuePoint& p) {               //创建队列
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
//bool DelQueue(QueuePoint& p) {                       //删除队列节点
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
//void printQueue(QueuePoint p) {                                //打印队列
//	int i = 1;
//	while(p.front != NULL) {
//		printf("第%d个元素是%d\n", i, p.front->data);
//		i++;
//		p.front = p.front->next;
//	}
//}

//int main() {
//	QueuePoint p;
//	InitQueue(p);
//	if (isEmpty(p))
//		printf("队列是空的\n");
//	CreateQueue(p);
//	printQueue(p);
//	printf("********************************************\n");
//	if (isEmpty(p))
//		printf("队列是空的\n");
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
//		printf("队列是空的\n");
//	
//
//}