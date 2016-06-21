//
//  main.m
//  GoalOffer
//
//  Created by little nie on 16/6/16.
//  Copyright © 2016年 NIEHAILI. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <stdlib.h>
#import "LinkedList.h"
#import "BinaryTreeNode.h"

BOOL find(int *matrix, int rows, int columns, int number);
void replaceBlank(char string[], int length);

int main(int argc, const char * argv[]) {
    ///*
     //在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数
     //*/
    //int matrix[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    //printf("1、found = %d\n",find(matrix, 3, 4, 9));
    
    ///*
     //请实现一个函数，把字符串的每个空格替换成"%20",例如输入"we are happy.",则输出"we%20are%20happy."
     //*/
    //char string[50] = "we are family";
    //replaceBlank(string, 50);
    //printf("2、string = %s\n",string);

    
    //ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    //node -> value = 1;
    //node -> next = NULL;
    //ListNode **listNode = &node;
    //for (int i = 0 ; i < 10 ; i++) {
        //addToTail(listNode, i);
    //}
    //printf("listnode = %p\n",listNode);
    
    
    //
    int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode root = reBuildBinaryTreeNode(preorder, inorder, 8);
    printTree(root, 1);
    return 0;
}

/**
 *  从一个左右、上下递增的二维数组中，查找指定数值，返回查找结果
 *
 *  @param matrix  int数组
 *  @param rows    对应二维数组的行数
 *  @param columns 对应二维数组的列数
 *  @param number  要查找的数字
 *
 *  @return 是否找到对应数值
 */
BOOL find(int *matrix, int rows, int columns, int number){
    BOOL found = NO;
    if (matrix != NULL && rows > 0 && columns > 0) {
        int row = 0;
        int column = columns - 1;
        while (row < rows && column >= 0) {
            if (matrix[row * columns + column] == number) {
                found = YES;
                break;
            }
            else if(matrix[row * columns + column] > number){
                column--;
            }
            else{
                row++;
            }
        }
    }
    return found;
}

/**
 *  返回替换后的字符数组
 *
 *  @param string 原字符数组
 *  @param length 原字符数组的总长度
 */
void replaceBlank(char string[], int length){
    if (string == NULL || length <= 0) {
        return;
    }
    
    int originLength = 0;
    int blankNumber = 0;
    int index = 0;
    while (string[index++] != '\0') {
        if (string[originLength] == ' ') {
            blankNumber++;
        }
        originLength++;
    }
    
    int newLength = originLength + 2 * blankNumber;
    if (newLength > length) {
        return;
    }
    int originIndex = originLength;
    int newIndex = newLength;
    while (originIndex >= 0 && newIndex >= 0) {
        if (string[originIndex] == ' ') {
            string[newIndex--] = '0';
            string[newIndex--] = '2';
            string[newIndex--] = '%';
        }
        else{
            string[newIndex--] = string[originIndex];
        }
        originIndex--;
    }
}
