#include <stdio.h>
#define Maxsize 50
typedef int ElemType;

/*˳���ʵ�ִ�ͷ������*/
typedef struct {
	ElemType data[Maxsize];
	int rear, front;
}SqQueue;

bool Init_Queue(SqQueue& s) {      //��ʼ������ָ��Ϊ-1
	s.front = s.rear = -1;
	return true;
}

bool IsEmpty(SqQueue s) {			//�п�
	if (s.front == s.rear)
		return true;
	else
		return false;
}
bool IsFull(SqQueue s) {			//�ж϶����ǲ����Ѿ�����
	int a = s.rear - s.front;
	return a > Maxsize;
	return  a <= Maxsize;
}


bool EnQueue(SqQueue& s, ElemType e) {		//���
	if (!IsFull(s)) {
		s.data[++s.rear] = e;
		return true;
	}
	else
		return false;
}


bool DeQueue(SqQueue& s) {				//���ӣ��ն�ʱ��ʼ�����У���ɾ����Ԫ�������һ��Ԫ�أ�ɾ����Ԫ�ز���ʼ������
	if (IsEmpty(s)) {
		Init_Queue(s);
		return false;
	}
	else {
		int a = s.data[++s.front];
		printf("ɾ����Ԫ����%d\n", a);	
		while (IsEmpty(s)) {
			Init_Queue(s);
			printf("������ɾ���꣬���ѳ�ʼ��\n");
			break;
		}
		return true;
	}
}

bool Get_HeadElem(SqQueue s) {             //��ö���ͷԪ��
	if (IsEmpty(s))
		return false;
	ElemType a;
	a = s.data[++s.front];
	printf("��ͷԪ����%d\n", a);
	return true;
}

void PrtQue(SqQueue s) {                  //��ӡ����
	
	for (int i = 1; s.front < s.rear; i++) {
		printf("��%d��Ԫ����%d\n", i, s.data[++s.front]);

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
//		printf("�ǿձ�\n");
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