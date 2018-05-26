//
//  Sort.c
//  Chapter05
//
//  Created by mac on 18/1/23.
//  Copyright (c) 2018年 duanchuanxin. All rights reserved.
//

#include "Sort.h"
int a[N]={1,0,9,3,2};
static int count = 0;
void trest(int a[],int n)//冒泡排序
{
        for (int i = 0; i<5-1; ++i) {//控制循环比较的趟数/轮数
            for (int j = 0; j<(5-1)-i; ++j) {//控制没趟比较的次数：本趟比前一趟比较少一次
                if (a[j]<a[j+1]) {
                    int t = a[j];
                    a[j] = a[j+1];
                    a[j+1] = t;
                }
                count++;
            }
        }
//    for (int i = 0; i<n-1;++i) {
//        int *p,*q;
//        p = &a[0];
//        q = &a[1];
//        for (int j = 0; j<(n-1)-i; ++j,++p,++q) {
//            if(*p>*q)
//            {
//                int t = *p;
//                *p = *q;
//                *q = t;
//            }
//            count++;
//        }
//    }
    printf("%d\n",count);
}
void printA(int a[],int n)//打印
{
    for (int i = 0; i<n; ++i) {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void print(int *array,int n)//打印
{
    for(int i = 0;i < n;++i)
    {
        printf("\t%d",*(array+i));
        if(i == n-1)
        {
            printf("\n");
            break;
        }
    }
    return;
}
void selectSort(int a[],int n)//选择排序-下标
{
    //min表示每次排序的基准位（数据元素的下标位置）
    int min = 0,temp,i,j;
    for(i = 0;i<n-1;++i)
    {
        printf("第%d轮：",i+1);
        print(a,n);
        min = i;//假设无序区第一个元素最小
        for(j = i+1;j<n;++j)
        {
            if(a[min]>a[j])//选择最小元素
                min=j;//更新最小元素位置
        }
        if(min!=i)
        {
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
        printf("|基准位:%d|基准元素:%d|A[%d]—A[%d]最小的元素:%d|\n",min,a[min],i,n-1,a[i]);
        print(a,n);
    }
    printf("\n");
}
void sor1(int a[],int n)//选择排序-指针
{
    for (int i = 0; i<n-1; ++i) {
        int * m = &a[i];
        int * p = &a[i];
        for (int j = i+1; j<n; ++j) {
            int * q = &a[j];
            if (*m>*q) {
                m=q;
            }
        }
        if (p!=m) {
            int temp;
            temp = *p;
            *p=*m;
            *m=temp;
        }
    }
}
void sort1(int a[],int n)//插入排序
{
    int i;//无序区NO.1
    int j;//有序区NO.1
    int temp;//存储被插入元素（无序区中第一个元素）
    
    for (i = 1; i<n; ++i) {
        printf("第%d轮：\n",i);
        print(a,n);
        temp = a[i];//1、存储被插入元素
        //2、找适合被插入元素的位置（在有序区中：自右向左）
        for (j = i-1; j>=0; --j) {
            if (temp<a[j]) {//如果小于，右移
                a[j+1]=a[j];
            }else{
                break;
            }
        }
        //3、直接插入：位置：有序区标记的位置j+1
        a[j+1]=temp;
        print(a,n);
    }
}
int* quick_sort(int s[], int first, int last)//快速排序-下标
{
    if (first < last){
        int i = first, j = last, middle = s[first];//
        while (i < j){//循环
            //1、自右向左（寻找小于middle的数）
            while(i < j && s[j] >= middle){
                j--;
            }
            if(i < j){
                s[i++] = s[j];
            }
            //2、自左向右（寻找大于middle的数）
            while(i < j && s[i] < middle){
                i++;
            }
            if(i < j){
                s[j--] = s[i];
            }
        }
        //在适当的位置处插入数据（i==j）
        s[i] = middle;
        //对小于key的数据再次进行快速排序
        quick_sort(s, first, i - 1);
        //对大于key的数据再次进行快速排序
        quick_sort(s, i + 1, last);
    }
    return s;
}
int* quicksort(int s[], int* first, int* last)//快速排序-指针
{
    if (first < last){
        int *i = first, *j = last, middle = *i;//
        while (i < j){//循环
            //1、自右向左（寻找小于middle的数）
            while(i < j && *j >= middle){
                j--;
            }
            if(i < j){
                *i = *j;
                i++;
            }
            //2、自左向右（寻找大于middle的数）
            while(i < j && *i < middle){
                i++;
            }
            if(i < j){
                *j = *i;
                j--;
            }
        }
        //在适当的位置处插入数据（i==j）
        *i = middle;
        //对小于key的数据再次进行快速排序
        quicksort(s, first, i - 1);
        //对大于key的数据再次进行快速排序
        quicksort(s, i + 1, last);
    }
    return s;
}
void Print(int s[])//打印
{
    for (int k=0; k<7; ++k){
        printf("%d ",s[k]);
    }
    printf("\n");
}
void BuildHeap(int array[],int length)//堆排序程序
{
    int i;
    for (i = length/2-1 ; i >= 0; --i)
    {
        HeapAdjust(array, i, length);
    }
}
void HeapAdjust(int array[], int i, int nLength)//堆排序调整程序
{
    int nChild = 0;
    int nTemp = 0;
    for (nTemp = array[i]; 2 * i + 1 < nLength; i = nChild) {
    nChild = 2 * i + 1;
        if ( nChild < nLength - 1 && array[nChild + 1] >
            array[nChild])
        {
            ++nChild;
        }
        if (nTemp < array[nChild])
        {
            array[i] = array[nChild];
            array[nChild]= nTemp;
        }
        else
        {
            break;
        }
    }
}
void HeapSort(int array[],int length)//堆排序运行程序
{
    int tmp;
    BuildHeap(array, length);
    for (int i = length - 1; i > 0; --i)
    {
        {
            tmp = array[i];
            array[i] = array[0];
            array[0] = tmp;
        }
        HeapAdjust(array, 0, i);
    }
    printf("\n");
    print(array, length);
}
//调整堆：满足堆的特性（数据源，非叶子节点位置，无序区元素个数）
void heapAdjust(int array[],int i,int length)//调整堆
{
    int leftChild = 0;
    int maxChild = 0;
    int temp;
    //2*i+1<length:非叶子节点有效
    for (temp = array[i]; 2*i+1<length; i =maxChild) {
        leftChild = 2*i+1;//标记有效的非叶子节点
        //是否有右孩子
        if (leftChild<length-1&&array[leftChild]<array[leftChild+1]) {
            leftChild++;//右孩子，右节点
        }
        maxChild=leftChild;
        //父节点与较大孩子节点数值进行交换
        if (temp<array[maxChild]) {
            array[i]=array[maxChild];
            array[maxChild]=temp;
        }else{
            break;
        }
    }
}
void chushidui(int array[])
{
    int temp;//交换数据的临时变量
    //1、建立初始堆
    int length = N;//存储当前无序区的元素个数
    for (int i = length/2-1;i>=0;--i)//i:非叶子节点下标（倒数）
    {
        //调整堆
        heapAdjust(array,i,length);//数据源，非叶子节点，无序区元素个数
    }
    //2、交换，排序(堆顶元素与无序区最后一个元素交换)
    for (int j = length-1;j>0; --j) {
        //交换
        {
            temp = array[0];//temp存储堆顶元素
            array[0] = array[j];//无序区最后一个元素赋值给堆顶元素
            array[j] = temp;//原来堆顶元素赋值给无序区最后一个元素（即变为有序区的新元素）
        }
        //对交换后的无序区元素重新进行堆调整
        for (int i = j/2-1;i>=0;--i)//i:非叶子节点下标（倒数）
        {
            //调整堆
            heapAdjust(array,i,j);//数据源，非叶子节点，无序区元素个数
        }
    }
}
void Heapsort()
{
//    int a[N]={12,32,1,34,45,56,7,33,4,31,77};
    trest(a, N);
    print(a, N);
//    print(a, N);
}
