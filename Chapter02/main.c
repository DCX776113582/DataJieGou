//
//  main.c
//  Chapter02
//
//  Created by mac on 18/1/18.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include <stdio.h>
#include "Header.h"
#include "studinfo.h"
#include "DoubleList.h"
#include "CircularlyList.h"
extern NODE *head;
extern NODED *headD;
extern NODED *tailD;
extern NODE*headC;
extern NODED * headCD;//标记头结点
extern NODED * tailCD;//标记尾结点
extern STU*headL;
void menu()
{
    int choose;
    char yes;
loop:
        puts("**********************************");
        puts("*              1、创建            *");
        puts("*              2、添加            *");
        puts("*              3、保存            *");
        puts("*              4、读取            *");
        puts("*              5、打印            *");
        puts("*              6、查询            *");
        puts("*              7、删除            *");
        puts("*              8、逆置            *");
        puts("*              9、排序            *");
        puts("*              10、修改           *");
        puts("*              11、释放           *");
        puts("**********************************");
        printf("请选择：");
        scanf("%d",&choose);
        switch (choose) {
            case 1:{
                puts("1:单链表创建  2:双链表创建   3:循环链表创建");
                int xuan;
                printf("Please choose:");
                scanf("%d",&xuan);
                switch (xuan) {
                    case 1:{
                    l1:puts("1:头插法   2:尾插法");
                        int xuan;
                        printf("Please choose:");
                        scanf("%d",&xuan);
                        switch (xuan) {
                            case 1:
                                StudentHead();//头插法
                                break;
                            case 2:
                                StudentLinkLable();//尾插法
                                break;
                            default:goto l1;
                                break;
                        }
                        break;}
                    case 2:{
                    l2:puts("1:头插法   2:尾插法");
                        int xuan;
                        printf("Please choose:");
                        scanf("%d",&xuan);
                        switch (xuan) {
                            case 1:
                                StudentDHead();//头插法
                                break;
                            case 2:
                                CretDLinkLable();//尾插法
                                break;
                            default:goto l2;
                                break;
                        }
                        break;}
                    case 3:{
                    l3:puts("1:双链表尾插法   2:单链表尾插法  3:循环尾插法");
                        int xuan;
                        printf("Please choose:");
                        scanf("%d",&xuan);
                        switch (xuan) {
                            case 1:
                                CretCDLinkLable();//尾插法
                                break;
                            case 2:
                                CretCLinkLable();//尾插法
                                break;
                            case 3:
                                CretLOLinkLable();//尾插法
                                break;
                            default:goto l3;
                                break;
                        }
                        break;}
                    default:
                        break;
                }
                puts("创建成功！");
                break;}
            case 2:{
            l4:puts("1:单链表添加  2:双链表添加");
                int xuan;
                printf("Please choose:");
                scanf("%d",&xuan);
                switch (xuan) {
                    case 1:
                        insertlink(head);//添加
                        break;
                    case 2:
                        insertDlink(headD);//添加
                        break;
                    default:goto l4;
                        break;
                }
                puts("添加成功！");
                break;}
            case 3:{
            l5:puts("1:单链表保存  2:双链表保存");
                int xuan;
                printf("Please choose:");
                scanf("%d",&xuan);
                switch (xuan) {
                    case 1:
                        SaveStuLinkLable(head);//保存
                        break;
                    case 2:
                        SaveStuDLinkLable(headD);//保存
                        break;
                    default:goto l5;
                        break;
                }
                puts("保存成功！");
                break;}
            case 4:{
            l6:puts("1:单链表读取  2:双链表读取");
                int xuan;
                printf("Please choose:");
                scanf("%d",&xuan);
                switch (xuan) {
                    case 1:
                        load(head);
                        break;
                    case 2:
                        loadD(headD);
                        break;
                    default:goto l6;
                        break;
                }
                puts("读取成功！");
                break;}
            case 5:{
            l7:puts("1:单链表打印  2:双链表打印 3:循环单链表 4:循环双链表  5:循环打印");
                int xuan;
                printf("Please choose:");
                scanf("%d",&xuan);
                switch (xuan) {
                    case 1:
                        PrintStuLinkLable(head);//打印链表
                        break;
                    case 2:
                        PrintStuDLinkLable(headD);//打印链表
                        PrintStuDLinkLableT(tailD);
                        break;
                    case 3:
                        PrintStuCLinkLable(head);//打印链表
                        break;
                    case 4:
                        PrintStuCDLinkLable(headCD);//打印链表
                        PrintStuCDLinkLableT(tailCD);//打印链表
                        break;
                    case 5:
                        PrintStuLOLinkLable(headL);//打印链表
                    default:goto l7;
                        break;
                }
                puts("打印成功！");
                break;}
            case 6:{
            k1:puts("1:单链表查询  2:双链表查询");
                int xuan;
                printf("Please choose:");
                scanf("%d",&xuan);
                switch (xuan) {
                    case 1:
                        search(head);//查询链表
                        break;
                    case 2:
                        searchD(headD);//查询链表
                        break;
                    default:goto k1;
                        break;
                }
                searchD(headD);
                break;}
            case 7:{
            l8:puts("1:单链表删除  2:双链表删除 3:循环链表删除");
                int xuan;
                printf("Please choose:");
                scanf("%d",&xuan);
                switch (xuan) {
                    case 1:
                        StudentDeleteLinkLable(head);//删除链表
                        break;
                    case 2:
                        StudentDeleteDLinkLable(headD);//删除链表
                        break;
                    case 3:
                        
                        break;
                    default:goto l8;
                        break;
                }
                break;}
            case 8:{
            l9:puts("1:单链表逆置  2:双链表逆置1 3:双链表逆置2");
                int xuan;
                printf("Please choose:");
                scanf("%d",&xuan);
                switch (xuan) {
                    case 1:
                        reverseList(head);//逆置
                        break;
                    case 2:
                        reverseDList(headD);//逆置
                        break;
                    case 3:
                        reverseDListT(headD);//逆置
                        break;
                    default:goto l9;
                        break;
                }
                puts("逆置成功！");
                break;}
            case 9:{
            ll:puts("1:单链表排序  2:双链表排序");
                int xuan;
                printf("Please choose:");
                scanf("%d",&xuan);
                switch (xuan) {
                    case 1:{
                        puts("1:冒泡排序  2:选择排序");
                        int xuan;
                        printf("Please choose:");
                        scanf("%d",&xuan);
                        switch (xuan) {
                            case 1:
                                sortlink(head);
                                break;
                            case 2:
                                Sortlink(head);
                                break;
                            default:goto ll;
                                break;
                        }
                        break;}
                    case 2:{
                        puts("1:冒泡排序  2:选择排序  3:插入排序  4:快速排序");
                        int xuan;
                        printf("Please choose:");
                        scanf("%d",&xuan);
                        switch (xuan) {
                            case 1:
                                SortlinkD(headD);
                                break;
                            case 2:
                                sortlinkD(headD);
                                break;
                            case 3:
                                SortlinkDC(headD);
                                break;
                            case 4:{
                                puts("1:ID  2:NAME  3:AGE");
                                int chose;
                                printf("Please choose:");
                                scanf("%d",&chose);
                                switch (chose) {
                                    case 1:
                                        SortlinkID(headD,headD,tailD);
                                        break;
                                    case 2:
                                        SortlinkNAME(headD,headD,tailD);
                                        break;
                                    case 3:
                                        SortlinkAGE(headD,headD,tailD);
                                        break;
                                    default:
                                        break;
                                }
                                
                                break;}
                            default:goto ll;
                                break;
                        }
                        break;}
                    default:
                        break;
                }
                puts("排序成功！");
                break;}
            case 10:{
                //                sortlink(head);//排序
                xiugai(tailD);
                puts("修改成功！");
                break;}
            case 11:{
            ll1:puts("1:单链表释放  2:双链表释放 3:循环释放");
                int xuan;
                printf("Please choose:");
                scanf("%d",&xuan);
                switch (xuan) {
                    case 1:
                        Freehead(head);//释放
                        break;
                    case 2:
                        FreeheadD(headD);
                        break;
                    case 3:
                        FreeheadL(headL);
                        break;
                    default:goto ll1;
                        break;
                }
                puts("释放成功！");
                break;}
            default:puts("数据出错，正在退出");
                goto x;
                break;
        }
        printf("是否继续操作(y键继续，其他键退出)：");
        getchar();
        scanf("%c",&yes);
        if (yes=='y') {
            goto loop;
        }
        else
        {x:
            Freehead(head);//释放
            puts("退出成功");
        }
}
int main(int argc, const char * argv[]) {

    menu();
    return 0;
}
