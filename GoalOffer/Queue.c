//
//  Queue.c
//  GoalOffer
//
//  Created by little nie on 16/6/20.
//  Copyright © 2016年 NIEHAILI. All rights reserved.
//

#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>



#pragma mark ------------静态方法---------------
static int succ(int value, Queue queue){
    if (++value == queue -> capacity) {
        value = 0;
    }
    return value;
}


#pragma mark ------------非静态方法----------------
Queue createQueue(int maxElements)
{
    Queue queue = (Queue)malloc(sizeof(struct Queue));
    //if (queue == NULL) {
    //}
    
    queue -> array = malloc(sizeof(struct Queue) * maxElements);
    queue -> capacity = maxElements;
    makeEmpty(queue);
    return queue;
}
void disposeQueue(Queue queue){
    if (queue != NULL) {
        free(queue -> array);
        free(queue);
    }
}

int isFull(Queue queue){
    return queue -> size == queue -> capacity;
}
int isEmpty(Queue queue){
    return queue -> size == 0;
}
void makeEmpty(Queue queue){
    queue -> size = 0;
    queue -> front = 0;
    queue -> rear = 0;
    
    for (int i = 0; i<queue -> capacity; i++) {
        queue->array[i] = 0;
    }
    
}

void enqueue(ElementType x, Queue queue){
    if (isFull(queue)) {
        printf("Full queue");
    }
    else{
        queue -> size ++;
        queue -> rear = succ(queue -> rear, queue);
        queue -> array[queue -> size - 1] = x;
    }
}

void dequeue(Queue queue){
    if (isEmpty(queue)) {
        printf("Empty queue");
    }
    else{
        queue -> size--;
        queue -> front = succ(queue -> front, queue);
    }
}

ElementType frontAndDequeue(Queue queue){
    ElementType x = queue -> array[queue -> front];
    dequeue(queue);
    return x;
}

