#include <stdio.h>
#include <stdlib.h>
#include "ElementType.h"
#include "CreateBinaryTree.h"
#include "PreOrderTraverse.h"
#include "InOrderTraverse.h"
#include "PostOrderTraverse.h"
#include "ZOrderTraverse.h"
#include "InOrderTraverse_Re.h"
#include "CBTree.h"
#include "GetCBTreeDepth.h"


int main()
{
	BinaryTree tree;
	InitBinaryTree(&tree);
	//容易遗漏的点：根结点需要事先分配内存
	tree.root = (TreeNode *)malloc(sizeof(TreeNode));
	printf("请输入根结点：");
	CreateBinaryTree(tree.root);
	
	printf("\n\n前序遍历结果：\n");
	PreOrderTraverse(tree.root);
	
	printf("\n\n中序遍历结果：\n");
	InOrderTraverse(tree.root);
	
	printf("\n\n后序遍历结果：\n");
	PostOrderTraverse(tree.root);
	
	printf("\n\n层序遍历结果：\n");
	ZOrderTraverse(tree.root);
	
	printf("\n\n非递归的中序遍历：\n");
	InOrderTraverse_Re(tree.root);
	
	free(tree.root);


	//CBTree *cbTree;
	//InitCBTree(&cbTree);
	//printf("\nCBTree根结点为：");
	//CreateCBTree(&cbTree);
	//
	//printf("\nCBTree先序遍历：\n");
	//PreOrderCBTree(cbTree);
	//
	//printf("\nCBTree后序遍历：\n");
	//PostOrderCBTree(cbTree);


	system("pause");
    return 0;
}
