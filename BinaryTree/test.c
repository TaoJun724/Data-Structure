#include "BinaryTree.h"

void Test()
{
	char array[] = { 'A', 'B', 'D', '#', '#', '#', 'C',
		'E', '#', '#', 'F', '#', '#' };
	size_t i = 0;
	BTNode* tree = BinaryTreeCreate(array, sizeof(array) / sizeof(BTDataType), &i);
	/* BinaryTreeDestory(&tree);*/
	BinaryTreePrevOrder(tree);
	printf("\n");
	BinaryTreePrevOrderNonR(tree);
	printf("\n");
	BinaryTreeInOrder(tree);
	printf("\n");
	BinaryTreeInOrderNonR(tree);
	printf("\n");
	BinaryTreePostOrder(tree);
	printf("\n");
	BinaryTreePostOrderNonR(tree);
	printf("\n");

	/*printf("%d", BinaryTreeSize(tree));*/
	/*printf("%d", BinaryTreeLeafSize(tree));*/
	/*printf("%d", BinaryTreeKlevelSize(tree, 1));*/
	/* BinaryTreeLevelOrder(tree);*/
	/*printf("%d", BTreeHeight(tree));*/
	/*printf("%d", BinaryTreeComplete(tree));*/
}
int main()
{
	Test();
	system("pause");
	return 0;
}