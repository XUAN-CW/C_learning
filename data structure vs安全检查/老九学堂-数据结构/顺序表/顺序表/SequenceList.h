 #ifndef SEQUENCELIST_H_INCLUDED
 #define SEQUENCELIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataElement.h"

void InitList(SeqList * seqList, ElementType * elemArray, int length);

void InsertElement(SeqList * seqList, int index, ElementType element);

void DeleteElement(SeqList * seqList, int index, ElementType *delElement);

int GetLength(SeqList * seqList);
 
int IsEmpty(SeqList * seqList);
 
void ClearList(SeqList * seqList);
 
void PrintList(SeqList * seqList);

#endif  SEQUENCELIST_H_INCLUDED


