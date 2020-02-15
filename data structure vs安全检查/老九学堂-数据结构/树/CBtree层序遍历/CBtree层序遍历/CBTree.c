#include <string.h>
#include <conio.h>
#include "CBTreeElement.h"
#include "LinkedQueue.h"


void InitCBTree(CBTree ** cbTree) 
{
	//使用二级指针可以在函数内部malloc
	*cbTree = (CBTree*)malloc(sizeof(CBNode));
	(*cbTree)->firstChild = NULL;
	(*cbTree)->nextSibling = NULL;
}

void CreateCBTree(CBNode ** cbNode) 
{
	/* 输入字符串 */
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
	//printf("%s的长子结点为：", (*cbNode)->data.name);
	//CreateCBTree(&((*cbNode)->firstChild));
	//printf("%s的兄弟结点为：", (*cbNode)->data.name);
	//CreateCBTree(&((*cbNode)->nextSibling));

	/* 输入字符 */
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
	printf("\n%s的长子结点为：", (*cbNode)->data.name);
	CreateCBTree(&((*cbNode)->firstChild));
	printf("\n%s的兄弟结点为：", (*cbNode)->data.name);
	CreateCBTree(&((*cbNode)->nextSibling));
}

void PreOrderCBTree(CBNode *cbNode) 
{
	/***
	 * 根结点的兄弟结点及兄弟的子结点访问不到 
	 * 测试数据：[父亲][我][][][叔叔][堂弟][][][][][][][][]
	 * 解决方法：加一个爷爷结点，根结点从父亲变成爷爷
	 */
	if (cbNode != NULL) 
	{
		/*** 从栈的角度理解 ***
		 *打印，有子，	入栈
		 *		无子，	tempNode = tempNode->nextSibling;
		 *		无兄弟，出栈，tempNode = 出栈元素.nextSibling
		 */
		printf("[%d, %s] ", cbNode->data.id, cbNode->data.name);	//访问了父结点
		CBNode *currentNode = cbNode->firstChild;					//访问了长子
		PreOrderCBTree(currentNode);
		while (currentNode) 
		{
			currentNode = currentNode->nextSibling;					//访问了长子的兄弟
			PreOrderCBTree(currentNode);
		}
	}
																	//没有访问父结点的兄弟
}

////一般的树没有中序遍历，只有先序和后序遍历
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





///** 销毁树 */
//void DestroyCBTree(CBTree * cbTree) {
//	if (*cbTree != NULL) {
//		free(*cbTree);
//	}
//}
//
//void TestCBTree() {
//	CBTree cbTree;
//	InitCBTree(&cbTree);
//	printf("根结点：");
//	CreateCBTree(&cbTree);
//	printf("\n");
//	printf("深度：%d\n", GetCBTreeDepth(cbTree));
//	printf("\n先序遍历：\n");
//	PreOrderCBTree(cbTree);
//	printf("\n中序遍历：\n");
//	InOrderCBTree(cbTree);
//	printf("\n后序遍历：\n");
//	PostOrderCBTree(cbTree);
//
//	//  测试数据：
	//                      A
	//               /      |     \
	//              B       C      D
	//             / \     /|\    / \
	//            E   F   G H I  J   K
	//根结点：A
	//请输入长子结点：B
	//请输入长子结点：E
	//请输入长子结点：
	//请输入兄弟结点：F
	//请输入长子结点：
	//请输入兄弟结点：
	//请输入兄弟结点：C
	//请输入长子结点：G
	//请输入长子结点：
	//请输入兄弟结点：H
	//请输入长子结点：
	//请输入兄弟结点：I
	//请输入长子结点：
	//请输入兄弟结点：
	//请输入兄弟结点：D
	//请输入长子结点：J
	//请输入长子结点：
	//请输入兄弟结点：K
	//请输入长子结点：
	//请输入兄弟结点：
	//请输入兄弟结点：
	//请输入兄弟结点：
	//
	//
	//第1层：[A]
	//第2层：[B] [C] [D]
	//第3层：[E] [F] [G] [H] [I] [J] [K] 深度：3
	//
	//先序遍历：
	//[1, A] [2, B] [3, E] [4, F] [5, C] [6, G] [7, H] [8, I] [9, D] [10, J] [11, K]
	//中序遍历：
	//
	//后序遍历：
	//[3, E] [4, F] [2, B] [6, G] [7, H] [8, I] [5, C] [10, J] [11, K] [9, D] [1, A]
//
//}







