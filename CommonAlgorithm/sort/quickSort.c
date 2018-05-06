//
//  quickSort.c
//  CommonAlgorithm
//
//  Created by Jia Wang on 2018/3/24.
//  Copyright © 2018年 Jia Wang. All rights reserved.
//

#include <stdio.h>


//第一步分治，以最后一个元素A作为基准，将list分为两部分
//第一部分都小于等于A
//第二部分都大于等于A
int partion(int* list, int startIndex, int endIndex)
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

    return i;
}

int quickSort(int *list, int startIndex, int endIndex)
{
    int i = 0;
    if(startIndex < endIndex)
    {
        i = partion(list, startIndex, endIndex);
        quickSort(list,startIndex,i-1);
        quickSort(list,i+1, endIndex);
    }
    return 1;
}

void test_sort(int *l, int len)
{
    int i = 0;
    quickSort(l, 0, len);
    for(i = 0; i< len; i++)
    {
        printf("%d ",l[i]);
    }
    printf("\n");
}

void /*quickSort_mainmain*/tatic(void)
{
    int l_1[10] = {10,9,8,7,6,5,4,3,2,1};
    int l_2[10] = {10,10,8,9,9,5,4,3,2,1};
    int l_3[10] = {1,1,1,3,3,3,3,3,3,2};
    test_sort(l_1,9);
    test_sort(l_2,9);
    test_sort(l_3,9);
}
