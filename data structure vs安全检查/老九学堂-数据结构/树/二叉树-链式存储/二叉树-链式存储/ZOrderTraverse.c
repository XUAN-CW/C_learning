#include "ZOrderTraverse.h"
#include "LinkedQueue.h"

/** �������������Ҫ�ݹ飬����ʱ��Ҫ�õ����� */
void ZOrderTraverse(TreeNode * node)
{
	LinkedQueue queue;
	InitLinkedQueue(&queue);
	//��������
	enQueue(&queue, node);
	while (!IsLinkedQueueEmpty(&queue)) 
	{
		TreeNode * node = deQueue(&queue);
		printf("[%d, %s] ", node->data.id, node->data.name);
		if (node->left != NULL)
		{
			enQueue(&queue, node->left);
		}
		if (node->right != NULL) 
		{
			enQueue(&queue, node->right);
		}
	}
}
