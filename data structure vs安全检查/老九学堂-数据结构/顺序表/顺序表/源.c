#include <stdio.h>
#include <stdlib.h>
#include "SequenceList.h"

int main()
{
	ElementType dataArray[] = {
	{1, "������"},
	{2, "�����ӳ�"},
	{3, "̫���Ͼ�"},
	{4, "��������"}
	};
	SeqList seqList;    
    InitList(&seqList, dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    printf("��ʼ����\n");
    PrintList(&seqList);
	printf("\n\n");


	printf("����Ԫ�أ�\n");
	ElementType newElement;
	newElement.id = 1234;
	strcpy_s(newElement.name, sizeof(newElement.name), "��������");
	InsertElement(&seqList, 2, newElement);
	PrintList(&seqList);
	printf("\n\n");


	ElementType *delElement = (ElementType *)malloc(sizeof(ElementType));
	//���±�ɾ��
	DeleteElement(&seqList, 2, delElement);
	printf("ɾ����\n");
	PrintList(&seqList);
	printf("��ɾ����Ԫ�أ�\n");
	printf("%d\t%s\n", delElement->id, delElement->name);
	free(delElement);//��Ϊһ��רҵ��ʿ��һ��Ҫ�ǵ��ͷŷ�����ڴ棡
	printf("\n\n");

	system("pause");
    return 0;
}