//
//  test.c
//  Demo01
//
//  Created by mac on 18/1/18.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "test.h"
#include <stdlib.h>
#include <string.h>

Node* hCreatList(int n)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->pNext = NULL;
    while (n-- > 0) {
        Node* f = (Node*)malloc(sizeof(Node));
        f->data = n;
        f->pNext = p->pNext;
        p->pNext = f;
    }
    return p;
}
Node* tCreatList(int n)
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->pNext = NULL;
    Node* s = head;
    while (n-- > 0) {
        Node* p = (Node*)malloc(sizeof(Node));
        p->data = n;
        p->pNext = NULL;
        s->pNext = p;
        s = p;
    }
    return head;
}
int searchList(Node* head,int num)
{
    int i = 0;
    for(Node* p=head->pNext;p!=NULL;p=p->pNext)
    {
        ++i;
        if (num == p->data)
        {
            return i; }
    }
    return -1;
}
Node* deleteNode(Node* head,int num)
{
    for (Node* p = head; p->pNext != NULL; p =p->pNext)
    {
        if (num == (p->pNext)->data)
        {
            Node* t = p->pNext;
            p->pNext = t->pNext;
            free(t);
        }
    }
    return head;
}
Node* insertList(Node* head,int index)
{
    Node* p = head->pNext;
    int i = 0;
    while (i < index) {
        p = p->pNext;
        ++i;
    }
    Node* nNode = malloc(sizeof(Node));
    nNode->data = 10;
    nNode->pNext = p->pNext;
    p->pNext = nNode;
    return head;
}
Node* freeList(Node* head)
{
    while (head->pNext != NULL )
    {
        Node* md = head->pNext;
        head->pNext = md->pNext;
        free(md);
    }
    return head;
}
Node* reverseList(Node* head)
{
    Node* p,*q;
    p = head->pNext;
    head->pNext = NULL;
    while (p != NULL)
    {
        q = p->pNext;
        p->pNext = head->pNext;
        head->pNext = p;
        p = q;
    }
    return head;
}
void printList(Node* head)
{
    Node* p = head->pNext;
    while (p)
    {
        printf("data: %d\n",p->data);
        p = p->pNext;
    }
}
void test1()
{
    Node* head = hCreatList(10);
    printList(head);
    deleteNode(head, 4);
    insertList(head, 0);
    printList(head);
    freeList(head);
    reverseList(head);
    printList(head);
    int x = searchList(head,3);
    if(x==-1){
        printf("no\n");
    }
    printf("%d\n",x);
}
NODE students[N];

void StudentLinkLable()
{
    for (int i = 0; i<N; ++i) {
        //初始化数据域
        printf("请输入第%d个学生的信息:\n",i+1);
        printf("ID:");
        scanf("%ld",&students[i].ID);
        printf("Name:");
        scanf("%s",students[i].Name);
        printf("Age:");
        scanf("%d",&students[i].Age);
        //初始化指针域
        if (i<N-1) {
            students[i].pNEXT=students+(1+i);
        }
        else
        {
            students[i].pNEXT=NULL;
        }
    }
}
void PrintStuLinkLable(NODE students[])
{
    printf("学生信息：\n");
    NODE* p= students;
    while (p!=NULL) {
        printf("%ld\t%s\t%d\n",p->ID,p->Name,p->Age);
        p=p->pNEXT;
    }
}
//指针域完成保存文件，读取文件，查询数据，删除数据
void test2()
{
    StudentLinkLable();
    PrintStuLinkLable(students);
}
