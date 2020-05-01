/*
	һԪ�����ʽ�ļӷ�
	1.�ȴ��������洢����ʽ
	2.�������ʽ
	3.��������ʽ���
	4.�������ʽ
*/
#define _CRT_SECURE_NO_WARNINGS 1    //vs������ȡ����ȫ��飬������������ɾȥ�˾�
# include <stdio.h>
# include <malloc.h>

typedef struct dxs  //����ʽ�ڵ�
{
	float coe;  //ϵ��
	int exp;   //ָ��
	struct dxs* pNext;  //ָ����

}DXS, * PDXS;

PDXS creat_dxs();   //��������ʽ
void traverse(PDXS pHead);   //��������ʽ����
PDXS add(PDXS Da, PDXS Db);  //����ʽ���

int main(void)
{
	//������ṹ��������������ʽ
	PDXS Da = creat_dxs();
	traverse(Da);

	PDXS Db = creat_dxs();
	traverse(Db);

	//����������ʽ�ļӷ�
	PDXS Dj = add(Da, Db);
	traverse(Dj);

	return 0;
}

PDXS creat_dxs()
{
	PDXS pHead = (PDXS)malloc(sizeof(DXS)); //����ͷ���
	pHead->pNext = NULL;  //βָ��

	PDXS pTail = pHead;
	PDXS pNew = NULL;

	int len;
	float c;
	int e;
	int i;

	printf("�������ʽ��������len = ");
	scanf("%d", &len);

	for (i = 0; i < len; i++)
	{
		printf("�ֱ������%d���ϵ��c��ָ��e:", i + 1);
		scanf("%f%d", &c, &e);

		pNew = (PDXS)malloc(sizeof(DXS));

		//����ʽ�ϵ����ָ��
		pNew->coe = c;
		pNew->exp = e;
		pNew->pNext = NULL;

		pTail->pNext = pNew;
		pTail = pNew;
	}

	return pHead;
}

//��������
void traverse(PDXS pHead)
{
	PDXS p = pHead->pNext;  //�׽ڵ�

	while (p != NULL)
	{
		printf("(%.2f %d), ", p->coe, p->exp);
		p = p->pNext;
	}
	printf("\n");
}


//����ʽ���
PDXS add(PDXS Da, PDXS Db)
{
	PDXS Dj = (PDXS)malloc(sizeof(DXS));  //�͵�ͷ���
	Dj->pNext = NULL;
	PDXS pTail = Dj;  //�͵�β�ڵ�

	PDXS Dah = Da->pNext;  //ָ�����ʽ���׽ڵ�
	PDXS Dbh = Db->pNext;

	//ѭ����������ʽA��B
	while (Dah && Dbh)
	{
		//�Ƚϵ�ǰ���ڵ��ָ��
		//��ǰ A��ڵ�ָ�� < B��ڵ�ָ��
		if (Dah->exp < Dbh->exp)
		{
			pTail->pNext = Dah;  //����A������������
			pTail = Dah;

			Dah = Dah->pNext;  //A����ʽ������
		}

		//��ǰ A��ڵ�ָ�� < B��ڵ�ָ��
		else if (Dah->exp > Dbh->exp)
		{
			pTail->pNext = Dbh;  //����B������������
			pTail = Dbh;

			Dbh = Dbh->pNext;  // //B����ʽ������
		}

		//������ڵ��ָ�����
		else
		{
			//��ǰָ����ϵ���Ͳ�Ϊ0
			//A���б���ϵ���ͣ��Ѵ�A������������
			if (0 != (Dah->coe + Dbh->coe))
			{
				Dah->coe = Dah->coe + Dbh->coe;
				pTail->pNext = Dah;
				pTail = Dah;
			}

			//A,B��������
			Dah = Dah->pNext;
			Dbh = Dbh->pNext;
		}
	}

	//����ʣ���
	if (Dah != NULL)
	{
		pTail->pNext = Dah;
	}
	if (Dbh != NULL)
	{
		pTail->pNext = Dbh;
	}

	return Dj;
}