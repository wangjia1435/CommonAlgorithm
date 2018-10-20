//
//  KMP.c
//  CommonAlgorithm
//
//  Created by Jia Wang on 2018/1/6.
//  Copyright © 2018年 Jia Wang. All rights reserved.
//

#include "../config.h"
/*计算KMP算法的辅助函数T，用于字符串匹配时进行有效偏移*/
void computePrefix(const char p[], int next[])
{
    int q,k;
    unsigned long m = strlen(p);
    next[0] = 0;
    for(q = 1, k = 0; q < m; ++q)
    {
        while(k > 0 && p[q] != p[k])
            k = next[k-1];
        if(p[q] == p[k])
        {
            k++;
        }
        next[q] = k;
    }

}
