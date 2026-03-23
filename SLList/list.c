
演示单链表



#include<stdio.h>
#include<stdlib.h>
//创建链表
//定义链表
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
}ListNode;

//申请空间创建链表
ListNode* BuyNode(LTDataType x)
{
	ListNode* newnode;
	newnode=(ListNode*)malloc(sizeof(ListNode));
	//申请错误时
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	//赋值
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//打印链表
void PrintList(ListNode* head)
{
	ListNode* cur = head;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
			cur = cur->next;
	}
	printf("NULL");
}

//尾插
void ListPushBack(ListNode** pphead, LTDataType x)
{
	//先给要插入的节点申请空间
	ListNode* newnode = BuyNode(x);
	//插入之前判断链表是否为空的
	if (*pphead == NULL)
	{
		*pphead = newnode;
		return;
	}
	//开始插入链表中
	//先定义尾节点
	ListNode* tail = *pphead;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = newnode;
}

//头插
void ListPushFront(ListNode** pphead,LTDataType x)
{
	ListNode* newnode = BuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
	
}

//尾删
void ListPopBack(ListNode** pphead)
{
	//判断当链表为空时
	if (*pphead == NULL)
	{
		return;
	}
	//判断当链表只有一个元素时
	if ((*pphead)->next == NULL)
	{
		//释放头节点
		free(*pphead);
		*pphead = NULL;
	}
	//定义尾节点以及它的前一个节点
	ListNode* prev;
	ListNode* tail = *pphead;
	while (tail->next != NULL)
	{
		prev = tail;
		tail = tail->next;
	}
	free(tail);
	tail == NULL;
	prev->next = NULL;
}

//头删
void ListPopFront(ListNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	ListNode* del = *pphead;
	*pphead = (*pphead)->next;
	free(del);
	del = NULL;
}

//查找
ListNode* ListFind(ListNode* head, LTDataType x)
{
	//定义寻找节点
	ListNode* cur = head;
	//节点一直向后直到为空停止
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在某个位置之前插入
void ListInsert(ListNode** pphead,ListNode* pos,LTDataType x)
{
	ListNode* newnode = BuyNode(x);
	//如果传入的位置和头节点的相同
	if (pos == *pphead)
	{
		newnode->next = *pphead;
		*pphead = newnode;
		return;
	}
	ListNode* cur = *pphead;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	cur->next = newnode;
	newnode->next = pos;

}
//在某个位置之后插入
void ListInsertAfter(ListNode* pos, LTDataType x)
{
	ListNode* newnode = BuyNode(x);
	if (pos == NULL)
	{
		pos = newnode;
		return;
	}
	newnode->next=pos->next;
	pos->next = newnode;
}
//删除某个位置的元素
void ListErase(ListNode** pphead, ListNode* pos)
{
	if (*pphead == NULL || pos == NULL)
	{
		return;
	}
	if (pos == *pphead)
	{
		*pphead = (*pphead)->next;
		free(pos);
		pos = NULL;
		return;
	}
	ListNode* prev;
	ListNode* cur = *pphead;
	while (cur != pos&&cur!=NULL)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	free(cur);
	cur = NULL;
}
//删除某个位置之后的元素
void ListEraseAfter(ListNode* pos)
{
	//为空就不用继续了
	if (pos == NULL || pos->next == NULL)
	{
		return;
	}
	ListNode* del = pos->next;
	pos->next = pos->next->next;
	free(del);
	del = NULL;
}
int main()
{
	//定义头节点
	ListNode* head;
	//调用函数申请空间
	head=BuyNode(1);
	head->next = BuyNode(2);
	head->next->next = BuyNode(3);
	//打印链表
	PrintList(head);
	//尾插
	ListPushBack(&head, 4);
	//头插
	ListPushFront(&head, 5);
	//尾删
	ListPopBack(&head);
	//头删
	ListPopFront(&head);
	//查找
	ListFind(head, 2);
	return 0;
}
