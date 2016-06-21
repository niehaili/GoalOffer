//
//  Queue.h
//  GoalOffer
//
//  Created by little nie on 16/6/20.
//  Copyright © 2016年 NIEHAILI. All rights reserved.
//

#include <stdio.h>
#include "BinaryTreeNode.h"

typedef BinaryTreeNode ElementType;
struct Queue{
    int capacity;
    int front;
    int rear;
    int size;
    ElementType *array;
};
typedef struct Queue *Queue;

int isEmpty(Queue queue);
int isFull(Queue queue);
Queue createQueue(int maxElements);
void disposeQueue(Queue queue);
void makeEmpty(Queue queue);
void enqueue(ElementType x,Queue queue);
ElementType front(Queue queue);
void dequeue(Queue queue);
ElementType frontAndDequeue(Queue queue);