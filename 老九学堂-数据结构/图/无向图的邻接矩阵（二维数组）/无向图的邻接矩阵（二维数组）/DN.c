//#include "DN.h"
//
//Status CreateDN(MatrixGraph * G) 
//{
//	//���õ�ǰ����ͼ������Ϊ������
//	G->kind = DN;      
//
//	printf("�������������Ķ�������");
//	scanf_s("%d", &G->verTexCount);
//
//	printf("������ߵ�������");
//	scanf_s("%d", &G->arcCount);
//
//	printf("�������붥����Ϣ\n");
//	for (int i = 0; i < G->verTexCount; i++) 
//	{
//		G->verTexs[i] = (VerTexType)malloc(sizeof(char) * 10);
//		printf("����%d��", i + 1);
//		scanf_s("%s", G->verTexs[i],sizeof(G->verTexs[i]));
//	}
//
//	//��ʼ���ڽӾ������бߵ�Ȩֵ����Ϊ��
//	for (int i = 0; i < G->verTexCount; i++) 
//	{
//		for (int j = 0; j < G->verTexCount; j++) 
//		{
//			G->arcs[i][j] = INT_MAX;    //ʹ��int_max������Ϊ�����
//		}
//	}
//
//	printf("�����붥����ڽӶ�����Ϣ�������ڽӾ���\n");
//	for (int i = 0; i < G->arcCount; i++) 
//	{
//		VerTexType vex1 = (VerTexType)malloc(sizeof(char) * 10);
//		VerTexType vex2 = (VerTexType)malloc(sizeof(char) * 10);
//		printf("���㣺");
//		scanf_s("%s", vex1,sizeof(vex1));
//		printf("�ڽӵ㣺");
//		scanf_s("%s", vex2,sizeof(vex2));
//		//�ֱ������������ڶ��������е�����
//		int x = LocateVex_DN(G, vex1);
//		int y = LocateVex_DN(G, vex2);
//		if (x == UNFOUND || y == UNFOUND)
//		{
//			return ERROR;
//		}
//		int value;
//		printf("������Ȩֵ��");
//		scanf_s("%d", &value);
//		G->arcs[x][y] = value;
//		free(vex1);
//		free(vex2);
//	}
//	return OK;
//}
//
//int LocateVex_DN(MatrixGraph * G, VerTexType vex)
//{
//	int index = 0;
//	while (index < G->verTexCount)
//	{
//		if (strcmp(G->verTexs[index], vex) == 0)
//		{
//			break;
//		}
//		index++;
//	}
//	return index == G->verTexCount ? UNFOUND : index;
//}