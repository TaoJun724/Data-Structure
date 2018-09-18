#ifndef __LINKLIST_H__ 
#define __LINKLIST_H__ 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int DataType;


typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode, List, *pList;




void InitLinkList(pList* pplist);
void DestroyLinkList(pList* pplist);
int GetListLength(pList plist);
void PushFront(pList* pplist, DataType d);
void PushBack(pList* pplist, DataType d);
pNode BuyNode(DataType d);
void PrintLinkList(pList plist);
void PopFront(pList* pplist);
//指定位置删除 
void Erase(pList* pplist, pNode pos);
void PopBack(pList* pplist);
pNode Find(pList plist, DataType d);
void EraseNotTailNode(pNode pos);
void Remove(pList* pplist, DataType d);
//在指定位置之前插入一个值 
void Insert(pList* pplist, pNode pos, DataType d);
//逆序打印单项链表 
void PrintTailToHead(pList plist);
void RemoveAll(pList* pplist, DataType d);





// 比较顺序表和链表的优缺点 
// 说说它们分别在什么场景下使用？ 
//顺序表：内存中地址连续，优点是随机访问比较便捷快速，创建也比较简单，随机查找比较方便，可以直接给出下标，排序也方便简单。
//缺点是不够灵活，删除增加的工作量叫大，比较麻烦，长度不能实时变化
//适用场景：适用于需要大量访问元素的 而少量增添 / 删除元素的程序
//单链表：内存中地址不是连续的，优点是插入删除比较方便，长度可以实时变化。
//缺点是不支持随机查找，查找元素需要遍历。
//适用场景 : 适用于需要进行大量增添 / 删除元素操作 而对访问元素无要求的程序
//单链表实现约瑟夫环 约瑟夫环(约瑟夫问题)是一个数学的应用问题:已知n个人(以编号1，2，3...n分别表示)围坐在一张圆桌周围。从编号为k的人开始报数，数到m的那个人出列;他的下一个人又从1开始报数，数到m的那个人又出列;依此规律重复下去，直到圆桌周围的人全部出列。通常解决这类问题时我们把编号从0~n-1，最后 结果+1即为原问题的解。
void JosephCycle(pList * pplist, int num);
// 查找单链表的中间节点，要求只能遍历一次链表 
void FindMidNode(pList pplist);
//查找单链表的倒数第k个节点，要求只能遍历一次链表 
void FindLastKNode(pList *pplist, int k);
//单链表排序（冒泡排序） 
void BubbleSort(pList * pplist);
//合并两个有序链表,合并后依然有序 
pList Merge(pList list1, pList list2);
//递归 
pList Merge_R(pList list1, pList list2);
//求两个有序单链表交集(差集)。 
void UnionSetJ(pList list1, pList list2);
void UnionSetC(pList list1, pList list2);
//逆置/反转单链表 
void ReverseList(pList* pplist);
//判断两个链表是否相交，若相交，求交点。（假设链表不带环） 
int CheckCross(pList list1, pList list2);
//求交点
pNode GetCrossNode(pNode list1, pList list2);
//判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】 
pNode GetCrossNodeH(pNode list1, pList list2);
 





//判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算每个算法的时间复杂度&空间复杂度。 
pNode IsCrossH(pList list1);
int GetCircleLength(pNode meet);
pNode GetCycleEntryNode(pList list);







//复杂链表的复制。 
//一个链表的每个节点，有一个指向next指针指向下一个节点， 
//还有一个random指针指向这个链表中的一个随机节点或者NULL， 
//现在要求实现复制这个链表，返回复制后的新链表。
typedef struct ComplexNode
{
	DataType _data;
	struct ComplexNode* _next;
	struct ComplexNode* _random;
}ComplexNode;

ComplexNode* CopyList(ComplexNode* list);








#endif 