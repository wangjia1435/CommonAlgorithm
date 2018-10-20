//
//  skip_list.c
//  CommonAlgorithm
//
//  Created by Jia Wang on 2018/4/12.
//  Copyright © 2018年 Jia Wang. All rights reserved.
//
/*跳跃表
 作用:
 1 快速查询一个有序连续元素的数据链表，时间复杂度O(logn)  空间复杂度O(n)
 组成:
 1 由很多层组成
 2 每一层都是一个有序链表，排列为高层到低层，至少包含两个链表节点 head。nil
 3 如果某一个元素出现在某层中，那么下一层也会出现，上层元素是下层元素的子集
 4 链表中每个节点包含两个指针，一个指向同一层下一个节点；一个指向下一层同一个节点
 
   -∞->       21->    37->            +∞
   ⬇️         ⬇️      ⬇️             ⬇️
   -∞->7->    21->    37->71->        +∞
   ⬇️  ⬇️     ⬇️      ⬇️  ⬇️        ⬇️
   -∞->7->14->21->32->37->71->85->117->+∞
 
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct skipnode
{
    struct skipnode* next;
    struct skipnode* below;
    int v;
}SKIPNODE;

typedef struct skiplist
{
    struct skipnode** ele;
}SKIPLIST;

//随机层数
int randomLevel(void)
{
    int k = 1;
    while(random()%2)
    {
        k++;
    }
    return k;
}

//创建跳跃表
//1 跳跃表最大层数8层
//2 每层链表head节点值指向的下一个-∞节点，尾节点指向下一个+∞节点
/*
-∞->       21->    37->            +∞
⬇️         ⬇️      ⬇️             ⬇️
-∞->7->    21->    37->71->        +∞
⬇️ ⬇️      ⬇️      ⬇️  ⬇️          ⬇️
-∞->7->14->21->32->37->71->85->117->+∞
 */
SKIPLIST* InitSkipList(int max_level)
{
    int i = 0;
    SKIPLIST* head = NULL;
    //SKIPNODE*  first_node = NULL;
    SKIPNODE*  end_node   = NULL;
    
    head = (SKIPLIST*)malloc(sizeof(&head));
    head->ele = (SKIPNODE**)malloc(sizeof(&head)*max_level);
    for(i = 0; i < max_level; i++)
    {
        head->ele[i]       = malloc(sizeof(SKIPNODE)); //first node 存储-∞； end node 存储+∞
        end_node          = malloc(sizeof(SKIPNODE));
        head->ele[i]->v    = INT_MIN;
        //head->ele[i]->below = NULL;
        head->ele[i]->next = end_node;
        end_node->v       = INT_MAX;
        //end_node->below    = NULL;
        end_node->next     = NULL;
        
        //收尾节点构建
        if(0 == i)
        {
            head->ele[i]->below = NULL;  //第一层节点first元素 below =NULL
            head->ele[i]->next->below    = NULL; //第一层节点end元素 below = NULL
        }
        else
        {
            head->ele[i]->below = head->ele[i-1];
            head->ele[i]->next->below = head->ele[i-1]->next->below;//中间层数的第一个节点与最后一个节点是关联的
        }
    }
    return head;
}

//插入跳跃表

//删除跳跃表

void skip_list_main(void)
{
    int randn = 0;
    int r1    = 0;
    int max   = 0;
    long maxcount = 10000;
    char a[]={0x12,0x34,0x56,0x78};
    short b[]={0x12,0x34,0x56,0x78};
    void* p = NULL;
    
    /*测试直接改变内存地址的值 */
    p = a;
    printf(" %p\n",a+1);
    *(char*)(a) = 1;
    *(char*)(a+1) = 2;
    *(char*)(a+2) = 3;
    *(char*)(a+3) = 4;
    printf("%d,%d,%d,%d\n ",a[0],a[1],a[2],a[3]);
    
    *(short*)(a) = 0x1122;
    *(short*)(a+2)=0x3344;//如果a是void 或者char型，那么a+1 地址只会加1
    *(short*)(b) = 0x1122;
    *(short*)(b+1)=0x3344;//如果a是short 地址会加2
    *(short*)(b+2)=0x5566;//addr + 4 //if (void*)b addr + 2+
    printf("0x%x,0x%x,0x%x,0x%x\n ",a[0],a[1],a[2],a[3]);
    printf("0x%x,0x%x,0x%x,0x%x\n ",b[0],b[1],b[2],b[3]);
    //*(short*)(a+2)=0x3344;
    memcpy((void*)(a+2),(void*)b,2);
    printf("0x%x,0x%x,0x%x,0x%x\n ",a[0],a[1],a[2],a[3]);
    
    
    /* 测试level*/
    for(long i = 0; i < maxcount; i++)
    {
        randn = randomLevel();
        
        //1出现的概率
        if(randn == 1) r1++;
        
        //最大层数
        if(randn>max) max = randn;
        
        printf("%d ",randn);
    }
    printf("\n");
    printf("r1=%d\n",r1);
    printf("\n");
    printf("f1=%f\n",r1/(float)maxcount);
    printf("\n");
    printf("max=%d\n",max);
    
    //创建跳跃表
    SKIPLIST * head = NULL;
    head =  InitSkipList(3);
    
}
