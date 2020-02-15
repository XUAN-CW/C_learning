#define _CRT_SECURE_NO_WARNINGS 1    //vs环境下取消安全检查，其他编译器可删去此句
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct node
{
	ElementType Data;
	struct node* Left;
	struct node* Right;
}TreeNode,*Position,* BinTree;

Position FindMin(BinTree BST)
{
	if (!BST) 
	{
		return NULL; /*空的二叉搜索树，返回NULL*/
	}
	else if (!BST->Left)
	{
		return BST; /*找到最左叶结点并返回*/
	}
	else 
	{
		return FindMin(BST->Left); /*沿左分支继续查找*/
	}
}

Position FindMax(BinTree BST)
{
	if (BST)
	{
		while (BST->Right)
		{
			/*沿右分支继续查找，直到最右叶结点*/
			BST = BST->Right;
		}
	}
	return BST;
}

BinTree Insert(ElementType X, BinTree BST)
{
	if (!BST) {
		/*若原树为空，生成并返回一个结点的二叉搜索树*/
		BST = malloc(sizeof(TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else /*开始找要插入元素的位置*/
	{
		if (X < BST->Data) 
		{
			BST->Left = Insert(X, BST->Left);
		}
		/*递归插入左子树*/
		else if (X > BST->Data)
		{
			BST->Right = Insert(X, BST->Right);
		}
		/*递归插入右子树*/
		/* else X已经存在，什么都不做 */
	}
	return BST;
}

BinTree Delete(ElementType X, BinTree BST)
{
	Position Tmp;
	if (!BST)
	{
		printf("要删除的元素未找到");
	}
	else if (X < BST->Data)
	{
		BST->Left = Delete(X, BST->Left); /* 左子树递归删除 */
	}
	else if (X > BST->Data)
	{
		BST->Right = Delete(X, BST->Right); /* 右子树递归删除 */
	}
	else /*找到要删除的结点 */
	{
		if (BST->Left && BST->Right) /*被删除结点有左右两个子结点 */
		{ 
			Tmp = FindMin(BST->Right);
			/*在右子树中找最小的元素填充删除结点*/
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Data, BST->Right);
			/*在删除结点的右子树中删除最小元素*/
		}
		else /*被删除结点有一个或无子结点*/
		{
			Tmp = BST;
			if (!BST->Left) /* 有右孩子或无子结点*/
			{
				BST = BST->Right;
			}
			else if (!BST->Right) /*有左孩子或无子结点*/
			{
				BST = BST->Left;
			}
			free(Tmp);
		}
	}
	return BST;
}

Position Find(ElementType X, BinTree BST)
{
	if (!BST)
	{
		return NULL; /*查找失败*/
	}
	if (X > BST->Data)
	{
		return Find(X, BST->Right); /*在右子树中继续查找*/
	}
	else if (X < BST->Data)
	{
		return Find(X, BST->Left); /*在左子树中继续查找*/
	}
	else /* X == BST->Data */
	{
		return BST; /*查找成功，返回结点的找到结点的地址*/
	}
}

Position IterFind(ElementType X, BinTree BST)
{
	while (BST) {
		if (X > BST->Data)
		{
			BST = BST->Right; /*向右子树中移动，继续查找*/
		}
		else if (X < BST->Data)
		{
			BST = BST->Left; /*向左子树中移动，继续查找*/
		}
		else /* X == BST->Data */
		{
			return BST; /*查找成功，返回结点的找到结点的地址*/
		}
	}
	return NULL; /*查找失败*/
}

void order(BinTree tree) {
	if (tree)
	{
		order(tree->Left);
		printf("%d ", tree->Data);
		order(tree->Right);
	}
}

BinTree createTree()
{
	int numberOfNode;
	printf("节点数目：");
	scanf("%d", &numberOfNode);
	BinTree tree = NULL;
	for (int i = 0; i < numberOfNode; i++)
	{
		ElementType data;
		scanf("%d", &data);
		tree=Insert(data, tree);
	}
	return tree;
}

Position Findmin(ElementType x, BinTree BST) {
	if (BST)
	{
		BinTree father = NULL;
			while (BST) {
				if (x > BST->Data)
				{
					father = BST;
					BST = BST->Right; /*向右子树中移动，继续查找*/
				}
				else if (x < BST->Data)
				{
					father = BST;
					BST = BST->Left; /*向左子树中移动，继续查找*/
				}
				else /* X == BST->Data */
				{
					break; /*查找成功，返回结点的找到结点的地址*/
				}
			}

			if (BST->Left)
			{
				//有左子树，要找的节点就是左子树中最大的点
				return FindMax(BST->Left);
			}
			else
			{
				if (father)	//没有左子树，要找的节点就是该节点的父亲
				{
					return father;
				}
				else		//没有左子树也没有父亲，就没有比这个结点小的结点
				{
					printf("没有比这个结点小的结点\n");
					return NULL;
				}
			}
	}
	else
	{
		printf("树为空\n");
		return NULL;
	}
	

}

int main()
{
	BinTree tree = createTree();
	printf("中序遍历：");
	order(tree);
	printf("\n");

	printf("要查找的元素：");
	int searchElement;
	scanf("%d", &searchElement);
	TreeNode* node = Find(searchElement, tree);
	if (node)
	{
		printf("----%d\n",node->Data);
	}


	printf("比查找元素小一点：");
	int searchElement2;
	scanf("%d", &searchElement2);
	TreeNode* nodemin = Findmin(searchElement2, tree);
	if (nodemin)
	{
		printf("----%d\n", nodemin->Data);
	}

	printf("要删除的元素：");
	int deletedElement;
	scanf("%d", &deletedElement);
	Delete(deletedElement, tree);
	printf("删除后：");
	order(tree);
	printf("\n");

	return 0;
}