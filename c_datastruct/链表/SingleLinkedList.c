
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
//尾部删除
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
//链表头部插入
void InsertFront(Node** list,int data){
    Node* newNode = CreateNode(data);
    if((*list) == NULL){
        newNode = *list;
    }else{
        newNode->next = *list;
        *list = newNode;
    }
}
//链表头部删除
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
//单链表的查找
bool Find(Node* list,int data){
    while(list != NULL){
        if(list->data == data) return true;
        list = list->next;
    }
    return false;
}
//在pos位置插入数据
void InsertAfter(Node* pos,int data){
    Node* newNode = CreateNode(data);
    newNode->next = pos->next;
    pos->next = newNode;
}
//在pos位置之后的数据的删除
void DeleteAfter(Node* pos){
    if(pos->next == NULL){
        printf("后面没有数据\n");
        return;
    }else{
        Node* prev = pos;
        Node* cur = pos->next;
        prev->next = cur->next;
        free(cur);
        cur = NULL;
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
    //DeleteEnd(&head);
    InsertFront(&head,2);
    DeleteFront(&head);
    InsertAfter(head,9);
    DeleteAfter(head);
    printList(head);
    // bool n = Find(head,7);
    // printf("%d",n);
}