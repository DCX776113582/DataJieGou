//
//  Header.h
//  Chapter02
//
//  Created by mac on 18/1/18.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef Chapter02_Header_h
#define Chapter02_Header_h
typedef struct student{
    //数据域
    long ID;
    char Name[10];
    int Age;
    //指针域
    struct student *pNEXT;
}NODE;
typedef struct studentDouble{
    struct studentDouble *pPre;//直接前驱
    //数据域
    long ID;
    char Name[10];
    int Age;
    //指针域
    struct studentDouble *pNEXT;//直接后继
}NODED;
typedef struct{
    //数据域
    long ID;
    char Name[10];
    int Age;
} DATA;
typedef struct stu{
    DATA data;
    struct stu*pNEXT;
} STU;

#endif
