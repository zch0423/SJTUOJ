/*
 *   FileName      ：OJ1214.cpp
 *   Author        ：@zch0423
 *   Date          ：2020年10月21日
 *   Description   ：先序 后序 层次遍历二叉树 注意是孩子兄弟表示法！！
 *
输入文件一共包含N+1行。
第一行含有一个正整数N，代表树中结点总数。
第二行到第N+1行，每行包含三个整数，代表一个节点，序号为 1 的节点在这 N 行中的第 1 行（不包括节点总数那一行）。
其中第i行的三个整数Pi，Qi，Vi，代表序号为 i 的节点左孩子序号为Pi，右兄弟序号为Qi，序号为 i 的结点自身的权值为Vi。
若Pi=0，则表明结点i没有左孩子。同样的，若Qi=0，则表明i节点没有右兄弟。(ps. 第i行指的是这N行中的第i行)
输出包含三行。
第一行包含N个数，表示按先序遍历输出的各个结点的权值，用一个空格隔开。
第二行包含N个数，表示按后序遍历输出的各个结点的权值，用一个空格隔开。
第三行包含N个数，表示按层次遍历输出的各个结点的权值，用一个空格隔开。
*/
#include <iostream>
using namespace std;

struct node{
    node* child; // left child
    node* next; // right sibling
    int vi;
    node(){
        child=nullptr;
        next = nullptr;
    }
    ~node()= default;
};

template <typename T>
class Queue{
private:
    struct node{
        T data;
        node* next;
        node(const T&d, node* n= nullptr){
            data=d;
            next = n;
        }
        node(){
            next= nullptr;
        }
        ~node()= default;
    };
    node* front;
    node* rear;
public:
    Queue(){
        front= nullptr;
        rear=nullptr;
    }
    ~Queue(){
        node* temp;
        while(front!=nullptr){
            temp = front;
            front = front->next;
            delete temp;
        }
    }
    void enQueue(const T& n){
        if(rear==nullptr){
            rear = new node(n, nullptr);
            front = rear;
        }else{
            rear = rear->next = new node(n, nullptr);
        }
    }

    T deQueue(){
        node* temp = front;
        front = front->next;
        T data = temp->data;
        delete temp;
        if(front==nullptr)rear = nullptr;
        return data;
    }
    bool isEmpty()const {
        return front==nullptr;
    }

};

void processOne(node* t, int i, int lchild, int rsibling, int value){
    node* temp = &t[i];
    temp->vi = value;
    if(lchild!=0){
        temp->child = &t[lchild-1];
    }
    if(rsibling!=0 ){
        temp->next = &t[rsibling-1];
    }
}

void preOrder(node* r){
    if(r==nullptr){
        return;
    }
    printf("%d ", r->vi);
    preOrder(r->child);
    preOrder(r->next);
}

void postOrder(node* r){
    if(r==nullptr){
        return;
    }
    postOrder(r->child);
    printf("%d ", r->vi);
    postOrder(r->next);
}

void levelOrder(node* r){
    // queue
    node* temp;
    node* c;
    Queue<node*> q;
    q.enQueue(r);
    while(!q.isEmpty()) {
        temp = q.deQueue();
        printf("%d ", temp->vi);
        c = temp->child;
        while (c != nullptr) {
            q.enQueue(c);
            c = c->next;
        }
    }
}

int main(){
    int number;
    int lchild, rsibling, value;
    node* tree;
    node* root;
    long long temp = 0; // use to find root
    scanf("%d", &number);
    tree = new node[number]; // 第i个节点是第i-1个位置
//    temp = (number%2==0)?number/2*(number+1):(number+1)/2*number;
    for(int i=0; i<number;++i){
        scanf("%d %d %d", &lchild, &rsibling, &value);
        processOne(tree, i, lchild, rsibling, value);
        temp += i+1;
        temp -= lchild;
        temp -= rsibling;
    }
    root = &tree[temp-1];
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    levelOrder(root);
    delete []tree;
    return 0;
}

