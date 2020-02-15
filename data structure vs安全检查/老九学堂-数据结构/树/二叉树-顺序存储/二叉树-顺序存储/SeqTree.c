
#include <conio.h>
#include "SeqTree.h"


void InitSeqTree(SeqTree tree)
{
    //将字符数组中的每个元素都设置为空字符
    for(int i = 0; i < MAX_SIZE; i++)
	{
        tree[i] = '\0';
    }
}

void CreateSeqTree(SeqTree tree, int i)
{
    char ch; 
	ch = _getch();
	fflush(stdin);
    if(ch == 13)
	{
		//输入^符号表示结束当前结点的输入
        tree[i] = '\0';
        return;
    }
    tree[i] = ch;
    //某个结点输入完毕后，还需要让用户输入左孩子和右孩子
	printf("\n%c的左孩子结点：", *(tree + i));
    CreateSeqTree(tree, 2 * i + 1); //递归调用
    printf("\n%c的右孩子结点：", *(tree + i));
    CreateSeqTree(tree, 2 * (i + 1));
}

char GetSeqTreeRoot(SeqTree tree)
{
    return tree[0];
}

int GetSeqTreeLength(SeqTree tree)
{
    int len = 0;
    for(int i = 0; i < MAX_SIZE; i++)
	{
        if(tree[i] == '\0')
		{
            continue;
        }
        len++;
    }
    return len;
}

int GetSeqTreeDepth(SeqTree tree)
{
    int depth = 0; 
	int lastNode = -1;
	//从数组最后一位找，找到最深的叶子结点
	for (int i = MAX_SIZE - 1; i >= 0; i--)
	{
		if (tree[i] != '\0')
		{
			lastNode = i;
			break;
		}
	}

	if (lastNode != -1)	//树不为空
	{
		int currentDepthIndexMaxNode = 1;
		while (currentDepthIndexMaxNode - 1 < lastNode)		//currentDepthIndexMaxNode - 1 按下标算，减一
		{
			//性质2：深度为k的二叉树最多有2^k-1个结点
			currentDepthIndexMaxNode = 1;
			depth++;
			for (int i = 0; i < depth; i++)
			{
				currentDepthIndexMaxNode *= 2;
			}
			currentDepthIndexMaxNode--;
		
		}
	}

    return depth;
}






