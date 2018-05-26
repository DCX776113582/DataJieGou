//
//  studinfo.h
//  Chapter02
//
//  Created by mac on 18/1/18.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter02__studinfo__
#define __Chapter02__studinfo__


#include "Header.h"
void StudentLinkLable();//尾插法
void PrintStuLinkLable(NODE * p);//打印链表
void StudentHead();//头插法
void Freehead(NODE * p);//释放链表
int search(NODE * p);//查询链表
int StudentDeleteLinkLable(NODE * p);//删除链表
void SaveStuLinkLable(NODE * p);//保存
void LoadStuLinkLable(NODE  *p);//读取
void insertlink(NODE*p);
void reverseList(NODE*p);
void load(NODE*p);
void sortlink(NODE*p);
void Sortlink(NODE*p);
#endif /* defined(__Chapter02__studinfo__) */
