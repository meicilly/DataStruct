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
    void create(int n);//��ʼ��n�����ĵ�����
};

LinkList::LinkList(){
    head = new Node;
    head->data = 0;
    head->next = nullptr;
}   
void LinkList::create(int n){

}