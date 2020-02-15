#define _CRT_SECURE_NO_WARNINGS 1    //vs������ȡ����ȫ��飬������������ɾȥ�˾�
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
		return NULL; /*�յĶ���������������NULL*/
	}
	else if (!BST->Left)
	{
		return BST; /*�ҵ�����Ҷ��㲢����*/
	}
	else 
	{
		return FindMin(BST->Left); /*�����֧��������*/
	}
}

Position FindMax(BinTree BST)
{
	if (BST)
	{
		while (BST->Right)
		{
			/*���ҷ�֧�������ң�ֱ������Ҷ���*/
			BST = BST->Right;
		}
	}
	return BST;
}

BinTree Insert(ElementType X, BinTree BST)
{
	if (!BST) {
		/*��ԭ��Ϊ�գ����ɲ�����һ�����Ķ���������*/
		BST = malloc(sizeof(TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else /*��ʼ��Ҫ����Ԫ�ص�λ��*/
	{
		if (X < BST->Data) 
		{
			BST->Left = Insert(X, BST->Left);
		}
		/*�ݹ����������*/
		else if (X > BST->Data)
		{
			BST->Right = Insert(X, BST->Right);
		}
		/*�ݹ����������*/
		/* else X�Ѿ����ڣ�ʲô������ */
	}
	return BST;
}

BinTree Delete(ElementType X, BinTree BST)
{
	Position Tmp;
	if (!BST)
	{
		printf("Ҫɾ����Ԫ��δ�ҵ�");
	}
	else if (X < BST->Data)
	{
		BST->Left = Delete(X, BST->Left); /* �������ݹ�ɾ�� */
	}
	else if (X > BST->Data)
	{
		BST->Right = Delete(X, BST->Right); /* �������ݹ�ɾ�� */
	}
	else /*�ҵ�Ҫɾ���Ľ�� */
	{
		if (BST->Left && BST->Right) /*��ɾ����������������ӽ�� */
		{ 
			Tmp = FindMin(BST->Right);
			/*��������������С��Ԫ�����ɾ�����*/
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Data, BST->Right);
			/*��ɾ��������������ɾ����СԪ��*/
		}
		else /*��ɾ�������һ�������ӽ��*/
		{
			Tmp = BST;
			if (!BST->Left) /* ���Һ��ӻ����ӽ��*/
			{
				BST = BST->Right;
			}
			else if (!BST->Right) /*�����ӻ����ӽ��*/
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
		return NULL; /*����ʧ��*/
	}
	if (X > BST->Data)
	{
		return Find(X, BST->Right); /*���������м�������*/
	}
	else if (X < BST->Data)
	{
		return Find(X, BST->Left); /*���������м�������*/
	}
	else /* X == BST->Data */
	{
		return BST; /*���ҳɹ������ؽ����ҵ����ĵ�ַ*/
	}
}

Position IterFind(ElementType X, BinTree BST)
{
	while (BST) {
		if (X > BST->Data)
		{
			BST = BST->Right; /*�����������ƶ�����������*/
		}
		else if (X < BST->Data)
		{
			BST = BST->Left; /*�����������ƶ�����������*/
		}
		else /* X == BST->Data */
		{
			return BST; /*���ҳɹ������ؽ����ҵ����ĵ�ַ*/
		}
	}
	return NULL; /*����ʧ��*/
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
	printf("�ڵ���Ŀ��");
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
					BST = BST->Right; /*�����������ƶ�����������*/
				}
				else if (x < BST->Data)
				{
					father = BST;
					BST = BST->Left; /*�����������ƶ�����������*/
				}
				else /* X == BST->Data */
				{
					break; /*���ҳɹ������ؽ����ҵ����ĵ�ַ*/
				}
			}

			if (BST->Left)
			{
				//����������Ҫ�ҵĽڵ���������������ĵ�
				return FindMax(BST->Left);
			}
			else
			{
				if (father)	//û����������Ҫ�ҵĽڵ���Ǹýڵ�ĸ���
				{
					return father;
				}
				else		//û��������Ҳû�и��ף���û�б�������С�Ľ��
				{
					printf("û�б�������С�Ľ��\n");
					return NULL;
				}
			}
	}
	else
	{
		printf("��Ϊ��\n");
		return NULL;
	}
	

}

int main()
{
	BinTree tree = createTree();
	printf("���������");
	order(tree);
	printf("\n");

	printf("Ҫ���ҵ�Ԫ�أ�");
	int searchElement;
	scanf("%d", &searchElement);
	TreeNode* node = Find(searchElement, tree);
	if (node)
	{
		printf("----%d\n",node->Data);
	}


	printf("�Ȳ���Ԫ��Сһ�㣺");
	int searchElement2;
	scanf("%d", &searchElement2);
	TreeNode* nodemin = Findmin(searchElement2, tree);
	if (nodemin)
	{
		printf("----%d\n", nodemin->Data);
	}

	printf("Ҫɾ����Ԫ�أ�");
	int deletedElement;
	scanf("%d", &deletedElement);
	Delete(deletedElement, tree);
	printf("ɾ����");
	order(tree);
	printf("\n");

	return 0;
}