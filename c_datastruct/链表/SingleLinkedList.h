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
//������β��ɾ��
extern void DeleteEnd(Node** list);
//������ͷ������
extern void InsertFront(Node** list,int data);
//������ͷ��ɾ��
extern void DeleteFront(Node** list);
//������Ĳ���
extern bool Find(Node* list,int data);
//��posλ�ò�������
extern void InsertAfter(Node* pos,int data);
//��posλ��֮������ݵ�ɾ��
extern void DeleteAfter(Node* pos);
#endif