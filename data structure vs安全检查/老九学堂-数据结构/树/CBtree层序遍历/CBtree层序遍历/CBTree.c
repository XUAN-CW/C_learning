#include <string.h>
#include <conio.h>
#include "CBTreeElement.h"
#include "LinkedQueue.h"


void InitCBTree(CBTree ** cbTree) 
{
	//ʹ�ö���ָ������ں����ڲ�malloc
	*cbTree = (CBTree*)malloc(sizeof(CBNode));
	(*cbTree)->firstChild = NULL;
	(*cbTree)->nextSibling = NULL;
}

void CreateCBTree(CBNode ** cbNode) 
{
	/* �����ַ��� */
	//char inputName[NAME_SIZE];
	//gets(inputName);
	//if (strcmp(inputName, "\0") == 0) 
	//{
	//	return;
	//}
	//if (*cbNode == NULL) 
	//{
	//	*cbNode = (CBNode *)malloc(sizeof(CBNode));
	//	(*cbNode)->firstChild = NULL;
	//	(*cbNode)->nextSibling = NULL;
	//}
	//static int id = 0;
	//(*cbNode)->data.id = ++id;
	//strcpy_s((*cbNode)->data.name, sizeof((*cbNode)->data.name),inputName);
	//printf("%s�ĳ��ӽ��Ϊ��", (*cbNode)->data.name);
	//CreateCBTree(&((*cbNode)->firstChild));
	//printf("%s���ֵܽ��Ϊ��", (*cbNode)->data.name);
	//CreateCBTree(&((*cbNode)->nextSibling));

	/* �����ַ� */
	char inputName;
	inputName = _getch();
	fflush(stdin);
	if (inputName == 13)
	{
		return;
	}
	if (*cbNode == NULL)
	{
		*cbNode = (CBNode *)malloc(sizeof(CBNode));
		(*cbNode)->firstChild = NULL;
		(*cbNode)->nextSibling = NULL;
	}
	static int id = 0;
	(*cbNode)->data.id = ++id;
	(*cbNode)->data.name[0] = inputName;
	(*cbNode)->data.name[1] = '\0';
	printf("\n%s�ĳ��ӽ��Ϊ��", (*cbNode)->data.name);
	CreateCBTree(&((*cbNode)->firstChild));
	printf("\n%s���ֵܽ��Ϊ��", (*cbNode)->data.name);
	CreateCBTree(&((*cbNode)->nextSibling));
}

void PreOrderCBTree(CBNode *cbNode) 
{
	/***
	 * �������ֵܽ�㼰�ֵܵ��ӽ����ʲ��� 
	 * �������ݣ�[����][��][][][����][�õ�][][][][][][][][]
	 * �����������һ��үү��㣬�����Ӹ��ױ��үү
	 */
	if (cbNode != NULL) 
	{
		/*** ��ջ�ĽǶ���� ***
		 *��ӡ�����ӣ�	��ջ
		 *		���ӣ�	tempNode = tempNode->nextSibling;
		 *		���ֵܣ���ջ��tempNode = ��ջԪ��.nextSibling
		 */
		printf("[%d, %s] ", cbNode->data.id, cbNode->data.name);	//�����˸����
		CBNode *currentNode = cbNode->firstChild;					//�����˳���
		PreOrderCBTree(currentNode);
		while (currentNode) 
		{
			currentNode = currentNode->nextSibling;					//�����˳��ӵ��ֵ�
			PreOrderCBTree(currentNode);
		}
	}
																	//û�з��ʸ������ֵ�
}

////һ�����û�����������ֻ������ͺ������
//void InOrderCBTree(CBNode *cbNode) {}

void PostOrderCBTree(CBNode *cbNode) 
{
	if (cbNode != NULL) 
	{
		CBNode *currentNode = cbNode->firstChild;
		PostOrderCBTree(currentNode);
		while (currentNode) 
		{
			currentNode = currentNode->nextSibling;
			PostOrderCBTree(currentNode);
		}
		printf("[%d, %s] ", cbNode->data.id, cbNode->data.name);
	}
}





///** ������ */
//void DestroyCBTree(CBTree * cbTree) {
//	if (*cbTree != NULL) {
//		free(*cbTree);
//	}
//}
//
//void TestCBTree() {
//	CBTree cbTree;
//	InitCBTree(&cbTree);
//	printf("����㣺");
//	CreateCBTree(&cbTree);
//	printf("\n");
//	printf("��ȣ�%d\n", GetCBTreeDepth(cbTree));
//	printf("\n���������\n");
//	PreOrderCBTree(cbTree);
//	printf("\n���������\n");
//	InOrderCBTree(cbTree);
//	printf("\n���������\n");
//	PostOrderCBTree(cbTree);
//
//	//  �������ݣ�
	//                      A
	//               /      |     \
	//              B       C      D
	//             / \     /|\    / \
	//            E   F   G H I  J   K
	//����㣺A
	//�����볤�ӽ�㣺B
	//�����볤�ӽ�㣺E
	//�����볤�ӽ�㣺
	//�������ֵܽ�㣺F
	//�����볤�ӽ�㣺
	//�������ֵܽ�㣺
	//�������ֵܽ�㣺C
	//�����볤�ӽ�㣺G
	//�����볤�ӽ�㣺
	//�������ֵܽ�㣺H
	//�����볤�ӽ�㣺
	//�������ֵܽ�㣺I
	//�����볤�ӽ�㣺
	//�������ֵܽ�㣺
	//�������ֵܽ�㣺D
	//�����볤�ӽ�㣺J
	//�����볤�ӽ�㣺
	//�������ֵܽ�㣺K
	//�����볤�ӽ�㣺
	//�������ֵܽ�㣺
	//�������ֵܽ�㣺
	//�������ֵܽ�㣺
	//
	//
	//��1�㣺[A]
	//��2�㣺[B] [C] [D]
	//��3�㣺[E] [F] [G] [H] [I] [J] [K] ��ȣ�3
	//
	//���������
	//[1, A] [2, B] [3, E] [4, F] [5, C] [6, G] [7, H] [8, I] [9, D] [10, J] [11, K]
	//���������
	//
	//���������
	//[3, E] [4, F] [2, B] [6, G] [7, H] [8, I] [5, C] [10, J] [11, K] [9, D] [1, A]
//
//}







