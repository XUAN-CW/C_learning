#include "ElementType.h"

/** 栈结点 */
typedef struct stackNode
{
	TreeNode * data;            //数据域-与之前实现的链栈有所不同
	struct stackNode * next;    //指针域
}StackNode;

typedef struct
{
	StackNode * top;            //栈顶指针
	int length;                 //栈长度
}LinkedStack;