//
//  simple_factory.cpp
//  common_algorithm
//
//  Created by Jia Wang on 2018/11/6.
//  Copyright © 2018 Jia Wang. All rights reserved.
//

#include "simple_factory.hpp"

fruit::fruit(void)
{
    //;
}

fruit::~fruit(void)
{
    //;
}

apple::apple(void)
{
    std::cout<<"new apple"<<std::endl;
}

pear::pear(void)
{
    std::cout<<"new pear"<<std::endl;
}

fruit_factory::fruit_factory(void)
{

}

fruit_factory::~fruit_factory(void)
{
    
}

fruit* fruit_factory::get_instance(int type)
{
    if(1==type)
    {
        return new apple();
    }
    else if(2==type)
    {
        return new pear();
    }
    else{
        return nullptr;
    }
}
