#ifndef ELEMENTTYPE_H_INCLUDED
#define ELEMENTTYPE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024
#define NAME_SIZE 255
#define SUCCEED 1
#define FAILURE 0

typedef struct 
{
    int id;
    char name[NAME_SIZE];
}ElementType;

typedef struct treeNode 
{
	ElementType data;           //������������
	struct treeNode * left;     //������
	struct treeNode * right;    //������
}TreeNode;

//�������� 
typedef struct 
{
	TreeNode * root;        //�������ĸ����
	int length;             //���������������
	int depth;              //������������
	int diameter;           //ֱ�� - ��Ҷ��㵽Ҷ�����·��(ĳЩ���Ի��漰)
}BinaryTree;

#endif // ELEMENTTYPE_H_INCLUDED
