package com.meicilly.链表;

public class _02_反转链表 {
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    /**
     *使用递归的方法
     * @param head
     * @return
     */
    public ListNode reverseList1(ListNode head){
        return recur(head,null);
    }

    /**
     * 1 -> 2 -> 3 -> 4 -> 5 -> null
     * recur(cur,pre)
     * recur(1,null)                 1 -> null
     * recur(2,1)                    2 -> 1
     * recur(3,2)                    3 -> 2
     * recur(4,3)                    4 -> 3
     * recur(5,4)                    5 -> 4
     * recur(null,5) -> 返回值         pre = 5
     * @param cur
     * @param pre
     * @return
     */
    private ListNode recur(ListNode cur, ListNode pre){
        if(cur == null) return pre;
        ListNode res = recur(cur.next, cur);  // 递归后继节点
        cur.next = pre;              // 修改节点引用指向
        return res;                  // 返回反转链表的头节点
    }

    /**
     * 使用迭代的方法
     * 1   ->   2   ->  3   ->   4   ->   5   ->   null
     * ^                                             ^
     * cur                                          pre  初始化pre cur 分别指向null和头节点
     *
     *
     * 1     2   ->  3   ->   4   ->   5   ->   null
     * ^     ^                                    ^
     * cur   tmp                                 pre
     * tmp = cur.next 暂存后继结点
     * cur.next = pre 修改引用指向
     *
     * 1        2   ->  3   ->   4   ->   5   ->   null
     * ^        ^
     * pre     cur tmp
     * pre = cur 暂存当前节点
     * cur = tmp 访问下一节点
     *
     * 1    <-    2     3   ->   4   ->   5   ->   null
     * ^          ^     ^
     * pre       cur    tmp
     * tmp = cur.next 暂存后继结点
     * cur.next = pre 修改引用指向
     *
     * 1    <-    2     3   ->   4   ->   5   ->   null
     *            ^     ^
     *            pre  cur,tmp
     *  pre = cur 暂存当前节点
     *  cur = tmp 访问下一节点
     * @param head
     * @return
     */
    public ListNode reverseList2(ListNode head){
        ListNode cur = head,pre = null;
        while (cur != null){
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
}
