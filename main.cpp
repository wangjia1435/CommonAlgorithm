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
#include "design_mode/facade/facade_test.h"
#include "design_mode/flyweight/flyweight_test.h"
#include "design_mode/proxy/proxy_test.h"
#include "design_mode/command/command_test.h"
#include "os/fork/fork.h"


int main(int argc, const char * argv[]) {
	command_test();
    return 0;
}


