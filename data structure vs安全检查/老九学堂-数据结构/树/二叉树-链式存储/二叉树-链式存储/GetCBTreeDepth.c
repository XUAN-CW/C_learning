
//#include "GetCBTreeDepth.h"
//#include "CBLinkedQueue.h"

/** ���������� */
//int GetCBTreeDepth(CBTree **cbTree) 
//{
//	/*ʹ�����Ĳ�����������������*/
//	//ʹ�ö��м�¼���
//	CBLQueue queue;
//	InitQueue(&queue);
//	enQueue(&queue, *cbTree);//��������
//
//	int zorder = 1;//���
//	printf("\n��%d�㣺", zorder);
//	CBNode* last = *cbTree;
//	CBNode* lastchild = *cbTree;
//	while (!IsEmpty(&queue)) 
//	{
//		CBNode* cbNode = deQueue(&queue);
//		printf("[%s] ", cbNode->data.name);//���ʳ��ӵĽ��
//
//		//�Ƚ����к��ӽ��������
//		CBNode *tempNode = cbNode->firstChild;
//		while (tempNode) 
//		{
//			enQueue(&queue, tempNode);
//			lastchild = tempNode;
//			tempNode = tempNode->nextSibling;
//		}
//		//���к��ӽ�㶼�����ˣ�������һ�㻹�к��ӽ�㣬�������һ��
//		if (!IsEmpty(&queue) && last == cbNode)
//		{
//			zorder++;
//			printf("\n��%d�㣺", zorder);
//			last = lastchild;
//		}
//	}
//	return zorder;
//}