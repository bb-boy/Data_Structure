#include <stdio.h>
#include <malloc.h>
#pragma warning(disable : 4996)

typedef char BiElemType;

typedef struct BiTree {                  //二叉树节点
	BiElemType data;
	struct BiTree* Lchild, * Rchild;
}BiTree,*TreeNode;

typedef struct QueueNode {          //队列节点
	TreeNode data;
	struct QueueNode* next;
}QueueList, * Queue;

typedef struct {                    //队列头尾指针
	Queue front, rear,head;
}QueuePoint;

QueuePoint InitQueue(QueuePoint& p) {     //初始化队列
	p.front = p.rear = p.head=NULL;
	return p;

}

bool isEmpty(QueuePoint p) {						//判断队列是否为空
	if (p.front == NULL || p.rear == NULL)
		return true;
	return false;
}


Queue EnQueue(QueuePoint& p, TreeNode a) {                 //入队
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

bool DelQueue(QueuePoint& p) {                       //删除队列节点
	if (isEmpty(p))
		return false;
	Queue q;
	q = p.front;
	//free(p.front);                                //释放节点
	p.front = p.front->next;
	if (NULL == p.front)
		p.rear = p.head=NULL;

	return true;

}

            
void InitTree(QueuePoint &p,BiTree* &bt) {                    //初始化树和辅助队列
	bt = (TreeNode)calloc(1,sizeof(BiTree));
	InitQueue(p);
}

bool CreateTree(QueuePoint& p, BiTree*& bt,BiElemType c) {         //层序建树

	if (NULL == p.front) {                                  //如果为空树，data给树根，树根入队
		bt->data = c;
		//printf("成功插入树根\n");
		EnQueue(p, bt);
		return true;
	}	

	TreeNode s = (TreeNode)calloc(1, sizeof(BiTree));       //新的树节点
	EnQueue(p, s);											//新节点入队	
	s->data = c;											//data给新节点		
		
	if (NULL == p.front->data->Lchild) {                    //左孩子为空，新节点成为左孩子
		p.front->data->Lchild = s;
		//printf("成功插入左孩子\n");
		return true;
	}

	else
	{
		p.front->data->Rchild = s;							//右孩子为空，新节点成为右孩子，队列头出队
		DelQueue(p);
		//printf("成功插入右孩子\n");
		return true;
	}
	
	return false;
}

void  LevelOrder(QueuePoint p) {        //层序遍历
	while (true) {
		putchar(p.head->data->data);
		if (p.head->next == NULL)
			break;
		p.head = p.head->next;

	}
}

void InOrder(BiTree *a) {               //中序遍历
	if (a != NULL) {                      
		InOrder(a->Lchild);             //左中右
		putchar(a->data);
		InOrder(a->Rchild);
	}

}

void ProOrder(BiTree* a) {               //前序遍历
	if (a != NULL) {
		putchar(a->data);
		ProOrder(a->Lchild);             //中左右
		
		ProOrder(a->Rchild);
	}

}

void PostOrder(BiTree* a) {               //后序遍历
	if (a != NULL) {
		PostOrder(a->Lchild);             //左右中
		
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