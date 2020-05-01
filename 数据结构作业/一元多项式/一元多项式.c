#define _CRT_SECURE_NO_WARNINGS 1    //vs环境下取消安全检查，其他编译器可删去此句
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

	printf("请输入每一项的系数和指数(中间以逗号隔开):\n");
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
		//已找到最后一个节点，下面将两个链表连接起来
		lastNode->next = polyb->next;
		free(polyb);//释放b链表的头节点

		//此时，两个链表已经合并成了一个链表
		node *frontNode = polya;//指向头结点
		/** 查找指数相同的节点，相加 */
		while (frontNode->next) {//链表不为空
			node* NextNodeExpEqualTo_curNode = frontNode->next;
			while (NextNodeExpEqualTo_curNode->next) {
				// 找到指数相同的节点 
				if (frontNode->next->exp == NextNodeExpEqualTo_curNode->next->exp) {
					//相加
					frontNode->next->coef += NextNodeExpEqualTo_curNode->next->coef;
					//删除该节点
					node* tempNode = NextNodeExpEqualTo_curNode->next;
					NextNodeExpEqualTo_curNode->next = NextNodeExpEqualTo_curNode->next->next;
					free(tempNode);
					//从新的 NextNodeExpEqualTo_curNode->next 继续查找
					continue;
				}
				//还没找到，节点后移继续找
				NextNodeExpEqualTo_curNode = NextNodeExpEqualTo_curNode->next;
			}
			//系数相加后系数为0，删除 frontNode->next 节点
			if (0 == frontNode->next->coef) {
				node* tempNode = frontNode->next;
				frontNode->next = frontNode->next->next;
				free(tempNode);
				//从新的 frontNode->next 继续查找
				continue;
			}
			//节点后移
			frontNode = frontNode->next;
		}
		return polya;
	}
	else//链表为空，直接返回
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
	/** polya变为-polya */
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

/** 链表排序 */
void sort(node* list)
{
	int nodeCount = 0;
	node* countNode = list->next;
	//数出元素个数
	for ( ; countNode; nodeCount++){
		countNode = countNode->next;
	}

	//指向链表的指针数组，一个指针指向一个结点
	node** pArray = (node**)malloc(sizeof(node*) * nodeCount);
	//指针数组里的指针逐个指向链表
	node* curNode = list->next;
	if (pArray && curNode) {
		//一个指针指向一个节点
		for (int i = 0; curNode; i++)
		{
			pArray[i] = curNode;
			curNode = curNode->next;
		}
		//排序，这里使用冒泡排序
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
		//输出
		/*** 输出 **/
		for (int i = 0; i < nodeCount; i++)
		{
			printf("%d*x^%d  ", pArray[i]->coef, pArray[i]->exp);
		}
	}

}

int main(void)
{
	node* polya, * polyb, *polyc;

	printf("请输入第一个一元多项式的系数和指数（假定以输入系数为0来结束）:\n");
	polya = CreatePoly();
	printf("请输入的第一个一元多项式为:\n");
	Print(polya);

	printf("请输入第二个一元多项式的系数和指数（假定以输入系数为0来结束）:\n");
	polyb = CreatePoly();
	printf("请输入的第二个一元多项式为:\n");
	Print(polyb);

	printf("请输入第三个一元多项式的系数和指数（假定以输入系数为0来结束）:\n");
	polyc = CreatePoly();
	printf("请输入的第三个一元多项式为:\n");
	Print(polyc);

	//printf("这两个一元多项式相减后的结果为:\n");
	//Print(PolyAdd(polya, polyb));

	//Print(PolyAdd(PolyAdd(polya, polyb), polyc));

	//Print(sub_poly(polya, polyb));

	sort(PolyAdd(polya, polyb));


	return 1;
}






