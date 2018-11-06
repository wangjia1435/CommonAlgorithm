//
//  simple_factory.hpp
//  common_algorithm
//
//  Created by Jia Wang on 2018/11/6.
//  Copyright © 2018 Jia Wang. All rights reserved.
//

#ifndef simple_factory_hpp
#define simple_factory_hpp

#include <stdio.h>
#include <iostream>
/*
 简单工程模式
 苹果类
 桃子类
 工厂类
 在工厂类中提供方法，通过参数来实例具体的类
 */
class fruit{
public:
    fruit(void);
    ~fruit(void);
    //virtual void method(void) const=0;
};

class apple:public fruit {
public:
    apple(void);
    ~apple(void);
    //inline void method(void){std::cout<<"i am apple"<<std::endl;}
};

class pear:public fruit{
public:
    pear(void);
    ~pear(void);
    //inline void method(void){std::cout<<"i am pear"<<std::endl;}
};

class fruit_factory{
public:
    fruit_factory(void);
    ~fruit_factory(void);
    fruit* get_instance(int type);
};


#endif /* simple_factory_hpp */

