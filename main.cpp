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
#include "design_mode/builder/director.h"
#include "design_mode/builder/builder.h"
#include "design_mode/simple_factory/simple_factory.hpp"
#include "design_mode/adpter/adpter_test.h"
#include "design_mode/bridge/bridge_test.h"
#include "design_mode/decorator/decorator_test.h"
int gloab=6; 


int main(int argc, const char * argv[]) {
	decorator_test();
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


