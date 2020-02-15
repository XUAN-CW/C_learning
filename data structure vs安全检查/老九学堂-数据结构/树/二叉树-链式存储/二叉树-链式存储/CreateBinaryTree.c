#include "CreateBinaryTree.h"


void InitBinaryTree(BinaryTree * tree){
    tree->root = NULL;
    tree->depth = 0;
    tree->diameter = 0;
    tree->length = 0;
}

/** ��������� - �ⲿ��Ҫ���ȶԽ������ڴ� */
int CreateBinaryTree(TreeNode * root)
{
    //��������Ϊ�գ����˳���������
	if (!root)
	{
		return FAILURE;
	}
	else
	{
		char inputName[NAME_SIZE];  //�û�����Ľ����
		gets(inputName);
		//�û�����س���ʾ������ǰ�����Ĵ���
		if (strcmp(inputName, "\0") == 0)
		{
			return FAILURE;
		}

		//������ǰ���
		static int id = 0;	//����ʵ�ֽ��id�������� 
		root->data.id = ++id;
		strcpy_s(root->data.name, sizeof(root->data.name),inputName);
		//Ϊ�������ҽ����׼�� - Ϊ���ҽ��ָ������ڴ�
		root->left = (TreeNode *)malloc(sizeof(TreeNode));
		root->right = (TreeNode *)malloc(sizeof(TreeNode));
		//�ֱ�ݹ鴴����������������

		printf("%s�����㣺",root->data.name);
		if (CreateBinaryTree(root->left) == FAILURE)
		{
			//���ٴ�����������Ч�����շ�����ڴ�
			free(root->left);
			root->left = NULL;
		}
		printf("%s���ҽ�㣺", root->data.name);
		if (CreateBinaryTree(root->right) == FAILURE)
		{
			free(root->right);
			root->right = NULL;
		}
		return SUCCEED;
	}
}


