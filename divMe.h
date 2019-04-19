//
// Created by Михаил Терентьев on 2019-04-18.
//

#ifndef OS_JIT_FUNC_H
#define OS_JIT_FUNC_H

#include <cstring>
using namespace std;

/*
 * Function, which program try to map
 *
int div(int b){
    int a = 5000000;
    return (a/b);
}
*/


unsigned char asmCode[] = { 0x55,0x48, 0x89, 0xe5, 0x89 ,0x7d, 0xfc,
        0xc7, 0x45 , 0xf8 ,
        /*---->*/0x40 ,0x4b , 0x4c , 0x00,//<-----
         0x8b , 0x45 , 0xf8,
         0x99,
         0xf7 , 0x7d , 0xfc,
         0x5d,
         0xc3,
         0x66 , 0x0f , 0x1f , 0x84 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00};

void modify(int x){
    memcpy(asmCode + 10, &x, 4);
}

#endif //OS_JIT_FUNC_H
