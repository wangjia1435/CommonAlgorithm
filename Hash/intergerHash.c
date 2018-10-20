//
//  intergerHash.c
//  CommonAlgorithm
//
//  Created by Jia Wang on 2018/1/20.
//  Copyright © 2018年 Jia Wang. All rights reserved.
//

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
static int dict_hash_function_seed = 5381;

/*
整型hash算法使用 Thomas Wang‘s32 BIt／64Bit Mix function：基于移位运算的散列方法。
 通过左移和右移，移位过程中累加，避免乘法运算，提高性能
*/
unsigned int dicIntHashFunction(unsigned int key)
{
    key += ~(key << 15);
    key ^=  (key >> 10);
    key += (key << 3);
    key ^= (key >> 6);
    key += (key << 11);
    key ^= (key >> 16);
    return key;
}

/*
 字符串使用的MurmurHash算法，Hurmur具有高运算性能，低碰撞率的特点，由Austin Appleby 创建
 于2008年，现已应用到Hadoop、libstdc.nginx很多开源系统。Murmur是multiply and rotate意思
 算法核心 不断乘法和位移 x *= m  k^= k >> r
 */
unsigned int dictGenHashFunction(const void *key, int len) {
    /* 'm' and 'r' are mixing constants generated offline.
     They're not really 'magic', they just happen to work well.  */
    uint32_t seed = /*dict_hash_function_seed*/5381;
    const uint32_t m = 0x5bd1e995;
    const int r = 24;
    
    /* Initialize the hash to a 'random' value */
    uint32_t h = seed ^ len;
    
    /* Mix 4 bytes at a time into the hash */
    const unsigned char *data = (const unsigned char *)key;
    
    while(len >= 4) {
        uint32_t k = *(uint32_t*)data;
        
        k *= m;
        k ^= k >> r;
        k *= m;
        
        h *= m;
        h ^= k;
        
        data += 4;
        len -= 4;
    }
    
    /* Handle the last few bytes of the input array  */
    switch(len) {
        case 3: h ^= data[2] << 16;
        case 2: h ^= data[1] << 8;
        case 1: h ^= data[0]; h *= m;
    };
    
    /* Do a few final mixes of the hash to ensure the last few
     * bytes are well-incorporated. */
    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;
    
    return (unsigned int)h;
}

/*
 加法hash通过遍历数据中的元素然后每次对某个初始值进行加操作，其中加的值和这个数据的一个元素有关
 */
/********************************
 *加法哈希
 *@key   输入字符串
 *@prime 素数
 ********************************/
int additiveHash(const char *key, int prime)
{
    size_t hash, i;
    size_t len = strlen(key);
    for(hash = len, i = 0; i < len; ++i)
    {
        hash += (int)(key[i]);
    }
    return (hash%prime);
}

/* And a case insensitive hash function (based on djb hash) */
/* 一种比较简单的哈希算法，也是对字符串进行哈希的 */
unsigned int dictGenCaseHashFunction(const unsigned char *buf, int len) {
    unsigned int hash = (unsigned int)dict_hash_function_seed;
    
    while (len--)
        hash = ((hash << 5) + hash) + (tolower(*buf++)); /* hash * 33 + c */
    return hash;
}

void intergerHash_main(void)
{
    int i;
    for(i=0; i<100; i++)
    {
        printf("hash valve = %d\n ",dicIntHashFunction(i));
    }

}
