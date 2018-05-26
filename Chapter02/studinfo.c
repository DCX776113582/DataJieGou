//
//  studinfo.c
//  Chapter02
//
//  Created by mac on 18/1/18.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "studinfo.h"
#include "Header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
NODE *head;
int n;
void chushi(NODE*p1,NODE*q)
{
    //交换数据域ID
    NODE chae;
    chae.ID = p1->ID;
    p1->ID = q->ID;
    q->ID = chae.ID;
    //交换数据域NAME
    strcpy(chae.Name, p1->Name);
    strcpy(p1->Name, q->Name);
    strcpy(q->Name, chae.Name);
    //交换数据域AGE
    chae.Age = p1->Age;
    p1->Age = q->Age;
    q->Age = chae.Age;
}
void chu(NODE*new)
{
    //初始化数据域
    printf("ID:");
    scanf("%ld",&new->ID);
    printf("Name:");
    scanf("%s",new->Name);
    printf("Age:");
    scanf("%d",&new->Age);
}
void StudentLinkLable()//尾插法创建
{
    //创建数据链
    head =NULL;
    int i = 0;
    NODE *s = head;
    NODE * new;
    printf("请输入元素个数：");
    scanf("%d",&n);
    //创建数据链
    while (i<n) {
        new = (NODE*)malloc(sizeof(NODE));
        if (0==i) {//固定头结点
            head = new;
        }
        else
        {
            s->pNEXT = new;//链接
        }
        s=new;//跟踪尾结点（更新尾结点）
        new->pNEXT=NULL;//尾结点后继置空
        i++;
    }
    NODE * p = head;
    for (int i = 0; p!=NULL; ++i) {
        printf("请输入第%d个学生的信息：\n",i+1);
        //初始化数据域
        chu(p);
        p = p->pNEXT;
    }
}
void StudentHead()//头插法创建
{
    head = NULL;
    int i = 0;
    NODE * new;
    printf("请输入元素个数：");
    scanf("%d",&n);
    while (i<n) {
        new = (NODE*)malloc(sizeof(NODE));//申请
        new->pNEXT = head;//链接
        head = new;//更新头结点
        ++i;
    }
    NODE * p = head;
    for (int i = 0; p!=NULL; ++i) {
        printf("请输入第%d个学生的信息：\n",i+1);
        //初始化数据域
        chu(p);
        p = p->pNEXT;
    }
}
void PrintStuLinkLable(NODE * p)//打印
{
    printf("共%d个学生信息：\n",n);
    while (p!=NULL) {
        printf("%ld\t%s\t%d\n",p->ID,p->Name,p->Age);
        p=p->pNEXT;
    }
}
//释放链表
void Freehead(NODE * p)
{
    while (head!=NULL) {
        NODE * s = head;
        head = s->pNEXT;
        free(s);//释放
        s = NULL;
    }
    if (head==NULL) {
        puts("链表释放成功！无内存问题！");
    }
}
int search(NODE * p)//查询
{
    int find=0;
    if (p==NULL) {//链表为空
        puts("链表为空！");
    }
    else
    {//链表不为空
        long id;
        printf("请输入要查询的学号：");
        scanf("%ld",&id);
        NODE * s = p;
        while (NULL!=s) {
            if (id == s->ID) {
                printf("%ld\t%s\t%d\n",s->ID,s->Name,s->Age);
                find = 1;
            }
            s = s->pNEXT;
        }
    }
    if (1 == find) {
        puts("查找成功！");
        return 1;
    }
    else
    {
        puts("查找失败，不存在此数据！");
        return -1;
    }
}
int StudentDeleteLinkLable(NODE * p)//删除
{
    int find=0;
    if (p==NULL) {//链表为空
        puts("链表为空！");
    }
    else
    {//链表不为空
        long id;
        printf("请输入要删除的学员学号：");
        scanf("%ld",&id);
        NODE * s = p;//搜索指针
        //情况一:头结点
        if(id == s->ID){
            printf("%ld\t%s\t%d\n",s->ID,s->Name,s->Age);
            find = 1;
            head = head->pNEXT;
            free(s);
            s = NULL;
        }
        else
        {//情况二:非头结点
            while (NULL!=s&&NULL!=s->pNEXT) {
                if (id == s->pNEXT->ID) {//若存在，则打印本条信息
                    printf("%ld\t%s\t%d\n",s->pNEXT->ID,s->pNEXT->Name,s->pNEXT->Age);
                    find = 1;
                    //删除，建立链接
                    NODE * t = s->pNEXT;//标记被删除的结点
                    s->pNEXT = t->pNEXT;//建立新的链接
                    free(t);            //释放被标记的结点
                    t = NULL;
                }
                s = s->pNEXT;//向后搜索
            }
        }
        n--;
    }
    if (1 == find) {
        puts("删除成功！");
        return 1;
    }
    else
    {
        puts("删除失败，不存在此数据！");
        return -1;
    }
}
void SaveStuLinkLable(NODE * p)//保存
{
    //打开文件：路径
    FILE * fp = NULL;
    fp = fopen("SAVE.txt", "w");
    //保存文件：内存到文件
    if (fp!=NULL) {
        puts("文件打开成功！");
        fprintf(fp, "%s\n","学生信息：");
        fprintf(fp, "%d\n",n);
        NODE*s=p;
        for (int i = 0; s!=NULL; ++i) {
            fprintf(fp, "%ld\t%s\t%d\n",s->ID,s->Name,s->Age);
            s = s->pNEXT;
        }
    }
    //关闭文件
    int i = fclose(fp);
    if(0==i)
    {
        puts("文件关闭成功！");
    }
    fp = NULL;
}
void load(NODE*p)
{
    FILE * fp = NULL;
    fp = fopen("SAVE.txt", "r");
    if (fp!=NULL) {
        puts("文件打开成功！");
        int count = 0;
        NODE * new;
        NODE*s=NULL;
        NODE stu;
        char str[20];
        fscanf(fp, "%s%d",str,&n);
        printf("%s\t%d\n",str,n);
        if (p!=NULL) {
            Freehead(p);
        }
        while (fscanf(fp, "%ld%s%d",&stu.ID,stu.Name,&stu.Age)!=EOF) {
            count++;
            new = (NODE*)malloc(sizeof(NODE));
            *new =stu;
            if (1==count) {//固定头结点
                p = new;
            }
            else
            {
                s->pNEXT = new;//链接
            }
            s=new;//跟踪尾结点（更新尾结点）
            new->pNEXT=NULL;//尾结点后继置空
            head=p;
        }
    }
    int i = fclose(fp);
    if(0==i)
    {
        puts("文件关闭成功！");
    }
    fp = NULL;
}
void LoadStuLinkLable(NODE* p)//读取
{
    FILE * fp = NULL;
    fp = fopen("SAVE.txt", "r");
    if (fp!=NULL) {
        puts("文件打开成功！");
        p = NULL;
        int i = 0;
        NODE * new;
        char str[20];
        fscanf(fp, "%s%d",str,&n);
        printf("%s\t%d\n",str,n);
        if (p!=NULL) {
            Freehead(p);
        }
        while (i<n) {
            new = (NODE*)malloc(sizeof(NODE));//申请
            new->pNEXT = head;//链接
            head = new;//更新头结点
            p = head;
            ++i;
        }
        for (int j=0; j<n;++j) {
            fscanf(fp, "%ld%s%d",&p->ID,p->Name,&p->Age);
            printf("%ld\t%s\t%d\n",p->ID,p->Name,p->Age);
            p = p->pNEXT;
        }
    }
    int i = fclose(fp);
    if(0==i)
    {
        puts("文件关闭成功！");
    }
    fp = NULL;
}
void insertlink(NODE*p)//插入元素
{
    if(head==NULL) {//链表为空
        puts("链表为空！");
    }
    else
    {//链表不为空
        puts("请选择要插入的方式：1、首部插入、2、指定位置处插入、3、尾部插入");
        int c;
        scanf("%d",&c);
        switch (c) {
            case 1:
            {
                puts("你选择的是首部插入数据，请输入：");
                //创建链表
                NODE* new = (NODE*)malloc(sizeof(NODE));//申请
                new->pNEXT = p;//链接
                p = new;//更新头结点
                head = p;
                //初始化数据域
                chu(new);
                break;
            }
            case 2:
            {
                puts("你选择的是指定位置插入数据，请输入要插入的具体位置：");
                int index;
            loop:
                scanf("%d",&index);//2(第一个元素的后面进行插入)
                if(index>1&&index<=n)
                {
                    int i = 1;
                    NODE * s = p;
                    while (i<index-1) {
                        s=s->pNEXT;//s指向当前位置的前一个元素（上一个结点）
                        i++;
                    }
                    NODE* new = (NODE*)malloc(sizeof(NODE));//申请
                    new->pNEXT = s->pNEXT;//链接
                    s->pNEXT = new;//更新结点
                    //初始化数据域
                    chu(new);
                }
                else
                {
                    printf("重新输入：");
                    goto loop;
                }
                break;
            }
            case 3:
            {
                puts("你选择的是尾部插入数据，请输入：");
                NODE * s = p;
                while (s->pNEXT!=NULL) {
                    s=s->pNEXT;
                }
                NODE* new = (NODE*)malloc(sizeof(NODE));//申请
                new->pNEXT = s->pNEXT;//链接
                s->pNEXT = new;//更新尾结点
                chu(new);

                break;
            }
            default:
                break;
        }
        n++;
        PrintStuLinkLable(p);
    }
}
void reverseList(NODE*p)//逆置
{
    NODE*p1=NULL;//标记被逆
    NODE*p2=NULL;//标记即将被逆
    p1 = p;
    p = NULL;
    while (p1!=NULL) {
        p2 = p1->pNEXT;
        p1->pNEXT=p;
        p=p1;
        p1=p2;
    }
    head = p;
    PrintStuLinkLable(head);
}
void sortlink(NODE*p)//冒泡排序
{
    if(p!=NULL && p->pNEXT!=NULL) {
        int choose;
        puts("请选择排序方法：1、NAME  2、ID  3、AGE");
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                for (int i = 0; i<n-1; ++i) {
                    NODE*p1,*q;
                    p1= p;
                    q=p->pNEXT;
                    for (int j = 0; j<n-1-i; ++j) {
                        if (strcmp(p1->Name, q->Name)>0) {//比较排序交换
                            //交换数据域ID
                            chushi(p1, q);
                        }
                        p1=p1->pNEXT;
                        q=q->pNEXT;
                    }
                }
                break;
            case 2:
                for (int i = 0; i<n-1; ++i) {
                    NODE*p1,*q;
                    p1= p;
                    q=p->pNEXT;
                    for (int j = 0; j<n-1-i; ++j) {
                        if (p1->ID>q->ID) {//比较排序交换
                            //交换数据域ID
                            chushi(p1, q);
                        }
                        p1=p1->pNEXT;
                        q=q->pNEXT;
                    }
                }
                break;
            case 3:
                for (int i = 0; i<n-1; ++i) {
                    NODE*p1,*q;
                    p1= p;
                    q=p->pNEXT;
                    for (int j = 0; j<n-1-i; ++j) {
                        if (p1->Age>q->Age) {//比较排序交换
                            //交换数据域ID
                            chushi(p1, q);
                        }
                        p1=p1->pNEXT;
                        q=q->pNEXT;
                    }
                }
                break;
            default:puts("错误！");
                break;
        }
    }
    else
    {
        puts("条件不足，无法比较！");
    }

}
void Sortlink(NODE*p)//选择排序
{
    if(p!=NULL && p->pNEXT!=NULL) {
        int choose;
        puts("请选择排序方法：1、NAME  2、ID  3、AGE");
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                for (int i = 0; i<n-1; ++i) {
                    NODE*p1,*q=NULL,*m;
                    p1= p;
                    m=p;
                    q=p1->pNEXT;
                    for (int j = i+1; j<n; ++j) {
                        if (strcmp(m->Name, q->Name)<0) {//比较排序交换
                            m=q;
                        }
                        p1=p1->pNEXT;
                        q=q->pNEXT;
                    }
                    if (p1!=m) {
                        chushi(p1,m);
                    }
                    p=p->pNEXT;
                }
                break;
            case 2:
                for (int i = 0; i<n-1; ++i) {
                    NODE*p1,*q=NULL,*m;
                    p1= p;
                    m=p;
                    q=p1->pNEXT;
                    for (int j = 0; j<n-1-i; ++j) {
                        
                        if (m->ID<q->ID) {//比较排序交换
                            m=q;
                        }
                        p1=p1->pNEXT;
                        q=q->pNEXT;
                    }
                    if (p1!=m) {
                        chushi(p1,m);
                    }
                    p=p->pNEXT;
                }
                break;
            case 3:
                for (int i = 0; i<n-1; ++i) {
                    NODE*p1,*q=NULL,*m;
                    p1= p;
                    m=p;
                    q=p1->pNEXT;

                    for (int j = i+1; j<n; ++j) {
                        
                        if (m->Age<q->Age) {//比较排序交换
                            m=q;
                        }
                        p1=p1->pNEXT;
                        q=q->pNEXT;
                    }
                    if (p1!=m) {
                        chushi(p1,m);
                    }
                    p=p->pNEXT;
                }
                break;
            default:puts("错误！");
                break;
        }
    }
    else
    {
        puts("条件不足，无法比较！");
    }
}

