#include <stdio.h>
int main()
{
	//A[0]~A[9] �ֱ���� a~j
	int A[10] = { 1,1,2,2,2,3,3,3,3,3 }; //A[x] == L ����λ���Ա x ��˵������Ϊ L�� 1�����2�����ģ�3��Ӣ��
	int matrixOfRelation[10][10] = { 0 };	
	int property = 0;					 //���Է��ԡ��Գ��ԡ������Զ�����ʱ��property == 3
	int x = 0, y = 0, z = 0;
	for (z = 0; z < 10; z++)
		for (y = 0; y < 10; y++)
			for (x = 0; x < 10; x++)
			{
				property = 0;
				/*** �Է��� **/
				if (0 <= x && x <= 9)
				{
					//�������Է��ԣ��򹹽�һ�� x �� x �ıߣ��� x ��˵������ΪȨ�أ�����ֱ����������ѭ��
					if (A[x] == A[x])
					{
						property++;
						matrixOfRelation[x][x] = A[x];
					}
					else
						goto justForBreakingOutOfMultipleLoops;
				}
				/*** �Գ��� **/
				if ((0 <= x && x <= 9) && (0 <= y && y <= 9) && A[x] == A[y])
				{
					//������Գ��ԣ��򹹽�x �� y �ı�, y �� x �ı�, �� y ��˵������ΪȨ�أ�����ֱ����������ѭ��
					if (A[y] == A[x])
					{
						property++;
						matrixOfRelation[y][x] = A[y];
						matrixOfRelation[x][y] = A[y];
					}
					else
						goto justForBreakingOutOfMultipleLoops;
				}
				/*** ������ **/
				if ((0 <= x && x <= 9) && (0 <= y && y <= 9) && (0 <= z && z <= 9) && A[x] == A[z] && A[z] == A[y])
				{
					//�������Է��ԣ��򹹽�һ�� x �� z �ıߣ��� x ��˵������ΪȨ�أ�����ֱ����������ѭ��
					if (A[x] == A[y])
					{
						property++;
						matrixOfRelation[x][z] = A[x];
					}
					else
						goto justForBreakingOutOfMultipleLoops;
				}
			}
	justForBreakingOutOfMultipleLoops:;
	if (3 == property)		//����ÿһ�������û��һ��������ȼ۹�ϵ�ģ���ӡ��ϵ����
	{
		printf("\nR��A�ϵĵȼ۹�ϵ,���ϵ�������£�\n\n");
		printf("  a b c d e f g h i j \n");
		for (int i = 0; i < 10; i++)
		{
			printf("%c", i + 'a');
			for (int j = 0; j < 10; j++)
			{
				printf("%2d",matrixOfRelation[i][j]);
			}
			printf("\n");
		}
		printf("\n1�����2�����ģ�3��Ӣ��\n\n");
	}
	else
		printf("R����A�ϵĵȼ۹�ϵ\n");
	return 0;
}












//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	//0�������1�������ģ�2����Ӣ��
//	int A[10] = { 0,0,1,1,1,2,2,2,2,2 };		//a��b�����c��d��e�����ģ�f��g��h��i��j��Ӣ��
//	int isEquivalentRelation = 1;
//	int x = 0, y = 0, z = 0;
//	for (z = 0; z < 10; z++)
//	{
//
//
//		for (y = 0; y < 10; y++)
//		{
//			for (x = 0; x < 10; x++)
//			{
//				int equivalentRelation = 0;		//�����Է��ԡ��Գ��ԡ�������ʱ��equivalentRelation == 3
//				/*** �Է��� **/
//				if (0 <= x && x <= 9)			// x �� A
//				{
//					if (A[x] == A[x])
//					{
//						equivalentRelation++;			//�����Է���
//					}
//					/*** �Գ��� **/
//					if ((0 <= x && x <= 9) && (0 <= y && y <= 9) && A[x] == A[y])
//					{
//						if (A[y] == A[x]) 
//						{
//							equivalentRelation++;		//����Գ���
//						}
//						/*** ������ **/
//						if ((0 <= x && x <= 9) && (0 <= y && y <= 9) && (0 <= z && z <= 9) && A[x] == A[z] && A[z] == A[y])
//						{
//							if (A[x] == A[y])
//							{
//								equivalentRelation++;	//���㴫����
//							}
//							if (equivalentRelation != 3)				//�Է��ԡ��Գ��ԡ���������һ��������
//							{
//								isEquivalentRelation = 0;
//								goto justForBreakingOutOfMultipleLoops;
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	justForBreakingOutOfMultipleLoops:;
//	if (isEquivalentRelation)	
//		printf("R��A�ϵĵȼ۹�ϵ\n");
//	else						
//		printf("R����A�ϵĵȼ۹�ϵ\n");
//
//	return 0;
//}







//#include <stdio.h>
//#include <stdlib.h>
//
//enum LANGUAGE { FRENCH, CHINESE, ENGLISH };
//
//int main()
//{
//	//a��b�����c��d��e�����ģ�f��g��h��i��j��Ӣ�
//	int A[10] =
//	{	FRENCH, FRENCH,
//		CHINESE,CHINESE,CHINESE,
//		ENGLISH,ENGLISH,ENGLISH,ENGLISH,ENGLISH
//	};
//	int isEquivalentRelation = 0;
//	int x = 0, y = 0, z = 0;
//	for ( z = 0; z < 10; z++)
//		for ( y = 0; y < 10; y++)
//			for (x = 0; x < 10; x++)
//			{
//				int equivalentRelation = 0;		//�����Է��ԡ��Գ��ԡ�������ʱ��equivalentRelation == 3
//				/*** �Է��� **/
//				if (0 <= x && x <= 9)						// x �� A
//				{
//					if (A[x] == A[x])
//					{
//						equivalentRelation++;			//�����Է���
//					}
//				}
//				/*** �Գ��� **/
//				if ((0 <= x && x <= 9) && (0 <= y && y <= 9) && A[x] == A[y])
//				{
//					if (A[y] == A[x])
//					{
//						equivalentRelation++;
//					}
//				}
//				/*** ������ **/
//				if ((0 <= x && x <= 9) && (0 <= y && y <= 9) && (0 <= z && z <= 9) && A[x] == A[z] && A[z] == A[y])
//				{
//					if (A[x] == A[y])
//					{
//						equivalentRelation++;
//					}
//				}
//
//				if (0 <= x && x <= 9)
//					if ((0 <= x && x <= 9) && (0 <= y && y <= 9) && A[x] == A[y])
//						if ((0 <= x && x <= 9) && (0 <= y && y <= 9) && (0 <= z && z <= 9) && A[x] == A[y] && A[y] == A[z])
//							if (equivalentRelation == 3)
//								isEquivalentRelation = 1;
//			}
//	
//	if (isEquivalentRelation)
//		printf("R��A�ϵĵȼ۹�ϵ\n");
//	else
//		printf("R����A�ϵĵȼ۹�ϵ\n");
//
//
//	return 0;
//}
