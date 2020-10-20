/*
Created by @zch0423 on 2020/10/17.
Filename: OJ1109.cpp
Content: 二哥买车票 80 分
*/



#include <iostream>
using namespace std;
template <typename T>
class linkStack{
private:
    struct node{
        T data;
        node* next;
        node(const T&temp, node* n= nullptr){data=temp;next=n;}
        node(){next= nullptr;}
        ~node(){}
    };
    node* topP;
public:
    linkStack();
    ~linkStack();
    bool isEmpty()const;
    void push(const T&temp);
    T pop();
    T top()const;
    void traverse(){
        if(isEmpty()) {
            return;
        }
        node* temp = topP->next;
        while(temp!= nullptr){
            T value = pop();
            printf("%d ", value);
            temp = topP->next;
        }
        printf("%d", pop());
    }
};

template <typename T>
linkStack<T>::linkStack() {
    topP= nullptr;
}

template <typename T>
linkStack<T>::~linkStack() {
    node* temp;
    while(topP!= nullptr){
        temp = topP->next;
        delete topP;
        topP = temp;
    }
}

template <typename T>
bool linkStack<T>::isEmpty() const {
    return topP== nullptr;
}

template <typename T>
void linkStack<T>::push(const T &temp) {
    topP = new node(temp, topP);
}

template <typename T>
T linkStack<T>::pop() {
    node* temp = topP;
    T data = temp->data;
    topP = topP->next;
    delete temp;
    return data;
}

template <typename T>
T linkStack<T>::top() const {
    return topP->data;
}

void processOnePerson(int no, linkStack<int>&s1, linkStack<int>&s2, linkStack<int>&ns1, linkStack<int>&ns2){
    int ai, ci;
    scanf("%d %d", &ai, &ci);
    int v = s1.top();
    for (int i = 0; v<ai&&i < ci; ++i) {
        s2.push(s1.pop());
        ns2.push(ns1.pop());
        v = s1.top();
    }
    s1.push(ai);
    ns1.push(no);
    while(!s2.isEmpty()){
        s1.push(s2.pop());
        ns1.push(ns2.pop());
    }
}

int main(){
    int number;
    scanf("%d", &number);
    linkStack<int> noStack1, noStack2;// 存储编号
    linkStack<int> stack1, stack2; // 存储重要度
    stack1.push(number+1);  // 保证有top元素
    for (int i = 1; i <= number; ++i) {
        processOnePerson(i, stack1, stack2, noStack1, noStack2);
    }
    while(!noStack1.isEmpty()){
        noStack2.push(noStack1.pop());
    }
    noStack2.traverse();
    return 0;
}