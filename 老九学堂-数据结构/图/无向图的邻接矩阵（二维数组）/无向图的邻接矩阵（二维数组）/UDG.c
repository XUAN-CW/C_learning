#include "UDG.h"


//����ͼ���ص㣺
//1������ͼ���ڽӾ����ǶԳ�
//2������i�Ķ� = ��i��(��)��1�ĸ���
Status CreateUDG(MatrixGraph * G) 
{
	G->kind = UDG;      //���õ�ǰ����ͼ������Ϊ����ͼ

	printf("����������ͼ�Ķ�������");
	scanf_s("%d", &G->verTexCount);
	printf("������ߵ�������");
	scanf_s("%d", &G->arcCount);

	printf("�������붥����Ϣ\n");
	for (int i = 0; i < G->verTexCount; i++) 
	{
		G->verTexs[i] = (VerTexType)malloc(sizeof(char) * 10);
		printf("����%d��", i + 1);
		scanf_s("%s", G->verTexs[i],sizeof(G->verTexs[i]));
	}

	//��ʼ���ڽӾ������бߵ�Ȩֵ����Ϊ0
	for (int i = 0; i < G->verTexCount; i++) 
	{
		for (int j = 0; j < G->verTexCount; j++) 
		{
			G->arcs[i][j] = 0;
		}
	}

	printf("�����붥����ڽӶ�����Ϣ�������ڽӾ���\n");
	for (int i = 0; i < G->arcCount; i++)
	{
		VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
		VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
		printf("���㣺");
		scanf_s("%s", vex1,sizeof(vex1));
		printf("�ڽӵ㣺");
		scanf_s("%s", vex2,sizeof(vex2));
		//�ֱ������������ڶ��������е�����
		int x = LocateVex_UDG(G, vex1);
		int y = LocateVex_UDG(G, vex2);
		if (x == UNFOUND || y == UNFOUND)
		{
			return ERROR;
		}
		G->arcs[x][y] = 1;
		G->arcs[y][x] = G->arcs[x][y];      //����ͼ���ڽӾ����ǶԳƵ�

		free(vex1);
		free(vex2);
	}

	return OK;
}



int LocateVex_UDG(MatrixGraph * G, VerTexType vex) 
{
	int index = 0;
	while (index < G->verTexCount) 
	{
		if (strcmp(G->verTexs[index], vex) == 0) 
		{
			break;
		}
		index++;
	}
	return index == G->verTexCount ? UNFOUND : index;
}
