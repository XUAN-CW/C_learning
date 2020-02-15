#include "ZOrderTraverse.h"
#include "LinkedQueue.h"

/** 层序遍历：不需要递归，遍历时需要用到队列 */
void ZOrderTraverse(TreeNode * node)
{
	LinkedQueue queue;
	InitLinkedQueue(&queue);
	//根结点入队
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
