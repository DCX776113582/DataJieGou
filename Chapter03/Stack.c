//
//  Stack.c
//  Chapter03
//
//  Created by mac on 18/1/24.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Stack.h"
#include <stdlib.h>
#include <string.h>
SqStack* initStack()//初始化栈
{
    SqStack* s =(SqStack*)malloc(sizeof(SqStack));
    s->top = -1;
    return s;
}
int getTop(SqStack * s, int* e)//取栈顶元素
{
    if(s->top == -1){
        return -1;
    }
    *e = s->data[s->top];
    return *e;
}
int Push(SqStack * s,int e)//进栈
{
    if(s->top == N-1){
        puts("入栈溢出");
        return -1;
    }
    s->top++;
    s->data[s->top] = e;
    return 1;
}
void Pop(SqStack * s,int* e)//出栈
{
    if(s->top == -1){
        puts("出栈失败");

    }
    *e = s->data[s->top];
    s->top--;
    puts("出栈成功");
    //    return 1;
}
void destroyStack(SqStack * s)//销毁栈
{
    free(s);
}
void test()
{
    printf("初始化栈...\n");
    SqStack* s = initStack();
    
    printf("入栈中...\n");
    for (int i = 0; i<N; ++i) {
        Push(s, (i+1)*4);
    }
    printf("入栈完成...\n");
    
    printf("出栈:\n");
    int x;
    for (int i =N; i>0; --i) {
        printf("获取栈顶元素:\n");
        int y;
        getTop(s,&y);
        printf("y:%d\n",y);
        
        Pop(s,&x);
        printf("x:%d\n",x);
    }
    
    printf("销毁栈...\n");
    destroyStack(s);
}
int symnetry(SQStack*s)
{
    for (int i=0; i<N; i++) {
        PushStu(s,s->data[i]);
    }
    int tag = 1;
    int i = 0;
    while (i<N) {
        STU e;
        PopStu(s, &e);
        if (e.ID == s->data[i].ID&&strcmp(e.Name, s->data[i].Name)==0&&e.Age==s->data[i].Age) {
            i++;
        }else{
            tag = 0;
            break;
        }
        
    }
    clearStu(s);
    return tag;
}
SQStack* initStuStack()
{
    SQStack* s =(SQStack*)malloc(sizeof(SQStack));
    for (int i = 0; i<N; ++i) {
        s->data[i].ID=0;
        strcpy(s->data[i].Name,"");
        s->data[i].Age=0;
    }
    s->top = NULL;
    return s;
}
int getStuTop(SQStack * s, STU* e)
{
    if ((s->top) == NULL) {
        return 0;
    }else{
        *e = *s->top;
        return 1;
    }
}
int PushStu(SQStack * s,STU e)
{
    if ((s->top) == &s->data[N-1]) {//栈是否满了
        return -1;
        
    } else {//再入栈
        if (s->top == NULL) {
            s->top = &(s->data[-1]);
        }
        s->top++;
        s->size++;
        *(s->top) = e;
        return 1;
        
    }
}
int yuansu(SQStack*s)
{
    return s->size;
}
int PopStu(SQStack * s,STU* e)
{
    if ((s->top) == NULL) {//栈是否满了
        return -1;
        
    } else {//再入栈
        *e = *(s->top);
        s->top--;
        s->size--;
        if (s->top - &s->data[0]==-1) {
            s->top=NULL;
        }
        return 1;
        
    }
}
int destroyStuStack(SQStack * s)
{
    if (s!=NULL) {
        free(s);
        s=NULL;
    }
    if (s==NULL) {
        return 1;
    }else{
        return -1;
    }
}
int clearStu(SQStack *s)
{
    while (s->top!=NULL) {
        s->top->ID=0;
        strcpy(s->top->Name,"");
        s->top->Age=0;
        s->top--;
        if (s->top - &s->data[0]==-1) {
            s->top=NULL;
        }
    }
    if (s->top==NULL) {
        return 1;
        
    }else{
        return -1;
        
    }
}
void testStu()
{
    printf("初始化栈...\n");
    SQStack* s = initStuStack();
    
    printf("入栈中...\n");
    for (int i = 0; i<N; ++i) {
        s->data[i].ID=i+1;
        printf("请输入第%d个姓名：",i+1);
        scanf("%s",s->data[i].Name);
        s->data[i].Age=(i+1)*5;
        PushStu(s, s->data[i]);
    }
    printf("入栈完成...\n");
    
    printf("出栈:\n");
    STU x;
    for (int i =N; i>0; --i) {
        printf("获取栈顶元素:\n");
        STU y;
        getStuTop(s,&y);
        printf("y:%ld\t%s\t%d\n",y.ID,y.Name,y.Age);
        
        PopStu(s,&x);
        printf("x:%ld\t%s\t%d\n",x.ID,x.Name,x.Age);
    }
    
    printf("销毁栈...\n");
    destroyStuStack(s);
}