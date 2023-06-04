#include <stdio.h.>
#include <malloc.h>

/*链表实现带头结点队列*/

typedef int ElemType;
typedef struct LinkNode {				//队列节点
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct {					 //LinkNode型指针
	LinkNode* front, * rear;
}LinkQueue;

void Init_LinkQueue(LinkQueue &s) {					//初始化将rear和front指针指向头节点
	s.front = s.rear = (LinkNode*)malloc(sizeof(LinkNode));
	s.rear->next = NULL;
}

bool IsEmpty(LinkQueue p) {                        //使用front指针判空
	if (p.front->next == NULL)
		return true;
	else
		return false;
}

bool EnLinkQueue(LinkQueue& p,ElemType e) {			//尾插法入队
	LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = e;
	p.rear->next =s;
	s->next = NULL;
	p.rear = s;
	return true;

}

bool DeLinkQueue(LinkQueue& p) {                       //删除节点
	if (IsEmpty(p)) {
		printf("无法执行删除操作，队列为空");
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
		printf("这是一个空表\n");
		return false;
	}
	printf("队头元素是%d\n", s.front->next->data);
	return true;

}

void PrtLQue(LinkQueue p) {                        //从front到rear打印队列
	for (int i = 1; p.front->next != NULL; i++) {
		printf("第%d个元素是%d\n", i, p.front->next->data);
		p.front=p.front->next;
	}
}



//int main() {
//	
//	LinkQueue s;
//	Init_LinkQueue( s);
//	if (IsEmpty(s))
//		printf("这是个空队列\n");
//	EnLinkQueue(s, 2);
//	//if (IsEmpty(s))
//	//	printf("这是个空队列\n");
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