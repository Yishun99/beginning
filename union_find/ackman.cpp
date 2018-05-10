#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

const int maxn = 100 + 10;

long long ackman(int m, int n)
{
    while(m){
        if(!n) n = 1;
        else n = ackman(m, n-1);
        m -= 1;
    }
    return n + 1;
}

int main()
{
    int n,m;
    while(scanf("%d %d", &m, &n)!=EOF){
        long long res = ackman(m,n);
        cout<<res<<endl;
    }
}
