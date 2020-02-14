#define _CRT_SECURE_NO_WARNINGS 1    //vs������ȡ����ȫ��飬������������ɾȥ�˾�
# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct  PolyNode
{
	int  coef;
	int  exp;
	struct  PolyNode* next;
}node;

node* CreatePoly()
{
	node* h, * tail, * newNode;
	int  coef, exp;

	h = (node*)malloc(sizeof(node));
	if (!h)
	{
		exit(-1);
	}
	h->next = NULL;
	tail = h;

	printf("������ÿһ���ϵ����ָ��(�м��Զ��Ÿ���):\n");
	printf("coef,exp: ");
	scanf("%d,%d", &coef, &exp);
	while (coef)
	{
		newNode = (node*)malloc(sizeof(node));
		if (!newNode)
		{
			exit(-1);
		}
		newNode->coef = coef;
		newNode->exp = exp;

		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;

		printf("ceof,exp: ");
		scanf("%d,%d", &coef, &exp);
	}

	return h;
}

node* PolyAdd(node * polya, node * polyb)
{
	node* lastNode = polya->next;
	if (lastNode) {		
		while (lastNode->next)
		{
			lastNode = lastNode->next;
		}
		//���ҵ����һ���ڵ㣬���潫����������������
		lastNode->next = polyb->next;
		free(polyb);//�ͷ�b�����ͷ�ڵ�

		//��ʱ�����������Ѿ��ϲ�����һ������
		node *frontNode = polya;//ָ��ͷ���
		/** ����ָ����ͬ�Ľڵ㣬��� */
		while (frontNode->next) {//����Ϊ��
			node* NextNodeExpEqualTo_curNode = frontNode->next;
			while (NextNodeExpEqualTo_curNode->next) {
				// �ҵ�ָ����ͬ�Ľڵ� 
				if (frontNode->next->exp == NextNodeExpEqualTo_curNode->next->exp) {
					//���
					frontNode->next->coef += NextNodeExpEqualTo_curNode->next->coef;
					//ɾ���ýڵ�
					node* tempNode = NextNodeExpEqualTo_curNode->next;
					NextNodeExpEqualTo_curNode->next = NextNodeExpEqualTo_curNode->next->next;
					free(tempNode);
					//���µ� NextNodeExpEqualTo_curNode->next ��������
					continue;
				}
				//��û�ҵ����ڵ���Ƽ�����
				NextNodeExpEqualTo_curNode = NextNodeExpEqualTo_curNode->next;
			}
			//ϵ����Ӻ�ϵ��Ϊ0��ɾ�� frontNode->next �ڵ�
			if (0 == frontNode->next->coef) {
				node* tempNode = frontNode->next;
				frontNode->next = frontNode->next->next;
				free(tempNode);
				//���µ� frontNode->next ��������
				continue;
			}
			//�ڵ����
			frontNode = frontNode->next;
		}
		return polya;
	}
	else//����Ϊ�գ�ֱ�ӷ���
	{
		return polyb;
	}



	//node* pa, * pb, * preNode, * temp;
	//int  sum = 0;
	//
	//pa = polya->next;
	//pb = polyb->next;
	//preNode = polya;
	//
	//while (pa && pb)
	//{
	//	if (pa->exp < pb->exp)
	//	{
	//		preNode->next = pa;
	//		preNode = pa;
	//		pa = pa->next;
	//	}
	//	else if (pa->exp > pb->exp)
	//	{
	//		preNode->next = pb;
	//		preNode = pb;
	//		pb = pb->next;
	//	}
	//	else
	//	{
	//		sum = pa->coef + pb->coef;
	//		if (sum)
	//		{
	//			pa->coef = sum;
	//			preNode->next = pa;
	//			preNode = pa;
	//			pa = pa->next;
	//
	//			temp = pb->next;
	//			free(pb);
	//			pb = temp;
	//		}
	//		else
	//		{
	//			temp = pa->next;
	//			free(pa);
	//			pa = temp;
	//
	//			temp = pb->next;
	//			free(pb);
	//			pb = temp;
	//		}
	//	}
	//}
	//
	//preNode->next = pa ? pa : pb;

}

node* sub_poly(node* polya, node* polyb) {
	/** polya��Ϊ-polya */
	node* temp = polya->next;
	while (temp)
	{
		temp->coef = -temp->coef;
		temp = temp->next;
	}
	return PolyAdd(polya, polyb);
}

int Print(node * h)
{
	node* p = h->next;

	while (p)
	{
		printf("%d*x^%d  ", p->coef, p->exp);
		p = p->next;
	}
	printf("\n");

	return 1;
}

/** �������� */
void sort(node* list)
{
	int nodeCount = 0;
	node* countNode = list->next;
	//����Ԫ�ظ���
	for ( ; countNode; nodeCount++){
		countNode = countNode->next;
	}

	//ָ�������ָ�����飬һ��ָ��ָ��һ�����
	node** pArray = (node**)malloc(sizeof(node*) * nodeCount);
	//ָ���������ָ�����ָ������
	node* curNode = list->next;
	if (pArray && curNode) {
		//һ��ָ��ָ��һ���ڵ�
		for (int i = 0; curNode; i++)
		{
			pArray[i] = curNode;
			curNode = curNode->next;
		}
		//��������ʹ��ð������
		for (int i = 0; i < nodeCount - 1; i++)
		{
			for (int j = 0; j < nodeCount - 1 - i; j++)
			{
				node* tempNode;
				if (pArray[j]->exp > pArray[j + 1]->exp)
				{
					tempNode = pArray[j];
					pArray[j] = pArray[j + 1];
					pArray[j + 1] = tempNode;
				}
			}
		}
		//���
		/*** ��� **/
		for (int i = 0; i < nodeCount; i++)
		{
			printf("%d*x^%d  ", pArray[i]->coef, pArray[i]->exp);
		}
	}

}

int main(void)
{
	node* polya, * polyb, *polyc;

	printf("�������һ��һԪ����ʽ��ϵ����ָ�����ٶ�������ϵ��Ϊ0��������:\n");
	polya = CreatePoly();
	printf("������ĵ�һ��һԪ����ʽΪ:\n");
	Print(polya);

	printf("������ڶ���һԪ����ʽ��ϵ����ָ�����ٶ�������ϵ��Ϊ0��������:\n");
	polyb = CreatePoly();
	printf("������ĵڶ���һԪ����ʽΪ:\n");
	Print(polyb);

	printf("�����������һԪ����ʽ��ϵ����ָ�����ٶ�������ϵ��Ϊ0��������:\n");
	polyc = CreatePoly();
	printf("������ĵ�����һԪ����ʽΪ:\n");
	Print(polyc);

	//printf("������һԪ����ʽ�����Ľ��Ϊ:\n");
	//Print(PolyAdd(polya, polyb));

	//Print(PolyAdd(PolyAdd(polya, polyb), polyc));

	//Print(sub_poly(polya, polyb));

	sort(PolyAdd(polya, polyb));


	return 1;
}






