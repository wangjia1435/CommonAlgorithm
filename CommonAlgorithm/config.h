//
//  config.h
//  CommonAlgorithm
//
//  Created by Jia Wang on 2018/1/6.
//  Copyright © 2018年 Jia Wang. All rights reserved.
//

#ifndef config_h
#define config_h

#include "stdio.h"
#include "string.h"
#include <stdlib.h>


typedef struct bst
{
    int v;
    struct bst* left;
    struct bst* right;
}BST;


typedef struct queue
{
    int* ele;
    int front;
    int rear;
    int max;
}QUEUE;

typedef struct queue_bst
{
    BST** ele;
    int front;
    int rear;
    int max;
}QUEUE_BST;

extern void computePrefix(const char p[], int next[]);

//根据给定数组创建二叉搜索树
extern BST* createBSTList(int *l, int len);
//创建根节点
extern BST* createBST(int v);
//开辟一个节点空间
extern BST* createBSTNode(int s);
//往二叉搜索树中插入节点
extern BST* insertBST(BST* head, BST* q);

//初始化二叉树队列
extern QUEUE_BST* InitQueue_BST(int size);
//二叉树节点队列添加元素
extern BST* inQueue_BST(QUEUE_BST *q, BST* v);
//二叉树节点队列弹出元素
extern BST* outQueue_BST(QUEUE_BST *q);
#endif /* config_h */

