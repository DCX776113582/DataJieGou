//
//  CircularlyList.c
//  Chapter02
//
//  Created by mac on 18/1/23.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "CircularlyList.h"
#include <stdlib.h>
NODE * headC;//标记头结点
NODED * headCD;//标记头结点
NODED * tailCD;//标记尾结点
STU*headL=NULL;
STU*tailL=NULL;

int n_L = 0;
int n_C = 0;
void CretCLinkLable()//尾插法
{
    headC =NULL;
    int i = 0;
    NODE *s = headC;
    NODE * new;
    printf("请输入元素个数：");
    scanf("%d",&n_C);
    //创建数据链
    while (i<n_C) {
        new = (NODE*)malloc(sizeof(NODE));
        if (0==i) {//固定头结点
            headC = new;
        }
        else
        {
            s->pNEXT = new;//链接
        }
        s=new;//跟踪尾结点（更新尾结点）
        new->pNEXT=NULL;//尾结点后继置空
        i++;
    }
    NODE * p = headC;
    for (int i = 0; p!=NULL; ++i) {
        printf("请输入第%d个学生的信息：\n",i+1);
        //初始化数据域
        printf("ID:");
        scanf("%ld",&p->ID);
        printf("Name:");
        scanf("%s",p->Name);
        printf("Age:");
        scanf("%d",&p->Age);
        p = p->pNEXT;
    }
    //链接尾结点和头结点
    s->pNEXT=headC;
}
void CretCDLinkLable()//尾插法
{
    headCD =NULL;
    tailCD = NULL;
    int i = 0;
    NODED *s = headCD;
    NODED * new = NULL;
    printf("请输入元素个数：");
    scanf("%d",&n_C);
    //创建数据链
    while (i<n_C) {
        new = (NODED*)malloc(sizeof(NODED));
        new->pPre=s;//初始化前驱
        if (0==i) {//固定头结点
            headCD = new;
        }
        else
        {
            s->pNEXT = new;//链接
        }
        s=new;//跟踪尾结点（更新尾结点）
        tailCD=new;
        new->pNEXT=NULL;//尾结点后继置空
        i++;
    }
    NODED * p = headCD;
    for (int i = 0; p!=NULL; ++i) {
        printf("请输入第%d个学生的信息：\n",i+1);
        //初始化数据域
        printf("ID:");
        scanf("%ld",&p->ID);
        printf("Name:");
        scanf("%s",p->Name);
        printf("Age:");
        scanf("%d",&p->Age);
        p = p->pNEXT;
    }
    tailCD->pNEXT=headCD;
    headCD->pPre=tailCD;
}
void PrintStuCLinkLable(NODE * p)//打印链表
{
    printf("共%d个学生信息：\n",n_C);
    NODE*t=p;//标记指针
    while (p!=NULL) {
        printf("%ld\t%s\t%d\n",p->ID,p->Name,p->Age);
        p=p->pNEXT;
        if (p==t) {
            printf("%ld\t%s\t%d\n",p->ID,p->Name,p->Age);
            puts("此链表为循环链表");
            break;
        }
    }
}
void PrintStuCDLinkLable(NODED * p)//打印链表
{
    printf("共%d个学生信息：\n",n_C);
    NODED*t=p;//标记指针
    while (p!=NULL) {
        printf("%ld\t%s\t%d\n",p->ID,p->Name,p->Age);
        p=p->pNEXT;
        if (p==t) {
            printf("%ld\t%s\t%d\n",p->ID,p->Name,p->Age);
            puts("此链表为循环链表");
            break;
        }
    }
}
void PrintStuCDLinkLableT(NODED * p)//打印链表
{
    printf("共%d个学生信息：\n",n_C);
    NODED*t=p;//标记指针
    while (p!=NULL) {
        printf("%ld\t%s\t%d\n",p->ID,p->Name,p->Age);
        p=p->pPre;
        if (p==t) {
            printf("%ld\t%s\t%d\n",p->ID,p->Name,p->Age);
            puts("此链表为循环链表");
            break;
        }
    }
}
void CretLOLinkLable()//尾插法
{
    int i = 0;
    STU *s = headL;
    STU * new=NULL;
    printf("请输入元素个数：");
    scanf("%d",&n_L);
    //创建数据链
    DATA d;
    while (i<n_L) {
        new = (STU*)malloc(sizeof(STU));
        printf("请输入第%d个学生的信息：\n",i+1);
        //初始化数据域
        printf("ID:");
        scanf("%ld",&d.ID);
        printf("Name:");
        scanf("%s",d.Name);
        printf("Age:");
        scanf("%d",&d.Age);
        new->data = d;
        //初始化链域
        if (0==i) {//固定头结点
            headL = new;
        }
        else
        {
            s->pNEXT = new;//链接
        }
        s=new;//跟踪尾结点（更新尾结点）
        new->pNEXT=headL;
        i++;
    }
    tailL=new;
}
void PrintStuLOLinkLable(STU * p)//打印链表
{
    printf("共%d个学生信息：\n",n_L);
    STU*t=p;//标记指针
    while (p!=NULL) {
        printf("%ld\t%s\t%d\n",p->data.ID,p->data.Name,p->data.Age);
        p=p->pNEXT;
        if (p==t) {
        printf("%ld\t%s\t%d\n",p->data.ID,p->data.Name,p->data.Age);
            puts("此链表为循环链表");
            break;
        }
    }
}
void FreeheadL(STU * p)//释放链表
{
    STU * s=p;
    STU * q=p;
    while (p!=q->pNEXT) {
        q=q->pNEXT;
    }
    while (p!=NULL) {
        p = p->pNEXT;//更新头结点
        q->pNEXT=p;//循环：尾结点链接头结点
        if (s==q) {//处理尾结点
            free(s);
            n_L--;
            s=NULL;
            p=q=s;
            break;
        }
        free(s);//释放
        n_L--;
        s=p;//跟踪头结点
    }
    headL=p;
    if (headL==NULL) {
        puts("链表释放成功！无内存问题！");
    }
}

