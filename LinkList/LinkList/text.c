#define _CRT_SECURE_NO_WARNINGS 1

#include"LinkList.h"
void test()
{
	Node* plist = NULL;//指向第一个节点的指针
	InitLinkList(&plist);//初始化plist为空指针，所以要传地址
	PushBack(&plist, 1);//传地址的原因：当链表中没有节点时，要改变plist，所以要传地址
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PrintLinkList(plist);
	/*DestroyLinkList(&plist);
	PrintLinkList(plist);*/
	printf("%d个节点\n", GetListLength(plist));
}
void TestPopBack()
{
	Node* plist = NULL;//指向第一个节点的指针
	InitLinkList(&plist);//初始化plist为空指针，所以要传地址
	PushBack(&plist, 1);//传地址的原因：当链表中没有节点时，要改变plist，所以要传地址
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PrintLinkList(plist);
	PopBack(&plist);
	PrintLinkList(plist);
	DestroyLinkList(&plist);
}
void TestPushFront()
{
	Node* plist = NULL;//指向第一个节点的指针
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintLinkList(plist);
	DestroyLinkList(&plist);
}
void TestPopFront()
{
	Node* plist = NULL;//指向第一个节点的指针
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);

	PrintLinkList(plist);

	PopFront(&plist);

	PrintLinkList(plist);
	DestroyLinkList(&plist);
}
void TestFind()
{
	Node* plist = NULL;//指向第一个节点的指针
	pNode pos = NULL;
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 8);
	PrintLinkList(plist);
	pos = Find(plist, 1);
	if (pos != NULL)
	{
		printf("%d\n", pos->data);
	}
	PrintLinkList(plist);
	DestroyLinkList(&plist);
}
void TestErase()
{
	Node* plist = NULL;//指向第一个节点的指针
	pNode pos = NULL;
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintLinkList(plist);
	pos = Find(plist, 2);
	if (pos != NULL)
	{
		Erase(&plist, pos);
	}
	PrintLinkList(plist);
	DestroyLinkList(&plist);
}
void TestEraseNotNode()
{
	Node* plist = NULL;//指向第一个节点的指针
	pNode pos = NULL;
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PrintLinkList(plist);
	pos = Find(plist, 3);
	if (pos != NULL)
	{
		EraseNotTailNode(pos);
	}
	PrintLinkList(plist);
	DestroyLinkList(&plist);
}


void TestInsert()
{
	Node* plist = NULL;//指向第一个节点的指针
	pNode pos = NULL;
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PrintLinkList(plist);
	pos = Find(plist, 2);
	if (pos != NULL)
	{
		Insert(&plist, pos, 8);
	}
	PrintLinkList(plist);
	DestroyLinkList(&plist);
}
void TestPrintTailToHead()
{
	Node* plist = NULL;//指向第一个节点的指针
	InitLinkList(&plist);//初始化plist为空指针，所以要传地址
	PushBack(&plist, 1);//传地址的原因：当链表中没有节点时，要改变plist，所以要传地址
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PrintTailToHead(plist);
}


void TestRemove()
{
	Node* plist = NULL;//指向第一个节点的指针
	pNode pos = NULL;
	PushBack(&plist, 3);
	PushBack(&plist, 1);
	PushBack(&plist, 3);
	PushBack(&plist, 3);
	PrintLinkList(plist);
	Remove(&plist, 3);
	PrintLinkList(plist);
}
void TestRemoveAll()
{
	Node* plist = NULL;//指向第一个节点的指针
	PushBack(&plist, 2);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 3);
	PrintLinkList(plist);
	RemoveAll(&plist, 2);
	PrintLinkList(plist);
}

void TestJosephCycle()
{
	Node* plist = NULL;//指向第一个节点的指针
	pNode pos = NULL;
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PrintLinkList(plist);
	JosephCycle(&plist, 3);
}
void TestFindMidNode()
{
	Node* plist = NULL;//指向第一个节点的指针
	pNode pos = NULL;
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PrintLinkList(plist);
	FindMidNode(&plist);
}
void TestFindLastKNode()
{
	Node* plist = NULL;//指向第一个节点的指针
	pNode pos = NULL;
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PrintLinkList(plist);
	FindLastKNode(&plist,2);
}

void TestBubbleSort()
{
	Node* plist = NULL;//指向第一个节点的指针
	pNode pos = NULL;
	PushBack(&plist, 65);
	PushBack(&plist, 2);
	PushBack(&plist, 47);
	PushBack(&plist, 4);
	PushBack(&plist, 11);
	BubbleSort(&plist);
	PrintLinkList(plist);
}

void TestMerge_R()
{
	Node* newlist = NULL;
	Node* plist1 = NULL;//指向第一个节点的指针
	PushBack(&plist1, 10);
	PushBack(&plist1, 2);
	PushBack(&plist1, 6);
	PushBack(&plist1, 40);
	PushBack(&plist1, 111);
	PrintLinkList(plist1);
	Node* plist2 = NULL;//指向第一个节点的指针
	PushBack(&plist2, 4);
	PushBack(&plist2, 21);
	PushBack(&plist2, 600);
	PrintLinkList(plist2);
	newlist = Merge_R(plist1, plist2);
	PrintLinkList(newlist);
}
void TestMerge()
{
	Node* newlist = NULL;
	Node* plist1 = NULL;//指向第一个节点的指针
	PushBack(&plist1, 2);
	PushBack(&plist1, 3);
	PushBack(&plist1, 6);
	PushBack(&plist1, 40);
	PushBack(&plist1, 111);
	PrintLinkList(plist1);
	Node* plist2 = NULL;//指向第一个节点的指针
	PushBack(&plist2, 1);
	PushBack(&plist2, 21);
	PushBack(&plist2, 600);
	PrintLinkList(plist2);
	newlist = Merge(plist1, plist2);
	PrintLinkList(newlist);
}
void TestUnionSet()
{
	Node* newlist = NULL;
	Node* plist1 = NULL;//指向第一个节点的指针
	PushBack(&plist1, 1);
	PushBack(&plist1, 5);
	PushBack(&plist1, 22);
	PushBack(&plist1, 77);
	PrintLinkList(plist1);
	Node* plist2 = NULL;//指向第一个节点的指针
	PushBack(&plist2, 2);
	PushBack(&plist2, 5);
	PushBack(&plist2, 22);
	PushBack(&plist2, 90);
	PushBack(&plist2, 777);
	PrintLinkList(plist2);
    UnionSetC(plist1, plist2);
	PrintLinkList(newlist);
}
void TestReverseList()
{
	Node* plist1 = NULL;//指向第一个节点的指针
	PushBack(&plist1, 1);
	PushBack(&plist1, 5);
	PushBack(&plist1, 22);
	PushBack(&plist1, 77);
	PrintLinkList(plist1);
	ReverseList(&plist1);
	PrintLinkList(plist1);
}
void TestCheckCross()
{
	Node* plist1 = NULL;//指向第一个节点的指针
	Node* plist2 = NULL;//指向第一个节点的指针
	PushBack(&plist1, 2);
	PushBack(&plist1, 5);
	PushBack(&plist1, 22);
	PushBack(&plist1, 77);
	PrintLinkList(plist1);
	PushBack(&plist2, 2);
	PushBack(&plist2, 5);
	plist2->next->next = Find(plist1, 22);
	PrintLinkList(plist2);
	int ret = CheckCross(plist1, plist2);
	printf("%d\n", ret);
	pNode cur;
	cur = GetCrossNode(plist1,plist2);
	printf("%d", cur->data);

}
void TestCycle()
{
	Node* plist = NULL;//指向第一个节点的指针
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PushBack(&plist, 6);
	pNode cur = NULL;
	cur = plist;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = plist;
	int ret = GetCircleLength(plist);
	pNode del = GetCycleEntryNode(plist);
	printf("%d\n", ret);
	printf("%d\n", del->data);
}
int main()
{
	/*test();*/
	//TestPopBack();
	//TestPushFront();
	/*TestPopFront();*/
	/*TestFind();*/
	/*TestErase();*/
    /*TestEraseNotNode();*/
	/*TestRemove();*/
	/*TestInsert();*/
	/*TestPrintTailToHead();*/
	/*TestRemoveAll();*/
	/*TestJosephCycle();*/
	/*TestFindMidNode();*/
	/*TestFindLastKNode();*/
	/*TestBubbleSort();*/
	/*TestMerge();*/
	/*TestUnionSet();*/
	/*TestReverseList();*/
	/*TestCheckCross();*/
	TestCycle();
	system("pause");
	return 0;
}