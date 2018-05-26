//
//  DoubleList.h
//  Chapter02
//
//  Created by mac on 18/1/22.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter02__DoubleList__
#define __Chapter02__DoubleList__

#include <stdio.h>
#include "Header.h"
void CretDLinkLable();//尾插法
void PrintStuDLinkLable(NODED * p);//打印链表
void PrintStuDLinkLableT(NODED * p);//打印链表
void StudentDHead();//头插法
void FreeheadD(NODED * p);//释放链表
void searchD(NODED * p);//查询链表
void StudentDeleteDLinkLable(NODED * p);//删除链表
void SaveStuDLinkLable(NODED * p);//保存
void LoadStuDLinkLable(NODED  *p);//读取
void insertDlink(NODED*p);
void reverseDList(NODED*p);
void reverseDListT(NODED*p);
void loadD(NODED*p);
void sortlinkD(NODED*p);
void SortlinkD(NODED*p);
void SortlinkDC(NODED*p);//插入排序
//NODED* SortlinkDK(NODED*p,NODED*q);//快速排序
NODED* SortlinkID(NODED*p1,NODED*p,NODED*q);//快速排序
NODED* SortlinkNAME(NODED*p1,NODED*p,NODED*q);//快速排序
NODED* SortlinkAGE(NODED*p1,NODED*p,NODED*q);//快速排序
void xiugai(NODED*p);
void swap(NODED*p1,NODED*q);

#endif /* defined(__Chapter02__DoubleList__) */
