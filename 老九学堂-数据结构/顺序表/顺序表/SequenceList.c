#include "SequenceList.h"

void InitList(SeqList * seqList, ElementType * elemArray, int length)
{
    if(length > MAX_SIZE)
    {
        printf("超出了数组的最大容量，初始化失败！\n");
        return;
    }
    seqList->length = 0;    //记得在初始化顺序表时，将顺序表的长度置零
    for(int i = 0; i < length; i++)
    {
        //每次循环都在下标为i的位置插入一个元素
        InsertElement(seqList, i, elemArray[i]);
    }
}

void InsertElement(SeqList * seqList, int index, ElementType element)
{
    //1、验证插入后的元素空间是否超过MAX_SIZE
    //2、index的值是否合法[0, MAX_SIZE-1]
    //3、插入的index应该在length之内
    //4、从第length-1个下标开始，前面一个元素赋值给后面一个元素
	int i;
    if(seqList->length + 1 > MAX_SIZE)
    {
        printf("数组已满，插入元素失败！\n");
        return;
    }
    if(index < 0 || index > MAX_SIZE - 1)
    {
        printf("只能在允许的下标范围内插入元素[0, %d]\n", MAX_SIZE - 1);
        return;
    }
    if(index > seqList->length)
    {
        printf("插入的下标超过了数组的最大长度-1，插入失败！\n");
        return;
    }
    for( i = seqList->length - 1; i >= index; i--)
    {
        seqList->datas[i + 1] = seqList->datas[i];
    }
    //5、将要插入的值赋给第index个元素
    seqList->datas[index] = element;
    //6、顺序表的总长度+1 ！！！！ - 非常容易漏掉的地方
    seqList->length++;
}

void DeleteElement(SeqList * seqList, int index, ElementType *delElement)
{
    if(index < 0 || index > MAX_SIZE - 1)
    {
        printf("下标越界，无法删除指定下标的元素！\n");
		delElement->id = -1;
		strcpy_s(delElement->name,sizeof(delElement->name), "删除失败！");
        return;
    }
    *delElement = seqList->datas[index];
    //从指定位置删除，后面一个元素赋值给前面一个元素
	for (int i = index; i < seqList->length - 1; i++)
	{
		if (i != MAX_SIZE)
		{
			seqList->datas[i] = seqList->datas[i + 1];
		}
	}
    //顺序表的总长度-1，障眼法，实际上删除前的最后一个元素的位置仍存储着最后一个元素的信息
    seqList->length--;
    return;
}

int GetLength(SeqList * seqList)
{
    if(seqList == NULL)
        return 0;
	else
	{
		return seqList->length;
	}
}

int IsEmpty(SeqList * seqList)
{
    return GetLength(seqList) == 0 ? TRUE : FALSE;
}

void ClearList(SeqList * seqList)
{
    if(seqList == NULL) return;
    seqList->length = 0;
}

void PrintList(SeqList * seqList)
{
    for(int i = 0; i < seqList->length; i++)
	{
        printf("%d\t%s\n", seqList->datas[i].id, seqList->datas[i].name);
    }
}