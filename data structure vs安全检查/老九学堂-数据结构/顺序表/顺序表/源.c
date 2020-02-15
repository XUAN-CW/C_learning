#include <stdio.h>
#include <stdlib.h>
#include "SequenceList.h"

int main()
{
	ElementType dataArray[] = {
	{1, "登龙剑"},
	{2, "美国队长"},
	{3, "太上老君"},
	{4, "菩提老祖"}
	};
	SeqList seqList;    
    InitList(&seqList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    printf("初始化后\n");
    PrintList(&seqList);
	printf("\n\n");


	printf("插入元素：\n");
	ElementType newElement;
	newElement.id = 1234;
	strcpy_s(newElement.name, sizeof(newElement.name), "斗气化马");
	InsertElement(&seqList, 2, newElement);
	PrintList(&seqList);
	printf("\n\n");


	ElementType *delElement = (ElementType *)malloc(sizeof(ElementType));
	//按下标删除
	DeleteElement(&seqList, 2, delElement);
	printf("删除后\n");
	PrintList(&seqList);
	printf("被删除的元素：\n");
	printf("%d\t%s\n", delElement->id, delElement->name);
	free(delElement);//身为一个专业人士，一定要记得释放分配的内存！
	printf("\n\n");

	system("pause");
    return 0;
}