
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int SLDataType;
typedef struct Node{
    SLDataType data;
    struct Node* next;
}Node;

//��ʼ��һ���ڵ�
Node* CreateNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node*));
    if(newNode){
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}
//β������ڵ�
void InsertEnd(Node** head,int data){
    Node* newNode = CreateNode(data);
    if(*head == NULL){
        *head = newNode;
    }else{
        Node* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}
//β��ɾ��
void DeleteEnd(Node** list){
    Node* cur = *list;
    Node* prev = NULL;
    if(cur->next == NULL){
        free(cur);
        *list = NULL;
    }else{
        while (cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
        }
        free(cur);
        prev->next = NULL;   
    }
 
}
//����ͷ������
void InsertFront(Node** list,int data){
    Node* newNode = CreateNode(data);
    if((*list) == NULL){
        newNode = *list;
    }else{
        newNode->next = *list;
        *list = newNode;
    }
}
//����ͷ��ɾ��
void DeleteFront(Node** list){
    Node* cur = *list;
    if(cur->next == NULL){
        free(cur);
        *list = NULL;
    }else{
        cur = cur->next;
        free(*list);
        *list = cur;
    }
}
//������Ĳ���
bool Find(Node* list,int data){
    while(list != NULL){
        if(list->data == data) return true;
        list = list->next;
    }
    return false;
}
//��posλ�ò�������
void InsertAfter(Node* pos,int data){
    Node* newNode = CreateNode(data);
    newNode->next = pos->next;
    pos->next = newNode;
}
//��posλ��֮������ݵ�ɾ��
void DeleteAfter(Node* pos){
    if(pos->next == NULL){
        printf("����û������\n");
        return;
    }else{
        Node* prev = pos;
        Node* cur = pos->next;
        prev->next = cur->next;
        free(cur);
        cur = NULL;
    }
}
// ����������ӡ�ڵ�����
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main(void){
    Node* head = NULL;
    InsertEnd(&head,5);
    InsertEnd(&head,6);
    //DeleteEnd(&head);
    InsertFront(&head,2);
    DeleteFront(&head);
    InsertAfter(head,9);
    DeleteAfter(head);
    printList(head);
    // bool n = Find(head,7);
    // printf("%d",n);
}