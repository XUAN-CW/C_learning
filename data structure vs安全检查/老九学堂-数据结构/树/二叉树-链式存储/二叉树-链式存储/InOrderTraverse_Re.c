#include "InOrderTraverse_Re.h"
#include "LinkedStack.h"

void InOrderTraverse_Re(TreeNode * node) 
{
	//思路：
	//根据中序遍历的顺序，对任意结点来讲，优先访问左孩子，而左孩子又可以看做一个根结点
	//然后继续访问左孩子结点为空的结点，按照相同的规则访问右子树
	LinkedStack linkedStack;
	InitLinkedStack(&linkedStack);
	TreeNode * root = node;
	//currNode用来保存每个出栈的结点指针
	TreeNode * currNode = (TreeNode *)malloc(sizeof(TreeNode));
	//还需要一个临时指针，用来确保最后释放掉上面分配的内存
	TreeNode * tempNode = currNode;

	while (root || !IsLinkedStackEmpty(&linkedStack))
	{
		if (root) 
		{
			Push(&linkedStack, root);
			root = root->left;
		}
		else 
		{
			//难点
			Pop(&linkedStack, &currNode);
			printf("[%d, %s]-", currNode->data.id, currNode->data.name);
			root = currNode->right;
		}
	}
	free(tempNode);
}
