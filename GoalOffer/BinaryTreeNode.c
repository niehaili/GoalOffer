
//
//  BinaryTreeNode.c
//  GoalOffer
//
//  Created by little nie on 16/6/17.
//  Copyright © 2016年 NIEHAILI. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BinaryTreeNode.h"
#include "Queue.h"


struct BinaryTreeNode{
    int value;
    BinaryTreeNode left;
    BinaryTreeNode right;
};


BinaryTreeNode reBuildBinaryTreeNode(int *preorder, int *inorder, int length){
    if (preorder == NULL || inorder == NULL || length <= 0) {
        return NULL;
    }
    return construct(preorder, 0, length, inorder, 0, length);
}

BinaryTreeNode construct(int *preorder, int pre_begin, int pre_end, int *inorder, int in_begin, int in_end){
    // 开始位置大于结束位置说明已经没有处理的元素了
    if (pre_begin > pre_end) {
        return NULL;
    }
    
    // 在中序遍历中查找根节点的位置
    int index = in_begin;
    int value = preorder[pre_begin];
    while (index <= in_end && inorder[index] != value) {
        index++;
    }
    if (index > in_end) {
        // 抛出异常
        printf("Invalid input");
        return NULL;
    }
    
    // 取前序遍历的第一个数字，就是当前的根节点
    BinaryTreeNode node = malloc(sizeof(struct BinaryTreeNode));
    node -> value = value;

    // 递归构建当前根结点的左子树，左子树的元素个数：index-is+1个
    // 左子树对应的前序遍历的位置在[ps+1, ps+index-is]
    // 左子树对应的中序遍历的位置在[is, index-1]
    node -> left = construct(preorder, pre_begin + 1, pre_begin + index - in_begin, inorder, in_begin, index - 1);
    // 递归构建当前根结点的右子树，右子树的元素个数：ie-index个
    // 右子树对应的前序遍历的位置在[ps+index-is+1, pe]
    // 右子树对应的中序遍历的位置在[index+1, ie]
    node -> right = construct(preorder, pre_begin + index - in_begin + 1, pre_end, inorder, index + 1, in_end);
    
    return node;
}

int treeDeep(BinaryTreeNode root){
    if (root == NULL) {
        return 0;
    }
    else{
        return fmaxf(treeDeep(root -> left) + 1, treeDeep(root -> right) + 1);
    }
}

BinaryTreeNode getEmptyNode(){
    BinaryTreeNode emptyNode = malloc(sizeof(struct BinaryTreeNode));
    emptyNode -> value = 0;
    emptyNode -> left = NULL;
    emptyNode -> right = NULL;
    return emptyNode;
}

#pragma mark---------private method
void nodeEnqueue(BinaryTreeNode node, Queue queue,BinaryTreeNode emptyNode){
    if (node) {
        enqueue(node, queue);
    }
    else{
        enqueue(emptyNode, queue);
    }
}
void printBlackSpace(int number){
    while (number-- >= 0) {
        printf(" ");
    }
}

// 树形打印二叉树
void printTree(BinaryTreeNode root, int layer){
    printf("\n");
    if (root == NULL) {
        return;
    }
    int deep = treeDeep(root);
    Queue queue = createQueue(1);
    enqueue(root, queue);
    
    BinaryTreeNode emptyNode = getEmptyNode();
    Queue nextQueue = NULL;
    int index = 1;
    while (!isEmpty(queue)) {
        int currentQueueCapacity = (int)pow(2, index - 1);
        int nextQueueCapacity = 2 * currentQueueCapacity;
        if (queue -> size == currentQueueCapacity) {
            nextQueue = createQueue(nextQueueCapacity);
        }
        BinaryTreeNode currentNode = frontAndDequeue(queue);
        nodeEnqueue(currentNode -> left, nextQueue, emptyNode);
        nodeEnqueue(currentNode -> right, nextQueue, emptyNode);
        
        // 计算应打印的空格数
        if (currentNode -> value == 0) {
            printf(" ");
        }
        else{
            printf("%d",currentNode -> value);
        }

        if (queue -> size == 0 && index != deep) {
            free(queue);
            queue = nextQueue;
            printf("\n");
            index++;
        }
        else{
            continue;
        }
    }
    
    free(emptyNode);
    free(queue);
}

