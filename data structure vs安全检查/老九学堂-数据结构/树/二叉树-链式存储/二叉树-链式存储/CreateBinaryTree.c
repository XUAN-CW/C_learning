#include "CreateBinaryTree.h"


void InitBinaryTree(BinaryTree * tree){
    tree->root = NULL;
    tree->depth = 0;
    tree->diameter = 0;
    tree->length = 0;
}

/** 构造二叉树 - 外部需要事先对结点分配内存 */
int CreateBinaryTree(TreeNode * root)
{
    //根结点如果为空，就退出创建过程
	if (!root)
	{
		return FAILURE;
	}
	else
	{
		char inputName[NAME_SIZE];  //用户输入的结点名
		gets(inputName);
		//用户输入回车表示结束当前子树的创建
		if (strcmp(inputName, "\0") == 0)
		{
			return FAILURE;
		}

		//创建当前结点
		static int id = 0;	//用来实现结点id的自增长 
		root->data.id = ++id;
		strcpy_s(root->data.name, sizeof(root->data.name),inputName);
		//为输入左右结点做准备 - 为左右结点指针分配内存
		root->left = (TreeNode *)malloc(sizeof(TreeNode));
		root->right = (TreeNode *)malloc(sizeof(TreeNode));
		//分别递归创建左子树和右子树

		printf("%s的左结点：",root->data.name);
		if (CreateBinaryTree(root->left) == FAILURE)
		{
			//不再创建这个结点则效果结点刚分配的内存
			free(root->left);
			root->left = NULL;
		}
		printf("%s的右结点：", root->data.name);
		if (CreateBinaryTree(root->right) == FAILURE)
		{
			free(root->right);
			root->right = NULL;
		}
		return SUCCEED;
	}
}


