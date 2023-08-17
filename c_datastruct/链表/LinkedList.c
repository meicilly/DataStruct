#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int LDataType;
typedef struct ListNode
{
	LDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;
//创建链表节点
ListNode* BuyListNode()
{
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	if (tmp == NULL)
	{
		perror("malloc");
	}
	return tmp;
}
void ListPushfront(ListNode* phead, LDataType x)
{
	assert(phead);
	ListNode* newnode = BuyListNode();
	ListNode* tail = phead->next;
	phead->next = newnode;
	newnode->next = tail;
	newnode->prev = phead;
	tail->prev = newnode;
	newnode->data = x;
	//ListInsert(phead->next, x);
}
void ListPopFront(ListNode* phead)
{
	assert(phead);
	ListNode* tail = phead->next;
	tail->next->prev = phead;
	phead->next = tail->next;
	free(tail);
	//ListErase(phead->next);
}
void ListPushBack(ListNode* phead, LDataType x)
{
	ListNode* plist = BuyListNode();
	ListNode* tail = phead->prev;
	tail->next = plist;
	plist->prev = tail;
	plist->next = phead;
	phead->prev = plist;
	plist->data = x;
	//ListInsert(phead, x);
}
void ListPopBack(ListNode* phead)
{
	assert(phead);
	ListNode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
	//ListErase(phead->prev);
}
void ListInsert(ListNode* pos, LDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode();
	pos->prev->next = newnode;
	newnode->prev = pos->prev;
	newnode->next = pos;
	pos->prev = newnode;
	newnode->data = x;
}
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}
ListNode* ListFind(ListNode* phead, LDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (phead != cur)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}