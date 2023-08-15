
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int SLDataType;
typedef struct Node{
    SLDataType data;
    struct Node* next;
}Node;

//初始化一个节点
Node* CreateNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node*));
    if(newNode){
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}
//尾部插入节点
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
// 遍历链表并打印节点数据
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