#ifdef _SList_H_
#define _SList_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int SLDataType;
typedef struct Node{
    SLDataType data;
    struct Node* next;
}Node;
//初始化一个节点
extern Node* CreateNode(int data);
//单链表尾部插入
extern void InsertEnd(Node** list,int data);
//单链表尾部删除
extern void DeleteEnd(Node** list);
//单链表头部插入
extern void InsertFront(Node** list,int data);
//单链表头部删除
extern void DeleteFront(Node** list);
//单链表的查找
extern bool Find(Node* list,int data);
//在pos位置插入数据
extern void InsertAfter(Node* pos,int data);
//在pos位置之后的数据的删除
extern void DeleteAfter(Node* pos);
#endif