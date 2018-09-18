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
//ָ��λ��ɾ�� 
void Erase(pList* pplist, pNode pos);
void PopBack(pList* pplist);
pNode Find(pList plist, DataType d);
void EraseNotTailNode(pNode pos);
void Remove(pList* pplist, DataType d);
//��ָ��λ��֮ǰ����һ��ֵ 
void Insert(pList* pplist, pNode pos, DataType d);
//�����ӡ�������� 
void PrintTailToHead(pList plist);
void RemoveAll(pList* pplist, DataType d);





// �Ƚ�˳�����������ȱ�� 
// ˵˵���Ƿֱ���ʲô������ʹ�ã� 
//˳����ڴ��е�ַ�������ŵ���������ʱȽϱ�ݿ��٣�����Ҳ�Ƚϼ򵥣�������ұȽϷ��㣬����ֱ�Ӹ����±꣬����Ҳ����򵥡�
//ȱ���ǲ�����ɾ�����ӵĹ������д󣬱Ƚ��鷳�����Ȳ���ʵʱ�仯
//���ó�������������Ҫ��������Ԫ�ص� ���������� / ɾ��Ԫ�صĳ���
//�������ڴ��е�ַ���������ģ��ŵ��ǲ���ɾ���ȽϷ��㣬���ȿ���ʵʱ�仯��
//ȱ���ǲ�֧��������ң�����Ԫ����Ҫ������
//���ó��� : ��������Ҫ���д������� / ɾ��Ԫ�ز��� ���Է���Ԫ����Ҫ��ĳ���
//������ʵ��Լɪ�� Լɪ��(Լɪ������)��һ����ѧ��Ӧ������:��֪n����(�Ա��1��2��3...n�ֱ��ʾ)Χ����һ��Բ����Χ���ӱ��Ϊk���˿�ʼ����������m���Ǹ��˳���;������һ�����ִ�1��ʼ����������m���Ǹ����ֳ���;���˹����ظ���ȥ��ֱ��Բ����Χ����ȫ�����С�ͨ�������������ʱ���ǰѱ�Ŵ�0~n-1����� ���+1��Ϊԭ����Ľ⡣
void JosephCycle(pList * pplist, int num);
// ���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������ 
void FindMidNode(pList pplist);
//���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������ 
void FindLastKNode(pList *pplist, int k);
//����������ð������ 
void BubbleSort(pList * pplist);
//�ϲ�������������,�ϲ�����Ȼ���� 
pList Merge(pList list1, pList list2);
//�ݹ� 
pList Merge_R(pList list1, pList list2);
//����������������(�)�� 
void UnionSetJ(pList list1, pList list2);
void UnionSetC(pList list1, pList list2);
//����/��ת������ 
void ReverseList(pList* pplist);
//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣���������������� 
int CheckCross(pList list1, pList list2);
//�󽻵�
pNode GetCrossNode(pNode list1, pList list2);
//�ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿 
pNode GetCrossNodeH(pNode list1, pList list2);
 





//�жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ÿ���㷨��ʱ�临�Ӷ�&�ռ临�Ӷȡ� 
pNode IsCrossH(pList list1);
int GetCircleLength(pNode meet);
pNode GetCycleEntryNode(pList list);







//��������ĸ��ơ� 
//һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬 
//����һ��randomָ��ָ����������е�һ������ڵ����NULL�� 
//����Ҫ��ʵ�ָ�������������ظ��ƺ��������
typedef struct ComplexNode
{
	DataType _data;
	struct ComplexNode* _next;
	struct ComplexNode* _random;
}ComplexNode;

ComplexNode* CopyList(ComplexNode* list);








#endif 