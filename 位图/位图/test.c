#include "BitSet.h"




void test()
{
	BitSet a;
	BitSetInit(&a, 10);
	BitSetSet1(&a, 5);
	BitSetSet1(&a, 2);
	BitSetSet1(&a, 9);
	BitSetSet1(&a, 3);
	BitSetSet0(&a, 2);
	printf("%d\n", HaveNumber(&a, 5));
	printf("%d\n", HaveNumber(&a, 2));
	printf("%d\n", HaveNumber(&a, 9));
}
int main()
{
	test();
	system("pause");
	return 0;
}