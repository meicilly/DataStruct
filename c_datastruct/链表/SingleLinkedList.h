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
//��ʼ��һ���ڵ�
extern Node* CreateNode(int data);
//������β������
extern void InsertEnd(Node** list,int data);
#endif