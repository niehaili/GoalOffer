

//
//  LinkedList.c
//  GoalOffer
//
//  Created by little nie on 16/6/16.
//  Copyright © 2016年 NIEHAILI. All rights reserved.
//

#include "LinkedList.h"

void addToTail(ListNode **pHead, int value){
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode -> value = value;
    newNode -> next = NULL;
    if (*pHead == NULL) {
        *pHead = newNode;
    }
    else{
        ListNode *pNode = *pHead;
        while (pNode -> next != NULL) {
            pNode = pNode -> next;
        }
        pNode -> next = newNode;
    }
}

void printListReversingly_Iteratively(ListNode *pHead){
    if (pHead != NULL) {
        if (pHead -> next != NULL) {
            printListReversingly_Iteratively(pHead -> next);
        }
        printf("%d\t",pHead -> value);
    }
}