#define _CRT_SECURE_NO_WARNINGS 1    //vs������ȡ����ȫ��飬������������ɾȥ�˾�

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_SCENIC 20
#define UNREACHABLE 1024*1024*1024
int visited[MAX_SCENIC + 1];
int minshort[MAX_SCENIC + 1];
int lastNode[1005];
typedef struct {
	int dis;
} Distance;
typedef struct {
	char name[20];
	char code[20];//����
	char briefIntroduction[200];//���
} Scenic;
typedef struct {
	Scenic Scen[MAX_SCENIC];
	Distance distance[MAX_SCENIC][MAX_SCENIC];
} Campus;
Campus G;

int num;

void init(int num) {
	printf("������ѧУ���ص����ƣ�\n");
	for (int i = 1; i <= num; i++) {
		printf("�������%d���ص�����ƣ�\n", i);
		scanf("%s", &G.Scen[i].name);
	}
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			G.distance[i][j].dis = UNREACHABLE;
		}
	}
}//�˵�
int mune() {                 //�˵�����
	int i;
	printf("--- ���˵� ---\n");
	printf("0.�˳�\n");
	printf("1.�޸Ľڵ���Ϣ\n");
	printf("2.�鿴У԰�ص�\n");
	printf("3.����У԰·��\n");
	printf("4.�鿴У԰·��\n");
	printf("5.�鿴���������·��\n");
	printf("6.�޸�·��\n");
	printf("7.���ӽڵ�\n");

	printf("��ѡ��");
	scanf("%d", &i);
	return i;
}

//�鿴����ص�ſ�
void ShowSchoolScenic(int num) {
	for (int i = 1; i <= num; i++) {
		printf("        %d--->   %s\n", i, G.Scen[i].name);
	}
}//������ͼ
void CreatCampusPath(int num) {
	int start, endd, distance;
	printf("����·���������յ����1~%d֮�䣬���Ϊ0�˳�����·��\n", num);
	for (int i = 0; i < num * (num - 1); i++) {
		printf("�������%d��·����\n", i + 1);
		printf("��㣺");
		scanf("%d", &start);
		if (start == 0) {
			break;
		}
		printf("�յ㣺");
		scanf("%d", &endd);
		printf("���룺");
		scanf("%d", &distance);
		G.distance[start][endd].dis = G.distance[endd][start].dis = distance;
	}
}//�Ͻ�˹�����㷨�����һ���㵽����������·��
void dijiesite(int now, int num) {
	for (int i = 1; i <= num; i++) {
		lastNode[i] = 0;
		minshort[i] = UNREACHABLE;//��ǵ��õ�����·��
	}
	int i, j, min;
	for (i = 1; i <= num; i++) {
		visited[i] = 0;//����߹��Ľڵ�
	}
	minshort[now] = 0;//��ʼ
	for (i = 1; i <= num; i++) {
		int pos;
		min = UNREACHABLE;
		for (j = 1; j <= num; j++) {//�ҳ���С������±�
			if (!visited[j] && minshort[j] < min) {
				min = minshort[j];
				pos = j;
			}
		}
		visited[pos] = 1;
		for (j = 1; j <= num; j++) {
			if (!visited[j] && minshort[j] > minshort[pos] + G.distance[pos][j].dis) {
				minshort[j] = minshort[pos] + G.distance[pos][j].dis;//����·��
				lastNode[j] = pos;//��¼ǰ���ڵ���Ϣ
			}
		}
	}
}

//��ʾ�����ĵ�ͼ
void ShowShoolMap(int num) {
	printf("У԰ͼ���£�\n");
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			if (G.distance[i][j].dis == UNREACHABLE) {
				printf("��   ");
			}
			else {
				printf("%-5d", G.distance[i][j].dis);
			}
		}
		printf("\n");
	}
}//������·������·������
void shortestPath(int allNode) {
	int path[100], i, j, node;
	int start, end;
	printf("��������㣺");
	scanf("%d", &start);
	printf("�������յ㣺");
	scanf("%d", &end);
	dijiesite(start, allNode);
	if (minshort[end] >= UNREACHABLE) {
		printf("�����޷��޷�����Ŀ�ĵ�\n");
	}
	else {
		printf("��̾����ǣ�%d\n", minshort[end]);
		printf("·��Ϊ��");
		for (j = end, i = 1; j != start; j = lastNode[j], i++) {
			path[i] = j;
		}
		path[i] = start;
		for (node = i; node > 1; node--) {
			printf("%s->",G.Scen[path[node]].name);
		}
		printf("%s\n",G.Scen[path[node]].name);
	}
}

void modify() {
	int index;
	printf("Ҫ�޸ĵĽڵ��±꣺");
	scanf("%d", &index);
	printf("��Ϊ��");
	scanf("%s", &G.Scen[index].name);
}

void modifyPath() {
	int start, endd, distance;
	for (; ; ) {
		printf("��㣺");
		scanf("%d", &start);
		if (start == 0) {
			break;
		}
		printf("�յ㣺");
		scanf("%d", &endd);
		printf("���룺");
		scanf("%d", &distance);
		if (distance == -1)
		{
			G.distance[start][endd].dis = G.distance[endd][start].dis = UNREACHABLE;
		}
		else
		{
			G.distance[start][endd].dis = G.distance[endd][start].dis = distance;
		}
	}
}

void addNode() {
	num++;
	printf("�ص����ƣ�\n");
	scanf("%s", &G.Scen[num].name);
		for (int j = 1; j <= num; j++) {
			G.distance[num][j].dis = UNREACHABLE;
			G.distance[j][num].dis = UNREACHABLE;
		}
}

int main() {
	
	printf("������ѧУ�ص���Ŀ��\n");
	scanf("%d", &num);
	init(num);
	CreatCampusPath(num);
	while (1) {
		int i;
		i = mune();
		switch (i) {
		case 0:
			exit(0);
			break;
		case 1:
			modify();
			break;
		case 2:
			ShowSchoolScenic(num);
			break;
		case 3:
			CreatCampusPath(num);
			break;
		case 4:
			ShowShoolMap(num);
			break;
		case 5:
			shortestPath(num);
			break;
		case 6:
			modifyPath();
			break;
		case 7:
			addNode();
			break;
		default:
			printf("���벻��ȷ~\n");
			break;
		}
	}
	return 0;
}
