#include <stdio.h>
#include <stdlib.h>
#include "UDG.h"
#include "DN.h"
#include "DN2.h"
void UDGMatrixGraph();
void DNMatrixGraph();

int main()
{
	//UDGMatrixGraph();
	DNMatrixGraph();
	system("pause");
    return 0;
}

void UDGMatrixGraph()
{
	MatrixGraph G;
	//��������ͼ
	Status status = CreateUDG(&G);
	if(status == ERROR)
	{
	    printf("����ͼʧ�ܣ���������ԣ�\n");
	}
	else
	{
		printf("��ӡͼ���ڽӾ���\n");

		printf("\t");
		for (int i = 0; i < G.verTexCount; i++)
		{
			printf("\t%s", G.verTexs[i]);
		}

		printf("\n");

		for (int i = 0; i < G.verTexCount; i++)
		{
			printf("\t%s", G.verTexs[i]);
			for (int j = 0; j < G.verTexCount; j++)
			{
					printf("\t%d", G.arcs[i][j]);
			}
			printf("\n");
		}
	}
    
}

void DNMatrixGraph()
{
	MatrixGraph G;
	//��������ͼ
	//Status status = CreateDN(&G);
	Status status = CreateDN2(&G);
	/*** 
	 * ���⣺
		Status status = CreateDN(&G);		-------�޷��������ⲿ���� _CreateDN
		Status status = CreateDN2(&G);		-------����
	 * ����������½�һ�� .c��.h�ļ�������������������ճ������������ݼ���
	   ���鿴�ļ��Ƿ�Ϊͬ�����ļ����� main.cpp��DN.c  �轫 main.cpp �ĳ� main.c
	 */

	if (status == ERROR)
	{
		printf("����ͼʧ�ܣ���������ԣ�\n");
	}
	else
	{
		printf("��ӡͼ���ڽӾ���\n");
	
		printf("\t");
		for (int i = 0; i < G.verTexCount; i++)
		{
			printf("\t%s", G.verTexs[i]);
		}
	
		printf("\n");
	
		for (int i = 0; i < G.verTexCount; i++)
		{
			printf("\t%s", G.verTexs[i]);
			for (int j = 0; j < G.verTexCount; j++)
			{
				if (G.arcs[i][j] == INT_MAX) 
				{
					printf("\t��");
				}
				else 
				{
					printf("\t%d", G.arcs[i][j]);
				}
			}
			printf("\n");
		}
	}
}