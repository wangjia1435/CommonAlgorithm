//
//  queue.h
//  CommonAlgorithm
//
//  Created by Jia Wang on 2018/4/6.
//  Copyright © 2018年 Jia Wang. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include <stdlib.h>
#include "../config.h"

extern QUEUE* InitQueue(int size);
extern int inQueue(QUEUE *q, int v);
extern int outQueue(QUEUE *q);
extern int printQueue(QUEUE *q);
#endif /* queue_h */
