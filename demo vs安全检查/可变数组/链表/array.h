#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 20

typedef struct _array
{
	int size;
	int *array;
}Array;

Array ArrayCreate(int initSize);

void ArrayFree(Array *a);

int ArraySize(const Array *a);

int *ArrayAt(Array *a, int index);

void ArrayInflate(Array *a, int moreSize);

Array ArrayCreate(int initSize)
{
	Array a;
	a.size = initSize;
	a.array = (int*)malloc(sizeof(int)*a.size);
	return a;
}

void ArrayFree(Array *a)
{
	free(a->array);
	a->array = NULL;
	a->size = 0;
}

int ArraySize(const Array *a) 
{
	return a->size;
}

int *ArrayAt(Array *a, int index)
{
	if (index >= a->size)
	{
		ArrayInflate(a, (index / BLOCK_SIZE + 1)*BLOCK_SIZE - a->size);
	}
	return &(a->array[index]);
}

void ArrayInflate(Array *a, int moreSize)
{
	int *p = (int*)malloc(sizeof(int)*(a->size + moreSize));
	int i;
	for ( i = 0; i < a->size; i++)
	{
		p[i] = a->array[i];
	}
	free(a->array);
	a->array = p;
	a->size += moreSize;
}