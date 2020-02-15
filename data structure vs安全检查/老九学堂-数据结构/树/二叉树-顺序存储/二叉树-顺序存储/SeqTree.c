
#include <conio.h>
#include "SeqTree.h"


void InitSeqTree(SeqTree tree)
{
    //���ַ������е�ÿ��Ԫ�ض�����Ϊ���ַ�
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
		//����^���ű�ʾ������ǰ��������
        tree[i] = '\0';
        return;
    }
    tree[i] = ch;
    //ĳ�����������Ϻ󣬻���Ҫ���û��������Ӻ��Һ���
	printf("\n%c�����ӽ�㣺", *(tree + i));
    CreateSeqTree(tree, 2 * i + 1); //�ݹ����
    printf("\n%c���Һ��ӽ�㣺", *(tree + i));
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
	//���������һλ�ң��ҵ������Ҷ�ӽ��
	for (int i = MAX_SIZE - 1; i >= 0; i--)
	{
		if (tree[i] != '\0')
		{
			lastNode = i;
			break;
		}
	}

	if (lastNode != -1)	//����Ϊ��
	{
		int currentDepthIndexMaxNode = 1;
		while (currentDepthIndexMaxNode - 1 < lastNode)		//currentDepthIndexMaxNode - 1 ���±��㣬��һ
		{
			//����2�����Ϊk�Ķ����������2^k-1�����
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






