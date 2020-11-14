/*
 *   FileName      ：OJ1216.cpp
 *   Author        ：@zch0423
 *   Date          ：2020年11月08日
 *   Description   ：二叉堆的优先队列实现, insert, find, decrease
*/
#include <iostream>
using namespace std;

class minHeap{
    private:
        int * elem;
        int currentSize;
        int maxSize;
    void floatUp(int i){
        //从第i个元素上浮
        int hole = i;
        int temp = elem[i];
        for(;hole>1&& temp<elem[hole/2];hole/=2){
            elem[hole] = elem[hole/2];
        }
        elem[hole] = temp;
    }
    public:
        minHeap(int capacity=100){
            elem= new int[capacity+1];
            maxSize = capacity;
            currentSize = 0;
        }
        ~minHeap(){
            delete []elem;
        }

        void insert(const int & x){
            // 插入
            int hole = ++currentSize;
            for(;hole>1&&x<elem[hole/2];hole/=2){
                elem[hole] = elem[hole/2];
            }
            elem[hole] = x;
        }
        void find(const int & x){
            // 打印优先值大于x的最小元素，输出下标
            int targetMin = 2147483647;
            int target = 0;
            int temp;
            for(int i =1;i<=currentSize;++i){
                temp = elem[i];
                if(temp>x && temp<targetMin){
                    targetMin = temp;
                    target = i;
                    }
                }
            cout<<target<<endl;
            }
    void decrease(int i, int v){
        elem[i] -= v;
        floatUp(i);
    }
        };



int main(){
    int number;
    scanf("%d", &number );
    char op[10];
    int value;
    int dValue;
    minHeap h(number);
    for(int i=0;i<number;++i){
        scanf("%s %d", op, &value);
        switch(op[0]){
            case 'i':h.insert(value);break;
            case 'd':scanf("%d", &dValue);h.decrease(value, dValue);break;
            case 'f':h.find(value);
        }
    }
    return 0;
}
