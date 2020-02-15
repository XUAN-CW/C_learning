#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#define MAX_SIZE 5
#define TRUE 1
#define FALSE 0

//定义栈中元素
typedef struct {
	int id;
	char name[20];
}ElementType;

//链栈的结点 
typedef struct StackNode {
	ElementType data;           //结点中保存的元素
	struct StackNode * next;    //指向下个结点的指针
}StackNode;

//
typedef struct LinkedStack {
	StackNode * top;            //栈顶指针
	int length;                 //链栈的长度（元素个数）
}LinkedStack;

#endif // ELEMENT_H_INCLUDED
