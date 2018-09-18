#include"LinkList.h"

void InitLinkList(pList * pplist)
{
	assert(pplist != NULL);
	*pplist = NULL;
}
void PrintLinkList(pList plist)
{
	pNode cur = plist;
	if (NULL == plist)
	{
		printf(" ");
		return;
	}
	while (cur != NULL)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("Over\n");
}
void PushFront(pList * pplist, DataType d)
{
	pNode newNode = NULL;
	assert(pplist != NULL);
	newNode = BuyNode(d);
	newNode->next = *pplist;
	*pplist = newNode;
}
void PushBack(pList * pplist, DataType d)
{
	pNode newNode = BuyNode(d);//����BuyNode�����½ڵ�
	assert(pplist != NULL);
	if (*pplist == NULL)//������
	{
		*pplist = newNode;//��ͷָ����½ڵ��������
	}
	else//�ǿ�����
	{
		pNode cur = *pplist;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}
int GetListLength(pList plist)
{
	pNode cur = plist;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

pNode BuyNode(DataType d)
{
	pNode newNode = (pNode)malloc(sizeof(Node));//�����½ڵ�
	if (NULL == newNode)
	{
		exit(EXIT_FAILURE);
	}
	newNode->data = d;
	newNode->next = NULL;
	return newNode;
}

void DestroyLinkList(pList * pplist)
{
	pNode cur = NULL;
	assert(pplist != NULL);
	cur = *pplist;
	while (cur)
	{
		pNode del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	*pplist = NULL;
}



void PopBack(pList * pplist)
{
	assert(pplist != NULL);
	if (*pplist == NULL)//û�нڵ�
	{
		return;
	}
	if ((*pplist)->next == NULL)//һ���ڵ�
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	else//һ�����ϵĽڵ�
	{
		pNode cur = *pplist;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}

}



void PopFront(pList * pplist)
{
	assert(pplist != NULL);
	if (*pplist == NULL)//û�нڵ�
	{
		return;
	}
	else//�нڵ�
	{
		pNode del = *pplist;
		*pplist = del->next;
		free(del);
		del = NULL;
	}

}

pNode Find(pList plist, DataType d)
{
	pNode cur = plist;
	while (cur)
	{
		if (cur->data == d)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;//û�ҵ�
}

void Erase(pList * pplist, pNode pos)
{
	assert(pplist != NULL);
	assert(pos != NULL);
	if (*pplist == pos)//���ָ���һ���ڵ�
	{
		pNode del = pos;
		*pplist = (*pplist)->next;
		free(del);
		del = NULL;
	}
	else
	{
		pNode cur = *pplist;
		while (cur && cur->next != pos)//�˴�Ҫ�ҵ�pos��ǰһ���ڵ㣬����Ҫ��pos�ڵ�freeǰ��
			//���뽫pos��ǰһ�ڵ�ͺ�һ�ڵ������������Դ˴�����cur!=pos��Ϊ����
		{
			cur = cur->next;
		}
		if (cur != NULL)
		{
			cur->next = pos->next;
			free(pos);
			pos = NULL;
		}
	}
}


void EraseNotTailNode(pNode pos)
{
	pNode del = NULL;
	assert(pos);
	assert(pos->next);
	//
	del = pos->next;
	pos->data = pos->next->data;
	//
	pos->next = del->next;
	free(del);
	del = NULL;
}
void Insert(pList * pplist, pNode pos, DataType d)
{
	pNode newNode = NULL;
	assert(pplist != NULL);
	assert(*pplist != NULL);
	assert(pos != NULL);
	if (pos == *pplist)
	{
		newNode = BuyNode(d);
		newNode->next = *pplist;
		*pplist = newNode;
	}
	else
	{
		pNode cur = *pplist;
		while (cur && cur->next != pos)
		{
			cur = cur->next;
		}
		if (cur != NULL)
		{
			newNode = BuyNode(d);
			newNode->next = pos;
			cur->next = newNode;
		}
	}
}




//�����ӡ�������� 
//
//
//void PrintTailToHead(pList plist)
//{
//	if (plist == NULL)
//		return;
//	PrintTailToHead(plist->next);
//	printf("%d ", plist->data);
//}


void Remove(pList* pplist, DataType d)
{
	pNode cur = NULL;
	pNode prev = NULL;
	assert(pplist);
	cur = *pplist;
	while (cur)
	{
		if (cur->data == d)
		{
			//��һ���ڵ�
			if (*pplist == cur)
			{
				{
					*pplist = cur->next;
					free(cur);
					cur = NULL;
				}
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = NULL;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
void RemoveAll(pList * pplist, DataType d)
{
	pNode cur = NULL;
	pNode prev = NULL;
	cur = *pplist;
	assert(pplist != NULL);
	while (cur)
	{
		if (cur->data == d)//�ҵ���
		{
			if (*pplist == cur)//��һ���ڵ�
			{
				*pplist = cur->next;
				free(cur);
				cur = *pplist;
			}
			else//���ǵ�һ���ڵ�
			{
				prev->next = cur->next;
				free(cur);
				cur = prev;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}


void PrintTailToHead(pList plist)
{
	pNode tail = NULL;
	pNode cur = plist;
	pNode prev = NULL;
	if (plist == NULL)
	{
		return;
	}
	while (cur)
	{
		tail = cur;
		cur = cur->next;
	}
	while (tail != plist)
	{
		cur = plist;
		while (cur != tail)
		{
			prev = cur;
			cur = cur->next;
		}
		printf("%d->", tail->data);
		tail = prev;
	}
	printf("%d->NULL\n", tail->data);
}



void JosephCycle(pList * pplist, int num)
{
	assert(pplist);
	pNode cur = NULL;
	pNode del = NULL;
	int count = 0;
	cur = *pplist;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = *pplist;
	cur = *pplist;
	while (cur->next!=cur)
	{
		count = num;
		while (--count)
		{
			cur = cur->next;
		}
		printf("ɾ����%d\n", cur->data);
		del = cur->next;
		cur->data = del->data;
		cur->next = del->next;
		free(del);
		del = NULL;
	}
	cur->next = NULL;

}


//һ��������һ����һ��
void FindMidNode(pList* pplist)
{
	/*pNode fast = *pplist;
	pNode slow = *pplist;
	if (NULL == *pplist)
	{
		printf("������Ϊ��");
	}
	else if (NULL == slow->next)
	{
		printf("%d ", slow->data);
	}
	else
	{
		while (fast->next&&fast)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		printf("%d ", slow->data);
	}*/
}

//һ������k��
void FindLastKNode(pList *pplist, int k)
{

	pNode fast = *pplist;
	pNode slow = *pplist;
	if (NULL == *pplist||k<=0)
	{
		printf("������Ϊ��");
	}
	while (k--)
	{
		fast = fast->next;
	}
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
		printf("%d ", slow->data);
}





void BubbleSort(pList * pplist)
{
	pNode cur = *pplist;
	pNode pre = *pplist;
	pNode end = NULL;
	int flag = 1;
	DataType tmp = 0;
	while (pre &&  pre->next && flag)
	{
		flag = 0;
		cur = *pplist;
		while (cur&&cur->next!=end)
		{
			if (cur->data > cur->next->data)
			{
				flag = 1;
				tmp = cur->data;
				cur->data=cur->next->data;
				cur->next->data = tmp;
			}
			cur = cur->next;
		}
		end = cur;
		pre = pre->next;
	}
}
pList Merge(pList list1, pList list2)
{
	pList newlist = NULL;
	if (NULL == list1)
	{
		return list2;
	}
	if (NULL == list2)
	{
		return list1;
	}
	if ((list1)->data < (list2)->data)
	{
		newlist = list1;
		newlist->next = Merge_R((list1)->next, list2);
	}
	if ((list1)->data >(list2)->data)
	{
		newlist = list2;
		newlist->next = Merge_R(list1, (list2)->next);
	}
	while (list1)
	{
		list1 = (list1)->next;
	}
	while (list2)
	{
		list2 = (list2)->next;
	}
	return newlist;
}
pList Merge_R(pList list1, pList list2)
{
    pList newlist = NULL;
	pNode cur = NULL;
	if (list1 == NULL)
		newlist = list2;
	if (list2 == NULL)
		newlist = list1;
	if (list1->data >= list2->data)
	{
		cur = BuyNode(list2->data);
		list2 = list2->next;
		newlist = cur;
	}
	else if (list1->data < list2->data)
	{
		cur = BuyNode(list1->data);
		list1 = list1->next;
		newlist = cur;
	}
	while (list1&&list2)
	{
		if (list1->data >= list2->data)
		{
			cur->next = BuyNode(list2->data);
			list2 = list2->next;
			cur = cur->next;
		}
		else if (list1->data < list2->data)
		{
			cur->next = BuyNode(list1->data);
			list1 = list1->next;
			cur = cur->next;
		}
	}
	while (list1)
	{
		cur->next = BuyNode(list1->data);
		list1 = list1->next;
		cur = cur->next;
	}
	while (list2)
	{
		cur->next = BuyNode(list2->data);
		list2 = list2->next;
		cur = cur->next;
	}
	return newlist;

}
//
void UnionSetJ(pList list1, pList list2)
{
	if (list1 == NULL || list2 == NULL)
		return;
	while (list1 && list2)
	{
		if (list1->data < list2->data)
		{
			list1 = list1->next;
		}
		else if (list1->data > list2->data)
		{
			list2 = list2->next;
		}
		else
		{
			printf("%d ", list1->data);
			list1 = list1->next;
			list2 = list2->next;
		}
	}
}

void UnionSetC(pList list1, pList list2)
{
	pList prev1 = NULL;
	pList prev2 = NULL;
	if (list1 == NULL || list2 == NULL)
		return;
	while (list1 && list2)
	{
		if (list1->data == list2->data)
		{
			list1 = list1->next;
			list2 = list2->next;
		}
		else if (list1->data > list2->data)
		{
			prev2 = list2;
           list2 = list2->next;
		   printf("%d ", prev2->data);
		}
		else
		{
			prev1 = list1;
			list1 = list1->next;
			printf("%d ", prev1->data);	
		}
	}
	while (list1)
	{
		printf("%d ", list1->data);
		list1 = list1->next;
	}
	while (list2)
	{
		printf("%d ", list2->data);
		list2 = list2->next;
	}
}




//��ָ�뷨
//void ReverseList(pList* pplist)
//{
//	pNode cur = NULL;
//	pNode prev = NULL;
//	pNode tmp = NULL;
//	assert(pplist);
//	if (*pplist == NULL || (*pplist)->next == NULL)
//	{
//		return;
//	}
//	prev = *pplist;
//	cur = prev->next;
//	tmp = cur->next;
//	while (cur)
//	{
//		cur->next = prev;
//		prev = cur;
//		cur = tmp;
//		if (tmp)
//			tmp = tmp->next;
//	}
//	(*pplist)->next = NULL;
//	*pplist = prev;
//}

//ͷ�巨
void ReverseList(pList* pplist)
{
	assert(pplist);
	if (*pplist == NULL || (*pplist)->next == NULL)
	{
		return;
	}
	pNode cur = NULL;
	pList newnode = NULL;
	while (*pplist)
	{
		cur = *pplist;
		*pplist = cur->next;
		cur->next = newnode;
		newnode = cur;
	}
	*pplist= newnode;
}


//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣���������������� 
int CheckCross(pList list1, pList list2)
{
	if (NULL == list1 || NULL == list2)
		return 0;
	//���������һ���ڵ�
	while (list1->next)
	{
		list1 = list1->next;
	}
	while (list2->next)
	{
		list2 = list2->next;
	}
	if (list1 == list2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//�󽻵�
pNode GetCrossNode(pNode list1, pList list2)
{
	if (NULL == list1 || NULL == list2)
		return 0;
	int size1 = 0;
	int size2 = 0;
	int del = 0;
	pNode cur1= list1;
	pNode cur2 = list2;
	while (cur1)
	{
		cur1 = cur1->next;
		size1++;
	}
	while (cur2)
	{
		cur2 = cur2->next;
		size2++;
	}
	del = size1 - size2;
    cur1 = list1;
	cur2 = list2;
	if (del > 0)
	{
		while (del--)
		{
			cur1 = cur1->next;
		}
	}
	else
	{
		while (del++)
		{
			cur2 = cur2->next;
		}
	}
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;
}
//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿 
pNode GetCrossNodeH(pNode list1, pList list2)
{
	pNode fast = list1;
	pNode slow = list2;
	if (NULL == list1 || NULL == list2)
		return 0;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
			return slow;
	}
	return NULL;
}

//�жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ÿ���㷨��ʱ�临�Ӷ�&�ռ临�Ӷȡ�
pNode IsCrossH(pList list1)
{
	pNode fast = list1;
	pNode slow = list1;
	if (NULL == list1 )
		return NULL;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
			return slow;
	}
	return NULL;
}
int GetCircleLength(pNode meet)
{
	pNode cur = meet;
	int len = 1;
	if (NULL == meet)
	{
		return 0;
	}
	else
	{
		while (cur->next!=meet)
		{
			cur = cur->next;
			len++;
		}
	}
	return len;
}
//��ڵ�
pNode GetCycleEntryNode(pList list)
{
	pNode plist = list;
	pNode pmeet = IsCrossH(list);
	if (NULL == list)
		return NULL;
	else
	{
		while (plist != pmeet)
		{
			plist = plist->next;
			pmeet = pmeet->next;
		}
	}
	return pmeet;
}




ComplexNode* BuyComplexNode(DataType x)
{
	ComplexNode* node = (ComplexNode*)malloc(sizeof(ComplexNode));
	node->_next = NULL;
	node->_random = NULL;
	node->_data = x;
	return node;
}
ComplexNode* CopyList(ComplexNode** list)
{
	ComplexNode* cur = NULL;
	ComplexNode* newnode = NULL;
	ComplexNode* newlist = NULL;
	if (*list == NULL)
		return NULL;
	//������ͬ�ڵ㲢���ں���
	cur = *list;
	while (cur)
	{
		newnode = BuyComplexNode(cur->_data);
		newnode->_next = cur->_next;
		cur->_next = newnode;
		cur = newnode->_next;
	}
	//�������ֵ
	while (cur)
	{
		newnode = cur->_next;
		if (cur->_random)
		{
			newnode->_random = cur->_random->_next;
		}
		cur = newnode->_next;
	}
	//����
	cur = *list;
	newlist = (*list)->_next;
	while (cur->_next)
	{
		newnode = cur->_next;
		cur->_next = newnode->_next;
		cur = newlist;
	}
	return newlist;
}



