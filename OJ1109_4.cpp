/*
Created by @zch0423 on 2020/10/18.
Filename: OJ1109_4.cpp
Content: 数组实现 100分
*/



#include <iostream>
using namespace std;
#define MAX_NUM 100000

class person{
public:
    person(){}
    ~person(){}
    int ai;
    int no;
};

int main(){
    int number;
    scanf("%d", &number);
    person queue[MAX_NUM+1];
    queue[0].ai = number+1;
    int ci;
    int top;
    int temp;
    person tempPerson;
    for (int i = 1; i <=number; ++i) {
        scanf("%d %d", &temp, &ci);
        queue[i].ai = temp;
        queue[i].no = i;
        top = queue[i-1].ai;
        for (int j = 0;top<temp&&j <ci;) {
            tempPerson = queue[i-j-1];
            queue[i-j-1] = queue[i-j];
            queue[i-j] = tempPerson;
            ++j;
            top = queue[i-j-1].ai;
        }
    }
    for (int i = 1; i <=number ; ++i) {
        printf("%d ", queue[i].no);
    }
    return 0;
}


