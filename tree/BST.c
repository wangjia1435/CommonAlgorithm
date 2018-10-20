//
//  BST.c
//  CommonAlgorithm
//
//  Created by Jia Wang on 2018/4/2.
//  Copyright © 2018年 Jia Wang. All rights reserved.
//

/*
1 二叉搜索树的 左子树存在，那么左子树值小于根节点；右子树存在，那么右子树值大于根节点
2 节点值都不相等
主要介绍二叉搜索树的 建立、添加元素、删除元素
 */
#include "../config.h"

//创建根节点
BST* createBST(int v)
{
    BST* head =NULL;
    head = (BST*)malloc(sizeof(BST));
    head->left   = NULL;
    head->right  = NULL;
    head->v     = v;
    return head;
}

//开辟一个节点空间
BST* createBSTNode(int s)
{
    BST* head =NULL;
    head = (BST*)malloc(sizeof(BST));
    head->left   = NULL;
    head->right  = NULL;
    head->v     = s;
    return head;
}

void BSTfree(BST* p)
{
    memset(p,0,sizeof(BST));
    free(p);
    p = NULL;
}

//往二叉搜索树中插入节点
BST* insertBST(BST* head, BST* q)
{
    BST* p = head;
    while(p != NULL)
    {
        if(p->v > q->v)
        {
            if(p->left == NULL)
            {
                p->left = q;
                break;
            }
            else
            {
                p = p->left;
            }
        }
        else
        {
            if(p->right == NULL)
            {
                p->right = q;
                break;
            }
            else
            {
                p = p->right;
            }
        }
    }
    return head;
}

//根据给定数组创建二叉搜索树
BST* createBSTList(int *l, int len)
{
    int     i = 0;
    BST* head = NULL;
    BST* p    = NULL;
    for(i = 0; i < len; i++)
    {
        if(i==0)
        {
            head = createBST(l[i]);
        }
        else
        {
            p = createBSTNode(l[i]);
            head =insertBST(head, p);
        }
    }
    return head;
}

//删除二叉搜索树节点
//return 1; delete correct
//return 0; delete success
int deleteBSTnode(BST* head, int v)
{
    BST*  p   = head;
    BST*  f = head;
    while(p!=NULL)
    {
        if(p->v > v)
        {
            f = p;
            p = p->left;
        }
        else if(p->v < v)
        {
            f = p;
            p = p->right;
        }
        else
        {
            //这里需要分几种情况
            //1 删除的节点左子树、右子树为NULL；那么直接将指向该节点的父节点方向指向NULL
            //2 删除的节点左子树或则会右子树不为NULL；那么将该节点的父节点指向不为NULL的节点
            //3 删除的节点左右子树都不为NULL。那么将该节点的父节点指向右子树，右子树再指向左子树
            if(p->left == NULL && p->right == NULL)
            {
                BSTfree(p);
                return 1;
            }
            if(p->left != NULL && p->right != NULL)
            {
                f->right = p->right;
                f->right->left = p->left;
                BSTfree(p);
                return 1;
            }
            else
            {
                //删除节点的左子树不为NULL
                if(f->left == p && p->left != NULL)
                {
                    f->left = p->left;
                }
                else if(f->left == p && p->right != NULL)
                {
                    f->left = p->right;
                }
                else if(f->right == p && p->left != NULL)//删除节点的右子树不为NULL
                {
                    f->right= p->left;
                }
                else if(f->right == p && p->right != NULL)
                {
                    f->right= p->left;
                }
                else
                {
                    return 0;
                }
                BSTfree(p);
                return 1;
            }
        }
    }
    return 0;
}

//创建存放二叉树节点队列,利用队列来根据层级打印二叉树各个节点值
//
//

static int queuesize = 100;
void printBST(BST* head)
{
    QUEUE_BST*  queue = NULL;
    BST*    b = NULL;
    BST*    inBST = NULL;
    BST*    outBST = NULL;
    int     last = -1;
    int     nlast = -1;
    if(NULL == head) return;
    
    queue = InitQueue_BST(queuesize);
    last = nlast = head->v;
    inBST = inQueue_BST(queue, head);
    do
    {
        outBST = outQueue_BST(queue);

        if(NULL==outBST)//循环退出条件，没有元素了
        {
            break;
        }
        
        if(NULL != outBST->left)//弹出元素的左子树入队列
        {
            //更新nlast
            inBST = inQueue_BST(queue, outBST->left);
            nlast = inBST->v;
        }
        
        if(NULL != outBST->right)//弹出元素的右子树入队列
        {
            //更新nlast
            inBST = inQueue_BST(queue, outBST->right);
            nlast = inBST->v;
        }
        
        if(outBST->v == last)//发现弹出来的值是每行最后一个元素
        {
            printf("%d\n",outBST->v);
            last = nlast;//关键步骤，更行下一层最后一个元素标志
        }//不是最后一个
        else
        {
            printf("%d  ",outBST->v);
        }
    }while(1);
}

void BST_main(void)
{
    BST* head = NULL;
    BST* t1   = NULL;
    BST* t2   = NULL;
    BST* t3   = NULL;
    BST* t4   = NULL;
    BST* t5   = NULL;
    BST* t6   = NULL;
    BST* t7   = NULL;
    BST* t8   = NULL;
    int rt    = 0;
    int l[9] = {12, 5, 18, 2, 9, 15, 19, 17, 16};
    
    //指针数组
    BST s1,s2,s3,s4;
    BST *p[4]={&s1,&s2,&s3,&s4};
    
    printf("0x%p, 0x%p, 0x%p, 0x%p\n",p[0],p[1],p[2],p[3]);
    
    printf("0x%p, %d\n",&rt,(int)sizeof(&rt));
    //创建节点测试
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
    
    //创建list二叉搜索树
    head = createBSTList(l, 9);
    
    //打印二叉搜索树
    printBST(head);
    
    //删除二叉搜索树节点
    rt = deleteBSTnode(head, 18); //删除节点的左右子树都不为空
    //打印二叉搜索树
    printBST(head);
    
    //创建list二叉搜索树
    head = createBSTList(l, 9);
    rt = deleteBSTnode(head, 15); //删除节点的右子树为空
}

