#include "array.h"

int main()
{
	int count = 0;
	int number;
	Array a = ArrayCreate(100);
	printf("%d\n", ArraySize(&a));	//·â×°£¬±£»¤size
	printf("%d\n", a.size);			
	*ArrayAt(&a, 0) = 10;
	printf("%d\n", *ArrayAt(&a, 0));
	
	while (number != -1)
	{
		scanf("%d", &number);
		if (number != -1)
		{
			*ArrayAt(&a, count++) = number;
		}
	}
	ArrayFree(&a);
	system("pause");
	return 0;
}



