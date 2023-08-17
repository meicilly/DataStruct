#include <stdio.h>
#include <stdbool.h>

struct ListNode{
    int val;
    struct ListNode* next;
};
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head -> next == NULL)
        return false;
    struct  ListNode* slow = head->next;
    struct  ListNode* fast = head->next->next;
    //快慢指针的思想
    while (fast != slow){
        if(fast == NULL || fast->next == NULL)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}