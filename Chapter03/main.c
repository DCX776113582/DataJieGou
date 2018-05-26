//
//  main.c
//  Chapter03
//
//  Created by mac on 18/1/24.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include <stdio.h>
#include "Stack.h"
#include <stdlib.h>
SQStack* s;
void menu()
{loop:
    puts("*************STACK MENU**************");
    puts("             1:创建容器");
    puts("             2:添加数据");
    puts("             3:访问数据");
    puts("             4:移除数据");
    puts("             5:清除数据");
    puts("             6:释放容器");
    puts("             7:元素个数");
    puts("             8:判断对称串");
    puts("             7:退出");
    puts("--------------------------------------");
    int choose;
    printf("Please choose:");
    scanf("%d",&choose);
    switch (choose) {
        case 1:{
            s = initStuStack();
            s->size = 0;
            puts("创建容器成功！");
            break;}
        case 2:{
            static int i = 0;
                printf("请输入第%d个学生信息：",i+1);
                printf("ID:");
                scanf("%ld",&s->data[i].ID);
                printf("NAME:");
                scanf("%s",s->data[i].Name);
                printf("AGE:");
                scanf("%d",&s->data[i].Age);
                int k = PushStu(s, s->data[i]);
            i++;
            if (1==k) {
                puts("添加(入栈)成功");
            }else{
                puts("添加(入栈)失败");
            }
            break;}
        case 3:{
            STU y;
            int k = getStuTop(s,&y);
            printf("%ld\t%s\t%d\n",y.ID,y.Name,y.Age);
            if (k==1) {
                puts("访问数据成功！");
            }else{
                puts("访问数据失败！");
            }
            break;}
        case 4:{
            STU x;
            int k = PopStu(s,&x);
            if (1==k) {
                printf("%ld\t%s\t%d\n",x.ID,x.Name,x.Age);
                puts("出栈(移除)成功");
            }else{
                puts("栈已空,出栈(移除)失败");
            }
            break;}
        case 5:{
            int k = clearStu(s);
            if (1==k) {
                puts("清除成功！");
            }else{
                puts("清除失败");
            }
            break;}
        case 6:{
            int k = destroyStuStack(s);
            if (1==k) {
                puts("释放成功");
            }else{
                puts("释放失败");
            }
            break;}
        case 7:{
            int k = yuansu(s);
            printf("元素个数为%d\n",k);
            break;}
        case 8:{
            int k = symnetry(s);
            printf("k = %d\n",k);
            if (k == 1) {
                puts("是对称串");
            }else{
                puts("不是对称串");
            }
            break;}

        case 9:{
            destroyStuStack(s);
            puts("退出成功");
            break;}

        default:
            break;
    }
    printf("是否继续操作(y/n):");
    char yes;
    getchar();
    scanf("%c",&yes);
    if (yes=='y') {
        goto loop;
    }else{
        puts("退出！");
    }
}
typedef struct ST{

}NEW;
int main(int argc, const char * argv[]) {
   
//    menu();
//    testIsStack();
//    int a[5]={1,2,3,4,5};
//    printf("%p\n",&a);
//    int*ptr=(int*)(&a+1);
//    printf("%p\n",ptr);
//    printf("%d,%d\n",*(a+1),*(ptr-1));
//    printf("%p\t%p\n",(a+1),(ptr-1));
    char *ptr;
    if ((ptr = (char *)malloc(0)) == NULL)
        puts("Got a null pointer");
    else
        puts("Got a valid pointer");
    return 0;
}
