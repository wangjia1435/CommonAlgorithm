//
//  crc.c
//  CommonAlgorithm
//
//  Created by Jia Wang on 2018/8/5.
//  Copyright © 2018年 Jia Wang. All rights reserved.
//

#include <stdio.h>

int crc_single(char b, int crcPoly, int crcInitValue)
{
	int crc=crcInitValue;
	crc = crc^b<<8;
	for(int i=0; i<8; i++)
	{
		if(crc^0x80)
		{
			crc=(crc<<1)^crcPoly;
		}
		else
		{
			crc=crc<<1;
		}
	}
	return crc;
}
