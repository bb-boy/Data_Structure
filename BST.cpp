#include <stdio.h>
#include <malloc.h>
#pragma warning(disable : 4996)

/*二叉查找树基于递归实现
* 2023/5/24
*/

typedef int ElemType;
typedef struct BsTree {							//二叉树节点
	ElemType data;
	struct BsTree* Lchild, * Rchild;
}*BstNode,BsTree;


/*插入操作*/
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

/*查找操作*/
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
//	/*while循环插入操作，当为9999时跳出循环*/
//	while (true) {
//		scanf("%d", &c);
//		if (c == 9999) {        
//			break;
//		}
//		if (insertIntoBST(root, c))
//			printf("插入成功\n");
//		else
//			printf("插入失败\n");
//	}
//
//	BstNode search = Bst_search(root, 3, parent);
//	if (search)
//		printf("找到节点为%d,其父节点为%d", search->data, parent->data);
//	else
//		printf("没有这样的节点");
//	
//
//}
//	