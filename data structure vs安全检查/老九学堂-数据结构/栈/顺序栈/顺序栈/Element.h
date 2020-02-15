#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED

#define MAX_SIZE 5
#define TRUE 1
#define FALSE 0
#define WHITE 1
#define BLACK 2

//定义栈中元素
typedef struct {
	int id;
	char name[20];
}ElementType;


//定义栈的顺序存储方式 
typedef struct SeqStack {
	ElementType elements[MAX_SIZE]; //顺序栈中用来存放数据元素的数组
	int top;                        //栈顶（数组中的下标），如果为-1则证明栈为空
	int length;                     //当前栈的元素个数
}SeqStack;


#endif // ELEMENT_H_INCLUDED
