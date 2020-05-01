#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct acmer
{
	char name[15];
	int timeScore;
	int AC;
}acmer;

//acmer Acmer[10] = 
//{ 
//	{"aa",1	,5	},
//	{"ab",1	,4	},
//	{"ac",2	,4	},
//	{"ad",2	,4	},
//	{"ae",1	,3	},
//	{"dd",1	,5	},
//};

acmer Acmer[] =
{
	{"ab",1	,5	},
	{"ad",1	,4	},
	{"aa",2	,4	},
	{"ae",2	,4	},
	{"dd",1	,3	},
	{"ac",1	,5	},
	{"af",3	,5	},
	{"ag",4	,5	},
	{"de",2	,3	},
	{"df",4	,4	},
};

/*** qsort() 辅助函数  **/
int cmp(const void* a, const void* b);

int main()
{


	int currentACMer = sizeof(Acmer) / sizeof(acmer);

	/*** qsort多级排序 **/
	qsort(Acmer, currentACMer, sizeof(acmer), cmp);

	/*** 输出 **/
	for (int j = 0; j < currentACMer; j++)
	{
		printf("%-10s %2d %4d\n", Acmer[j].name, Acmer[j].AC, Acmer[j].timeScore);

		//printf("%2d %4d %-10s\n",Acmer[j].AC,  Acmer[j].timeScore ,Acmer[j].name);
	}

	return 0;
}


/*** qsort() 辅助函数  **/
int cmp(const void* a, const void* b)
{
	/*** 转换成需要的类型 **/
	acmer* A = (acmer*)a;
	acmer* B = (acmer*)b;

	/*** 定义排序方式 **/
	if (A->AC != B->AC)
	{
		// A->xxx - B->xxx ：升序
		// B->xxx - A->xxx ：降序
		return B->AC - A->AC;
	}
	else if (A->timeScore != B->timeScore)
	{
		return A->timeScore - B->timeScore;
	}
	return strcmp(A->name, B->name);

	//if (strcmp(A->name, B->name))
	//{
	//	// A->xxx - B->xxx ：升序
	//	// B->xxx - A->xxx ：降序
	//	return strcmp(A->name, B->name);
	//}
	//else if (A->timeScore != B->timeScore)
	//{
	//	return A->timeScore - B->timeScore;
	//}
	//return B->AC - A->AC;
}

