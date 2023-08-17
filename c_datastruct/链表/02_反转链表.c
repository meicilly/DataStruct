#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode* next;
};
struct ListNode* rever(struct ListNode* cur,struct ListNode* pre){
    if(cur == NULL) return pre;
    struct ListNode* res = rever(cur->next,cur);
    cur->next = pre;
    return res;
}
struct ListNode* reverseList1(struct ListNode* head){
    return rever(head,NULL);
}

struct ListNode* reverseList2(struct ListNode* head){
    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    while(cur != NULL){
        struct ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}



