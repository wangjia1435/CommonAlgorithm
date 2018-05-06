//
//  quene.c
//  CommonAlgorithm
//
//  Created by Jia Wang on 2018/4/6.
//  Copyright © 2018年 Jia Wang. All rights reserved.
//  循环队列
#include "queue.h"

//循环队列初始条件：rear = front = 0
//队列满条件：Mod（rear+1,m) = front
//队列空条件：rear = front
//队列进: front = Mod(front+1,m)
//队列出：rear =  Mod(rear+1,m)

//单#号是将后面的宏参数进行字符串操作，后面参数双引号引起来
//双#号用于连接


QUEUE* InitQueue_int(int size)
{
    QUEUE* q = NULL;
    
    q = (QUEUE*)malloc(sizeof(QUEUE));
    q->ele = (int*)malloc(size*sizeof(int));
    memset(q->ele,0,size);
    q->front = 0;
    q->rear = 0;
    q->max = size;
    return q;
}

//最开始0树组下标不存放元素随着元素的更迭，最大空间元素个数
//为size-1
int inQueue_int(QUEUE *q, int v)
{
    if((q->rear+1)%(q->max)==q->front)
    {
        printf("queue full\n ");
        return -1;
    }
    else
    {
        q->ele[q->rear+1] = v;
        q->rear = q->rear + 1;
        return v;
    }
}

int outQueue_int(QUEUE *q)
{
    int out;
    if(q->front == q->rear)
    {
        printf("queue empty\n ");
        return -1;
    }
    else
    {
        out = q->ele[q->front+1];
        q->ele[q->front+1] = -1;
        q->front = q->front + 1;
        return out;
    }
}

int printQueue_int(QUEUE *q)
{
    int i = 0;
    if(NULL == q) return -1;
    
    while(q->front+i != q->rear)
    {
        i++;
        printf("%d ",q->ele[q->front + i]);
    }
    printf("\n");
    return 1;
}

void queue_int_main(void)
{
    QUEUE * queue = NULL;
    queue = InitQueue_int(6);
    inQueue_int(queue, 1);
    inQueue_int(queue, 2);
    inQueue_int(queue, 3);
    inQueue_int(queue, 4);
    inQueue_int(queue, 5);
    printQueue_int(queue);
    
    outQueue_int(queue);
    printQueue_int(queue);
    
    inQueue_int(queue, 6);
    printQueue_int(queue);

    outQueue_int(queue);
    outQueue_int(queue);
    outQueue_int(queue);
    outQueue_int(queue);
    printQueue_int(queue);

    outQueue_int(queue);
    outQueue_int(queue);
    printQueue_int(queue);
}
