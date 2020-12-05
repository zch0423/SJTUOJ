/*
    Filename   : OJ1226.cpp
    Author     : @zch0423
    Date       : Dec 5, 2020
    Description: 快速排序

*/
#include<iostream>
using namespace std;

void quickSort(int* a, int low, int high){
    if(low>=high)return;
    int lowp = low, highp = high;
    int key = a[lowp];
    while(lowp<highp){
        while(a[highp]>=key&&highp>lowp){
            --highp;
        }
        a[lowp] = a[highp];
        while(a[lowp]<=key&&lowp<highp){
            ++lowp;
        }
        a[highp] = a[lowp];
    }
    a[lowp] = key;
    quickSort(a, low, lowp-1);
    quickSort(a, lowp+1, high);
}

int main(){
    int num;
    scanf("%d", &num);
    int* a;
    a = new int[num];
    for(int i=0;i<num;++i){
        scanf("%d", &a[i]);
    }
    quickSort(a, 0, num-1);
    for(int i=0;i<num;++i){
        printf("%d ", a[i]);
    }
    delete []a;
    return 0;
}

