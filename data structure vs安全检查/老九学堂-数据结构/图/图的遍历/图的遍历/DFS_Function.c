#include "DFS_Function.h"

void DFSTraverse_AMG(MatrixGraph G)
{
	//��ʼ��״̬����
	for (int i = 0; i < G.verTexCount; i++) 
	{
		visited[i] = UNVISITED;     //��ʼ״̬����Ϊδ����
	}

	//DFS����
	for (int i = 0; i < G.verTexCount; i++)
	{
		if (!visited[i]) //���ĳ������δ����
		{
			//���ñ�������
			DFS_AMG(G, i);
		}
	}
}

void DFS_AMG(MatrixGraph G, int index)
{
	printf(" -> %s", G.verTexs[index]);							//���ʶ���A
    visited[index] = VISITED;									//���Ķ���A�ķ���״̬
	int currentVex = FirstAdjVex_AMG(G, G.verTexs[index]);		//��ǰ����Ϊ����A�ĵ�һ���ڽӵ�
	for (currentVex; currentVex;)		//currentVexΪ0������ѭ��
	{
		if (!visited[currentVex])		//���û�з��ʹ����ͼ����ݹ���÷���
		{
			DFS_AMG(G, currentVex);  
		}
		currentVex = NextAdjVex_AMG(G, G.verTexs[index], G.verTexs[currentVex]);
	}

}

int FirstAdjVex_AMG(MatrixGraph G, VerTexType vex) 
{
	int i = LocateVex(&G, vex);         //�ҵ�����vex�ڶ��������е��±�
	if (i == UNFOUND)
	{
		return ERROR;
	}
	int defaultWeight;									  //Ĭ��Ȩ��
	defaultWeight = G.kind <= 1 ? 0 : INT_MAX;			  //ͼ/��
	//����ͼ���ڽӾ������붥��vex�ĵ�һ���ڽӵ��±�
	for (int j = i + 1; j < G.verTexCount; j++) 
	{
		if (G.arcs[i][j] != defaultWeight)
		{
			return j;
		}
	}
	return 0;
}

int NextAdjVex_AMG(MatrixGraph G, VerTexType vex1, VerTexType vex2) 
{
	int index1 = LocateVex(&G, vex1);
	int index2 = LocateVex(&G, vex2);
	if (index1 == UNFOUND || index2 == UNFOUND)
	{
		return ERROR;
	}
	int defaultWeight;
	defaultWeight = G.kind <= 1 ? 0 : INT_MAX;
	for (int i = index2 + 1; i < G.verTexCount; i++)
	{
		if (G.arcs[index1][i] != defaultWeight) 
		{
			return i;
		}
	}
	return 0;
}

int LocateVex(MatrixGraph * G, VerTexType vex)
{
	int index = UNFOUND;
	for (int i = 0; i < G->verTexCount; i++)
	{
        if(strcmp(G->verTexs[index], vex) == 0)
		{
			index = i;
            break;
        }
	}
	return index;
}

