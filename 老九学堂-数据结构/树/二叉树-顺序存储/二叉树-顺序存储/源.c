#include <stdio.h>
#include <stdlib.h>
#include "SeqTree.h"

int main()
{
	SeqTree tree;
	InitSeqTree(tree);
	printf("请输入根结点内容：");
	CreateSeqTree(tree, 0);
	printf("\n\n二叉树的顺序储存为：");
	for (int i = 0; i < 15; i++) 
	{
		printf("[%c]", tree[i]);
	}
	printf("\n");
	printf("总结点数：%d\n", GetSeqTreeLength(tree));
	printf("当前深度：%d\n", GetSeqTreeDepth(tree));
	system("pause");
	return 0;
}
