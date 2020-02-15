#ifndef GRAPHMODEL_H_INCLUDED
#define GRAPHMODEL_H_INCLUDED

#define OK 1
#define ERROR 0
#define MAX_VERTEX 100
#define VISITED 1
#define UNVISITED 0

/** ͼ������ö�� */
typedef enum
{
    DG,     //����ͼ   0
    UDG,    //����ͼ   1
    DN,     //������   2
    UDN     //������   3
}GraphKind;

/** ���ö������������Ϊ�ַ����� - ʹ��ʱ�ǵ÷����ڴ� */
typedef char * VerTexType;

/** ����Ȩֵ����Ϊ�������� */
typedef int ArcType;

/** ���ص�״̬���� */
typedef int Status;

/** ����ÿ������ķ���״̬[0-δ���ʣ�1-�ѷ��� */
int visited[MAX_VERTEX];


/** ͼ���ڽӾ���洢��ʾ */
typedef struct {
	VerTexType verTexs[MAX_VERTEX];         //��������
	ArcType arcs[MAX_VERTEX][MAX_VERTEX];   //�ڽӾ���Ȩ���飩
	int verTexCount;                        //ͼ�Ķ�����
	int arcCount;                           //ͼ�ı�/����
	GraphKind kind;                         //ͼ������
}MatrixGraph;

/** �߽ṹ */
typedef struct edge
{
	VerTexType head;            //�ߵ���ʼ����
	VerTexType tail;            //�ߵĽ�������
	ArcType value;              //�ߵ�Ȩֵ
}Edge, EdgeArray[MAX_VERTEX * (MAX_VERTEX - 1)];


































/** ʹ���ڽӾ����ʾ����������ͼ */
Status CreateUDG(MatrixGraph * G);

/** ʹ���ڽӾ����ʾ����������ͼ */
Status CreateDG(MatrixGraph * G);

/** ʹ���ڽӾ����ʾ������������ */
Status CreateDN(MatrixGraph * G);

/** ʹ���ڽӾ����ʾ������������ */
Status CreateUDN(MatrixGraph * G);

/** ����ĳ�������ڶ��㼯���е��±꣨��0��ʼ���������ڷ���-1 */
int LocateVex(MatrixGraph * G, VerTexType vex);

/** �ڽӾ����������ȱ��� */
void DFSTraverse_AMG(MatrixGraph G);

/** ������������ĺ����㷨��indexΪ���������ĳ�������±� */
void DFS_AMG(MatrixGraph G, int index);

/** ���ض���vex�������еĵ�һ���ڽӵ��±� */
int FirstAdjVex_AMG(MatrixGraph G, VerTexType vex);

/** �����붥��vex1�ڽӵ���һ���ڽӵ�(��vex2����һ���ڽӵ�)��û�оͷ���-1 */
int SecondAdjVex_AMG(MatrixGraph G, VerTexType vex1, VerTexType vex2);

/** �ڽӾ���Ĺ�����ȱ��� */
void BFSTraverse_AMG(MatrixGraph G);

/** ������������ĺ����㷨 - indexΪ�������������ĳ�������±� */
void BFS_AMG(MatrixGraph G, int index);

/*******  ������С������-��³˹�����㷨ʵ�� *******/


/** ��ͨ�������� - �������������м���� */
int vexset[MAX_VERTEX];

/** �ѱ����鰴Ȩֵ�������� */
void SortEdge(EdgeArray edgeArray, int len);

/** ��³˹�����㷨������С������ - �ڽӾ���ʵ�� */
void MST_kruskal_AMG(MatrixGraph G);

Status CreateDN1(MatrixGraph * G);
/** �Ͻ�˹�����㷨�������·�� */
void Dijkstra_AMG(MatrixGraph G);

void TestMatrixGraph();



#endif // GRAPHMODEL_H_INCLUDED
