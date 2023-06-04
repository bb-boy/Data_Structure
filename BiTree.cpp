#include <stdio.h>
#include <malloc.h>
#pragma warning(disable : 4996)

typedef char BiElemType;

typedef struct BiTree {                  //�������ڵ�
	BiElemType data;
	struct BiTree* Lchild, * Rchild;
}BiTree,*TreeNode;

typedef struct QueueNode {          //���нڵ�
	TreeNode data;
	struct QueueNode* next;
}QueueList, * Queue;

typedef struct {                    //����ͷβָ��
	Queue front, rear,head;
}QueuePoint;

QueuePoint InitQueue(QueuePoint& p) {     //��ʼ������
	p.front = p.rear = p.head=NULL;
	return p;

}

bool isEmpty(QueuePoint p) {						//�ж϶����Ƿ�Ϊ��
	if (p.front == NULL || p.rear == NULL)
		return true;
	return false;
}


Queue EnQueue(QueuePoint& p, TreeNode a) {                 //���
	Queue s = (Queue)malloc(sizeof(QueueList));
	s->data = a;
	if (isEmpty(p)) {
		p.front = p.rear = p.head=s;
		s->next = NULL;
		return s;
	}
	else {
		p.rear->next = s;
		p.rear = s;
	}
	s->next = NULL;
}

bool DelQueue(QueuePoint& p) {                       //ɾ�����нڵ�
	if (isEmpty(p))
		return false;
	Queue q;
	q = p.front;
	//free(p.front);                                //�ͷŽڵ�
	p.front = p.front->next;
	if (NULL == p.front)
		p.rear = p.head=NULL;

	return true;

}

            
void InitTree(QueuePoint &p,BiTree* &bt) {                    //��ʼ�����͸�������
	bt = (TreeNode)calloc(1,sizeof(BiTree));
	InitQueue(p);
}

bool CreateTree(QueuePoint& p, BiTree*& bt,BiElemType c) {         //������

	if (NULL == p.front) {                                  //���Ϊ������data���������������
		bt->data = c;
		//printf("�ɹ���������\n");
		EnQueue(p, bt);
		return true;
	}	

	TreeNode s = (TreeNode)calloc(1, sizeof(BiTree));       //�µ����ڵ�
	EnQueue(p, s);											//�½ڵ����	
	s->data = c;											//data���½ڵ�		
		
	if (NULL == p.front->data->Lchild) {                    //����Ϊ�գ��½ڵ��Ϊ����
		p.front->data->Lchild = s;
		//printf("�ɹ���������\n");
		return true;
	}

	else
	{
		p.front->data->Rchild = s;							//�Һ���Ϊ�գ��½ڵ��Ϊ�Һ��ӣ�����ͷ����
		DelQueue(p);
		//printf("�ɹ������Һ���\n");
		return true;
	}
	
	return false;
}

void  LevelOrder(QueuePoint p) {        //�������
	while (true) {
		putchar(p.head->data->data);
		if (p.head->next == NULL)
			break;
		p.head = p.head->next;

	}
}

void InOrder(BiTree *a) {               //�������
	if (a != NULL) {                      
		InOrder(a->Lchild);             //������
		putchar(a->data);
		InOrder(a->Rchild);
	}

}

void ProOrder(BiTree* a) {               //ǰ�����
	if (a != NULL) {
		putchar(a->data);
		ProOrder(a->Lchild);             //������
		
		ProOrder(a->Rchild);
	}

}

void PostOrder(BiTree* a) {               //�������
	if (a != NULL) {
		PostOrder(a->Lchild);             //������
		
		PostOrder(a->Rchild);
		putchar(a->data);
	}

}

//int main() {
//	QueuePoint p;
//	BiTree* bt;
//	InitTree(p, bt);
//	char c;
//	Queue head;
//	while (true) {
//		scanf("%c", &c);
//		if (c == '\n') {
//			break;
//		}
//		if (CreateTree(p, bt, c))
//			printf("Success\n");
//	}
//	
//	InOrder(bt);
//	printf("\n");
//	ProOrder(bt);
//	printf("\n");
//	PostOrder(bt);
//	printf("\n");
//	LevelOrder(p);
//	
//}