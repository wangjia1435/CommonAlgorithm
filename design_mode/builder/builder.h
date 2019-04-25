//
//  builder.h
//  common_algorithm
//
//  Created by Jia Wang on 2018/4/16.
//  Copyright © 2018 Jia Wang. All rights reserved.
//
#ifndef builder_h
#define builder_h

/*
构建者模式：将构建与表示分离，提高构建的简便性，其中有几个部分
1 director 指挥者，如何构建
2 Builder抽象建造者
2 builder 具体建设者，执行构建顺序
3 builderPartA 子部分
4 builderPartB 子部分
*/

class ConstructBuilder
{
public:
	ConstructBuilder();
	~ConstructBuilder();

	void buildPartA(void);
	void buildPartB(void);
	void buildPartC(void);
private:

};
#endif

