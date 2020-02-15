#include <stdio.h>
int main()
{
	//A[0]~A[9] 分别代表 a~j
	int A[10] = { 1,1,2,2,2,3,3,3,3,3 }; //A[x] == L 代表参会人员 x 所说的语言为 L， 1—法语，2—中文，3—英语
	int matrixOfRelation[10][10] = { 0 };	
	int property = 0;					 //当自反性、对称性、传递性都满足时，property == 3
	int x = 0, y = 0, z = 0;
	for (z = 0; z < 10; z++)
		for (y = 0; y < 10; y++)
			for (x = 0; x < 10; x++)
			{
				property = 0;
				/*** 自反性 **/
				if (0 <= x && x <= 9)
				{
					//若满足自反性，则构建一条 x 到 x 的边，以 x 所说的语言为权重，否则直接跳出三重循环
					if (A[x] == A[x])
					{
						property++;
						matrixOfRelation[x][x] = A[x];
					}
					else
						goto justForBreakingOutOfMultipleLoops;
				}
				/*** 对称性 **/
				if ((0 <= x && x <= 9) && (0 <= y && y <= 9) && A[x] == A[y])
				{
					//若满足对称性，则构建x 到 y 的边, y 到 x 的边, 以 y 所说的语言为权重，否则直接跳出三重循环
					if (A[y] == A[x])
					{
						property++;
						matrixOfRelation[y][x] = A[y];
						matrixOfRelation[x][y] = A[y];
					}
					else
						goto justForBreakingOutOfMultipleLoops;
				}
				/*** 传递性 **/
				if ((0 <= x && x <= 9) && (0 <= y && y <= 9) && (0 <= z && z <= 9) && A[x] == A[z] && A[z] == A[y])
				{
					//若满足自反性，则构建一条 x 到 z 的边，以 x 所说的语言为权重，否则直接跳出三重循环
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
	if (3 == property)		//遍历每一种情况，没有一个不满足等价关系的，打印关系矩阵
	{
		printf("\nR是A上的等价关系,其关系矩阵如下：\n\n");
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
		printf("\n1—法语，2—中文，3—英语\n\n");
	}
	else
		printf("R不是A上的等价关系\n");
	return 0;
}












//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	//0—讲法语，1—讲中文，2—讲英语
//	int A[10] = { 0,0,1,1,1,2,2,2,2,2 };		//a和b讲法语，c，d和e讲中文，f，g，h，i和j讲英语
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
//				int equivalentRelation = 0;		//满足自反性、对称性、传递性时，equivalentRelation == 3
//				/*** 自反性 **/
//				if (0 <= x && x <= 9)			// x ∈ A
//				{
//					if (A[x] == A[x])
//					{
//						equivalentRelation++;			//满足自反性
//					}
//					/*** 对称性 **/
//					if ((0 <= x && x <= 9) && (0 <= y && y <= 9) && A[x] == A[y])
//					{
//						if (A[y] == A[x]) 
//						{
//							equivalentRelation++;		//满足对称性
//						}
//						/*** 传递性 **/
//						if ((0 <= x && x <= 9) && (0 <= y && y <= 9) && (0 <= z && z <= 9) && A[x] == A[z] && A[z] == A[y])
//						{
//							if (A[x] == A[y])
//							{
//								equivalentRelation++;	//满足传递性
//							}
//							if (equivalentRelation != 3)				//自反性、对称性、传递性有一个不满足
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
//		printf("R是A上的等价关系\n");
//	else						
//		printf("R不是A上的等价关系\n");
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
//	//a和b讲法语，c，d和e讲中文，f，g，h，i和j讲英语。
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
//				int equivalentRelation = 0;		//满足自反性、对称性、传递性时，equivalentRelation == 3
//				/*** 自反性 **/
//				if (0 <= x && x <= 9)						// x ∈ A
//				{
//					if (A[x] == A[x])
//					{
//						equivalentRelation++;			//满足自反性
//					}
//				}
//				/*** 对称性 **/
//				if ((0 <= x && x <= 9) && (0 <= y && y <= 9) && A[x] == A[y])
//				{
//					if (A[y] == A[x])
//					{
//						equivalentRelation++;
//					}
//				}
//				/*** 传递性 **/
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
//		printf("R是A上的等价关系\n");
//	else
//		printf("R不是A上的等价关系\n");
//
//
//	return 0;
//}
