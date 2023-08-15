
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
    printList(head);
}