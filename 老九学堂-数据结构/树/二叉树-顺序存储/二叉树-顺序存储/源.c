#include <stdio.h>
#include <stdlib.h>
#include "SeqTree.h"

int main()
{
	SeqTree tree;
	InitSeqTree(tree);
	printf("�������������ݣ�");
	CreateSeqTree(tree, 0);
	printf("\n\n��������˳�򴢴�Ϊ��");
	for (int i = 0; i < 15; i++) 
	{
		printf("[%c]", tree[i]);
	}
	printf("\n");
	printf("�ܽ������%d\n", GetSeqTreeLength(tree));
	printf("��ǰ��ȣ�%d\n", GetSeqTreeDepth(tree));
	system("pause");
	return 0;
}
