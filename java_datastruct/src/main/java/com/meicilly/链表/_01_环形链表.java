package com.meicilly.链表;

public class _01_环形链表 {
    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) {
            val = x;
        }
    }
    public boolean hasCycle(ListNode head){
        if(head == null || head.next == null) return  false;
        ListNode slow = head.next;
        ListNode fast = head.next.next;
        while (slow != fast){
            if(fast == null || fast.next == null) return false;
            slow = slow.next;
            fast = fast.next.next;
        }
        return true;
    }
}
