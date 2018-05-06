//
//  main.c
//  CommonAlgorithm
//
//  Created by Jia Wang on 2018/1/6.
//  Copyright © 2018年 Jia Wang. All rights reserved.
//

#include <stdio.h>
#include "config.h"

int test_main(int argc, const char * argv[]) {
    // insert code here...
    char P[] = "ababaca";
    int next[7] = {0,};
    computePrefix(P, next);
    return 0;
}

