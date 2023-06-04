#include <stdio.h>
#define Maxsize 50
typedef int ElemType;

/*顺序表实现带头结点队列*/
typedef struct {
	ElemType data[Maxsize];
	int rear, front;
}SqQueue;

bool Init_Queue(SqQueue& s) {      //初始化队列指针为-1
	s.front = s.rear = -1;
	return true;
}

bool IsEmpty(SqQueue s) {			//判空
	if (s.front == s.rear)
		return true;
	else
		return false;
}
bool IsFull(SqQueue s) {			//判断队列是不是已经满了
	int a = s.rear - s.front;
	return a > Maxsize;
	return  a <= Maxsize;
}


bool EnQueue(SqQueue& s, ElemType e) {		//入队
	if (!IsFull(s)) {
		s.data[++s.rear] = e;
		return true;
	}
	else
		return false;
}


bool DeQueue(SqQueue& s) {				//出队，空队时初始化队列，若删除的元素是最后一个元素，删除该元素并初始化队列
	if (IsEmpty(s)) {
		Init_Queue(s);
		return false;
	}
	else {
		int a = s.data[++s.front];
		printf("删除的元素是%d\n", a);	
		while (IsEmpty(s)) {
			Init_Queue(s);
			printf("队列已删除完，并已初始化\n");
			break;
		}
		return true;
	}
}

bool Get_HeadElem(SqQueue s) {             //获得队列头元素
	if (IsEmpty(s))
		return false;
	ElemType a;
	a = s.data[++s.front];
	printf("队头元素是%d\n", a);
	return true;
}

void PrtQue(SqQueue s) {                  //打印队列
	
	for (int i = 1; s.front < s.rear; i++) {
		printf("第%d个元素是%d\n", i, s.data[++s.front]);

		}
	
}

//int main() {
//	SqQueue q;
//	Init_Queue(q);
//	EnQueue(q, 2);
//	EnQueue(q, 3);
//	EnQueue(q, 4);
//	PrtQue(q);
//	if (IsEmpty(q))
//		printf("是空表\n");
//
//	Get_HeadElem(q);
//	printf("***********************************************\n");
//	DeQueue(q);
//	PrtQue(q);
//	Get_HeadElem(q);
//	printf("***********************************************\n");
//	DeQueue(q);
//	PrtQue(q);
//	Get_HeadElem(q);
//	printf("***********************************************\n");
//	DeQueue(q);
//	PrtQue(q);
//	
//	if (Get_HeadElem(q) == false)
//		printf("%d", q.rear);
//}