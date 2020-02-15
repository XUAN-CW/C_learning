#define _CRT_SECURE_NO_WARNINGS 1    //vs环境下取消安全检查，其他编译器可删去此句

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
	char code[20];//代号
	char briefIntroduction[200];//简介
} Scenic;
typedef struct {
	Scenic Scen[MAX_SCENIC];
	Distance distance[MAX_SCENIC][MAX_SCENIC];
} Campus;
Campus G;

int num;

void init(int num) {
	printf("请输入学校各地点名称：\n");
	for (int i = 1; i <= num; i++) {
		printf("请输入第%d个地点的名称：\n", i);
		scanf("%s", &G.Scen[i].name);
	}
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			G.distance[i][j].dis = UNREACHABLE;
		}
	}
}//菜单
int mune() {                 //菜单函数
	int i;
	printf("--- 主菜单 ---\n");
	printf("0.退出\n");
	printf("1.修改节点信息\n");
	printf("2.查看校园地点\n");
	printf("3.创建校园路径\n");
	printf("4.查看校园路径\n");
	printf("5.查看景点间的最短路径\n");
	printf("6.修改路径\n");
	printf("7.增加节点\n");

	printf("请选择：");
	scanf("%d", &i);
	return i;
}

//查看输入地点概况
void ShowSchoolScenic(int num) {
	for (int i = 1; i <= num; i++) {
		printf("        %d--->   %s\n", i, G.Scen[i].name);
	}
}//创建地图
void CreatCampusPath(int num) {
	int start, endd, distance;
	printf("创建路径：起点和终点均在1~%d之间，起点为0退出创建路径\n", num);
	for (int i = 0; i < num * (num - 1); i++) {
		printf("请输入第%d条路径：\n", i + 1);
		printf("起点：");
		scanf("%d", &start);
		if (start == 0) {
			break;
		}
		printf("终点：");
		scanf("%d", &endd);
		printf("距离：");
		scanf("%d", &distance);
		G.distance[start][endd].dis = G.distance[endd][start].dis = distance;
	}
}//迪杰斯特拉算法，算出一个点到其他点的最短路径
void dijiesite(int now, int num) {
	for (int i = 1; i <= num; i++) {
		lastNode[i] = 0;
		minshort[i] = UNREACHABLE;//标记到该点的最短路径
	}
	int i, j, min;
	for (i = 1; i <= num; i++) {
		visited[i] = 0;//标记走过的节点
	}
	minshort[now] = 0;//开始
	for (i = 1; i <= num; i++) {
		int pos;
		min = UNREACHABLE;
		for (j = 1; j <= num; j++) {//找出最小距离的下标
			if (!visited[j] && minshort[j] < min) {
				min = minshort[j];
				pos = j;
			}
		}
		visited[pos] = 1;
		for (j = 1; j <= num; j++) {
			if (!visited[j] && minshort[j] > minshort[pos] + G.distance[pos][j].dis) {
				minshort[j] = minshort[pos] + G.distance[pos][j].dis;//更新路径
				lastNode[j] = pos;//记录前驱节点信息
			}
		}
	}
}

//显示创建的地图
void ShowShoolMap(int num) {
	printf("校园图如下：\n");
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			if (G.distance[i][j].dis == UNREACHABLE) {
				printf("∞   ");
			}
			else {
				printf("%-5d", G.distance[i][j].dis);
			}
		}
		printf("\n");
	}
}//输出最短路径及其路径走向
void shortestPath(int allNode) {
	int path[100], i, j, node;
	int start, end;
	printf("请输入起点：");
	scanf("%d", &start);
	printf("请输入终点：");
	scanf("%d", &end);
	dijiesite(start, allNode);
	if (minshort[end] >= UNREACHABLE) {
		printf("这里无法无法到达目的地\n");
	}
	else {
		printf("最短距离是：%d\n", minshort[end]);
		printf("路径为：");
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
	printf("要修改的节点下标：");
	scanf("%d", &index);
	printf("改为：");
	scanf("%s", &G.Scen[index].name);
}

void modifyPath() {
	int start, endd, distance;
	for (; ; ) {
		printf("起点：");
		scanf("%d", &start);
		if (start == 0) {
			break;
		}
		printf("终点：");
		scanf("%d", &endd);
		printf("距离：");
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
	printf("地点名称：\n");
	scanf("%s", &G.Scen[num].name);
		for (int j = 1; j <= num; j++) {
			G.distance[num][j].dis = UNREACHABLE;
			G.distance[j][num].dis = UNREACHABLE;
		}
}

int main() {
	
	printf("请输入学校地点数目：\n");
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
			printf("输入不正确~\n");
			break;
		}
	}
	return 0;
}
