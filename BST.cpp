#include <stdio.h>
#include <malloc.h>
#pragma warning(disable : 4996)

/*������������ڵݹ�ʵ��
* 2023/5/24
*/

typedef int ElemType;
typedef struct BsTree {							//�������ڵ�
	ElemType data;
	struct BsTree* Lchild, * Rchild;
}*BstNode,BsTree;


/*�������*/
bool insertIntoBST(BsTree*& root, ElemType e) {

	if (root == NULL) {
		root = (BsTree*)calloc(1, sizeof(BsTree));
		root->data = e;
		return true;
	}

	if (e < root->data)
		return insertIntoBST(root->Lchild, e);
			
	if (e > root->data)
		return insertIntoBST(root->Rchild, e);

	if (e = root->data)
		return false;
}

/*���Ҳ���*/
BstNode Bst_search(BsTree* root, ElemType e, BstNode &parent) {
	

	while (true) {


	    if (e < root->data) {
			parent = root;
			root = root->Lchild;

		}
		else if (e > root->data) {
			parent = root;
			root = root->Rchild;
		}


	   if (root == NULL || e == root->data) {
			return root;
			break;
		}
		
		
			

	}
}


//int main() {
//	BsTree* root;
//	BstNode parent;
//	root = NULL;
//	ElemType c;
//	
//	/*whileѭ�������������Ϊ9999ʱ����ѭ��*/
//	while (true) {
//		scanf("%d", &c);
//		if (c == 9999) {        
//			break;
//		}
//		if (insertIntoBST(root, c))
//			printf("����ɹ�\n");
//		else
//			printf("����ʧ��\n");
//	}
//
//	BstNode search = Bst_search(root, 3, parent);
//	if (search)
//		printf("�ҵ��ڵ�Ϊ%d,�丸�ڵ�Ϊ%d", search->data, parent->data);
//	else
//		printf("û�������Ľڵ�");
//	
//
//}
//	