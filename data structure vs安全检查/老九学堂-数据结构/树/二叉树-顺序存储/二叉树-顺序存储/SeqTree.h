#ifndef SEQTREE_H_INCLUDED
#define SEQTREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ElementType.h"

/** ��ʼ���ն����� */
void InitSeqTree(SeqTree tree);

/** ��ȡ���ĸ����Ԫ�� */
char GetSeqTreeRoot(SeqTree tree);

/** ��ȡ���Ľ������ */
int GetSeqTreeLength(SeqTree tree);

/** ��ȡ������� */
int GetSeqTreeDepth(SeqTree tree);

/** ������ȫ��������iΪ�����е��±� */
void CreateSeqTree(SeqTree tree, int i);


#endif // SEQTREE_H_INCLUDED
