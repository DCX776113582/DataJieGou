//
//  Sort.h
//  Chapter05
//
//  Created by mac on 18/1/23.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#ifndef __Chapter05__Sort__
#define __Chapter05__Sort__

#include <stdio.h>
#define N 5
void trest(int a[],int n);//冒泡排序
void printA(int a[],int n);
void print(int *array,int n);
void selectSort(int a[],int n);//选择排序
void sor1(int a[],int n);
void sort1(int a[],int n);//插入排序
int* quick_sort(int s[], int first, int last);
int* quicksort(int s[], int* first, int* last);

void Print(int s[]);
void BuildHeap(int array[],int length);
void HeapAdjust(int array[], int i, int nLength);
void HeapSort(int array[],int length);
void heapAdjust(int array[],int i,int length);
void chushidui(int array[]);
void Heapsort();
#endif /* defined(__Chapter05__Sort__) */
