package com.meicilly.链表;

public class Main {
    public static void main(String[] args) {
//        SingleLinkedList<Integer> list = new SingleLinkedList<>();
//        //测试add方法添加元素到尾部
//        list.add(1);
//        list.add(2);
//        list.add(3);
//        //测试add方法添加元素到对应的index
//        list.add(0,5);
//        list.add(1,4);
//        list.remove(0);
//        System.out.println(list.contains(7));
//        System.out.println(list);

        SingleCircleLinkedList<Object> singleCircleLinkedList = new SingleCircleLinkedList<>();
        singleCircleLinkedList.add(1);
        singleCircleLinkedList.add(2);
        singleCircleLinkedList.add(3);
        singleCircleLinkedList.add(5);
        singleCircleLinkedList.remove(2);
        System.out.println(singleCircleLinkedList);
    }
}
