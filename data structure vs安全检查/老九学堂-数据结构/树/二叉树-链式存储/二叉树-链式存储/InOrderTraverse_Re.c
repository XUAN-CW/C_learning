#include "InOrderTraverse_Re.h"
#include "LinkedStack.h"

void InOrderTraverse_Re(TreeNode * node) 
{
	//˼·��
	//�������������˳�򣬶����������������ȷ������ӣ��������ֿ��Կ���һ�������
	//Ȼ������������ӽ��Ϊ�յĽ�㣬������ͬ�Ĺ������������
	LinkedStack linkedStack;
	InitLinkedStack(&linkedStack);
	TreeNode * root = node;
	//currNode��������ÿ����ջ�Ľ��ָ��
	TreeNode * currNode = (TreeNode *)malloc(sizeof(TreeNode));
	//����Ҫһ����ʱָ�룬����ȷ������ͷŵ����������ڴ�
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
			//�ѵ�
			Pop(&linkedStack, &currNode);
			printf("[%d, %s]-", currNode->data.id, currNode->data.name);
			root = currNode->right;
		}
	}
	free(tempNode);
}
