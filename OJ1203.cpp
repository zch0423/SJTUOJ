#include <iostream>
#include <string>
using namespace std;

// 顺序表
template<class elemType>
class seqList{
private:
    elemType* data;
    int currentLength;
    int maxSize;
    void doubleSpace();

public:
    explicit seqList(int initSize=10);
    ~seqList(){delete []data;}
    void clear(){currentLength=0;}
    int length()const{return currentLength;}
    void insert(int i, const elemType& x);
    void remove(int i);
    int search(const elemType&x)const;
    elemType visit(int i)const;
    void traverse()const;
    seqList operator+(const seqList& list){
        int length = currentLength+list.currentLength;
        seqList<elemType> newList(length);
        int i = 0;
        for (; i < currentLength; ++i) {
            newList.data[i] = data[i];
        }
        for (int j=0; i < length; ++i,++j) {
            newList.data[i] = list.data[j];
        }
        newList.currentLength = length;
        return newList;
    }
};

// implementation of seqList
//template <class elemType>
//elemType seqList<elemType>::visit(int i) const {
//    return data[i];
//}

template <class elemType>
void seqList<elemType>::traverse() const {
    int i = 0;
    for(;i<currentLength-1;++i){
        cout<<data[i]<<' ';
    }
    if(currentLength!=0)cout<<data[i];
}

template <class elemType>
seqList<elemType>::seqList(int initSize) {
    data = new elemType[initSize];
    maxSize = initSize;
    currentLength = 0;
}

//template <class elemType>
//int seqList<elemType>::search(const elemType &x) const {
//    for(int i=0;i<currentLength;++i){
//        if(data[i]==x){
//            return i;
//        }
//    }
//    return -1;
//}

template <class elemType>
void seqList<elemType>::doubleSpace() {
    elemType* temp = data;
    maxSize *= 2;
    data = new elemType[maxSize];
    for(int i=0;i<currentLength;++i){
        data[i] = temp[i];
    }
    delete []temp;
}

template<class elemType>
void seqList<elemType>::insert(int i, const elemType &x) {
    if(currentLength==maxSize){
        doubleSpace();
    }
    for(int j=currentLength;j>i;--j){
        data[j] = data[j-1];
    }
    data[i] = x;
    ++currentLength;
}

//template<class elemType>
//void seqList<elemType>::remove(int i) {
//    for(int j=i;j<currentLength-1;++j){
//        data[j] = data[j+1];
//    }
//    --currentLength;
//}

template <typename T>
void combine(){
    int l1=0, l2=0;
    cin>>l1>>l2;
    seqList<T> link1(l1), link2(l2);
    for (int i = 0; i < l1; ++i) {
        T temp;
        cin>>temp;
        link1.insert(i, temp);
    }
    for (int j = 0; j < l2; ++j) {
        T temp;
        cin>>temp;
        link2.insert(j, temp);
    }
    seqList<T> newLink = link1+link2;
    newLink.traverse();
}

int main(){
    string type;
    cin>>type;
    if(type=="int"){
        combine<int>();
    }else if(type=="double"){
        combine<double>();
    }else{
        combine<char>();
    }
    return 0;
}
