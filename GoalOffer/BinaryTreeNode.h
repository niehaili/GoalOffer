//
//  BinaryTreeNode.h
//  GoalOffer
//
//  Created by little nie on 16/6/17.
//  Copyright © 2016年 NIEHAILI. All rights reserved.
//


struct BinaryTreeNode;
typedef struct BinaryTreeNode *BinaryTreeNode;

BinaryTreeNode reBuildBinaryTreeNode(int *preorder, int *inorder, int length);
BinaryTreeNode construct(int *preorder, int pre_begin, int pre_end, int *inorder, int in_begin, int in_end);

/**
 *  二叉树的深度
 *
 *  @param root 二叉树的根节点
 *
 *  @return 二叉树的深度
 */
int treeDeep(BinaryTreeNode root);

void printTree(BinaryTreeNode root, int layer);

// 创建二叉树

// 先序遍历递归方式

// 先序遍历非递归方式

// 中序遍历递归方式

// 中序遍历非递归方式

// 后序遍历递归方式

// 后序遍历非递归方式

// 叶子节点数

//






