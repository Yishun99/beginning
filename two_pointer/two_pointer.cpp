#include<iostream>
using namespace std;

void fun(int *a, int n){
    int head, tail;
    int s;
    head = 0;
    tail = n-1;
    while(head < tail){
        if(a[head] == 0){
            head++;
            continue;
        }
        if(a[tail] != 0){
            tail--;
            continue;
        }
        s = a[head];
        a[head] = a[tail];
        a[tail] = s;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
}

void fun2(int *a, int n){
    int head, tail;
    int s;
    head = 0;
    tail = n-1;
    while(true){
        while(!a[head]) head++;
        while(a[tail]) tail--;
        if(head >= tail) break;
        s = a[head];
        a[head] = a[tail];
        a[tail] = s;
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;
}

int main()
{
    int a[10] = {0,0,1,2,3,0,0,4,2,0};
    fun2(a, 10);
    cout<<*a<<endl;
}










