//
//  randomizedSelect.c
//  CommonAlgorithm
//
//  Created by Jia Wang on 2018/3/25.
//  Copyright © 2018年 Jia Wang. All rights reserved.
//  顺序统计学和求中位数
//  例如求n个元素中底i个小的元素

#include <stdio.h>
//以快速排序的分治法为前提
//第一步分治，以最后一个元素A作为基准，将list分为两部分
//第一部分都小于等于A
//第二部分都大于等于A
int randomized_partion(int* list, int startIndex, int endIndex)
{
    if(list == NULL)    return -1;
    int i = startIndex;
    int j = endIndex;
    int standard = list[endIndex];
    int replace;
    while( i < j )
    {
        while(list[i] <=standard && i < j)
        {
            i++;
        }
        //注意这个是大于等于，首先跟standard跟自己比通过
        while(list[j] >=standard && i < j)
        {
            j--;
        }
        
        if(i < j)
        {
            replace = list[i];
            list[i] = list[j];
            list[j] = replace;
        }
    }
    //找到的第i个元素左边肯定都小于等于standard。右边都大于等于standrand。将standrand插入中间
    list[endIndex] = list[i];
    list[i] = standard;
    for(i=startIndex; i<endIndex; i++)
    {
        printf("%d ",list[i]);
    }
    printf("\n");
    return i;
}

//求数组list第q-r的元素中第i小的元素
int randomized_select(int *list, int q, int r, int i)
{
    int k;
    if(q > r && i > r) return -1;
    //返回最后基准元素下标
    k = randomized_partion(list, q, r);
    //第i小元素下标i-1
    if (k+1 == i)
    {
        return list[i-1];
    }
    else if(k+1 > i)
    {
        return randomized_select(list, q, k-1, i);
    }
    else
    {
        return randomized_select(list, k+1, r, i-k+1);
    }
}

void randomizedSelect_test(int *list, int start, int end, int selectsize)
{
    printf("selectnumber is %d \n",randomized_select(list, start, end, selectsize));
}

void randomized_test_main(void)
{
    int list_1[10] = {10,9,8,7,6,5,4,3,2,1};
    int list_2[10] = {10,9,8,7,6,5,4,3,2,1};
    int list_3[10] = {1,1,1,2,2,2,4,4,4,4};
    int list_4[10] = {2,2,1,1,1,2,4,4,4,4};
    
    randomizedSelect_test(list_1, 0, 9, 4);
    randomizedSelect_test(list_2, 0, 5, 5);
    randomizedSelect_test(list_3, 0, 5, 5);
    randomizedSelect_test(list_4, 0, 5, 3);
}

