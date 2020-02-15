#ifndef GRAPHMODEL_H_INCLUDED
#define GRAPHMODEL_H_INCLUDED

#define OK 1
#define ERROR 0
#define MAX_VERTEX 100
#define VISITED 1
#define UNVISITED 0
#define UNFOUND -1

/** 图的类型枚举 */
typedef enum
{
    DG,     //有向图   0
    UDG,    //无向图   1
    DN,     //有向网   2
    UDN     //无向网   3 
}GraphKind;

/** 设置顶点的数据类型为字符串型 - 使用时记得分配内存 */
typedef char * VerTexType;

/** 设置权值类型为整数类型 */
typedef int ArcType;

/** 返回的状态类型 */
typedef int Status;

/** 保存每个顶点的访问状态[0-未访问；1-已访问 */
int visited[MAX_VERTEX];

/** 图的邻接矩阵存储表示 */
typedef struct
{
	VerTexType verTexs[MAX_VERTEX];         //顶点数组
	ArcType arcs[MAX_VERTEX][MAX_VERTEX];   //邻接矩阵（权数组）
	int verTexCount;                        //图的顶点数
	int arcCount;                           //图的边/弧数
	GraphKind kind;                         //图的类型
}MatrixGraph;

#endif // GRAPHMODEL_H_INCLUDED
