//
//  LinkedList.h
//  GoalOffer
//
//  Created by little nie on 16/6/16.
//  Copyright © 2016年 NIEHAILI. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int value;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

/**
 *  在链表最后添加结点
 *
 *  @param pHead 链表头结点
 *  @param value 新结点的值
 */
void addToTail(ListNode **pHead, int value);

/**
 *  逆向打印链表(当链表很长时，可能出现调用栈溢出)
 *
 *  @param pHead 链表
 */
void printListReversingly_Iteratively(ListNode *pHead);

