/*
 *   FileName      ：OJ1001.cpp
 *   Author        ：@zch0423
 *   Date          ：2020年10月18日
 *   Description   ：二哥摘苹果
*/
#include <iostream>
using namespace std;
int main(){
    int height, chair, num;
    int appleHeight;
    int count = 0;
    scanf("%d %d %d", &height, &chair, &num);
    height += chair;
    for(int i=0;i<num;++i){
        scanf("%d",&appleHeight);
        if(appleHeight<=height){
            ++count;
        }
    }
    printf("%d",count);
    return 0;
}
