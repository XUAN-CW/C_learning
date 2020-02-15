#ifndef GRAPHMODEL_H_INCLUDED
#define GRAPHMODEL_H_INCLUDED

#define OK 1
#define ERROR 0
#define MAX_VERTEX 100
#define VISITED 1
#define UNVISITED 0

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
typedef struct {
	VerTexType verTexs[MAX_VERTEX];         //顶点数组
	ArcType arcs[MAX_VERTEX][MAX_VERTEX];   //邻接矩阵（权数组）
	int verTexCount;                        //图的顶点数
	int arcCount;                           //图的边/弧数
	GraphKind kind;                         //图的类型
}MatrixGraph;

/** 边结构 */
typedef struct edge
{
	VerTexType head;            //边的起始顶点
	VerTexType tail;            //边的结束顶点
	ArcType value;              //边的权值
}Edge, EdgeArray[MAX_VERTEX * (MAX_VERTEX - 1)];


































/** 使用邻接矩阵表示法创建无向图 */
Status CreateUDG(MatrixGraph * G);

/** 使用邻接矩阵表示法创建有向图 */
Status CreateDG(MatrixGraph * G);

/** 使用邻接矩阵表示法创建有向网 */
Status CreateDN(MatrixGraph * G);

/** 使用邻接矩阵表示法创建无向网 */
Status CreateUDN(MatrixGraph * G);

/** 返回某个顶点在顶点集合中的下标（从0开始），不存在返回-1 */
int LocateVex(MatrixGraph * G, VerTexType vex);

/** 邻接矩阵的深度优先遍历 */
void DFSTraverse_AMG(MatrixGraph G);

/** 深度优先搜索的核心算法，index为深度搜索的某个顶点下标 */
void DFS_AMG(MatrixGraph G, int index);

/** 返回顶点vex所在行中的第一个邻接点下标 */
int FirstAdjVex_AMG(MatrixGraph G, VerTexType vex);

/** 返回与顶点vex1邻接的另一个邻接点(处vex2的下一个邻接点)，没有就返回-1 */
int SecondAdjVex_AMG(MatrixGraph G, VerTexType vex1, VerTexType vex2);

/** 邻接矩阵的广度优先遍历 */
void BFSTraverse_AMG(MatrixGraph G);

/** 广度优先搜索的核心算法 - index为广度优先搜索的某个顶点下标 */
void BFS_AMG(MatrixGraph G, int index);

/*******  网的最小生成树-克鲁斯卡尔算法实现 *******/


/** 连通分量数组 - 用于生成树的中间过程 */
int vexset[MAX_VERTEX];

/** 把边数组按权值降序排列 */
void SortEdge(EdgeArray edgeArray, int len);

/** 克鲁斯卡尔算法生成最小生成树 - 邻接矩阵实现 */
void MST_kruskal_AMG(MatrixGraph G);

Status CreateDN1(MatrixGraph * G);
/** 迪杰斯特拉算法生成最短路径 */
void Dijkstra_AMG(MatrixGraph G);

void TestMatrixGraph();



#endif // GRAPHMODEL_H_INCLUDED
