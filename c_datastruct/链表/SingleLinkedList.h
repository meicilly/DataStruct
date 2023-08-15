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
#endif