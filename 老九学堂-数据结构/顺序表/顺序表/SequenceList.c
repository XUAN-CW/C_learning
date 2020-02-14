#include "SequenceList.h"

void InitList(SeqList * seqList, ElementType * elemArray, int length)
{
    if(length > MAX_SIZE)
    {
        printf("����������������������ʼ��ʧ�ܣ�\n");
        return;
    }
    seqList->length = 0;    //�ǵ��ڳ�ʼ��˳���ʱ����˳���ĳ�������
    for(int i = 0; i < length; i++)
    {
        //ÿ��ѭ�������±�Ϊi��λ�ò���һ��Ԫ��
        InsertElement(seqList, i, elemArray[i]);
    }
}

void InsertElement(SeqList * seqList, int index, ElementType element)
{
    //1����֤������Ԫ�ؿռ��Ƿ񳬹�MAX_SIZE
    //2��index��ֵ�Ƿ�Ϸ�[0, MAX_SIZE-1]
    //3�������indexӦ����length֮��
    //4���ӵ�length-1���±꿪ʼ��ǰ��һ��Ԫ�ظ�ֵ������һ��Ԫ��
	int i;
    if(seqList->length + 1 > MAX_SIZE)
    {
        printf("��������������Ԫ��ʧ�ܣ�\n");
        return;
    }
    if(index < 0 || index > MAX_SIZE - 1)
    {
        printf("ֻ����������±귶Χ�ڲ���Ԫ��[0, %d]\n", MAX_SIZE - 1);
        return;
    }
    if(index > seqList->length)
    {
        printf("������±곬�����������󳤶�-1������ʧ�ܣ�\n");
        return;
    }
    for( i = seqList->length - 1; i >= index; i--)
    {
        seqList->datas[i + 1] = seqList->datas[i];
    }
    //5����Ҫ�����ֵ������index��Ԫ��
    seqList->datas[index] = element;
    //6��˳�����ܳ���+1 �������� - �ǳ�����©���ĵط�
    seqList->length++;
}

void DeleteElement(SeqList * seqList, int index, ElementType *delElement)
{
    if(index < 0 || index > MAX_SIZE - 1)
    {
        printf("�±�Խ�磬�޷�ɾ��ָ���±��Ԫ�أ�\n");
		delElement->id = -1;
		strcpy_s(delElement->name,sizeof(delElement->name), "ɾ��ʧ�ܣ�");
        return;
    }
    *delElement = seqList->datas[index];
    //��ָ��λ��ɾ��������һ��Ԫ�ظ�ֵ��ǰ��һ��Ԫ��
	for (int i = index; i < seqList->length - 1; i++)
	{
		if (i != MAX_SIZE)
		{
			seqList->datas[i] = seqList->datas[i + 1];
		}
	}
    //˳�����ܳ���-1�����۷���ʵ����ɾ��ǰ�����һ��Ԫ�ص�λ���Դ洢�����һ��Ԫ�ص���Ϣ
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