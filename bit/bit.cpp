#include<iostream>
#include<algorithm>
using namespace std;

int fun1(int n){
    int cnt=0;
    while(n){
        if(n & 1) cnt++;
        n = n >> 1;
    }
    return cnt;
}

int fun2(int n)
{
    int cnt = 0;
    while(n){//每次循环去掉末尾的1
        n &= n-1;
        cnt++;
    }
    return cnt;
}

void swap1(int &a, int &b){
    a ^= b;
    b ^= a;
    a ^= b;
}

int findSingleNumber(int *a, int n)
{
    int single = a[0];
    for(int i=1; i<n; i++) single ^= a[i];
    return single;
}

int findOne(int n){
    int loc = 0;
    int tmp = n ^ (n-1);
    while(tmp){
        loc++;
        tmp = tmp>>1;
    }
    return loc;
}
int main()
{
    //int a = 2, b = 3;
    int a=13123;
    cout<<(a^1)-(~a)<<endl;
    return 0;
}
