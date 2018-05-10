#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 10;

int f[maxn];//祖先

int find1(int x)
{
    while(f[x] != x)
        x = f[x];
    return x;
}

int find1(int x) //寻找到x的祖先
{
    return f[x] == x ? x : f[x] = find1(f[x]);//路径压缩
}

void join(int x, int y) //join两个集合
{
    int a = find1(x);
    int b = find1(y);
    if(a != b){
        f[a] = b;
    }
}


void count1(int n)

{
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(f[i]==i)
            cnt++;
    }
    cout <<cnt-1<<endl;

}

int main()
{
    int n;
    int m;
    int s,e;
    while(scanf("%d", &n) != EOF && n != 0){
        scanf("%d", &m);
        for(int i=1; i<=n; i++)//initial
            f[i] = i;
        for(int i=1; i<=m; i++){
            scanf("%d %d", &s, &e);
            join(s, e);
        }
        count1(n);
    }
    return 0;
}






























