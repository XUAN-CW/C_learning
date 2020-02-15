
//#include "GetCBTreeDepth.h"
//#include "CBLinkedQueue.h"

/** 获得树的深度 */
//int GetCBTreeDepth(CBTree **cbTree) 
//{
//	/*使用树的层序遍历计算树的深度*/
//	//使用队列记录结点
//	CBLQueue queue;
//	InitQueue(&queue);
//	enQueue(&queue, *cbTree);//根结点入队
//
//	int zorder = 1;//层号
//	printf("\n第%d层：", zorder);
//	CBNode* last = *cbTree;
//	CBNode* lastchild = *cbTree;
//	while (!IsEmpty(&queue)) 
//	{
//		CBNode* cbNode = deQueue(&queue);
//		printf("[%s] ", cbNode->data.name);//访问出队的结点
//
//		//先将所有孩子结点加入队列
//		CBNode *tempNode = cbNode->firstChild;
//		while (tempNode) 
//		{
//			enQueue(&queue, tempNode);
//			lastchild = tempNode;
//			tempNode = tempNode->nextSibling;
//		}
//		//所有孩子结点都出队了，并且下一层还有孩子结点，则进入下一层
//		if (!IsEmpty(&queue) && last == cbNode)
//		{
//			zorder++;
//			printf("\n第%d层：", zorder);
//			last = lastchild;
//		}
//	}
//	return zorder;
//}