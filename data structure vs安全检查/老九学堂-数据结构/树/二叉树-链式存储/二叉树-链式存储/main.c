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
	//������©�ĵ㣺�������Ҫ���ȷ����ڴ�
	tree.root = (TreeNode *)malloc(sizeof(TreeNode));
	printf("���������㣺");
	CreateBinaryTree(tree.root);
	
	printf("\n\nǰ����������\n");
	PreOrderTraverse(tree.root);
	
	printf("\n\n������������\n");
	InOrderTraverse(tree.root);
	
	printf("\n\n������������\n");
	PostOrderTraverse(tree.root);
	
	printf("\n\n������������\n");
	ZOrderTraverse(tree.root);
	
	printf("\n\n�ǵݹ�����������\n");
	InOrderTraverse_Re(tree.root);
	
	free(tree.root);


	//CBTree *cbTree;
	//InitCBTree(&cbTree);
	//printf("\nCBTree�����Ϊ��");
	//CreateCBTree(&cbTree);
	//
	//printf("\nCBTree���������\n");
	//PreOrderCBTree(cbTree);
	//
	//printf("\nCBTree���������\n");
	//PostOrderCBTree(cbTree);


	system("pause");
    return 0;
}
