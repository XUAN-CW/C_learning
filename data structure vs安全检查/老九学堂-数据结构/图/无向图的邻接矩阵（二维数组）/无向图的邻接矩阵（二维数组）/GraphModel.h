#ifndef GRAPHMODEL_H_INCLUDED
#define GRAPHMODEL_H_INCLUDED

#define OK 1
#define ERROR 0
#define MAX_VERTEX 100
#define VISITED 1
#define UNVISITED 0
#define UNFOUND -1

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
typedef struct
{
	VerTexType verTexs[MAX_VERTEX];         //��������
	ArcType arcs[MAX_VERTEX][MAX_VERTEX];   //�ڽӾ���Ȩ���飩
	int verTexCount;                        //ͼ�Ķ�����
	int arcCount;                           //ͼ�ı�/����
	GraphKind kind;                         //ͼ������
}MatrixGraph;

#endif // GRAPHMODEL_H_INCLUDED
