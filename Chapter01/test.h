//
//  test.h
//  Demo01
//
//  Created by mac on 18/1/18.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Demo01__test__
#define __Demo01__test__

#include <stdio.h>
typedef struct node{
    int data;
    struct node *pNext;
}Node;
Node* hCreatList(int n);
Node* tCreatList(int n);
int searchList(Node* head,int num);
Node* deleteNode(Node* head,int num);
Node* insertList(Node* head,int index);
Node* freeList(Node* head);
Node* reverseList(Node* head);
typedef struct student{
    //数据域
    long ID;
    char Name[10];
    int Age;
    //指针域
    struct student *pNEXT;
}NODE;
#define N 3
void printList(Node* head);
void test1();
void test2();
#endif /* defined(__Demo01__test__) */
