//
//  main.c
//  CommonAlgorithm
//
//  Created by Jia Wang on 2018/1/6.
//  Copyright © 2018年 Jia Wang. All rights reserved.
//

#include <stdio.h>
#include "config.h"
#include <sys/types.h>
#include <unistd.h>
#include "./design_mode/simple_factory.hpp"

int gloab=6;


int main(int argc, const char * argv[]) {
    // insert code here...
    fruit_factory a;
    fruit* b=a.get_instance(1);
    fruit* c=a.get_instance(2);
    
    //fruit* b=a.get_instance(1);
    char P[] = "ababaca";
    int next[7] = {0,};
    //computePrefix(P, next);
    printf("hello world\n");
    printf("pid=%d\n",getpid());
    printf("before fork \n");
    
    pid_t pid;
    int var=88;
    if((pid = fork())<0)
    {
        printf("fork error\n");
    }
    else if(pid==0)
    {
        gloab++;
        var++;
    }
    else
    {
        sleep(2);
    }
    
    if(pid==0)
    {
        printf("this is child\n");
        printf("pid=%d gloab=%d var=%d\n",getpid(), gloab, var);
    }
    else
    {
                printf("pid=%d gloab=%d var=%d\n",getpid(), gloab, var);
    }

    exit(0);
    
    return 0;
}
