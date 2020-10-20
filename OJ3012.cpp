/*
Created by @zch0423 on 2020/10/18.
Filename: OJ3012.cpp
Content: 
*/




#include <iostream>

using namespace std;

class stack{
private:
    int* data;
    int topP;
public:
    stack(int initSize){
        data = new int[initSize];
        topP = -1;
    }
    ~stack(){delete []data;}
    bool isEmpty()const{
        return topP==-1;
    }
    int pop(){
        return data[topP--];
    }
    void push(int& x){
        data[++topP] = x;
    }
};

int main() {
    int number;
    cin>>number;
    stack s(number);
    int op;
    int num;
    for(int i=0;i<number;++i){
        cin>>op>>num;
        switch(op){
            case 1:
                s.push(num);
                cout<<"OK"<<endl;
                break;
            case 2:
                if(s.isEmpty()){
                    cout<<"ERROR"<<endl;
                }else{
                    if(s.pop()!=num){
                        cout<<"NO"<<endl;
                    }else{
                        cout<<"YES"<<endl;
                    }
                }
                break;
        }
    }
    return 0;
}

