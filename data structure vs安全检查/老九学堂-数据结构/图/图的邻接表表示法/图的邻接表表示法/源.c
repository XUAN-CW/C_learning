#include "GraphModel.h"
#include "UDG.h"

void UDG_AdjList();

int main()
{
	UDG_AdjList();
	system("pause");
	return 0;
}

void UDG_AdjList()
{
	AdjListGraph G;
	Status status = CreateUDG_AdjList(&G);
	for (int i = 0; i < G.vexCount; i++) 
	{
		VNode vNode = G.vexes[i];
		printf("¶¥µã£º%s", vNode.vex);
		EdgeNode * edgeNode = vNode.firstEdge;
		while (edgeNode) 
		{
			printf(" -> %d", edgeNode->adjVex);
			edgeNode = edgeNode->nextEdge;
		}
		printf("\n");
	}
}