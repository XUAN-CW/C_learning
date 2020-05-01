#include <stdio.h>
#include <stdlib.h>
#include "CBTree.h"
#include "GetCBTreeDepth.h"

int main()
{

	CBTree *cbTree;
	InitCBTree(&cbTree);
	printf("\nCBTree根结点为：");
	CreateCBTree(&cbTree);

	printf("\nCBTree先序遍历：\n");
	PreOrderCBTree(cbTree);

	printf("\nCBTree后序遍历：\n");
	PostOrderCBTree(cbTree);


	system("pause");
	return 0;
}