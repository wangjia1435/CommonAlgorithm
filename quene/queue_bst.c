//
//  queue_bst.c
//  CommonAlgorithm
//
//  Created by Jia Wang on 2018/4/6.
//  Copyright © 2018年 Jia Wang. All rights reserved.
//

//创建存放二叉树节点队列
#include "queue.h"
//循环队列初始条件：rear = front = 0
//队列满条件：Mod（rear+1,m) = front
//队列空条件：rear = front
//队列进: front = Mod(front+1,m)
//队列出：rear =  Mod(rear+1,m)

//单#号是将后面的宏参数进行字符串操作，后面参数双引号引起来
//双#号用于连接


QUEUE_BST* InitQueue_BST(int size)
{
    QUEUE_BST* q = NULL;
    
    q = (QUEUE_BST*)malloc(sizeof(QUEUE_BST));
    q->ele = (BST**)malloc(size*sizeof(&q));
    memset(q->ele, 0, size*sizeof(&q));
    q->front = 0;
    q->rear = 0;
    q->max = size;
    return q;
}

//最开始0树组下标不存放元素随着元素的更迭，最大空间元素个数
//为size-1
BST* inQueue_BST(QUEUE_BST *q, BST* v)
{
    if((q->rear+1)%(q->max)==q->front)
    {
        printf("queue full\n ");
        return NULL;
    }
    else
    {
        //memcpy(&(q->ele[q->rear+1]), v, sizeof(BST));
        q->ele[q->rear+1] = v;
        q->rear = q->rear + 1;
        return v;
    }
}

BST* outQueue_BST(QUEUE_BST *q)
{
    BST* out = NULL;
    if(q->front == q->rear)
    {
        printf("queue empty\n ");
        return NULL;
    }
    else
    {
        out = (q->ele[q->front+1]);
        q->ele[q->front+1]= NULL;
        q->front = q->front + 1;
        return out;
    }
}

int printQueue_BST(QUEUE_BST *q)
{
    int i = 0;
    if(NULL == q) return -1;
    if(q->front == q->rear) {printf("no element\n"); return -1;}
    while(q->front+i != q->rear)
    {
        i++;
        printf("%d ",(q->ele[q->front + i])->v);
    }
    printf("\n");
    return 1;
}

int queue_bst_main(void)
{
    QUEUE_BST* queue = NULL;
    BST* head       = NULL;
    BST* t1         = NULL;
    BST* t2         = NULL;
    BST* t3         = NULL;
    BST* t4         = NULL;
    BST* t5         = NULL;
    BST* t6         = NULL;
    BST* t7         = NULL;
    BST* t8         = NULL;
    BST* inqueue    = NULL;
    BST* outqueue    = NULL;
    int rt          = 0;
    queue = InitQueue_BST(8);
    
    //创建节点
    head = createBST(12);
    t1 = createBSTNode(5);
    t2 = createBSTNode(18);
    t3 = createBSTNode(2);
    t4 = createBSTNode(9);
    t5 = createBSTNode(15);
    t6 = createBSTNode(19);
    t7 = createBSTNode(17);
    t8 = createBSTNode(16);
    //插入节点测试
    head = insertBST(head, t1);
    head = insertBST(head, t2);
    head = insertBST(head, t3);
    head = insertBST(head, t4);
    head = insertBST(head, t5);
    head = insertBST(head, t6);
    head = insertBST(head, t7);
    head = insertBST(head, t8);
    
    //节点添加到队列测试
    inqueue = inQueue_BST(queue, head);
    inqueue = inQueue_BST(queue, t1);
    inqueue = inQueue_BST(queue, t2);
    inqueue = inQueue_BST(queue, t3);
    inqueue = inQueue_BST(queue, t4);
    inqueue = inQueue_BST(queue, t5);
    inqueue = inQueue_BST(queue, t6);
    inqueue = inQueue_BST(queue, t7);
    inqueue = inQueue_BST(queue, t8);
    rt = printQueue_BST(queue);
    outqueue = outQueue_BST(queue);
    outqueue = outQueue_BST(queue);
    outqueue = outQueue_BST(queue);
    outqueue = outQueue_BST(queue);
    rt = printQueue_BST(queue);
    outqueue = outQueue_BST(queue);
    outqueue = outQueue_BST(queue);
    outqueue = outQueue_BST(queue);
    outqueue = outQueue_BST(queue);
    outqueue = outQueue_BST(queue);
    rt = printQueue_BST(queue);
    return 1;
}

