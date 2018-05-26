//
//  Stack.h
//  Chapter03
//
//  Created by mac on 18/1/24.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter03__Stack__
#define __Chapter03__Stack__

#include <stdio.h>
#define N 3

typedef struct {
    int data[N];
    int top;
}SqStack;
SqStack* initStack();
int getTop(SqStack * s, int* e);
int Push(SqStack * s,int e);
void Pop(SqStack * s,int* e);
void destroyStack(SqStack * s);
void test();
typedef struct{
    //数据域
    long ID;
    char Name[10];
    int Age;
} STU;
typedef struct {
    STU data[N];
    STU *top;
    int size;
}SQStack;
SQStack* initStuStack();
int getStuTop(SQStack * s, STU* e);
int PushStu(SQStack * s,STU e);
int PopStu(SQStack * s,STU* e);
int destroyStuStack(SQStack * s);
void testStu();
int clearStu(SQStack *s);
void testIsStack();
int symnetry(SQStack*s);
int yuansu(SQStack*s);
#endif /* defined(__Chapter03__Stack__) */
