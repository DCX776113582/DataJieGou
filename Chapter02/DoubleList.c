 //
//  DoubleList.c
//  Chapter02
//
//  Created by mac on 18/1/22.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "DoubleList.h"
#include <stdlib.h>
#include <string.h>
NODED * headD;//标记头结点
NODED * tailD;//标记尾结点
int n_D = 0;
void CretDLinkLable()//尾插法
{
    headD =NULL;
    tailD = NULL;
    int i = 0;
    NODED *s = headD;
    NODED * new;
    printf("请输入元素个数：");
    scanf("%d",&n_D);
    //创建数据链
    while (i<n_D) {
        new = (NODED*)malloc(sizeof(NODED));
        new->pPre=s;//初始化前驱
        if (0==i) {//固定头结点
            headD = new;
        }
        else
        {
            s->pNEXT = new;//链接
        }
        s=new;//跟踪尾结点（更新尾结点）
        tailD=new;
        new->pNEXT=NULL;//尾结点后继置空
        i++;
    }
    NODED * p = headD;
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
}
void PrintStuDLinkLable(NODED * p)//打印链表
{
    printf("共%d个学生信息：\n",n_D);
    while (p!=NULL) {
        printf("%ld\t%s\t%d\n",p->ID,p->Name,p->Age);
        p=p->pNEXT;
    }
}
void PrintStuDLinkLableT(NODED * p)//打印链表
{
    printf("共%d个学生信息：\n",n_D);
    while (p!=NULL) {
        printf("%ld\t%s\t%d\n",p->ID,p->Name,p->Age);
        p=p->pPre;
    }
}
void StudentDHead()//头插法
{
    headD = NULL;
    tailD = NULL;
    int i = 0;
    NODED * new;
    printf("请输入元素个数：");
    scanf("%d",&n_D);
    while (i<n_D) {
        new = (NODED*)malloc(sizeof(NODED));//申请
        new->pPre=NULL;
        new->pNEXT = headD;//链接
        if (0==i) {
            tailD=new;
        }
        else
        {
            headD->pPre=new;
        }
        headD = new;//更新头结点
        ++i;
    }
    NODED * p = headD;
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
}
void SaveStuDLinkLable(NODED * p)//保存
{
    if (p==NULL) {
        puts("链表为空，无法保存");
    }else{
        //打开文件：路径
        FILE * fp = NULL;
        fp = fopen("SAVE.txt", "w");
        //保存文件：内存到文件
        if (fp!=NULL) {
            puts("文件打开成功！");
            fprintf(fp, "%s\n","学生信息：");
            fprintf(fp, "%d\n",n_D);
            NODED*s=p;
            while(s!=NULL) {
                fprintf(fp, "%ld\t%s\t%d\n",s->ID,s->Name,s->Age);
                s = s->pNEXT;
            }
            puts("写入数据成功");
        }
        //关闭文件
        int i = fclose(fp);
        if(0==i)
        {
            puts("文件关闭成功！");
        }
        fp = NULL;
    }
}
void loadD(NODED*p)
{
    FILE * fp = NULL;
    fp = fopen("SAVE.txt", "r");
    if (fp!=NULL) {
        puts("文件打开成功！");
        int count = 0;
        NODED * new;
        NODED*s=NULL;
        NODED stu;
        char str[20];
        fscanf(fp, "%s%d",str,&n_D);
        printf("%s\t%d\n",str,n_D);
        if (p!=NULL) {
            FreeheadD(p);
        }
        while (fscanf(fp, "%ld%s%d",&stu.ID,stu.Name,&stu.Age)!=EOF) {
            count++;
            new = (NODED*)malloc(sizeof(NODED));
            *new =stu;
            new->pPre=s;//左链接
            if (1==count) {//固定头结点
                p = new;
            }
            else
            {
                s->pNEXT = new;//链接
            }
            count=n_D;
            s=new;//跟踪尾结点（更新尾结点）
            tailD=new;//标记尾结点
            headD=p;//标记头结点
            new->pNEXT=NULL;//尾结点后继置空
        }
    }
    int i = fclose(fp);
    if(0==i)
    {
        puts("文件关闭成功！");
    }
    fp = NULL;
}
void FreeheadD(NODED * p)//释放
{
    if (p==NULL) {
        puts("链表为空！无内存问题！");
    }else{
        NODED * s = NULL;//标记被释放的结点
        while (p!=NULL) {
            s = p;
            p = s->pNEXT;//更新头结点
            if (p!=NULL) {
                p->pPre=s->pPre;//头结点前驱指针置空
            }
            free(s);//释放
            s = NULL;
        }
        headD=p;
        tailD=p;
        puts("链表释放成功！无内存问题！");
    }
}
void StudentDeleteDLinkLable(NODED * p)//删除
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
        NODED * s = p;//搜索指针
        //情况一:头结点
        if(id == s->ID){
            printf("%ld\t%s\t%d\n",s->ID,s->Name,s->Age);
            find = 1;
            if (headD->pNEXT!=NULL) {
                headD = headD->pNEXT;
                headD->pPre=NULL;
            }
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
                    NODED * t = s->pNEXT;//标记被删除的结点
                    s->pNEXT = t->pNEXT;//建立新的链接
                    if (t->pNEXT!=NULL) {//排除尾结点
                        t->pNEXT->pPre=s;
                    }else{
                        tailD = s;
                    }
                    free(t);            //释放被标记的结点
                    t = NULL;
                }
                s = s->pNEXT;//向后搜索
            }
        }
        n_D--;
    }
    if (1 == find) {
        puts("删除成功！");
    }
    else
    {
        puts("删除失败，不存在此数据！");
    }
}
void searchD(NODED * p)//查询
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
        NODED * s = p;
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
    }
    else
    {
        puts("查找失败，不存在此数据！");
    }
}
void insertDlink(NODED*p)//插入元素
{
    if(headD==NULL) {//链表为空
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
                NODED* new = (NODED*)malloc(sizeof(NODED));//申请
                new->pNEXT = p;//链接
                p->pPre=new;
                p = new;//更新头结点
                p->pPre=NULL;
                headD = p;
                //初始化数据域
                printf("ID:");
                scanf("%ld",&new->ID);
                printf("Name:");
                scanf("%s",new->Name);
                printf("Age:");
                scanf("%d",&new->Age);
                break;
            }
            case 2:
            {
                puts("你选择的是指定位置插入数据，请输入要插入的具体位置：");
                int index;
            loop:
                scanf("%d",&index);//2(第一个元素的后面进行插入)
                if(index>1&&index<=n_D)
                {
                    int i = 1;
                    NODED * s = p;
                    while (i<index-1) {
                        s=s->pNEXT;//s指向当前位置的前一个元素（上一个结点）
                        i++;
                    }
                    NODED* new = (NODED*)malloc(sizeof(NODED));//申请
                    
                    new->pNEXT = s->pNEXT;//链接
                    new->pPre=s;
                    s->pNEXT = new;//更新结点
                    new->pNEXT->pPre=new;
                    //初始化数据域
                    printf("ID:");
                    scanf("%ld",&new->ID);
                    printf("Name:");
                    scanf("%s",new->Name);
                    printf("Age:");
                    scanf("%d",&new->Age);
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
                NODED * s = p;
                while (s->pNEXT!=NULL) {
                    s=s->pNEXT;
                }
                NODED* new = (NODED*)malloc(sizeof(NODED));//申请
                new->pPre=s;
                new->pNEXT = s->pNEXT;//链接
                s->pNEXT = new;//更新尾结点
                tailD=new;
                //初始化数据域
                printf("ID:");
                scanf("%ld",&new->ID);
                printf("Name:");
                scanf("%s",new->Name);
                printf("Age:");
                scanf("%d",&new->Age);
                break;
            }
            default:
                break;
        }
        n_D++;
        PrintStuDLinkLable(p);
    }
}
void reverseDList(NODED*p)//逆置
{
    NODED*p1=NULL;//标记被逆
    NODED*p2=NULL;//标记即将被逆
    p1 = p;
    p = NULL;
    while (p1!=NULL) {
        p2 = p1->pNEXT;
        p1->pNEXT=p;
        p=p1;
        p1=p2;
    }
    headD = p;
    PrintStuDLinkLable(headD);
}
void reverseDListT(NODED*p)//逆置
{
    NODED*p1=NULL;//标记被逆
    NODED*p2=NULL;//标记即将被逆
    p1 = p;
    p = NULL;
    while (p1!=NULL) {
        p2 = p1->pPre;
        p1->pPre=p;
        p=p1;
        p1=p2;
    }
    tailD = p;
    PrintStuDLinkLableT(tailD);
}
void sortlinkD(NODED*p)//选择排序
{
    if(p!=NULL && p->pNEXT!=NULL) {
        int choose;
        puts("请选择排序方法：1、NAME  2、ID  3、AGE");
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                for (int i = 0; i<n_D-1; ++i) {
                    NODED*p1,*q=NULL,*m;
                    p1= p;
                    m=p;
                    q=p1->pNEXT;
                    for (int j = i+1; j<n_D; ++j) {
                        if (strcmp(m->Name, q->Name)>0) {//比较排序交换
                            m=q;
                        }
                        p1=p1->pNEXT;
                        q=q->pNEXT;
                    }
                    if (p1!=m) {
                        swap(p1,m);
                    }
                }
                break;
            case 2:
                for (int i = 0; i<n_D-1; ++i) {
                    NODED*p1,*q=NULL,*m;
                    p1= p;
                    m=p;
                    q=p1->pNEXT;

                    for (int j = i+1; j<n_D; ++j) {
                        if (m->ID>q->ID) {//比较排序交换
                            m=q;
                        }
                        p1=p1->pNEXT;
                        q=q->pNEXT;
                    }
                    if (p1!=m) {
                        swap(p1,m);
                    }
                }
                break;
            case 3:
                for (int i = 0; i<n_D-1; ++i) {
                    NODED*p1,*q=NULL,*m;
                    p1= p;
                    m=p;
                    q=p1->pNEXT;
                    for (int j = i+1; j<n_D; ++j) {
                        if (m->Age>q->Age) {//比较排序交换
                            m=q;
                        }
                        p1=p1->pNEXT;
                        q=q->pNEXT;
                    }
                    if (p1!=m) {
                        swap(p1,m);
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
void SortlinkD(NODED*p)//冒泡排序
{
    if(p!=NULL && p->pNEXT!=NULL) {
        int choose;
        puts("请选择排序方法：1、NAME  2、ID  3、AGE");
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                for (int i = 0; i<n_D-1; ++i) {
                    NODED*p1,*q;
                    p1= p;
                    q=p->pNEXT;
                    for (int j = 0; j<n_D-1-i; ++j) {
                        if (strcmp(p1->Name, q->Name)>0) {//比较排序交换
                            swap(p1,q);
                        }
                        p1=p1->pNEXT;
                        q=q->pNEXT;
                    }
                }
                break;
            case 2:
                for (int i = 0; i<n_D-1; ++i) {
                    NODED*p1,*q;
                    p1= p;
                    q=p->pNEXT;
                    for (int j = 0; j<n_D-1-i; ++j) {
                        if (p1->ID>q->ID) {//比较排序交换
                            swap(p1,q);
                        }
                        p1=p1->pNEXT;
                        q=q->pNEXT;
                    }
                }
                break;
            case 3:
                for (int i = 0; i<n_D-1; ++i) {
                    NODED*p1,*q;
                    p1= p;
                    q=p->pNEXT;
                    for (int j = 0; j<n_D-1-i; ++j) {
                        if (p1->Age>q->Age) {//比较排序交换
                            swap(p1,q);
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
void SortlinkDC(NODED*p)//插入排序
{
    if(p!=NULL && p->pNEXT!=NULL) {
        int choose;
        int i,j;
        NODED*p1,*q;
        NODED s1;
        puts("请选择排序方法：1、NAME  2、ID  3、AGE");
        scanf("%d",&choose);
        switch (choose) {
            case 1:
                for (i = 1; i<n_D; ++i) {
                    q=p->pNEXT;//存储被插入元素
                    //存储被插入元素的信息
                    s1.ID=q->ID;
                    strcpy(s1.Name, q->Name);
                    s1.Age = q->Age;
                    //找适合
                    for (j = i-1; (p1=q->pPre)&&p1!=NULL; --j) {
                        if (strcmp(s1.Name, p1->Name)<=0) {//如果小于：右移
                            //向后移动数据
                            q->ID = p1->ID;
                            strcpy(q->Name, p1->Name);
                            q->Age = p1->Age;
                            //q和p1均向前移动
                            q=p1;//q先向p1移动
                            p1=p1->pPre;//p1向前移动
                        }else{
                            break;
                        }
                    }
                    //3、直接插入：位置：有序区标记的位置q
                    q->ID = s1.ID;
                    strcpy(q->Name, s1.Name);
                    q->Age=s1.Age;
                    //寻找无序区的首元素
                    p=p->pNEXT;
                }
                break;
            case 2:
                for (i = 1; i<n_D; ++i) {
                    q=p->pNEXT;
                    s1.ID=q->ID;
                    strcpy(s1.Name, q->Name);
                    s1.Age = q->Age;
                    for (j = i-1; (p1=q->pPre)&&p1!=NULL; --j) {
                        if (s1.ID<=p1->ID) {//比较排序交换
                            q->ID = p1->ID;
                            strcpy(q->Name, p1->Name);
                            q->Age = p1->Age;
                            q=q->pPre;
                            p1=p1->pPre;
                        }
                        else{
                            break;
                        }
                    }
                    q->ID = s1.ID;
                    strcpy(q->Name, s1.Name);
                    q->Age=s1.Age;
                    p=p->pNEXT;
                }
                break;
            case 3:
                for (i = 1; i<n_D; ++i) {
                    NODED*p1,*q;
                    q=p->pNEXT;

                    NODED s1;
                    s1.ID=q->ID;
                    strcpy(s1.Name, q->Name);
                    s1.Age = q->Age;

                    for (int j = i-1;(p1=q->pPre)&&p1!=NULL; --j) {
                        if (s1.Age<=p1->Age) {//比较排序交换
                            q->ID = p1->ID;
                            strcpy(q->Name, p1->Name);
                            q->Age = p1->Age;
                            q=p1;
                            p1=p1->pPre;
                        }
                        else{
                            break;
                        }
                    }
                    q->ID = s1.ID;
                    strcpy(q->Name, s1.Name);
                    q->Age=s1.Age;
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
NODED* SortlinkID(NODED*p1,NODED*p,NODED*q)//快速排序ID
{
    if (p1==NULL) {
        puts("空链表");
    }else{
    if (p!=q&&p!=NULL) {
        NODED *first = p;
        NODED *last = q;
        NODED stu;//存储
        stu.ID = first->ID;
        strcpy(stu.Name,first->Name);
        stu.Age = first->Age;
        while(first!=last){//循环
            //1、自右向左（寻找小于stu.ID的数）
            while(first!=last&&last->ID>=stu.ID){
                last=last->pPre;
            }
            if(first!=last)
            {
                first->ID=last->ID;
                strcpy(first->Name,last->Name);
                first->Age=last->Age;
                first=first->pNEXT;
            }
            //2、自左向右（寻找大于stu.ID的数）
            while(first!=last&&first->ID<=stu.ID){
                first=first->pNEXT;
            }
            if(first!=last)
            {
                last->ID=first->ID;
                strcpy(last->Name,first->Name);
                last->Age = first->Age;
                last=last->pPre;
            }
        }
        first->ID=stu.ID;
        strcpy(first->Name,stu.Name);
        first->Age=stu.Age;
        if (p!=first) {
            SortlinkID(p1,p,first->pPre);//递归调用
        }
        if (q!=last) {
            SortlinkID(p1,first->pNEXT,q);//递归调用
        }
    }}
    return p1;
}
NODED* SortlinkNAME(NODED*p1,NODED*p,NODED*q)//快速排序NAME
{
    if (p1==NULL) {
        puts("空链表");
    }else{
        NODED *first = p;
        NODED *last = q;
        NODED stu;//存储
        stu.ID = first->ID;
        strcpy(stu.Name,first->Name);
        stu.Age = first->Age;
        while(first!=last){//循环
            //1、自右向左（寻找小于stu.ID的数）
            while(first!=last&&strcmp(last->Name, stu.Name)>=0){
                last=last->pPre;
            }
            if(first!=last)
            {
                first->ID=last->ID;
                strcpy(first->Name,last->Name);
                first->Age=last->Age;
                first=first->pNEXT;
            }
            //2、自左向右（寻找大于stu.ID的数）
            while(first!=last&&strcmp(first->Name, stu.Name)<=0){
                first=first->pNEXT;
            }
            if(first!=last)
            {
                last->ID=first->ID;
                strcpy(last->Name,first->Name);
                last->Age = first->Age;
                last=last->pPre;
            }
        }
        first->ID=stu.ID;
        strcpy(first->Name,stu.Name);
        first->Age=stu.Age;
        if (p!=first) {
            SortlinkNAME(p1,p,first->pPre);//递归调用
        }
        if (q!=last) {
            SortlinkNAME(p1,first->pNEXT,q);//递归调用
        }
    }
    return p1;
}
NODED* SortlinkAGE(NODED*p1,NODED*p,NODED*q)//快速排序AGE
{
    if (p1==NULL) {
        puts("空链表");
    }else{

    if (p!=q&&p!=NULL) {
        NODED *first = p;
        NODED *last = q;
        NODED stu;//存储
        stu.ID = first->ID;
        strcpy(stu.Name,first->Name);
        stu.Age = first->Age;
        while(first!=last){//循环
            //1、自右向左（寻找小于stu.ID的数）
            while(first!=last&&last->Age>=stu.Age){
                last=last->pPre;
            }
            if(first!=last)
            {
                first->ID=last->ID;
                strcpy(first->Name,last->Name);
                first->Age=last->Age;
                first=first->pNEXT;
            }
            //2、自左向右（寻找大于stu.ID的数）
            while(first!=last&&first->Age<=stu.Age){
                first=first->pNEXT;
            }
            if(first!=last)
            {
                last->ID=first->ID;
                strcpy(last->Name,first->Name);
                last->Age = first->Age;
                last=last->pPre;
            }
        }
        first->ID=stu.ID;
        strcpy(first->Name,stu.Name);
        first->Age=stu.Age;
        if (p!=first) {
            SortlinkAGE(p1,p,first->pPre);//递归调用
        }
        if (q!=last) {
            SortlinkAGE(p1,first->pNEXT,q);//递归调用
        }
    }}
    return p1;
}

void xiugai(NODED*p)
{
    int find=0;
    if (p==NULL) {//链表为空
        puts("链表为空！");
    }
    else
    {//链表不为空
        long id;
        printf("请输入要修改的学号：");
        scanf("%ld",&id);
        NODED * s = p;
        while (NULL!=s) {
            if (id == s->ID) {
                printf("%ld\t%s\t%d\n",s->ID,s->Name,s->Age);
                find = 1;
                NODED q;
                puts("输入修改数据：");
                printf("ID:");
                scanf("%ld",&q.ID);
                printf("Name:");
                scanf("%s",q.Name);
                printf("Age:");
                scanf("%d",&q.Age);
                s->ID=q.ID;
                strcpy(s->Name, q.Name);
                s->Age=q.Age;
            }
            s = s->pNEXT;
        }
    }
    if (1 == find) {
        puts("查找成功！");
    }
    else
    {
        puts("查找失败，不存在此数据！");
    }
}
void swap(NODED*p1,NODED*q)
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

