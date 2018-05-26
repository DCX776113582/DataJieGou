//
//  main.c
//  Chapter05
//
//  Created by mac on 18/1/23.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include <stdio.h>
#include "Sort.h"
void linx()
{
    int k = 5;
    int j;
    for (int i = 0; i<k; ++i) {
        for (j =0; j<=k-1-i; ++j) {
            printf(" ");
        }
        for (int x =0; x<=2*i; ++x) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1; i<(k); ++i) {
        for (j =i; j>=0; --j) {
            printf(" ");
        }
        for (int x =0; x<2*(k-i)-1; ++x) {
            printf("*");
        }
        printf("\n");
    }
}
int renyi(int a)
{
    if (a<10) {
        return a;
    }else{
        return renyi(a/10)+a%10;
    }
}
int i = 0;
int rene(int a)
{
    if (a<10) {
        return 1;
    }else{
        ++i;
        rene(a/10);
        return i+1;
    }
}
int main(int argc, const char * argv[]) {
    Heapsort();
    return 0;
}
