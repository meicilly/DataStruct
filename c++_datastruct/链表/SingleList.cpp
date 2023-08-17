#include <iostream>

class LinkList{
private:
    class Node{
        public:
            int data;
            Node* next;
    };
    Node* head;
    int length = 0;
public:
    LinkList();
    void create(int n);//初始化n个结点的单链表
};

LinkList::LinkList(){
    head = new Node;
    head->data = 0;
    head->next = nullptr;
}   
void LinkList::create(int n){

}