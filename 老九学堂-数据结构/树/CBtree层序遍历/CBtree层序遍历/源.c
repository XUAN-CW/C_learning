#include <stdio.h>
#include <stdlib.h>
#include "CBTree.h"
#include "GetCBTreeDepth.h"

int main()
{

	CBTree *cbTree;
	InitCBTree(&cbTree);
	printf("\nCBTree�����Ϊ��");
	CreateCBTree(&cbTree);

	printf("\nCBTree���������\n");
	PreOrderCBTree(cbTree);

	printf("\nCBTree���������\n");
	PostOrderCBTree(cbTree);


	system("pause");
	return 0;
}