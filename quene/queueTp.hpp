//
//  queueTp.hpp
//  common_algorithm
//
//  Created by Jia Wang on 2018/11/4.
//  Copyright © 2018 Jia Wang. All rights reserved.
//

#ifndef queueTp_hpp
#define queueTp_hpp

#include <stdio.h>
/*
 功能：支持基础类型队列入队、出队
 运用CPP特性：
 1 模版
 2 析构、构造,构造函数在类中初始化
 3 嵌入类
 */
template <class Item>
class  queueTP
{
    enum {QSIZE=10};
    class Node
    {
        Item item;
        Node *next;
        Node(const Item &a):item(a),next(nullptr){}
    };
    Node *front;
    Node *rear;
private:
    int queue_size;
public:
    queueTP(int qs=0);
    ~queueTP();
    bool is_queue_empty(queueTP & q);
    bool is_queue_full(queueTP & q);
    bool in_queue(Item & item);
    bool out_queue(Item & item);
};
#endif /* queueTp_hpp */

