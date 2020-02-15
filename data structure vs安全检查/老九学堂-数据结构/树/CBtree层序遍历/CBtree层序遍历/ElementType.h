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
	ElementType data;           //树结点的数据域
	struct treeNode * left;     //左子树
	struct treeNode * right;    //右子树
}TreeNode;

//二叉链表 
typedef struct 
{
	TreeNode * root;        //二叉链的根结点
	int length;             //二叉链表结点的总数
	int depth;              //二叉链表的深度
	int diameter;           //直径 - 从叶结点到叶结点的最长路径(某些考试会涉及)
}BinaryTree;

#endif // ELEMENTTYPE_H_INCLUDED
